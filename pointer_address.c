#include <stdio.h>

int pointer() {
    int value = 42;
    int* ptr = &value;

    printf("Pointer address: %p\n", (void*)ptr);

    return 0;
}
