#include "main.h"

int main() {
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;
    if (num < 1) {
        std::cout << "n/a";
    } else {
        std::cout << fub(num);
    }
    return 0;
}

int fub(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    
    return fub(num - 1) + fub(num - 2);
}
