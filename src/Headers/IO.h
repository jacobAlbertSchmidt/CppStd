#ifndef IO_H
#define IO_H

#include "TypeUtil.h"
#include "Span.h"
#include "Result.h"


template<typename T, Error E>
concept Reader = requires(T thing, Span<T> s) {
        {thing.Read(s)} -> IsSame<Result<void, E>>();
};

template<typename T, Error E>
concept Writer = requires(T thing, Span<T> s) {
        {thing.Write(s)} -> IsSame<Result<void, E>>();
};



#endif