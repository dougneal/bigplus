# BigPlus

BigPlus is a modern calculator tool for professionals.

## Features

- Stack-based (RPN-like)
- Keyboard entry
- Free of skeuomorphic baggage; doesn't pretend to be an old handheld calculator

## Planned features

- Qt UI
- Configurable output format
- Unit-awareness
- Preview/staging of operations
- Undo function
- Whatever else I find useful!

## Usage

- Enter numbers to push them on to the stack
- Enter the symbol or the name of an operator to run said operator
- Two operands will be popped from the stack (most operators take two operands)
- The result will be pushed back on the stack
- Some operators pop 1 or 3 operands

```
$ build/standalone/BigPlus
bigplus> 7.2
7.2 [float]
bigplus> 9.9
7.2 [float]
9.9 [float]
bigplus> 3.24
7.2 [float]
9.9 [float]
3.24 [float]
bigplus> 2
7.2 [float]
9.9 [float]
3.24 [float]
2 [int]
bigplus> *
7.2 [float]
9.9 [float]
6.48 [float]
bigplus> +
7.2 [float]
16.380000000000003 [float]
bigplus> 2.0 
7.2 [float]
16.380000000000003 [float]
2 [float]
bigplus> -
7.2 [float]
14.380000000000003 [float]
bigplus> +
21.580000000000002 [float]
bigplus> 
```

## Build

Use the following command to build and run the executable target.

```bash
cmake -S standalone -B build/standalone
cmake --build build/standalone
./build/standalone/Bigplus
```

