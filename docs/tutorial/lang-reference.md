# **dap** Language Reference

## I. Introduction
**dap** is an experimental programming language with rich features.

## II. Lexical Structure

### (I) Keywords
- `if`: Used for conditional judgment. It introduces a conditional expression, and if the condition is true, the related code block will be executed.
- `else`: Used in conjunction with `if`. When the `if` condition is not met, the code block after `else` will be executed.
- `elif`: Provides an additional conditional branch in the `if - else` structure, allowing for sequential judgment of multiple conditions.
- `for`: Builds a loop structure and can repeat the execution of a section of code according to specific iteration rules.
- `return`: Returns a value from a function or ends the execution of the function. If the function has no return value, `return` can be used alone.
- `fun`: Used to define a function, specifying the function name, parameter list, and function body.
- `var`: Declares a mutable variable. The value of the variable can be modified within its lifetime.
- `imt`: Presumably used to declare an immutable variable. Once initialized, its value cannot be changed.
- `extern`: Probably used to declare functions or variables defined externally so that they can be used in the current code module.
- `struct`: Defines a structure type, used to combine multiple member variables of different types to create a custom data structure.
- `break`: Used to break out of the current loop (such as a `for` loop).
- `include`: Used to import external files or modules, probably for code reuse or functionality expansion.
- `package`: Related to the program's package management, used to organize code and implement modular programming.
- `nullable`: Represented by `?`, probably used to indicate that a variable or data type can hold a null value, increasing the flexibility of data processing.
- `non_nullable`: Represented by `!`, probably used to restrict that a variable or data type cannot be null, helping to improve the security and certainty of the code.

### (II) Identifiers
Identifiers are used to name programming entities such as variables, functions, and structures. They must start with a letter (`a - z` or `A - Z`) or an underscore (`_`), and can be followed by any number of letters, numbers (`0 - 9`), or underscores. For example, `my_variable`, `_private_function`, `MyStruct`, etc. are all legal identifiers.

### (III) Constants
- **Integer Constants**: Consist of a sequence of digits, such as `42`, `0`, `-123`, etc., representing integer values.
- **Floating-Point Constants**: A sequence of numbers containing a decimal point, such as `3.14`, `-0.5`, etc., used to represent values with a decimal part.
- **String Constants**: A sequence of characters enclosed in double quotes (`"`), such as `"Hello, World!"`. Escape characters can be used in strings, such as `\n` representing a newline and `\t` representing a tab character, etc., to represent special or invisible characters.

### (IV) Operators
- **Arithmetic Operators**
  - `+`: Addition operation, can be used for adding numerical values or concatenating strings (depending on the language's support for string operations).
  - `-`: Subtraction operation, used for subtracting numerical values.
  - `*`: Multiplication operation, performs the multiplication of numerical values.
  - `/`: Division operation, calculates the division of numerical values.
  - `%`: Modulo operation, returns the remainder of the division of two integers.
  - `++`: Increment operator, increases the value of a variable by 1. It can be a pre-increment (such as `++x`), and its exact semantics and precedence may vary slightly in different scenarios.
  - `--`: Decrement operator, decreases the value of a variable by 1, with two forms of pre-decrement (`--x`).
  - `+=`, `-=`, `*=`, `/=`, `%=`: Compound assignment operators. For example, `x += 5` is equivalent to `x = x + 5`, and the others are similar, used to simplify assignment operations and combine arithmetic operations.
- **Relational Operators**
  - `<`: Determines whether the value on the left is less than the value on the right, returning a boolean result.
  - `<=`: Checks whether the value on the left is less than or equal to the value on the right, producing a boolean value.
  - `>`: Determines whether the value on the left is greater than the value on the right, with a boolean-type result.
  - `>=`: Verifies whether the value on the left is greater than or equal to the value on the right, returning a boolean value.
  - `==`: Compares whether two values are equal. For different data types, the definition of equality may vary, and the result is of boolean type.
  - `!=`: Determines whether two values are not equal, with a boolean-type output.
- **Logical Operators**
  - `&&`: Logical AND operator. The entire expression is true only when both conditions on the left and right are true. It adopts a short-circuit evaluation strategy, that is, if the left condition is false, the right condition will not be evaluated.
  - `||`: Logical OR operator. The entire expression is true as long as one of the conditions on the left and right is true. It also has the short-circuit evaluation characteristic, that is, if the left condition is true, the right condition will not be evaluated.
  - `!`: Logical NOT operator, inverts a single condition, changing true to false and false to true.
- **Bitwise Operators**
  - `&`: Bitwise AND operator, performs a bitwise AND operation on the binary representations of two integers.
  - `|`: Bitwise OR operator, performs a bitwise OR operation on the binary bits of an integer.
  - `^`: Bitwise XOR operator, performs a bitwise XOR operation on the binary bits of an integer.
  - `~`: Bitwise NOT operator, performs a bitwise NOT operation on the binary representation of an integer.
  - `<<`: Left shift operator, shifts the binary bits of an integer to the left by a specified number of bits, filling the right side with 0s.
  - `>>`: Right shift operator, shifts the binary bits of an integer to the right by a specified number of bits. For signed integers, the left padding bit is the sign bit extension.
  - `>>>`: Unsigned right shift operator, shifts the binary bits of an unsigned integer to the right by a specified number of bits, always filling the left side with 0s.
- **Other Operators**
  - `=`: Assignment operator, assigns the value on the right to the variable or expression on the left.
  - `.`: Used to access the properties of an object or the member variables of a structure.

### (V) Punctuation Symbols
- `;`: Statement terminator, used to mark the end of a statement, indicating a pause and separation in the code execution flow at this point.
- `,`: Comma, mainly used to separate function parameters, array elements, structure member initialization lists, and other related but different items.
- `(` and `)`: Parentheses, used in expressions to change the precedence of operations. The expressions inside the parentheses are calculated first; in function definitions and calls, they are used to enclose the parameter list of the function.
- `{` and `}`: Braces, used to delimit code blocks, such as function bodies, loop bodies, conditional statement blocks, etc., clarifying the scope and execution order of the code.
- `[` and `]`: Square brackets, probably used for array-related operations, such as declaring array types, accessing array elements, etc., defining the index range and operation method of the array.

### (VI) Comments
- **Single-Line Comments**: Starting with `//`, all content until the end of the line is considered a comment. The compiler or interpreter will ignore these comment contents, mainly used for providing brief explanations of the code or temporarily disabling part of the code.
- **Multi-Line Comments**: Starting with `/*` and ending with `*/`, all content in between is a comment and can span multiple lines, suitable for providing detailed explanations and descriptions of longer code segments or functional modules.

## III. Data Types

### (I) Basic Data Types
- **Integer Type**: Represented by integer constants, used to store integer values. The specific byte size and value range may vary depending on the language implementation.
- **Floating-Point Type**: Used to handle values with a decimal part, following specific floating-point representation standards and precision rules.
- **String Type**: Defined by string constants, capable of storing text information and supporting various string operations such as concatenation, extraction, and searching.
- **Boolean Type**: Although boolean literals are not explicitly shown in the lexical units, boolean values will be generated in scenarios such as conditional judgment and logical operations, used to represent the logical states of true (`true`) or false (`false`).

### (II) Composite Data Types
- **Structure Type**: Created by the `struct` keyword, allowing developers to define a custom data structure containing multiple member variables of different types. For example:

```
struct Point {
    var int x = 1;
    var int y = 1;
}
```

The above code defines a structure named `Point` with two integer member variables `x` and `y`. The members of the structure can be accessed by the `.` operator, such as `point.x` and `point.y` (assuming `point` is an instance of the `Point` structure).

- **Array Type**: Can be declared and operated on using `[` and `]`. For example, `var int[3] arr;` declares an integer array. Array elements can be accessed by index, such as `arr[0]` representing the first element of the array `arr`. The length of the array is fixed.

## IV. Expressions

### (I) Arithmetic Expressions


### (II) Relational Expressions


### (III) Logical Expressions


### (IV) Function Call Expressions


### (V) Array Access Expressions


## V. Statements

### (I) Variable Declaration Statements
- Use the `var` keyword to declare a mutable variable. The syntax is as follows:

```
var dataType variableName [= initialValue];
```

where `variableName` is the variable name, `dataType` is the variable's data type, and `initialValue` is an optional initial value. For example, `var int x = 5;` declares an integer variable named `x` and initializes it to 5; `var string str;` declares a string variable `str` without initializing it, and its initial value will be determined according to the default rules.

- Use the `imt` keyword to declare an immutable variable. The syntax is:

```
imt dataType constantName = initialValue;
```

For example, `imt float PI = 3.14;` declares an immutable double-precision floating-point variable named `PI` and initializes it to 3.14. Once declared, the value of `PI` cannot be modified.

After variable declaration, array type declaration can also be carried out. For example, `var int[10] arr;` declares an integer array variable `arr`.

### (II) Assignment Statements
The assignment statement uses the `=` operator to assign the value on the right to the variable or expression on the left. For example, `x = 10;` assigns the value 10 to the variable `x`; `arr[0] = 5;` assigns 5 to the first element of the array `arr`. Compound assignment operators can also be used for more concise assignment operations. For example, `x += 3` is equivalent to `x = x + 3`.

### (III) Conditional Statements
- **`if` Statement**:

The `if` statement can have a return value.

```
if condition {
    // Statements to be executed when the condition is true
} else {
    // Statements to be executed when the condition is false (optional)
}
```

For example:

```
if x > 5 {
    y = 10;
} else {
    y = 0;
}
```

The above code first checks whether `x` is greater than 5. If it is, `y` is assigned the value 10; otherwise, `y` is assigned the value 0.

- **`if - elif - else` Statement**:

```
if condition1 {
    // Execution block 1
} elif condition2 {
    // Execution block 2
} else {
    // Execution block 3 (optional)
}
```

For example:

```
if score >= 90 {
    grade = "A";
} elif score >= 80 {
    grade = "B";
} elif score >= 70 {
    grade = "C";
} else {
    grade = "D";
}
```

This code determines the grade of `grade` based on the value of `score`, sequentially judging multiple conditions. Once a condition is met, the corresponding statement block is executed and subsequent condition judgments are skipped.

### (IV) Loop Statements
- **`for` Loop**:

```
for initialization; condition; increment {
    // Loop body
}
```

For example:

```
for int i = 0; i < 10; i++ {
    // Operations in the loop body, such as printing the current index value
    print(i);
}
```

In this `for` loop, first, the initialization `int i = 0` is performed, then the condition `i < 10` is checked. If the condition is true, the code in the loop body is executed, and finally, the increment operation `i++` is performed. The loop will repeat this process until the condition is not satisfied.

### (V) Function Declaration Statements

```
fun functionName(parameterList) [returnType] {
    // Function body
    return returnValue; // Optional, if the function has a return value
}
```

For example:

```
fun add(imt int x, var int y): INT_TOKEN {
    return x + y;
}
```

The above code defines a function named `add` that accepts two integer parameters `x` and `y` and returns their sum. The code in the function body is executed when the function is called, and after execution, a value is returned according to the function's definition (if a return value is declared) or the function execution is ended (if no return value is declared).

### (VI) Return Statements
- Use the `return` keyword to return a value from a function. If the function has a return value, the syntax is `return expression;` for example, `return x + y;`. If the function has no return value, only `return;` can be used to end the execution of the function and return the control flow to the function call location.

### (VII) Structure Declaration Statements

```
struct structName {
    // Declarations of structure member variables
}
```

As mentioned earlier in the `struct Point` example, the structure declaration defines a new data type containing specific member variables. Structures can be used in programs to create objects or data collections with related properties, improving the organization and readability of the code.

### (VIII) Include Statements
- The `include` statement is used to import external files or modules. The syntax is `include packageName.fileName;`. This helps with code modularity and reuse, dispersing functionality into different files or modules for easier maintenance and management.

### (IX) Package Statements
- The `package` statement is related to program package operations. The syntax is `package packageName;`. It is used to organize the code's namespace.