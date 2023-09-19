#include <stdio.h>

int main() {
    int value = 42;
    int* ptr = &value;

    printf("Pointer address: %p\n", (void*)ptr);

    return 0;
}
