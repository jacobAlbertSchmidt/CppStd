#ifndef RESULT_H
#define RESULT_H


template<typename T>
class _Ok {
        T thing;
public:
        _Ok(T thing) : thing(thing) {}
        T &Value() {return thing;}
};

template<>
class _Ok<void> {
public:
        _Ok() {}
        void Value() {}
};

template<typename T>
class Err {
        T thing;
public:
        Err(T thing) : thing(thing) {}
        T &Value() {return thing;}
};
#include "Assert.h"
#include "Error.h"
template<typename T, Error E>
class Result {
private:
        union {
                T thing;
                E err;
        };
        bool _ok;
public:
        Result(Ok<T> _ok) : thing(ok.Value()), _ok(true) {}
        Result(Err<E> err) : err(err.Value()), _ok(false) {}
        T &Check() {
                Assert(_ok, err.Msg());
                return thing;
        }
        E &Error() {
                Assert(!_ok, err.Msg());
                return err;
        }

        bool Ok() const {return _ok;}
};

struct Empty {}; //empty struct, sizeof(Empty) == 1

template<Error E>
class Result<void, E> {
private:
        union {
                Empty empty;
                E err;
        };
        bool _ok;
public:
        Result(Ok<void> _ok) : empty(), _ok(true) {}
        Result(Err<E> err) : err(err.Value()), _ok(false) {}
        void Check() {
                Assert(__ok, err.Msg());
        }
        E &Error() {
                Assert(!__ok, err.Msg());
                return err;
        }

        bool _Ok() const {return _ok;}
};




#endif