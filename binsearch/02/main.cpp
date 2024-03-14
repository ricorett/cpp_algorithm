#include "main.h"

int main() {
  int count_point = 0;
  int arr[8] = {14, 16, 19, 32, 32, 56, 69, 72};
  std::cout << "Введите точку отсчета: ";
  std::cin >> count_point;
  int greater_number = count_num(count_point, arr);
  if (greater_number < 0) {
    std::cout << "Ошибка подсчета.\n";
  } else if (greater_number == 0) {
    std::cout << "Чисел больше заданного нет.\n";
  } else {
    std::cout << "Количество элементов в массиве больших чем " << count_point
              << ": " << greater_number << std::endl;
  }

  return 0;
}

int count_num(int count_point, int *arr) {
  int left, right, middle;
  int count = 0, found_flag = 0, index = 0;
  left = 0;
  right = sizeof(arr) - 1;
  if (arr == nullptr) {
    count = -1;
    return count;
  }

  while (left < right) {
    middle = (left + right) / 2;
    if (arr[middle] == count_point) {
      index = middle;
      found_flag = 1;
      break;
    } else if (arr[middle] > count_point) {
      right = middle - 1;
    } else if (arr[middle] < count_point) {
      left = middle + 1;
    }
    if (arr[left] == count_point) {
      found_flag = 1;
      index = left;
    }
  }
  if (found_flag == 1) {
    for (int i = index; i < sizeof(arr) - 1; i++) {
      count++;
    }
  }
  if (found_flag == 0) {
    count = 0;
  }
  return count;
}