#ifndef ASSERT_H
#define ASSERT_H
#include "Debug.h"
#include "Panic.h"
constexpr void Assert(bool check, const Span<const char>& msg,  const char *file_name = __FILE__, int line_n = __LINE__, const char *fn = __FUNCTION__) {
        if constexpr (Debug()) {
                if (!check) {
                        Panic(msg, file_name, line_n, fn);
                }
        } else {
                (void) 0;
        }
}

#endif