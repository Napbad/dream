# This file will be useful for your reading

## some abbreviations

| Abbreviation | Meaning                            | Example    |
|--------------|------------------------------------|------------|
| cnt          | count                              | objCnt     |
| fun / func   | function                           | funGen_sys |
| gen          | generate                           | codegen    |
| inter        | internal / internal representation | inter_gen  |

## some references:

| Type                      | Number | Instruction    | Description                        |
|---------------------------|--------|----------------|------------------------------------|
| Terminator Instructions   | 1      | Ret            | Return instruction                 |
| Terminator Instructions   | 2      | Br             | Branch instruction                 |
| Terminator Instructions   | 3      | Switch         | Switch instruction                 |
| Terminator Instructions   | 4      | IndirectBr     | Indirect branch instruction        |
| Terminator Instructions   | 5      | Invoke         | Invoke instruction                 |
| Terminator Instructions   | 6      | Resume         | Resume instruction                 |
| Terminator Instructions   | 7      | Unreachable    | Unreachable instruction            |
| Terminator Instructions   | 8      | CleanupRet     | Cleanup return instruction         |
| Terminator Instructions   | 9      | CatchRet       | Catch return instruction           |
| Terminator Instructions   | 10     | CatchSwitch    | Catch switch instruction           |
| Terminator Instructions   | 11     | CallBr         | Call site terminator instruction   |
| Unary Operators           | 12     | FNeg           | Floating-point negation            |
| Binary Operators          | 13     | Add            | Addition                           |
| Binary Operators          | 14     | FAdd           | Floating-point addition            |
| Binary Operators          | 15     | Sub            | Subtraction                        |
| Binary Operators          | 16     | FSub           | Floating-point subtraction         |
| Binary Operators          | 17     | Mul            | Multiplication                     |
| Binary Operators          | 18     | FMul           | Floating-point multiplication      |
| Binary Operators          | 19     | UDiv           | Unsigned division                  |
| Binary Operators          | 20     | SDiv           | Signed division                    |
| Binary Operators          | 21     | FDiv           | Floating-point division            |
| Binary Operators          | 22     | URem           | Unsigned remainder                 |
| Binary Operators          | 23     | SRem           | Signed remainder                   |
| Binary Operators          | 24     | FRem           | Floating-point remainder           |
| Binary Operators          | 25     | Shl            | Left shift (logical)               |
| Binary Operators          | 26     | LShr           | Right shift (logical)              |
| Binary Operators          | 27     | AShr           | Right shift (arithmetic)           |
| Binary Operators          | 28     | And            | Bitwise AND                        |
| Binary Operators          | 29     | Or             | Bitwise OR                         |
| Binary Operators          | 30     | Xor            | Bitwise XOR                        |
| Memory Operations         | 31     | Alloca         | Stack allocation                   |
| Memory Operations         | 32     | Load           | Load from memory                   |
| Memory Operations         | 33     | Store          | Store to memory                    |
| Memory Operations         | 34     | GetElementPtr  | Get element pointer                |
| Memory Operations         | 35     | Fence          | Memory fence                       |
| Memory Operations         | 36     | AtomicCmpXchg  | Atomic compare and exchange        |
| Memory Operations         | 37     | AtomicRMW      | Atomic read-modify-write           |
| Cast Operators            | 38     | Trunc          | Truncate integers                  |
| Cast Operators            | 39     | ZExt           | Zero extend integers               |
| Cast Operators            | 40     | SExt           | Sign extend integers               |
| Cast Operators            | 41     | FPToUI         | Floating-point to unsigned integer |
| Cast Operators            | 42     | FPToSI         | Floating-point to signed integer   |
| Cast Operators            | 43     | UIToFP         | Unsigned integer to floating-point |
| Cast Operators            | 44     | SIToFP         | Signed integer to floating-point   |
| Cast Operators            | 45     | FPTrunc        | Truncate floating-point            |
| Cast Operators            | 46     | FPExt          | Extend floating-point              |
| Cast Operators            | 47     | PtrToInt       | Pointer to integer                 |
| Cast Operators            | 48     | IntToPtr       | Integer to pointer                 |
| Cast Operators            | 49     | BitCast        | Type cast                          |
| Cast Operators            | 50     | AddrSpaceCast  | Address space cast                 |
| Function Pad Instructions | 51     | CleanupPad     | Cleanup pad                        |
| Function Pad Instructions | 52     | CatchPad       | Catch pad                          |
| Other Instructions        | 53     | ICmp           | Integer comparison                 |
| Other Instructions        | 54     | FCmp           | Floating-point comparison          |
| Other Instructions        | 55     | PHI            | PHI node                           |
| Other Instructions        | 56     | Call           | Call a function                    |
| Other Instructions        | 57     | Select         | Select instruction                 |
| Other Instructions        | 58     | UserOp1        | User operation 1 (internal use)    |
| Other Instructions        | 59     | UserOp2        | User operation 2 (internal use)    |
| Other Instructions        | 60     | VAArg          | Variable argument instruction      |
| Other Instructions        | 61     | ExtractElement | Extract element from vector        |
| Other Instructions        | 62     | InsertElement  | Insert element into vector         |
| Other Instructions        | 63     | ShuffleVector  | Shuffle two vectors                |
| Other Instructions        | 64     | ExtractValue   | Extract value from aggregate       |
| Other Instructions        | 65     | InsertValue    | Insert value into aggregate        |
| Other Instructions        | 66     | LandingPad     | Landing pad instruction            |
| Other Instructions        | 67     | Freeze         | Freeze instruction                 |
