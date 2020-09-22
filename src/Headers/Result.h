#ifndef RESULT_H
#define RESULT_H


template<typename T>
class Ok {
        T thing;
public:
        Ok(T thing) : thing(thing) {}
        T &Value() {return thing;}
};

template<>
class Ok<void> {
public:
        Ok() {}
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
        bool ok;
public:
        Result(Ok<T> ok) : thing(ok.Value()), ok(true) {}
        Result(Err<E> err) : err(err.Value()), ok(false) {}
        T &Check() {
                Assert(ok, err.Msg());
                return thing;
        }
        E &Error() {
                Assert(!ok, err.Msg());
                return err;
        }

        bool IsOk() const {return ok;}
};

struct Empty {}; //empty struct, sizeof(Empty) == 1

template<Error E>
class Result<void, E> {
private:
        union {
                Empty empty;
                E err;
        };
        bool ok;
public:
        Result(Ok<void> ok) : empty(), ok(true) {}
        Result(Err<E> err) : err(err.Value()), ok(false) {}
        void Check() {
                Assert(ok, err.Msg());
        }
        E &Error() {
                Assert(!ok, err.Msg());
                return err;
        }

        bool IsOk() const {return ok;}
};




#endif