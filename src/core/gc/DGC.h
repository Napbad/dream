//
// Created by napbad on 11/13/24.
//

#ifndef DGC_H
#define DGC_H

class ObjRefCnt
{
};

/*
struct A {
    int x;
    int y;
};

struct b {
    int z;
    A a;
};

int main() {
    B b;
    b.a = A(); // we call it old a
    b.a = A(); // we call it new a
}
*/
/* DGC
 * GC of this programming language ---- dream
 * How does it work?
 * 1. For each object, it will have a
 * (a.)reference counter (maybe unuseful),
 * (b.) function direct referenced flag, which is recording the object
 * is directly referenced by a function or not,
 * (c.) object traverse flag,
 * which is used to record whether the object is traversed in a traversal.
 * (d.) the gc turn where the object live.
 *  2. If an object is not referenced by any element, it will be collected.
 *  How to check an object is referenced or not?
 *  an object has 3 status: directly refernced by a function (like the 'b'),
 *                          in-transitively referenced by a function (like the 'new a')
 *                          not referenced by any function (like the 'old a')
 *
 * 3. How to collect an object?
 * It is easy to collect the object which is not referenced by a function.
 */
class DGC
{
};

#endif // DGC_H