#include "main.h"

int main(){
    std::string str;

    while (true){
        std::cout << "Введите строку: ";
        std::cin >> str;
        std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
        if(str == "exit"){
            break;
        }
    }
    return 0;
}

int simple_string_hash(std::string &str){
    int hash = 0;
    for (char ch : str) {
        hash += (int)ch;
    }
    return hash;
}