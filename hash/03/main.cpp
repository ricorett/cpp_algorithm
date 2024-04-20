#include "main.h"

int main(){
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::string str;
    std::string substr;
    std::cin >> str;
    while(true){
        std::cout << "Введите строку, которую нужно найти: ";
        std::cin >> substr;
        find_substring_light_rabin_karp(str, substr);
        if(substr == "exit"){
            break;
        }
    }
    return 0;
}

int find_hash(const std::string& str, int start, int end) {
    int hash = 0;
    for (int i = start; i <= end; i++) {
        hash += str[i];
    }
    return hash;
}

void find_substring_light_rabin_karp(const std::string& str, const std::string& substr) {
    int substr_hash = find_hash(substr, 0, substr.length() - 1);
    int k = substr.length();
    int pos = -1;
    for (int i = 0; i <= str.length() - k; i++) {
        int h = find_hash(str, i, i + k - 1);
        if (h == substr_hash) {
            bool match = true;
            for (int j = 0; j < k; j++) {
                if (str[i + j] != substr[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                pos = i;
                break;
            }
        }
    }
    if (pos != -1) {
        std::cout << "Подстрока " << substr << " найдена по индексу: "<< pos << std::endl;
    } else {
        std::cout << "Не удалось найти подстроку " << substr << std::endl;
    }
}

