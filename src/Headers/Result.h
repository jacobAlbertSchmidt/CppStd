#ifndef RESULT_H
#define RESULT_H


template<typename T>
class Ok {
        T thing;
public:
        Ok(T thing) : thing(thing) {}
        T &Value() {return thing;}
};

template<typename T>
class Err {
        T thing;
public:
        Err(T thing) : thing(thing) {}
        T &Value() {return thing;}
};
#include "Assert.h"

template<typename T, typename E>
class Result {
private:
        union {
                T thing;
                E err;
        };
        bool ok;
public:
        Result(Ok<T> ok) : thing(ok), ok(true) {}
        Result(Err<E> err) : err(err), ok(false) {}
        T &Check() {
                Assert(ok);
                return thing;
        }
        E &Err() {
                Assert(!ok);
                return err;
        }

        bool Ok() const {return ok;}
};

struct Empty {}; //empty struct, sizeof(Empty) == 1

template<typename E>
class Result<void, E> {
private:
        union {
                Empty empty;
                E err;
        };
        bool ok;
public:
        Result(Ok<T> ok) : empty(), ok(true) {}
        Result(Err<E> err) : err(err), ok(false) {}
        void Check() {
                Assert(ok);
        }
        E &Err() {
                Assert(!ok);
                return err;
        }

        bool Ok() const {return ok;}
};




#endif