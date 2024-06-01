#include "header.h"

int main(){
    std::ifstream inputFile;
    inputFile.open("input.txt");

    if (!inputFile) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return 1;
    }
    inputFile.close();
    return 0;
}