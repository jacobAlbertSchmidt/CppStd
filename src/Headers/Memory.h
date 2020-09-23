#ifndef MEMORY_H
#define MEMORY_H


#include "TypeUtil.h"

namespace Memory {
        template<typename T>
        RemoveReference<T>&& Release(T&& thing) {
                return static_cast<RemoveReference<T>&&>(thing);
        }        
} // namespace Memory



#endif