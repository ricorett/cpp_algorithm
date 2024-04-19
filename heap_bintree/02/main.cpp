#include "main.h"

int main()
    std::cout << "Исходный массив: 1 3 6 5 9 8\n";
    int arr[6] = {1,3,6,5,9,8};
    int parent_index = 0;
    int child_index_left = 0, child_index_right = 0;
    int level = 0;
    Heap h;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
    h.data[i] = arr[i];
    }

    return 0;
}
