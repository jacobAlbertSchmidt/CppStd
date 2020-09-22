#ifndef PANIC_H
#define PANIC_H
#include "Span.h"

void Panic(const Span<const char> msg, const char *file_name = __FILE__, int line_n = __LINE__, const char *fn = __FUNCTION__);


#endif