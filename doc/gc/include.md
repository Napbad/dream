# GC

How's `dream`'s gc running?

> briefly about GC
> it generate delete statements automatically for you
 

assume that A has the following fields:
A {
    B b;
    D d;
}

B has the following fields:
B {
    C c;
}

```rust
DataRoot dataroot_f1;

fun f1 (A a) {
    a.b.c = new C();

    E e = new E();
}

DataRoot dataroot_main;

fun main() {
    A a = new A(); 
    a.b = new B(); 
    a.b.c = new C(); 
    D d_ = new D(); 
    a.d = d_; 

    f1(a); 
}

```