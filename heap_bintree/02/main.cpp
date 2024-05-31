#include "header.h"

int main() {
    std::cout << "Исходный массив: 1 3 6 5 9 8\n";
    int arr[6] = {1, 3, 6, 5, 9, 8};
    Heap h;
    const int root = 0;
    int current_index = 0;


    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        h.data[i] = arr[i];
    }

    while (true) {
        Command cmd = ParseNextCommand();
        switch (cmd) {
            case Command::Up:
                if (current_index != root) {
                    current_index = h.parent_index(current_index);
                    print_index(arr, 6, current_index, h);
                } else {
                    std::cout << "Already at root" << std::endl;
                }
                break;
            case Command::Right:
                if (h.right_index(current_index) < 6) {
                    current_index = h.right_index(current_index);
                    print_index(arr, 6, current_index, h);
                } else {
                    std::cout << "No right child" << std::endl;
                }
                break;
            case Command::Left:
                if (h.left_index(current_index) < 6) {
                    current_index = h.left_index(current_index);
                    print_index(arr, 6, current_index, h);
                } else {
                    std::cout << "No left child" << std::endl;
                }
                break;
            case Command::Exit:
                std::cout << "Exiting" << std::endl;
                return 0;
            case Command::Invalid:
            default:
                std::cout << "Invalid command" << std::endl;
                break;
        }
    }
    return 0;
}

void print_index(int* arr, int arr_size, int index, Heap h){
    assert(index < arr_size);
    if (index == 0)
    {
        std::cout << "0 root " << arr[0] << std::endl;
        return;
    }
    int parent_data = arr[h.parent_index(index)];
    std::cout << Heap::pyramid_level(index)
              << (Heap::is_left(index) ? " left" : " right")
              << "(" << parent_data << ") "
              << arr[index] << std::endl;
}

//void print_pyramid(Heap h, int parent_index, int child_index_left, int child_index_right, int level){
//    for (int i = 0; i < sizeof(h.data) / sizeof(h.data[0]); i++){
//        if (parent_index >= (sizeof(h.data)/sizeof(h.data[0]))) {
//            break;
//        }

//        if (i == 0) {
//            std::cout << level << " root " << h.root() << std::endl;
//            ++level;
//            parent_index = h.parent_index(i + 1);
//        }

//        if (parent_index < (sizeof(h.data)/sizeof(h.data[0]))) {
//            child_index_left = h.left_index(parent_index);
//            child_index_right = h.right_index(parent_index);
//
//            if (child_index_left < (sizeof(h.data)/sizeof(h.data[0]))) {
//                std::cout <<  level << " left (" << h.data[parent_index] << ") " << h.from_index(child_index_left) << std::endl;
//            }
//
//            if (child_index_right < (sizeof(h.data)/sizeof(h.data[0]))) {
//                std::cout <<  level << " right (" << h.data[parent_index] << ") " << h.from_index(child_index_right) << std::endl;
//            }
//
//            ++level;
//            ++parent_index;
//        }
//    }
//}

//while(true) {
//if (level == 0) {
//side = "root";
//current_index = root;
//}
//std::cout << "Вы находитесь здесь: ";
//std::cout << level << " " << side << " (" << h.data[((current_index - 1) / 2)] << ") " << h.data[current_index] << std::endl;
//
//std::cout << "Введите команду: ";
//std::cin >> command;
//if (strcmp(command, "right") == 0) {
//
//if (child_index_right >= h.size()) {
//std::cout << "Ошибка! Отсуствует правый потомок!" << std::endl;
//} else {
//current_index = h.right_index(current_index);
//side = "right";
//level++;
//std::cout << "OK\n";
//child_index_left = h.left_index(current_index);
//child_index_right = h.right_index(current_index);
//
//}
//}
//if (strcmp(command, "left") == 0) {
//
//if (child_index_left >= h.size()) {
//std::cout << "Ошибка! Отсуствует левый потомок! " << std::endl;
//} else {
//current_index =  h.left_index(current_index);
//side = "left";
//level++;
//std::cout << "OK\n";
//child_index_left = h.left_index(current_index);
//child_index_right = h.right_index(current_index);
//
//}
//}
//if (strcmp(command, "up") == 0) {
//if (current_index == root) {
//std::cout << "Ошибка! Отсутствует родитель! " << std::endl;
//} else {
//current_index = h.parent_index(current_index);
//--level;
//std::cout << "OK\n";
//
//}
//}
//if (strcmp(command, "exit") == 0){
//break;
//}
//}
