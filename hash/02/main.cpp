#include "main.h"

int main(){
    std::string str;
    int p = 0, n = 0;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    while (true){
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Реальный хэш строки " << str << " = " << real_string_hash(str, p, n) << std::endl;
        if(str == "exit"){
            break;
        }
    }
    return 0;
}

int real_string_hash(std::string &str, int p, int n){
    long long hash = 0;
    for (int i = 0; i < str.length(); i++) {
        hash += (pow(p, i)) * ((int)str[i]);
    }
    return hash % n;
}