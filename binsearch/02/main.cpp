#include "main.h"

int main() {
  int count_point = 0;
  std::vector<int> arr = {14, 16, 19, 32, 32, 32, 56, 69, 72};
  std::cout << "Введите точку отсчета: ";
  std::cin >> count_point;
  int index = binarySearch(arr, count_point);
  if (index == -1) {
      std::cout << "Ошибка подсчета!";
      return -1;
  }
  int count = arr.size() - index;
  std::cout << "Чисел больше, чем точка отсчета: " << count;
  return 0;
}

int binarySearch(const std::vector<int>& arr, int count_point) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > count_point) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;

}
