# This file will help you with reading and coding

## Some Abbreviations

| Abbreviation | Meaning                            | Example    |
|--------------|------------------------------------|------------|
| cnt          | Count                              | objCnt     |
| fun / func   | Function                           | funGen_sys |
| gen          | Generate                           | codegen    |
| inter        | Internal / Internal Representation | inter_gen  |

## Some References

| Type                      | Number | Instruction    | Description                        |
|---------------------------|--------|----------------|------------------------------------|
| Termination Instructions  | 1      | Ret            | Return Instruction                 |
| Termination Instructions  | 2      | Br             | Branch Instruction                 |
| Termination Instructions  | 3      | Switch         | Switch Instruction                 |
| Termination Instructions  | 4      | IndirectBr     | Indirect Branch Instruction        |
| Termination Instructions  | 5      | Invoke         | Call Instruction                   |
| Termination Instructions  | 6      | Resume         | Resume Instruction                 |
| Termination Instructions  | 7      | Unreachable    | Unreachable Instruction            |
| Termination Instructions  | 8      | CleanupRet     | Cleanup Return Instruction         |
| Termination Instructions  | 9      | CatchRet       | Catch Return Instruction           |
| Termination Instructions  | 10     | CatchSwitch    | Catch Switch Instruction           |
| Termination Instructions  | 11     | CallBr         | Call Site Termination Instruction  |
| Unary Operators           | 12     | FNeg           | Floating-point Negation            |
| Binary Operators          | 13     | Add            | Addition                           |
| Binary Operators          | 14     | FAdd           | Floating-point Addition            |
| Binary Operators          | 15     | Sub            | Subtraction                        |
| Binary Operators          | 16     | FSub           | Floating-point Subtraction         |
| Binary Operators          | 17     | Mul            | Multiplication                     |
| Binary Operators          | 18     | FMul           | Floating-point Multiplication      |
| Binary Operators          | 19     | UDiv           | Unsigned Division                  |
| Binary Operators          | 20     | SDiv           | Signed Division                    |
| Binary Operators          | 21     | FDiv           | Floating-point Division            |
| Binary Operators          | 22     | URem           | Unsigned Remainder                 |
| Binary Operators          | 23     | SRem           | Signed Remainder                   |
| Binary Operators          | 24     | FRem           | Floating-point Remainder           |
| Binary Operators          | 25     | Shl            | Left Shift (Logical)               |
| Binary Operators          | 26     | LShr           | Right Shift (Logical)              |
| Binary Operators          | 27     | AShr           | Right Shift (Arithmetic)           |
| Binary Operators          | 28     | And            | Bitwise AND                        |
| Binary Operators          | 29     | Or             | Bitwise OR                         |
| Binary Operators          | 30     | Xor            | Bitwise XOR                        |
| Memory Operations         | 31     | Alloca         | Stack Allocation                   |
| Memory Operations         | 32     | Load           | Load from Memory                   |
| Memory Operations         | 33     | Store          | Store to Memory                    |
| Memory Operations         | 34     | GetElementPtr  | Get Element Pointer                |
| Memory Operations         | 35     | Fence          | Memory Fence                       |
| Memory Operations         | 36     | AtomicCmpXchg  | Atomic Compare and Swap            |
| Memory Operations         | 37     | AtomicRMW      | Atomic Read-Modify-Write           |
| Type Conversion Operators | 38     | Trunc          | Truncate Integer                   |
| Type Conversion Operators | 39     | ZExt           | Zero Extend Integer                |
| Type Conversion Operators | 40     | SExt           | Sign Extend Integer                |
| Type Conversion Operators | 41     | FPToUI         | Floating-point to Unsigned Integer |
| Type Conversion Operators | 42     | FPToSI         | Floating-point to Signed Integer   |
| Type Conversion Operators | 43     | UIToFP         | Unsigned Integer to Floating-point |
| Type Conversion Operators | 44     | SIToFP         | Signed Integer to Floating-point   |
| Type Conversion Operators | 45     | FPTrunc        | Truncate Floating-point            |
| Type Conversion Operators | 46     | FPExt          | Extend Floating-point              |
| Type Conversion Operators | 47     | PtrToInt       | Pointer to Integer                 |
| Type Conversion Operators | 48     | IntToPtr       | Integer to Pointer                 |
| Type Conversion Operators | 49     | BitCast        | Type Cast                          |
| Type Conversion Operators | 50     | AddrSpaceCast  | Address Space Cast                 |
| Function Pad Instructions | 51     | CleanupPad     | Cleanup Pad                        |
| Function Pad Instructions | 52     | CatchPad       | Catch Pad                          |
| Other Instructions        | 53     | ICmp           | Integer Comparison                 |
| Other Instructions        | 54     | FCmp           | Floating-point Comparison          |
| Other Instructions        | 55     | PHI            | PHI Node                           |
| Other Instructions        | 56     | Call           | Call Function                      |
| Other Instructions        | 57     | Select         | Select Instruction                 |
| Other Instructions        | 58     | UserOp1        | User Operation 1 (Internal Use)    |
| Other Instructions        | 59     | UserOp2        | User Operation 2 (Internal Use)    |
| Other Instructions        | 60     | VAArg          | Variadic Argument Instruction      |
| Other Instructions        | 61     | ExtractElement | Extract Element from Vector        |
| Other Instructions        | 62     | InsertElement  | Insert Element into Vector         |
| Other Instructions        | 63     | ShuffleVector  | Shuffle Two Vectors                |
| Other Instructions        | 64     | ExtractValue   | Extract Value from Aggregate       |
| Other Instructions        | 65     | InsertValue    | Insert Value into Aggregate        |
| Other Instructions        | 66     | LandingPad     | Landing Pad Instruction            |
| Other Instructions        | 67     | Freeze         | Freeze Instruction                 |
