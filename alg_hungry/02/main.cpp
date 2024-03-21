#include "main.h"

/* АСИМПТОТИКА ИТЕРАТИВНОГО ПОДХОДА В ВЫЧИСЛЕНИИ ФИБОНАЧИ БУДЕТ РАВНА О(n) */

int main() {
    int n;
    std::cout << "Calculate Fibonacci for: ";
    std::cin >> n;
    std::cout << "Fibonacci of " << n << " is: " << fibonacci(n) << std::endl;
    return 0;
}

long long fibonacci(int n) {
    if (n <= 1)
        return n;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}