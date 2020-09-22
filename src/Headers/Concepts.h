#ifndef CONCEPTS_H
#define CONCEPTS_H
#include "TypeUtil.h"
template<typename T, typename U>
concept SameAs = IsSame<T,U>();


#endif