#include "main.h"
#include <cstring> // Добавляем библиотеку для функции strcmp()

int main() {
    std::cout << "Исходный массив: 1 3 6 5 9 8\n";
    int arr[6] = {1,3,6,5,9,8};
    int current_index = 0;
    int child_index_left, child_index_right;
    int level = 0;
    const int root = 0;
    Heap h;
    char command[10];
    std::string side = "root";

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
        h.data[i] = arr[i];
    }
    std::cout << "Пирамида: " << std::endl;
    print_pyramid(h, current_index, child_index_left, child_index_right, level);
    while(true) {
        if (level == 0) {
            side = "root";
            current_index = root;
        }
        std::cout << "Вы находитесь здесь: ";
        std::cout << level << " " << side << " (" << current_index << ") " << h.data[current_index] << std::endl;

        std::cout << "Введите команду: ";
        std::cin >> command;
        if (strcmp(command, "right") == 0) {
            child_index_right = h.right_index(current_index);
            if (child_index_right >= h.size()) {
                std::cout << "Ошибка! Отсуствует правый потомок!" << std::endl;
            } else {
                current_index = child_index_right;
                side = "right";
                level++;
                std::cout << "OK\n";
                child_index_left = h.left_index(current_index);
                child_index_right = h.right_index(current_index);

            }
        }
        if (strcmp(command, "left") == 0) {
            child_index_left = h.left_index(current_index);
            if (child_index_left >= h.size()) {
                std::cout << "Ошибка! Отсуствует левый потомок! " << std::endl;
            } else {
                current_index = child_index_left;
                side = "left";
                level++;
                std::cout << "OK\n";
                child_index_left = h.left_index(current_index);
                child_index_right = h.right_index(current_index);

            }
        }
        if (strcmp(command, "up") == 0) {
            current_index = h.parent_index(current_index);
            if (current_index == root) {
                std::cout << "Ошибка! Отсутствует родитель! " << std::endl;
            } else {

                level--;
                std::cout << "OK\n";

            }
        }
        if (strcmp(command, "exit") == 0){
            break;
        }
    }
    return 0;
}


void print_pyramid(Heap h, int parent_index, int child_index_left, int child_index_right, int level){
    for (int i = 0; i < sizeof(h.data) / sizeof(h.data[0]); i++){
        if (parent_index >= (sizeof(h.data)/sizeof(h.data[0]))) {
            break;
        }

        if (i == 0) {
            std::cout << level << " root " << h.root() << std::endl;
            ++level;
            parent_index = h.parent_index(i + 1);
        }

        if (parent_index < (sizeof(h.data)/sizeof(h.data[0]))) {
            child_index_left = h.left_index(parent_index);
            child_index_right = h.right_index(parent_index);

            if (child_index_left < (sizeof(h.data)/sizeof(h.data[0]))) {
                std::cout <<  level << " left (" << h.data[parent_index] << ") " << h.from_index(child_index_left) << std::endl;
            }

            if (child_index_right < (sizeof(h.data)/sizeof(h.data[0]))) {
                std::cout <<  level << " right (" << h.data[parent_index] << ") " << h.from_index(child_index_right) << std::endl;
            }

            ++level;
            ++parent_index;
        }
    }
}