#include "my_printf.h"
#include <stdio.h>
#include <unistd.h>

#define BUFFER_CAPACITY 1024

static int total_characters = 0;

static void emit_character(char character) {
    write(1, &character, 1);
    total_characters++;
}

static void emit_string(const char *str) {
    if (str == NULL) {
        emit_string("(null)");
        return;
    }
    while (*str) {
        emit_character(*str++);
    }
}

static void emit_integer(int number) {
    char buffer[BUFFER_CAPACITY];
    int index = 0;
    int is_negative = 0;

    if (number == 0) {
        emit_character('0');
        return;
    }
    
    if (number < 0) {
        is_negative = 1;
        number = -number;
    }
    while (number != 0) {
        buffer[index++] = '0' + (number % 10);
        number /= 10;
    }
    if (is_negative) {
        buffer[index++] = '-';
    }
    while (index > 0) {
        emit_character(buffer[--index]);
    }
}

static void emit_octal(unsigned int number) {
    char buffer[BUFFER_CAPACITY];
    int index = 0;

    if (number == 0) {
        emit_character('0');
        return;
    }

    while (number != 0) {
        buffer[index++] = '0' + (number % 8);
        number /= 8;
    }

    while (index > 0) {
        emit_character(buffer[--index]);
    }
}

static void emit_hex_lower(uintptr_t number) {
    char buffer[BUFFER_CAPACITY];
    const char *hex_chars = "0123456789abcdef";
    int index = 0;

    if (number == 0) {
        emit_character('0');
        return;
    }

    while (number != 0) {
        buffer[index++] = hex_chars[number % 16];
        number /= 16;
    }

    while (index > 0) {
        emit_character(buffer[--index]);
    }
}

static void emit_hex_upper(uintptr_t number) {
    char buffer[BUFFER_CAPACITY];
    const char *hex_chars = "0123456789ABCDEF";
    int index = 0;

    if (number == 0) {
        emit_character('0');
        return;
    }

    while (number != 0) {
        buffer[index++] = hex_chars[number % 16];
        number /= 16;
    }

    while (index > 0) {
        emit_character(buffer[--index]);
    }
}

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    total_characters = 0; 

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd':
                    emit_integer(va_arg(args, int));
                    break;
                case 'o':
                    emit_octal(va_arg(args, unsigned int));
                    break;
                case 'u':
                    emit_integer(va_arg(args, unsigned int));
                    break;
                case 'x':
                    emit_hex_upper((uintptr_t)va_arg(args, void *));
                    break;
                case 'c':
                    emit_character((char)va_arg(args, int));
                    break;
                case 's':
                    emit_string(va_arg(args, const char *));
                    break;
                case 'p':
                    emit_string("0x");
                    emit_hex_lower((uintptr_t)va_arg(args, void *));
                    break;
                case 'P': 
                    emit_hex_upper((uintptr_t)va_arg(args, void *));
                    break;
                default:
                    emit_character('%');
                    emit_character(*format);
                    break;
            }
        } else {
            emit_character(*format);
        }
        format++;
    }

    va_end(args);
    return total_characters;
}