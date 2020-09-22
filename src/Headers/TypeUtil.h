#ifndef TYPEUTIL_H
#define TYPEUTIL_H

template<typename T>
struct _RemoveReference {
        using Type = T;
};

template<typename T>
struct _RemoveReference<T&> {
        using Type = T;
};

template<typename T>
struct _RemoveReference<T&&> {
        using Type = T;
};

template<typename T>
using RemoveReference = _RemoveReference<T>::Type;


template<typename T, typename U>
struct _IsSame {
        static consteval bool Value() {return false;}
};

template<typename T>
struct _IsSame<T,T> {
        static consteval bool Value() {return true;}
};

template<typename T, typename U>
consteval bool IsSame() {
        return _IsSame<T,U>::Value();
}

template<typename T>
struct _RemoveConst {
        using Type = T;
};

template<typename T>
struct _RemoveConst<const T> {
        using Type = T;
};

template<typename T>
using RemoveConst = _RemoveConst<T>::Type;



#endif