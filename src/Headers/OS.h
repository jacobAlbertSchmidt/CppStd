#ifndef OS_H
#define OS_H
#include <errno.h>

static_assert(__linux__, "only linux is supported");
#include "Result.h"
#include "Span.h"
namespace OS {

        
        class Error {
        private:
                
        public:
                enum class Code {
                        Again = EAGAIN,
                        /*
                        EAGAIN The file descriptor fd refers to a file other than a socket
                                and has been marked nonblocking (O_NONBLOCK), and the write
                                would block.  See open(2) for further details on the
                                O_NONBLOCK flag.
                        */
                        WouldBlock = EWOULDBLOCK,
                        /*
                        EAGAIN or EWOULDBLOCK
                                The file descriptor fd refers to a socket and has been marked
                                nonblocking (O_NONBLOCK), and the write would block.
                                POSIX.1-2001 allows either error to be returned for this case,
                                and does not require these constants to have the same value,
                                so a portable application should check for both possibilities.
                        */
                        BadFile = EBADF,
                        /*
                        EBADF  fd is not a valid file descriptor or is not open for writing.
                        */
                        NoDestSet = EDESTADDRREQ,
                        /*
                        EDESTADDRREQ
                                fd refers to a datagram socket for which a peer address has
                                not been set using connect(2).
                        */
                        OverQuota = EDQUOT,
                        /*
                        EDQUOT The user's quota of disk blocks on the filesystem containing
                                the file referred to by fd has been exhausted.
                        */
                        MemFault = EFAULT,
                        /*
                        EFAULT buf is outside your accessible address space.
                        */
                        FileTooBig = EFBIG,
                        /*
                        EFBIG  An attempt was made to write a file that exceeds the
                                implementation-defined maximum file size or the process's file
                                size limit, or to write at a position past the maximum allowed
                                offset.
                        */
                        Interrupted = EINTR,
                        /*
                        EINTR  The call was interrupted by a signal before any data was
                                written; see signal(7).
                        */
                        INVALID = EINVAL,
                        /*
                        EINVAL fd is attached to an object which is unsuitable for writing;
                                or the file was opened with the O_DIRECT flag, and either the
                                address specified in buf, the value specified in count, or the
                                file offset is not suitably aligned.
                        */
                        IO = EIO,
                        /*
                        EIO    A low-level I/O error occurred while modifying the inode.
                                This error may relate to the write-back of data written by an
                                earlier write(), which may have been issued to a different
                                file descriptor on the same file.  Since Linux 4.13, errors
                                from write-back come with a promise that they may be reported
                                by subsequent.  write() requests, and will be reported by a
                                subsequent fsync(2) (whether or not they were also reported by
                                write()).  An alternate cause of EIO on networked filesystems
                                is when an advisory lock had been taken out on the file
                                descriptor and this lock has been lost.  See the Lost locks
                                section of fcntl(2) for further details.
                        */
                        NoSpace = ENOSPC,
                        /*
                        ENOSPC The device containing the file referred to by fd has no room
                                for the data.
                        */
                        PreventedByFileSeal = EPERM,
                        /*
                        EPERM  The operation was prevented by a file seal; see fcntl(2).
                        */
                        PipeClosed = EPIPE,
                        /*
                        EPIPE  fd is connected to a pipe or socket whose reading end is
                                closed.  When this happens the writing process will also
                                receive a SIGPIPE signal.  (Thus, the write return value is
                                seen only if the program catches, blocks or ignores this
                                signal.)
                        */
                };
private:
                
public: 
                static Code CodeNum() {
                        return ((Code) errno);
                }
                static Span<const char> Msg() {
                        switch (CodeNum()) {
                        // case Code::Again: return 
                        //         "Error: EAGAIN. The file descriptor fd refers to a file other than a socket"
                        //         "and has been marked nonblocking (O_NONBLOCK), and the write"
                        //         "would block.  See open(2) for further details on the"
                        //         "O_NONBLOCK flag. "_s;
                        case Code::WouldBlock: return 
                                "Error: EAGAIN or EWOULDBLOCK. "
                                "The file descriptor fd refers to a socket and has been marked"
                                "nonblocking (O_NONBLOCK), and the write would block."
                                "POSIX.1-2001 allows either error to be returned for this case,"
                                "and does not require these constants to have the same value,"
                                "so a portable application should check for both possibilities."_s;
                        
                        case Code::BadFile: return
                        
                                "Error: EBAD. fd is not a valid file descriptor or is not open for writing."_s;
                        
                        case Code::NoDestSet: return
                                "Error: EDESTADDRREQ. "
                                " fd refers to a datagram socket for which a peer address has"
                                "not been set using connect(2)"_s;
                        case Code::OverQuota: return 
                                "EDQUOT. The user's quota of disk blocks on the filesystem containing"
                                "the file referred to by fd has been exhausted."_s;
                        case Code::MemFault: return
                        "Error: EFAULT. buf is outside your accessible address space."_s;
                        case Code::FileTooBig: return
                        "Error: EFBIG/  An attempt was made to write a file that exceeds the"
                                "implementation-defined maximum file size or the process's file"
                                "size limit, or to write at a position past the maximum allowed"
                                "offset."_s;
                        case Code::Interrupted: return
                        "Error: EINTR. The call was interrupted by a signal before any data was"
                                "written; see signal(7)."_s;
                        case Code::INVALID: return
                        "Error: EINVAL. fd is attached to an object which is unsuitable for writing;"
                                "or the file was opened with the O_DIRECT flag, and either the"
                                "address specified in buf, the value specified in count, or the"
                                "file offset is not suitably aligned."_s;
                        case Code::IO: return
                        "Error: EIO. A low-level I/O error occurred while modifying the inode."
                                "This error may relate to the write-back of data written by an"
                                "earlier write(), which may have been issued to a different"
                                "file descriptor on the same file.  Since Linux 4.13, errors"
                                "from write-back come with a promise that they may be reported"
                                "by subsequent.  write() requests, and will be reported by a"
                                "subsequent fsync(2) (whether or not they were also reported by"
                                "write()).  An alternate cause of EIO on networked filesystems"
                                "is when an advisory lock had been taken out on the file"
                                "descriptor and this lock has been lost.  See the Lost locks"
                                "section of fcntl(2) for further details."_s;
                        case Code::NoSpace: return
                        "Error: ENOSPC. The device containing the file referred to by fd has no room"
                                "for the data."_s;
                        case Code::PreventedByFileSeal: return
                        "Error: EPERM. The operation was prevented by a file seal; see fcntl(2)."_s;
                        case Code::PipeClosed: return 
                        "Error: EPIPE. fd is connected to a pipe or socket whose reading end is"
                                "closed.  When this happens the writing process will also"
                                "receive a SIGPIPE signal.  (Thus, the write return value is"
                                "seen only if the program catches, blocks or ignores this"
                                "signal.)"_s;
                        
                        default:
                                return "Uknown Error"_s;
                        }
                }

        };
}

