#ifndef SPAN_H
#define SPAN_H

template<typename T>
class Span {
private:
        T *data;
        int size;
public:
        Span(T *data, int size) : data(data), size(size) {}
        Span(const Span<T>& other) = default;
        Span(Span<T>&& other) = default;
        Span<T> &operator=(const Span<T>& other) = default;
        T *Data() {return data;}
        int Size() const {return size;}
        T &operator[](int n);
        T Set(int idx, T thing);
        T At(int idx) const;
};

template<>
class Span<char> {
private:
        char *data;
        int size;
public:
        Span(char *data, int size) : data(data), size(size) {}
        Span(const Span<char>& other) = default;
        Span(Span<char>&& other) = default;
        Span<char> &operator=(const Span<char>& other) = default;
        char *Data() {return data;}
        int Size() const {return size;}
        char &operator[](int n);
        char Set(int idx, char thing);
        char At(int idx) const;
};

template<>
class Span<const char> {
private:
        const char *data;
        int size;
public:
        Span(const char *data, int size) : data(data), size(size) {}
        Span(const Span<const char>& other) = default;
        Span(Span<const char>&& other) = default;
        Span<const char> &operator=(const Span<const char>& other) = default;
        const char *Data() {return data;}
        int Size() const {return size;}
        const char &operator[](int n);
        const char Set(int idx, const char thing) const;
        const char At(int idx) const;
};


#include "Panic.h"

template<typename T>
T &Span<T>::operator[](int n) {
        
}

        // T Set(int idx, T thing);
        // T At(int idx) const;

#endif