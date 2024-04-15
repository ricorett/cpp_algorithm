#include "main.h"

int main (){
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

    int *arr = new int[logical_size];

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
        arr = append_to_dynamic_array(arr, logical_size, actual_size, e);
        print_dynamic_array(arr, logical_size, actual_size);
    }
    std::cout << "До свидания! Окончательный массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    delete [] arr;
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

int* append_to_dynamic_array(int *arr, int logical_size, int actual_size, int e){
    int last = logical_size;
    int *new_arr;
    if ((last + 1) == sizeof (*arr)){
        new_arr = new int[2 * (sizeof(*arr))];
        for (int i = 0; i < logical_size; i++){
            new_arr[i] = arr[i];
        }
        new_arr[logical_size + 1] = e;
        ++last;
    } else {
        for (int i = 0; i < logical_size; i++){
            new_arr[i] = arr[i];
        }
        new_arr[last] = e;
        ++last;
    }
    delete [] new_arr;
        return new_arr;
}
//
//int append_to_dynamic_array(int* arr, int logical_size, int actual_size, int e, int last){
//    DynamicArray new_arr;
//    *arr = new_arr.append(e, last);
//    return *arr;
//}
//
//int DynamicArray::get_i(int i, int last){
//    if (i <= last){
//        return array[i];
//    } else {
//       return OUT_OF_RANGE;
//    }
//}
//
//int DynamicArray::append(int e, int last){
//    if (last + 1 == sizeof(*array)){
//        new_size = 2 * (sizeof(*array));
//    }
//    int* new_data;
//    for (int i = 0; i < new_size; i++){
//        new_data[i] = array[i];
//        ++last;
//    }
//    e = new_data[last + 1];
//    return *new_data;
//}