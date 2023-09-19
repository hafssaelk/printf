#include <stdio.h>

int main() {
    int number = 42;
    float floatNumber = 3.14159;
    int octalValue = 075;
    int hexValue = 0xABCD;


    printf("Number with + flag: %+d\n", number); 
    printf("Number with space flag: % d\n", number); 
    printf("Octal with # flag: %#o\n", octalValue); 
    printf("Hexadecimal with # flag: %#X\n", hexValue); 

    // # flag for floating-point numbers
    printf("Float with # flag: %#f\n", floatNumber); 

    return 0;
}
