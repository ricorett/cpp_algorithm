#include "main.h"

int main(){
    std::cout << "Введите фактический размер массива: ";
    int actual_size = 0;
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    int logical_size = 0;
    std::cin >> logical_size;

    if (logical_size > actual_size){
        std::cout << "Ошибка! Логический размер не может превышать фактический!";
    } else {
        int arr[actual_size];
        for(int i = 0; i < logical_size; i ++){
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> arr[i];
        }
        print_dynamic_array(arr, logical_size, actual_size);
    }
}

void print_dynamic_array(int* arr, int logical_size, int actual_size){
    if (logical_size == actual_size){
        std::cout << "Динамический массив: ";
        for (int i = 0; i < actual_size; i++){
            std::cout << arr[i] << " ";
        }
    } else {
        int arr_print[actual_size];
        for (int i = 0; i < logical_size; i++) {
            arr_print[i] = arr[i];
            std::cout << arr_print[i] << " ";
        }
        for (int i = logical_size; i < actual_size; i++) {
            std::cout << "_ ";
        }
    }
}