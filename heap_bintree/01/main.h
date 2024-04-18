#include <iostream>

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
};


void print_pyramid(Heap h, int parent_index, int child_index_left, int child_index_right, int level);
