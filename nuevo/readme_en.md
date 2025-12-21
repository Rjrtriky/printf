*This project has been created as part of the 42 curriculum by rjuarez-*
# printf

## 📖 Description

DEFINITION:
It is a custom implementation of the standard printf() function from the C library. This project is part of the 42 curriculum and primarily aims to learn the handling of variable arguments (va_list) and advanced format string management, while also reinforcing concepts of dynamic memory management and modular programming in C.

PROTOTYPE:

int ft_printf(const char *format, ...);

PARAMETERS:

    -format - Character string containing the text to write, with optional format specifiers.
    -... - Variable arguments corresponding to the format specifiers.

RETURN:
    -Total number of characters written (excluding the null terminator byte).
    -In case of error, the behavior depends on the system, but generally returns a negative number.
    The function implements the following format specifiers:
        %c - Prints a single character
        %s - Prints a character string
        %p - Prints a pointer in hexadecimal format with "0x" prefix
        %d / %i - Prints a signed decimal integer
        %u - Prints an unsigned decimal integer
        %x - Prints a hexadecimal number in lowercase
        %X - Prints a hexadecimal number in uppercase
        %% - Prints the literal percentage symbol

## ⚙️ Instructions

COMPILATION
The project should be compiled with the standard 42 flags:
        make

This will generate the static library libftprintf.a.
To compile a program that uses ft_printf:
        cc -Wall -Wextra -Werror your_program.c libftprintf.a -o your_program

MAKEFILE
The Makefile includes the following rules:
        Rule	            Description
        make or make all    Compiles the static library libftprintf.a
        make clean	        Removes object files (.o)
        make fclean	        Removes object files and the library
        make re	            Recompiles the entire project

## 📚 Resources

CLASSIC REFERENCES:

	-Documentation for va-list data type and its associated functions (va_list, va_start, va_arg, va_end), authorized functions malloc, free, write in Linux with man and at https://man7.org/linux/man-pages/man2/read.2.html
	-Examples of previous 42 projects related to printf.
	-stdarg.h - Variable arguments

AI USAGE:

	-Pointer safety.
	-Creation of flowcharts after coding.

## 🔄 Algorithm Flow Diagram

```plaintext
┌─────────────────────────────┐
│        ft_printf(fmt)       │
└────────────┬────────────────┘
             │
             ▼
┌──────────────────────────────┐
│ Initialize va_list (args)    │
└────────────┬─────────────────┘
             │
             ▼
       ┌────────────────────┐
       │ Start Loop         │<───────────────────────────────────────────────────────┐
       └─────────┬──────────┘                                                        │
                 │                                                                   │
                 ▼                                                                   │
┌──────────────────────────────────┐                                                 │
│ Iterate each format character   │                                                 │
└───────┬───────────────┬──────────┘                                                 │
        │Literal        │'%'                                                         │
        ▼               ▼                                                            │
┌──────────────┐     ┌──────────────────────────────┐                                │
│ Print with   │     │ Move to next character       │                                │
│ ft_putchr_fd │     │ and call ft_type_check       │                                │
└────┬─────────┘     └────────────┬─────────────────┘                                │
     │                            │                                                  │
     ▼                            ▼                                                  │
┌──────────────────────────────┐ ┌──────────────────────────────┐                    │
│ count++                      │ │ Selection by specifier       │                    │
└──────────────────────────────┘ └────┬───────────────┬─────────┘                    │
                                      │E.g.: 'c','s','p'│Others                      │
                                      ▼               ▼                              │
                          ┌────────────────────┐   ┌─────────────────────┐           │
                          │ Conversion with    │   │ Numeric conversion  │           │
                          │ ft_conver_*        │   │ base 10/16          │           │
                          └─────────┬──────────┘   └─────────┬───────────┘           │
                                    │                        │                       │
                                    ▼                        ▼                       │
                          ┌────────────────────┐   ┌────────────────────┐            │
                          │ ft_puts_fd prints │   │ ft_puts_fd prints  │            │
                          │ and frees memory  │   │ and frees memory   │            │
                          └─────────┬──────────┘   └─────────┬──────────┘            │
                                    │                        │                       │
                                    ▼                        ▼                       │
                          ┌────────────────────────────────────┐                     │
                          │ count += printed text length       │                     │
                          └────────────────────────────────────┘                     │
             │                                                                       │
             ▼                                                                       │
┌──────────────────────────────┐                                                     │
│ End of format string?        │                                                     │
└───────┬───────────────┬──────┘                                                     │
        │Yes            │No                                                          │
        ▼               ▼                                                            │
┌─────────────┐     ┌──────────────┐                                                 │
│ va_end(args)│     │ Continue loop│─────────────────────────────────────────────────┘
└────┬────────┘     └──────────────┘
     │
     ▼
┌──────────────────────────────────────────────────┐
│           return count (total chars)             │
└──────────────────────────────────────────────────┘
