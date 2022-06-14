#include <stdio.h>

int main()
{
    u_int64_t i = (0xDEADBEEF & 0xFF00) >> 8;

    printf("%llX", i);

    return 0;
}