#include "main.h"

/* АСИМПТОТИКА РЕКУРСИВНОГО ВЫЧИСЛЕНИЯ ЧИСЕЛ ФИБОНАЧЧИ БУДЕТ РАВНА О(2^n) */


int main() {
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;
    if (num < 1) {
        std::cout << "n/a";
    } else {
        std::cout << fibonacci(num);
    }
    return 0;
}

int fibonacci(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    
    return fibonacci(num - 1) + fibonacci(num - 2);
}
