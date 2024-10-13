# Features

## Enhanced Nullable and Non-Nullable Support

In `dream`, you can explicitly declare whether a variable is nullable or non-nullable by appending `!` or `?` to the variable type. This helps prevent null reference exceptions and makes your code more robust. The compiler checks for these attributes during compilation, ensuring that potential runtime errors are caught early.

**Example**:
```dream
imt int nullable_variable? = null;
imt int non_nullable_variable! = 10;
```

## Flexible Mutable and Immutable Support

`dream` offers a straightforward way to define mutable and immutable variables using the `var` and `imt` keywords, respectively. Immutable variables, once assigned, cannot be changed, promoting safer and more predictable code.

**Example**:
```dream
imt int immutable_variable! = 10; // immutable
var int mutable_variable! = 20;   // mutable

immutable_variable = 20; // Compilation error: Cannot reassign immutable variable
mutable_variable = 10;   // Allowed
```

## Advanced Garbage Collection

`dream` employs a data-oriented garbage collector that efficiently manages memory. This garbage collector is designed to collect unused data promptly after it is no longer needed, optimizing performance and reducing memory overhead. However, please note that this is a feature currently under development, and practical examples are not yet available.

## Comprehensive Data Types

`dream` boasts a rich set of basic data types, including `int`, `long`, `short`, `float`, `ulong`, `ullong`, and more. This allows you to choose the most appropriate data type for your needs, ensuring optimal performance and resource utilization.

## Superior Performance

The `dream` compiler is optimized for performance, generating efficient and highly optimized code. This ensures that your applications run smoothly and quickly, even under heavy loads.

## User-Friendly Syntax

The `dream` programming language features an intuitive and easy-to-learn syntax. Its clear and concise structure makes it accessible to developers of all skill levels, reducing the learning curve and enabling you to write code more productively.

## Coroutine Support

`dream` offers robust coroutine support, enabling you to write asynchronous code in a synchronous manner. This simplifies the development of concurrent applications and improves code readability. Additionally, `dream` is working on non-stack coroutine support, which will further enhance its concurrency capabilities.

## Asynchronization Support

`dream` is actively developing support for asynchronization, enabling you to write efficient and responsive applications that can handle multiple tasks simultaneously. This feature is still under development, but it promises to bring significant benefits to developers working on high-performance and real-time applications.
