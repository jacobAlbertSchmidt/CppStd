// #define DEBUG true

#include "Headers/Span.h"
#include <unistd.h>
#include "Headers/Debug.h"
#include "Headers/Result.h"
#include "Headers/Memory.h"
#include "Headers/Array.h"
struct OverflowError {
        static const Span<const char> Msg() {
                return "Overflow Error!"_s;
        }
};

Result<int, OverflowError> Add(int a, int b) {
        int res;
        if (__builtin_add_overflow(a, b, &res)) {
                return Err(OverflowError{});
        }
        return Ok(res);
}


int main() {
        Array<char, 8> arr {'a','b','c','d','e','f','g','\n'};
        for (auto c: arr) {
                write(1, &c, 1);
        }

        auto arr2 ( Memory::Release(arr) );
        for (auto c: arr2) {
                write(1, &c, 1);
        }

        // auto a = Add(2,4).Check();
        // char c[] = {a + '0', '\n'};
        // write(1, c, 2);
        // auto a = Memory::Release(2);
        // auto s = "howdy!\n"_s;
        // write(1, s.Data(), s.Size());
        // char c[2] = {'0' + Debug(), '\n'};
        // write(1, c, 2);
}