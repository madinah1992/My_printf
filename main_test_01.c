#include "my_printf.h"
#include <stdio.h>

int main() {
    my_printf("Printing integers: %d, %d\n", 123, -456);
    my_printf("Printing octal: %o\n", 345);
    my_printf("Printing unsigned integer: %u\n", 789);
    my_printf("Printing hexadecimal (lowercase): %x\n", (uintptr_t)1234);
    my_printf("Printing characters: %c, %c\n", 'A', 'B');
    my_printf("Printing strings: %s, %s\n", "Hello", "World");
    my_printf("Printing pointer: %p\n", (void *)0x12345678);
    my_printf("Printing uppercase hexadecimal: %P\n", (uintptr_t)5678);

    return 0;
}