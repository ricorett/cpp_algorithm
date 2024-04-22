#include "main.h"

int main() {
    std::cout << "Исходный массив: 1 3 6 5 9 8\n";
    int arr[6] = {1,3,6,5,9,8};
    int current_index = 0;
    int child_index_left = 0, child_index_right = 0;
    int level = 0;
    const int root = 0;
    Heap h;
    char* command = " ";
    std::string side;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
    h.data[i] = arr[i];
    }
    std::cout << "Пирамида: " << std::endl;
    print_pyramid(h, current_index, child_index_left, child_index_right, level);
    while(true) {
        std::cout << "Вы находитесь здесь: ";
        if (level == 0) {
            side = "root";
            std::cout << level << " " << side << " " << h.root() << std::endl;
            ++level;
            current_index = root;
        }
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "right") {
            child_index_right = h.right_index(current_index);
            if (h.data[child_index_right] == NULL) {
                std::cout << "Ошибка отсуствует правый потомок!" << std::endl;
            } else {
                current_index = child_index_right;
                side = "right";
                level++;
                std::cout << level << " " << side << " " << current_index << " " << h.data[current_index] << std::endl;
            }
        }
        if (command == "left") {
            side = "left";
            child_index_right = h.left_index(current_index);
            if (h.data[child_index_left] == NULL) {
                std::cout << "Ошибка отсуствует левый потомок! " << std::endl;
            } else {
                current_index = h.left_index(current_index);
                level++;
                std::cout << level << " " << side << " " << current_index << " " << h.data[current_index] << std::endl;
            }
        }
        if (command == "up") {
            current_index = h.parent_index(current_index);
            if (current_index == root) {
                std::cout << "Ошибка! Отсутствует родитель! " << std::endl;
            } else {
                level--;
            }
        }
        if (command == "exit"){
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