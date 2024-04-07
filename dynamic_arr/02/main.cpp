#include "main.h"
int main (){
    std::cout << "Введите фактический размер массива";
    int actual_size;
    std::cin >> actual_size;

    std::cout << "Введите логический размер массива";
    int logical_size;
    std::cin >> logical_size;

    int arr[actual_size];
    for (int i = 0; i < logical_size; i++){
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }
    print_dynamic_array(arr, logical_size, actual_size);

    int e = 0;
    while (true){
        std::cout << "Введите элемент для добавления в конец(Введите 0 для выхода): ";
        std::cin >> e;
        if (e == 0){
            break;
        }
        append_to_dynamic_array(arr, logical_size, actual_size);
        print_dynamic_array(arr, logical_size, actual_size);
    }
    std::cout << "До свидания! Окончательный массив: ";
    for (int i = 0; i < actual_size; ++i){
        std::cout << arr[i] << " " << std::endl;
    }
    return 0;
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

int append_to_dynamic_array(int* arr, int logical_size, int actual_size);

int DynamicArray::get_i(int i){
    if (i <= last){
        return data[i];
    } else {
        throw lenght_error; //выставить стандартный эксепшн по выходы за границы
    }
}

int DynamicArray::append(int e){
    if (last + 1 == sizeof(*data)){
        int new_size = 2 * (sizeof(*data));
    }
    for (int i = 0; i < sizeof(*data); i++){
        new_data[i] = data[i];
        e = new_data[last + 1];
        ++last;
    }
}