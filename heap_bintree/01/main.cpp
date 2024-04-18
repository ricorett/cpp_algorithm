#include "main.h"

int main(){
    std::cout << "Исходный массив: 1 3 6 5 9 8\n";
    int arr[6] = {1,3,6,5,9,8};
    int parent_index = 0;
    int child_index_left = 0, child_index_right = 0;
    int level = 0;
    Heap h;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
        h.data[i] = arr[i];
    }
    print_pyramid(h,parent_index,child_index_left,child_index_right,level);

    return 0;
}


void print_pyramid(Heap h, int parent_index, int child_index_left, int child_index_right, int level){
    for (int i = 0; i < sizeof(h.data) / sizeof(h.data[0]); i++){
        if (i == 0) {
            std::cout << level << " root " << h.root() << std::endl;
            ++level;
            parent_index = h.parent_index(i + 1);
        }
        child_index_left = h.left_index(parent_index);
        child_index_right = h.right_index(parent_index);
        std::cout <<  level << " left (" << h.data[parent_index] << ") " << h.from_index(child_index_left) << std::endl;
        std::cout <<  level << " right (" << h.data[parent_index] << ") " << h.from_index(child_index_right) << std::endl;
        ++level;
        ++parent_index;
    }
}
