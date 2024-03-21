#include "main.h"

int main() {
    int size = 10; // для проверки первых данных 10, для вторых 15, для третьих 18.
    int *arr = new int[size];
    int left = 0;
    int right = size - 1;
    std::cout << "Заполните массив: ";
    for (int i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    quick_sort(arr, left, right);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    delete [] arr;
    return 0;
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot_index = partition(arr, left, right);

        quick_sort(arr, left, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, right);
    }
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
