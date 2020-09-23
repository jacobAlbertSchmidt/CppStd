#ifndef SPAN_H
#define SPAN_H
template<typename T>
class Span {
private:
        T *data;
        int size;
public:
        Span() = delete;
        Span(T *data, int size) : data(data), size(size) {}
        Span(const Span<T>& other) = default;
        Span(Span<T>&& other) = default;
        Span<T> &operator=(const Span<T>& other) = default;
        T *Data() {return data;}
        int Size() const {return size;}
        T &operator[](int n);
        T *begin() {return arr;}
        T *end() {return arr + size;}
        // T Set(int idx, T thing);
        // T At(int idx) const;
};

template<typename T>
class Span<const T> {
private:
        const T *data;
        int size;
public:
        Span() = delete;
        Span(const T *data, int size) : data(data), size(size) {}
        Span(const Span<const T>& other) = default;
        Span(Span<const T>&& other) = default;
        Span<const T> &operator=(const Span<const T>& other) = default;
        const T *Data() const {return data;}
        int Size() const {return size;}
        const T &operator[](int n) const;
        T *begin() {return arr;}
        T *end() {return arr + size;}
        // T Set(int idx, T thing);
        // T At(int idx) const;
};

template<>
class Span<char> {
private:
        char *data;
        int size;
public:
        Span() = delete;
        Span(char *data, int size) : data(data), size(size) {}
        Span(const Span<char>& other) = default;
        Span(Span<char>&& other) = default;
        Span<char> &operator=(const Span<char>& other) = default;
        char *Data() {return data;}
        int Size() const {return size;}
        char &operator[](int n);
        T *begin() {return arr;}
        T *end() {return arr + size;}
        // char Set(int idx, char thing);
        // char At(int idx) const;
};

template<>
class Span<const char> {
private:
        const char *data;
        int size;
public:
        Span() = delete;
        Span(const char *data, int size) : data(data), size(size) {}
        Span(const Span<const char>& other) = default;
        Span(Span<const char>&& other) = default;
        Span<const char> &operator=(const Span<const char>& other) = default;
        const char *Data() {return data;}
        int Size() const {return size;}
        const char &operator[](int n);
        T *begin() {return arr;}
        T *end() {return arr + size;}
        // const char Set(int idx, const char thing) const;
        // const char At(int idx) const;
};
#include<stddef.h>


Span<const char> operator""_s(const char *data, size_t size) {
        return Span<const char>(data, size);
}

#include "Panic.h"
#include "Assert.h"
template<typename T>
T &Span<T>::operator[](int n) {
        Assert(((unsigned) n) < size, "Error: idx out of range in Span"_s);
        return data[n];
}

template<typename T>
const T &Span<const T>::operator[](int n) const {
        Assert(((unsigned) n) < size, "Error: idx out of range in Span"_s);
        return data[n];
}
// template<typename T>
        // T Set(int idx, T thing);
        // T At(int idx) const;

#endif