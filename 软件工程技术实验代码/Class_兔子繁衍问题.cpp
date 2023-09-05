//兔子繁殖问题

#include <stdio.h>

int fib(int n) {
    if (n <= 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int months = 12;
    printf("一年后有 %d 对兔子\n", fib(months));
    return 0;
}
