*This project has been created as part of the 42 curriculum by rjuarez-*
# printf

## 📖 Description

DEFINITION:
This is a custom implementation of the standard printf() function from the C library. This project is part of the 42 curriculum and its main objectives are learning how to handle variable arguments (va_list) and advanced format string management, as well as reinforcing concepts of dynamic memory management and modular programming in C.

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
        make clean	    Removes object files (.o)
        make fclean	    Removes object files and the library
        make re	            Recompiles the entire project

## 📚 Resources

CLASSIC REFERENCES:

        -Documentation on va_list data type and its associated functions (va_list, va_start, va_arg, va_end), authorized functions malloc, free, write in Linux using man or at https://man7.org/linux/man-pages/man2/read.2.html
        -Examples of previous 42 projects related to printf
        -stdarg.h - Variable arguments

AI USAGE:

        -Pointer safety
        -Creating flowcharts after coding
        -Translation to English

## 🔄 Project Implementation

**Flowchart of the Algorithm**
        ┌─────────────────────────────────────────────┐
│           START ft_printf()                 │
└───────────────────┬─────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────────┐
│  Initialize:                                │
│  • va_start(list_arg, format)               │
│  • i = -1, count = 0                        │
└───────────────────┬─────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────────┐
│    Is format[i] != '\0'?                    │
│          │                                  │
│      ├── YES ───────────────────────────────┤
│      │                                      │
│      ▼                                      │
│ ┌─────────────┐                             │
│ │ Is format[i]│                             │
│ │   != '%'?   │                             │
│ └─────┬───────┘                             │
│       │                                     │
│   ├── YES ──► Print character:              │
│   │         ft_putchr_fd(format[i], 1)      │
│   │         count++                         │
│   │         i++                             │
│   │         └──► CONTINUE LOOP              │
│   │                                         │
│   └── NO ──►                                │
│         │                                   │
│         ▼                                   │
│   ┌─────────────┐                           │
│   │ i++         │                           │
│   │ Is format[i]│                           │
│   │ != '\0'?    │                           │
│   └─────┬───────┘                           │
│         │                                   │
│     ├── YES ──►                             │
│     │         ▼                             │
│     │ ┌────────────────────────────────┐    │
│     │ │ ft_type_check():               │    │
│     │ │                                │    │
│     │ │ Is chr 'c' or '%'?             │    │
│     │ │    ├── YES ──► ft_conver_c()   │    │
│     │ │    │                           │    │
│     │ │    └── NO ──►                  │    │
│     │ │                                │    │
│     │ │ Is chr 's'?                    │    │
│     │ │    └──► ft_conver_s()          │    │
│     │ │                                │    │
│     │ │ Is chr 'p'?                    │    │
│     │ │    └──► ft_conver_p()          │    │
│     │ │                                │    │
│     │ │ Is chr 'i'/'d'/'u'?            │    │
│     │ │    └──► ft_conver_nbr_base()   │    │
│     │ │                                │    │
│     │ │ Is chr 'x'/'X'?                │    │
│     │ │    ├──► ft_conver_nbr_base()   │    │
│     │ │    ├── If 'X' ──► ft_strtoup() │    │
│     │ │    └──► ft_puts_fd()           │    │
│     │ └─────────┬──────────────────────┘    │
│     │           │                           │
│     │           ▼                           │
│     │ ┌─────────────────────────┐           │
│     │ │ count += result         │           │
│     │ └─────────┬───────────────┘           │
│     │           │                           │
│     │           └──► i++                    │
│     │               └──► CONTINUE LOOP      │
│     │                                       │
│     └── NO ──►                              │
│           │                                 │
│           ▼                                 │
│     ┌─────────────┐                         │
│     │   BREAK     │                         │
│     └─────────────┘                         │
│                                             │
└─────────────────────────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────────┐
│   va_end(list_arg)                          │
│   return count                              │
└─────────────────────────────────────────────┘

**Components**

        MODULE 1: AUXILIARY FUNCTIONS (ft_auxiliars_libft.c)
        ├── ft_strlen()
        │   └──► Calculates string length for buffers
        ├── ft_bzero()
        │   └──► Initializes memory to zero for calloc
        ├── ft_calloc()
        │   └──► ft_bzero() → Allocates and initializes memory
        ├── ft_recalloc()
        │   ├──► ft_calloc() → New memory
        │   ├──► ft_strlen() → Old size
        │   └──► Copies data and frees old
        └── ft_strdup()
        ├──► ft_strlen() → Required size
        └──► malloc() + character copy

        MODULE 2: DATA OUTPUT (ft_puts.c)
        ├── ft_putchr_fd()
        │   └──► write() → Single character
        ├── ft_putstr_fd()
        │   ├──► ft_strlen() → Length to write
        │   └──► write() → Complete string
        └── ft_puts_fd()
        ├──► ft_strlen() → Length for return
        ├──► ft_putstr_fd() → Print string
        └──► free() → Free dynamic memory

        MODULE 3: BASIC CONVERSION (ft_conver.c)
        ├── ft_conver_null()
        │   └──► ft_strdup() → "(null)" or "(nil)"
        ├── ft_conver_c()
        │   └──► ft_putchr_fd() → Print character
        ├── ft_conver_s()
        │   ├──► ft_conver_null() → If str is NULL
        │   ├──► ft_strlen() → Size
        │   └──► ft_calloc() + copy
        └── ft_conver_p()
        ├──► ft_conver_null() → If ptr is NULL
        ├──► ft_conver_nbr_base() → Hexadecimal without "0x"
        ├──► ft_strdup() → "0x"
        ├──► ft_recalloc() → Expand to add "0x"
        └──► Manual concatenation

        MODULE 4: NUMERIC CONVERSION (ft_conver_numbers.c)
        ├── ft_conver_digital()
        │   └──► Digit → hexadecimal character conversion
        ├── ft_intlen_base()
        │   ├──► ft_abs() → Absolute value
        │   └──► Successive division to count digits
        ├── ft_abs()
        │   └──► Simple absolute value
        └── ft_conver_nbr_base()
        ├──► ft_intlen_base() → Required size
        ├──► ft_calloc() → Reserve memory
        ├──► ft_abs() → Absolute value
        └──► ft_conver_digital() → Each digit

        MODULE 5: MAIN CORE (ft_printf.c)
        ├── ft_strtoup()
        │   └──► In-place uppercase conversion
        ├── ft_type_check()
        │   ├── For 'c'/'%': ft_conver_c() → direct write
        │   ├── For 's': ft_conver_s() → string
        │   ├── For 'p': ft_conver_p() → pointer
        │   ├── For 'i'/'d'/'u': ft_conver_nbr_base(base=10)
        │   ├── For 'x'/'X':
        │   │   ├──► ft_conver_nbr_base(base=16)
        │   │   └── If 'X': ft_strtoup()
        │   └──► ft_puts_fd() → Print and free
        └── ft_printf()
        ├── va_start() → Initialize arguments
        ├── Loop through format string:
        │   ├── Normal character: ft_putchr_fd()
        │   └── Format specifier '%': ft_type_check()
        ├── va_end() → Clean up arguments
        └── return count → Total characters

**Execution Flow**
        User calls ft_printf("Hello %s, number: %d", "World", 42)
        │
        ├──► ft_printf() starts
        │     ├──► Prints "Hello " → ft_putchr_fd() x5
        │     │
        │     ├──► Finds '%' → ft_type_check('s')
        │     │     ├──► ft_conver_s("World")
        │     │     │     ├──► ft_strlen("World") = 5
        │     │     │     ├──► ft_calloc(6)
        │     │     │     └──► Copies "World"
        │     │     └──► ft_puts_fd()
        │     │           ├──► ft_strlen() = 5
        │     │           ├──► ft_putstr_fd() → write "World"
        │     │           └──► free() memory
        │     │
        │     ├──► Prints ", number: " → ft_putchr_fd() x10
        │     │
        │     ├──► Finds '%' → ft_type_check('d')
        │     │     ├──► ft_conver_nbr_base(42, 10)
        │     │     │     ├──► ft_intlen_base(42, 10) = 2
        │     │     │     ├──► ft_calloc(3)
        │     │     │     ├──► ft_abs(42) = 42
        │     │     │     ├──► 42/10=4, remainder=2 → '2'
        │     │     │     ├──► 4/10=0, remainder=4 → '4'
        │     │     │     └──► String: "42"
        │     │     └──► ft_puts_fd()
        │     │           ├──► ft_strlen() = 2
        │     │           ├──► ft_putstr_fd() → write "42"
        │     │           └──► free() memory
        │     │
        │     └──► Total sum: 5 + 5 + 10 + 2 = 22 characters
        │
        └──► return 22