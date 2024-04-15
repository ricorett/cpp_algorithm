#include <iostream>
#define OUT_OF_RANGE -1

//class DynamicArray {
//    int* array;
//    int new_size;
//public:
//    int get_i(int i, int last);
//    int append(int e, int last);
//};


void print_dynamic_array(int* arr, int logical_size, int actual_size);
int* append_to_dynamic_array(int* arr, int logical_size, int actual_size, int e);