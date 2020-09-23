#ifndef ARRAY_H
#define ARRAY_H
#include "Assert.h"
#include <initializer_list>
#include "Span.h"
#include <new>
#include "Memory.h"
template<typename T, int N>
class Array {
private:
        T arr[N];
public: 
        Array() {
                for (int i = 0; i < N; ++i) {
                        new (arr + i++) T();
                }
        }
        Array(std::initializer_list<T> l) {
                Assert(l.size() < N, "l.size() is greater than the size of the array"_s);
                int i = 0;
                for (auto el: l)  {
                        new (arr+(i++)) T (el);
                }
                while (i<N) {
                        new (arr+(i++)) T();
                }
        }

        T *Data() {
                return arr;
        }

        T &operator[](int i) {
                Assert(unsigned(i) < N, "Index out of range!"_s);
                return arr[i];
        }

        T *begin() {
                return arr;
        }
        T *end() {
                return arr + N;
        }

        Array(const Array<T,N>& other) {
                for (int i = 0; i < N; ++i) {
                        new (arr + i) T(other.arr[i]);
                }
        }

        Array(Array&& other) {
                for (int i = 0; i < N; ++i) {
                        new (arr + i) T(Memory::Release(other.arr[i]));
                }
        }


        ~Array() {
                for (int i = 0; i < N; ++i) {
                        arr[i].~T();
                }
        }
};

#endif