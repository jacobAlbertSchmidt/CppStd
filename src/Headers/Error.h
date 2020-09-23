#ifndef ERROR_H
#define ERROR_H
#include "Span.h"
#include "TypeUtil.h"
#include "Concepts.h"

template<typename T>
concept Error = requires(T thing) {
        {thing.Msg()} -> SameAs<const Span<const char>>;
};

// class GenericError {
// private:

// public:

// };

#endif