#include <iostream>
#include <cstring>
#include <cassert>
#include <unordered_map>

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

void print_index(int* arr, int arr_size, int index, Heap h);

enum class Command {
    Up,
    Right,
    Left,
    Exit,
    Invalid
};


//Парсинг строки в перечисление, чтобы не работать со строками в основной программе
Command ParseNextCommand(){
    static const std::unordered_map<std::string, Command> command_map = {
            {"Up", Command::Up},
            {"Right", Command::Right},
            {"Left", Command::Left},
            {"Exit", Command::Exit}
    };
    std::string input;
    std::cin >> input;

    auto it = command_map.find(input);
    if (it != command_map.end()) {
        return it->second;
    } else {
        return Command::Invalid;
    }
}




