#include <iostream>
#define OUT_OF_RANGE -1


void print_dynamic_array(int* arr, int logical_size, int actual_size);
void append_to_dynamic_array(int*& arr, int &logical_size, int &actual_size, int e);