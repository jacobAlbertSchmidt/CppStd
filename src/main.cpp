#define DEBUG true

#include "Headers/Span.h"
#include <unistd.h>
#include "Headers/Debug.h"

int main() {
        auto s = "howdy!\n"_s;
        write(1, s.Data(), s.Size());
        char c[2] = {'0' + Debug(), '\n'};
        write(1, c, 2);
}