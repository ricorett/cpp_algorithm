#include "main.h"

int main(){

std::cout << "Введите фактический размер массива ";
   int actual_size;
   std::cin >> actual_size;

   std::cout << "Введите логический размер массива ";
   int logical_size;
   std::cin >> logical_size;
   if (logical_size > actual_size){
       std::cout << "Ошибка! Логический размер не может превышать фактический!" << std::endl;
       exit(0);
   }

    int *arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++){
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);
    std::cout << std::endl;
    int e = 0;
    while (true){
        std::cout << "Введите элемент для добавления в конец (Введите 0 для выхода): ";
        std::cin >> e;
        if (e == 0){
            break;
        }
        append_to_dynamic_array(arr, logical_size, actual_size, e);
        print_dynamic_array(arr, logical_size, actual_size);
    }
    std::cout << "До свидания! Окончательный массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    return 0;
}


void print_dynamic_array(int* arr, int logical_size, int actual_size){
    std::cout << "Динамический массив: ";
    for (int i = 0; i < logical_size; i++){
        std::cout << arr[i] << " ";
    }
    for (int i = logical_size; i < actual_size; i++){
        std::cout << "_ ";
    }
    std::cout << std::endl;
}

void append_to_dynamic_array(int*& arr, int &logical_size, int &actual_size, int e){
        if (logical_size >= actual_size) {
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];

        for (int i = 0; i < logical_size; ++i) {
                new_arr[i] = arr[i];
            }

            delete[] arr;
            arr = new_arr;
            actual_size = new_actual_size;
    }
    arr[logical_size] = e;
    logical_size++;
}