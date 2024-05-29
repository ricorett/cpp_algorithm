#include <iostream>
#include <cstring>
#include <cassert>

struct Heap {
    int data[6];

    int root(){
        return data[0];
    }
    int from_index(int index){
        return data[index];
    }
    int left_index(int parent_index){
        return (2 * parent_index + 1);
    }
    int right_index(int parent_index){
        return (2 * parent_index + 2);
    }
    int parent_index(int child_index){
        return ((child_index - 1) / 2);
    }
    int size(){
        return sizeof(*data);
    }
    static int pyramid_level(int index) {
        return static_cast<int>(log(index + 1));
    }

    static bool is_left(int index) {
        int level = pyramid_level(index);
        int position = index - (1 << level) + 1;
        int mid = (1 << (level - 1));

        if (position < mid) {
            return true;
        } else {
            return false;
        }
    }
};

void print_index(int* arr, int arr_size, int index);

enum class Command {
    Up,
    Right,
    Left,
    Exit
};


//Парсинг строки в перечисление, чтобы не работать со строками в основной программе
Command ParseNextCommand(){
//TODO...

}




