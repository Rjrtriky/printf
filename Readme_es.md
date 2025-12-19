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
        make clean	        Elimina los archivos objeto (.o)
        make fclean	        Elimina los archivos objeto y la biblioteca
        make re	            Recompila completamente el proyecto

## 📚 Recursos

REFERENCIAS CLASICAS:

	-Documentación de tipo de datos va-list y sus funciones asociadas(va_list, va_start, va_arg, va_end), funciones autorizadas malloc, free, write en Linux con man y en https://man7.org/linux/man-pages/man2/read.2.html
	-Ejemplos de proyectos previos de 42 relacionados con printf.
	-stdarg.h - Argumentos variables

USO DE IA:

	-Seguridad en punteros.
	-Creación de diagramas de flujo despues de la codificación.

## 🔄 Diagrama de flujo del algoritmo

```plaintext
┌─────────────────────────────┐
│        ft_printf(fmt)       │
└────────────┬────────────────┘
             │
             ▼
┌──────────────────────────────┐
│ Inicializar va_list (args)   │
└────────────┬─────────────────┘
             │
             ▼
       ┌────────────────────┐
       │ Comienzo del Bucle │<───────────────────────────────────────────────────────┐
       └─────────┬──────────┘                                                        │
                 │                                                                   │
                 ▼                                                                   │
┌──────────────────────────────────┐                                                 │
│ Recorrer cada carácter de formato│                                                 │
└───────┬───────────────┬──────────┘                                                 │
        │Literal        │'%'                                                         │
        ▼               ▼                                                            │
┌──────────────┐     ┌──────────────────────────────┐                                │
│ Imprimir con │     │ Avanzar al siguiente char    │                                │
│ ft_putchr_fd │     │ y llamar ft_type_check       │                                │
└────┬─────────┘     └────────────┬─────────────────┘                                │
     │                            │                                                  │
     ▼                            ▼                                                  │
┌──────────────────────────────┐ ┌──────────────────────────────┐                    │
│ count++                      │ │ Selección según especificador│                    │
└──────────────────────────────┘ └────┬───────────────┬─────────┘                    │
                                      │Ej: 'c','s','p'│Otros                         │
                                      ▼               ▼                              │
                          ┌────────────────────┐   ┌─────────────────────┐           │
                          │ Conversión con     │   │ Conversión numérica │           │
                          │ ft_conver_*        │   │ base 10/16          │           │
                          └─────────┬──────────┘   └─────────┬───────────┘           │
                                    │                        │                       │
                                    ▼                        ▼                       │
                          ┌────────────────────┐   ┌────────────────────┐            │
                          │ ft_puts_fd imprime │   │ ft_puts_fd imprime │            │
                          │ y libera memoria   │   │ y libera memoria   │            │
                          └─────────┬──────────┘   └─────────┬──────────┘            │
                                    │                        │                       │
                                    ▼                        ▼                       │
                          ┌────────────────────────────────────┐                     │
                          │ count += longitud texto impreso    │                     │
                          └─┬──────────────────────────────────┘                     │
                            │                                                        │
                            ▼                                                        │
┌──────────────────────────────┐                                                     │
│ ¿Fin de cadena de formato?   │                                                     │
└───────┬───────────────┬──────┘                                                     │
        │Sí             │No                                                          │
        ▼               ▼                                                            │
┌─────────────┐     ┌──────────────┐                                                 │
│ va_end(args)│     │ Seguir bucle │─────────────────────────────────────────────────┘
└────┬────────┘     └──────────────┘
     │
     ▼
┌──────────────────────────────────────────────────┐
│           return count (total chars)             │
└──────────────────────────────────────────────────┘

