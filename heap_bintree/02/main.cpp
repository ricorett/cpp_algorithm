#include "header.h"

int main() {
    std::cout << "Исходный массив: 1 3 6 5 9 8\n";
    int arr[6] = {1, 3, 6, 5, 9, 8};
    Heap h;
    const int root = 0;
    int current_index = 0;
    int child_index_left = h.left_index(current_index);
    int child_index_right = h.right_index(current_index);
    int level = 0;
    char command[10];
    std::string side = "root";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        h.data[i] = arr[i];
    }
    for (int i : arr){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    while (true) {
        Command cmd = ParseNextCommand();
        switch (cmd) {
            case Command::Up:
                //std::cout << "Moving Up" << std::endl;

                break;
            case Command::Right:
                //std::cout << "Moving Right" << std::endl;
                break;
            case Command::Left:
                //std::cout << "Moving Left" << std::endl;
                break;
            case Command::Exit:
                //std::cout << "Exiting" << std::endl;
                return 0;
            case Command::Invalid:
            default:
                //std::cout << "Invalid command" << std::endl;
                break;
        }
    }
// печать всей пирамиды в начале
// текущий индекс для отображения = 0
// пока можем двигаться
// парсинг команд от пользователя
// получение нового индекса для перемещения через вызов нужной функции по введенной команде
// Если можем ли двигаться
// перемещение текущего индекса
// конец ЕСЛИ
// конец пока

    return 0;
}
//Обратите внимание, для печати строки мне не нужно передавать ничего кроме текущего индекса и массива. Код примерно в таком ключе:
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
