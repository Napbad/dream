# What does dap do?

## syntax

### imt and var ✅
* the `imt` and `var` functions should be able to handle multiple arguments, mutable and immutable variable's check while compile

without specification, the variable type is immutable by default

```dap

imt int a = 1;
var int b = 2;

a = 10; // wrong

b = 20; // correct

```

### nullable and non-nullable ✅
* the type of variable should be nullable or non-nullable

```dap
var int a? = null;  // nullable
imt int b = 1;      // non-nullable
var int c! = 3;     // non-nullable

a = c; // correct

c = a; // wrong, you can not assign a nullable variable to a non-nullable variable

b = null; // wrong

a = b; // correct
```


### function

define:
```dap

fun add(int a, int b) int {
    return a + b;
}

fun add2(int a, int b) int? {
    return a + b;
}

imt int res = add(1, 2); // correct
imt int res2? = add2(1, 2); // correct
imt int res3 = add2(1, 2); // wrong, you can not assign a nullable variable to a non-nullable variable

```

### control flow

* dap supports `if`, `for`, `when`

#### if
```dap

if true {
    println("true");
}

if (false) {
    println("never print");
}

if 1 < 2 {
    println("1 < 2");
} elif 1 > 2 {
    println("never print");
} else {
    println("never");
}

imt int a = if 1 > 2 { 1 } else { 2 }
```

#### for
```dap

for int i = 0; i < 1; ++i {
    println(i);
}

// not supported yet
for int i in 0..10 {
    println(i);
}

// not supported yet
for i : [variable can be ranged] {
    println(i);
}

// not supported yet
for true {
    println("always print");
}
```

#### when

```dap

when (a) {
    "1": {
        println("1");
    }
    a > 2: {
        println("a > 2");
    }
    default: {
        println("default");
    }
}

imt int a = when (b) {
    "1": 1,
    b > 2: 2,
    default: 0
}

```



### variable type auto detect
* the type of variable should be auto detect while compile

```dap
var a = 1;       // a -> int
var b = "hello"; // b -> string
var c = true;    // c -> bool

imt a1 = 1;      // a1 -> int

imt b1! = "hello"; // b1 -> string and non-nullable
```

### when statement



### marco usage (or annotation?)



### operator optimize
* the order of operator's combination

## language features

### type inference
* dap can infer the type of variable
```dap
var a = 1;
var b = "hello";
var c = true;
var d = a + b;
println(d); // d -> string
```

### object-oriented programming


// TODO: NOT SUPPORT YET
```dap
class Person {}

```

### no circular including✅
* dap can not include files circularly


### GC and memory check
* dap can use GC to free memory, and delete unused variables manually.
* but it can not use together in one module.

### module system
* module using GC -> d-module
* module using delete -> p-module

* module api argument, return value should be only common value rather than reference or pointer
* a program can be divided into multiple high cohesion, low coupling modules
* allow async gc in different module