#ifndef ERROR_H
#define ERROR_H
#include "Span.h"
#include "TypeUtil.h"
template<typename T>
concept Error = requires(T thing) {
        {thing.Msg()} -> IsSame<Span<const char>>)();

};


#endif