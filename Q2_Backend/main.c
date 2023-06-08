#include <stdio.h>

int func1(int n) {
    if (n <= 2)
        return n;
    
    return func1(n - 3) + func1(n - 2);
}

int func2(int n) {
    if (n <= 2)
        return n;

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;

    for (int i = 3; i <= n; i++)
        fib[i] = fib[i - 3] + fib[i - 2];

    return fib[n];
}

int func3(int n) {
    if (n <= 2)
        return n;

    int a = 0, b = 1, c = 2;
    int result;

    for (int i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = c;
        c = result;
    }

    return result;
}

int main() {
    int n = 10;
    printf("F_1(%d) = %d\nF_2(%d) = %d\nF_3(%d) = %d\n", n, func1(n), n, func2(n), n, func3(n));

    return 0;
}