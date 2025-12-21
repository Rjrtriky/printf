*Este proyecto ha sido creado como parte del currículo de 42 por rjuarez-*

# printf

## 📖 Descripción

DEFINICION:
Es una implementación personalizada de la función estándar printf() de la biblioteca C. Este proyecto forma parte del currículo de 42 y tiene como objetivo principal el aprendizaje del manejo de argumentos variables (va_list) y la gestión avanzada de cadenas de formato, además de reforzar conceptos de gestión de memoria dinámica y programación modular en C.

PROTOTIPO:

int ft_printf(const char *format, ...);

PARAMETROS:

    -format - Cadena de caracteres que contiene el texto a escribir, con especificadores de formato opcionales.
    -... - Argumentos variables correspondientes a los especificadores de formato.

RETORNO:
    -Número total de caracteres escritos (excluyendo el byte nulo terminador).
    -En caso de error, el comportamiento depende del sistema, pero generalmente devuelve un número negativo.
    La función implementa los siguientes especificadores de formato:
        %c - Imprime un solo carácter
        %s - Imprime una cadena de caracteres
        %p - Imprime un puntero en formato hexadecimal con prefijo "0x"
        %d / %i - Imprime un entero decimal con signo
        %u - Imprime un entero decimal sin signo
        %x - Imprime un número hexadecimal en minúsculas
        %X - Imprime un número hexadecimal en mayúsculas
        %% - Imprime el símbolo de porcentaje literal

## ⚙️ Instrucciones

COMPILACION
El proyecto debe compilarse con las banderas estándar de 42:
        make

Esto generará la biblioteca estática libftprintf.a.
Para compilar un programa que utilice ft_printf:
        cc -Wall -Wextra -Werror tu_programa.c libftprintf.a -o tu_programa

MAKEFILE
El Makefile incluye las siguientes reglas:
        Regla	            Descripción
        make o make all     Compila la biblioteca estática libftprintf.a
        make clean	    Elimina los archivos objeto (.o)
        make fclean	    Elimina los archivos objeto y la biblioteca
        make re	            Recompila completamente el proyecto

## 📚 Recursos

REFERENCIAS CLASICAS:

	-Documentación de tipo de datos va-list y sus funciones asociadas(va_list, va_start, va_arg, va_end), funciones autorizadas malloc, free, write en Linux con man y en https://man7.org/linux/man-pages/man2/read.2.html
	-Ejemplos de proyectos previos de 42 relacionados con printf.
	-stdarg.h - Argumentos variables

USO DE IA:

	-Seguridad en punteros.
	-Creación de diagramas de flujo despues de la codificación.

## 🔄 Planificacion del proyecto

**Implementación del proyecto**

        MÓDULO 1: FUNCIONES AUXILIARES (ft_auxiliars_libft.c)
        ├── ft_strlen()
        │   └──► Calcula longitud de strings para buffers
        ├── ft_bzero()
        │   └──► Inicializa memoria a cero para calloc
        ├── ft_calloc()
        │   └──► ft_bzero() → Asigna e inicializa memoria
        ├── ft_recalloc()
        │   ├──► ft_calloc() → Nueva memoria
        │   ├──► ft_strlen() → Tamaño antiguo
        │   └──► Copia datos y libera antiguo
        └── ft_strdup()
            ├──► ft_strlen() → Tamaño necesario
            └──► malloc() + copia caracteres

        MÓDULO 2: SALIDA DE DATOS (ft_puts.c)
        ├── ft_putchr_fd()
        │   └──► write() → Un solo carácter
        ├── ft_putstr_fd()
        │   ├──► ft_strlen() → Longitud a escribir
        │   └──► write() → String completo
        └── ft_puts_fd()
            ├──► ft_strlen() → Longitud para return
            ├──► ft_putstr_fd() → Imprimir string
            └──► free() → Liberar memoria dinámica

        MÓDULO 3: CONVERSIÓN BÁSICA (ft_conver.c)
        ├── ft_conver_null()
        │   └──► ft_strdup() → "(null)" o "(nil)"
        ├── ft_conver_c()
        │   └──► ft_putchr_fd() → Imprimir carácter
        ├── ft_conver_s()
        │   ├──► ft_conver_null() → Si str es NULL
        │   ├──► ft_strlen() → Tamaño
        │   └──► ft_calloc() + copia
        └── ft_conver_p()
            ├──► ft_conver_null() → Si ptr es NULL
            ├──► ft_conver_nbr_base() → Hexadecimal sin "0x"
            ├──► ft_strdup() → "0x"
            ├──► ft_recalloc() → Ampliar para añadir "0x"
            └──► Concatenación manual

        MÓDULO 4: CONVERSIÓN NUMÉRICA (ft_conver_numbers.c)
        ├── ft_conver_digital()
        │   └──► Conversión dígito → carácter hexadecimal
        ├── ft_intlen_base()
        │   ├──► ft_abs() → Valor absoluto
        │   └──► División sucesiva para contar dígitos
        ├── ft_abs()
        │   └──► Valor absoluto simple
        └── ft_conver_nbr_base()
            ├──► ft_intlen_base() → Tamaño necesario
            ├──► ft_calloc() → Reservar memoria
            ├──► ft_abs() → Valor absoluto
            └──► ft_conver_digital() → Cada dígito

        MÓDULO 5: NÚCLEO PRINCIPAL (ft_printf.c)
        ├── ft_strtoup()
        │   └──► Conversión a mayúsculas in-place
        ├── ft_type_check()
        │   ├── Para 'c'/'%': ft_conver_c() → write directo
        │   ├── Para 's': ft_conver_s() → string
        │   ├── Para 'p': ft_conver_p() → puntero
        │   ├── Para 'i'/'d'/'u': ft_conver_nbr_base(base=10)
        │   ├── Para 'x'/'X': 
        │   │   ├──► ft_conver_nbr_base(base=16)
        │   │   └── Si 'X': ft_strtoup()
        │   └──► ft_puts_fd() → Imprimir y liberar
        └── ft_printf()
            ├── va_start() → Inicializar argumentos
            ├── Bucle por format string:
            │   ├── Carácter normal: ft_putchr_fd()
            │   └── Especificador '%': ft_type_check()
            ├── va_end() → Limpiar argumentos
            └── return count → Total caracteres


**Flujo de ejecucion**

        Usuario llama ft_printf("Hola %s, número: %d", "Mundo", 42)
        │
        ├──► ft_printf() inicia
        │     ├──► Imprime "Hola " → ft_putchr_fd() x5
        │     │
        │     ├──► Encuentra '%' → ft_type_check('s')
        │     │     ├──► ft_conver_s("Mundo")
        │     │     │     ├──► ft_strlen("Mundo") = 5
        │     │     │     ├──► ft_calloc(6)
        │     │     │     └──► Copia "Mundo"
        │     │     └──► ft_puts_fd()
        │     │           ├──► ft_strlen() = 5
        │     │           ├──► ft_putstr_fd() → write "Mundo"
        │     │           └──► free() memoria
        │     │
        │     ├──► Imprime ", número: " → ft_putchr_fd() x10
        │     │
        │     ├──► Encuentra '%' → ft_type_check('d')
        │     │     ├──► ft_conver_nbr_base(42, 10)
        │     │     │     ├──► ft_intlen_base(42, 10) = 2
        │     │     │     ├──► ft_calloc(3)
        │     │     │     ├──► ft_abs(42) = 42
        │     │     │     ├──► 42/10=4, resto=2 → '2'
        │     │     │     ├──► 4/10=0, resto=4 → '4'
        │     │     │     └──► String: "42"
        │     │     └──► ft_puts_fd()
        │     │           ├──► ft_strlen() = 2
        │     │           ├──► ft_putstr_fd() → write "42"
        │     │           └──► free() memoria
        │     │
        │     └──► Suma total: 5 + 5 + 10 + 2 = 22 caracteres
        │
        └──► return 22


**Diagrama de flujo del algoritmo**


        ┌─────────────────────────────────────────────┐
        │           INICIO ft_printf()                │
        └───────────────────┬─────────────────────────┘
                            │
                            ▼
        ┌─────────────────────────────────────────────┐
        │  Inicializar:                               │
        │  • va_start(list_arg, format)               │
        │  • i = -1, count = 0                        │
        └───────────────────┬─────────────────────────┘
                            │
                            ▼
        ┌─────────────────────────────────────────────┐
        │    ¿format[i] != '\0'?                      │
        │          │                                  │
        │      ├── SI ────────────────────────────────┤
        │      │                                      │
        │      ▼                                      │
        │ ┌─────────────┐                             │
        │ │ ¿format[i]  │                             │
        │ │   != '%'?   │                             │
        │ └─────┬───────┘                             │
        │       │                                     │
        │   ├── SI ──► Imprimir caracter:             │
        │   │         ft_putchr_fd(format[i], 1)      │
        │   │         count++                         │
        │   │         i++                             │
        │   │         └──► CONTINUAR BUCLE            │
        │   │                                         │
        │   └── NO ──►                                │
        │         │                                   │
        │         ▼                                   │
        │   ┌─────────────┐                           │
        │   │ i++         │                           │
        │   │ ¿format[i]  │                           │
        │   │ != '\0'?    │                           │
        │   └─────┬───────┘                           │
        │         │                                   │
        │     ├── SI ──►                              │
        │     │         ▼                             │
        │     │ ┌────────────────────────────────┐    │
        │     │ │ ft_type_check():               │    │
        │     │ │                                │    │
        │     │ │ ¿chr es 'c' o '%'?             │    │
        │     │ │    ├── SI ──► ft_conver_c()    │    │
        │     │ │    │                           │    │
        │     │ │    └── NO ──►                  │    │
        │     │ │                                │    │
        │     │ │ ¿chr es 's'?                   │    │
        │     │ │    └──► ft_conver_s()          │    │
        │     │ │                                │    │
        │     │ │ ¿chr es 'p'?                   │    │
        │     │ │    └──► ft_conver_p()          │    │
        │     │ │                                │    │
        │     │ │ ¿chr es 'i'/'d'/'u'?           │    │
        │     │ │    └──► ft_conver_nbr_base()   │    │
        │     │ │                                │    │
        │     │ │ ¿chr es 'x'/'X'?               │    │
        │     │ │    ├──► ft_conver_nbr_base()   │    │
        │     │ │    ├── Si 'X' ──► ft_strtoup() │    │
        │     │ │    └──► ft_puts_fd()           │    │
        │     │ └─────────┬──────────────────────┘    │
        │     │           │                           │
        │     │           ▼                           │
        │     │ ┌─────────────────────────┐           │
        │     │ │ count += resultado      │           │
        │     │ └─────────┬───────────────┘           │
        │     │           │                           │
        │     │           └──► i++                    │
        │     │               └──► CONTINUAR BUCLE    │
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

