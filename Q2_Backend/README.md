# Development Environment and Source Code Compilation

This repository contains a C program that calculates the Fibonacci sequence using three different methods: recursive, iterative with an array, and iterative with variables.

## Development Environment

To compile and run the source code, you need to have a C compiler installed on your system. Here are a few popular options:

- GCC (GNU Compiler Collection): Available on Linux and macOS. You can check if GCC is installed by running `gcc --version` in a terminal.
- Clang: Available on multiple platforms, including Linux, macOS, and Windows. You can check if Clang is installed by running `clang --version` in a terminal.
- MinGW-w64: Available on Windows. It provides a Windows port of the GCC compiler. You can check if MinGW-w64 is installed by running `gcc --version` in the MinGW-w64 terminal.

Choose the C compiler that suits your platform and install it if necessary.

## Source Code Compilation

To compile the source code, follow these steps:

1. Clone this repository to your local machine.
2. Open a terminal or command prompt and navigate to the project directory.
3. Run the following command to compile the source code:

`gcc main.c -o fibonacci`

Note: If you're using a different C compiler, replace `gcc` with the appropriate command (e.g., `clang`, `mingw32-gcc`).
4. If there are no errors, the compilation process will generate an executable file named `fibonacci` (or `fibonacci.exe` on Windows).

## Running the Program

To run the program, follow these steps:

1. In the same terminal or command prompt, execute the following command:

`./fibonacci`

On Windows, use `fibonacci.exe` instead.

2. The program will calculate and display the Fibonacci sequence for values ranging from 0 to 10, using the three different methods.
3. The output will show the Fibonacci numbers calculated by each method for each value of `n`.

## Example Output

Here's an example of the program's output:

13