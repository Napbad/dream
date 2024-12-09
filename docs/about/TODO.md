# TODO

### imt and var
* the `imt` and `var` functions should be able to handle multiple arguments, mutable and immutable variable's check while compile

### marco usage (or annotation?)

### operator optimize
* the order of operator's combination

### GC and memory check
* dap can use GC to free memory, and delete unused variables manually.
* but it can not use together.

### module system
* module using GC -> d-module
* module using delete -> p-module

* module api argument, return value should be only common value rather than reference or pointer
* a program can be divided into multiple high cohesion, low coupling modules
* allow async gc in different module
