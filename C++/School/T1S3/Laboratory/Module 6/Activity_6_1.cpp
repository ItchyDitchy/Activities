#include <time.h>

#include <iostream>
#include <unordered_map>

void calcDuplicates(int cur, int arr[], int size,
                    std::unordered_map<int, int>& count) {
  count[arr[cur]] = arr[cur] ? count[arr[cur]] + 1 : 1;
  if (cur < size - 1) {
    calcDuplicates(cur + 1, arr, size, count);
    return;
  }
  for (const auto& pair : count)
    std::cout << pair.first << " appears " << pair.second << " time"
              << (pair.second > 1 ? "s" : "") << std::endl;
}

int main() {
  int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
  std::unordered_map<int, int> count;
  calcDuplicates(0, arr, sizeof(arr) / sizeof(arr[0]), count);
  std::cout << clock();
  return 0;
}