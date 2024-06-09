#include <time.h>

#include <iostream>
#include <unordered_map>

using namespace std;

void calcDuplicates(int cur, int arr[], int size,
                    unordered_map<int, int>& count) {
  if (arr[cur])
    count[arr[cur]] += 1;
  else
    count[arr[cur]] = 1;
  if (cur < size - 1) {
    calcDuplicates(cur + 1, arr, size, count);
    return;
  }
  for (const auto& pair : count)
    cout << pair.first << " appears " << pair.second << " time"
         << (pair.second > 1 ? "s" : "") << endl;
}

int main() {
  int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
  unordered_map<int, int> count;
  calcDuplicates(0, arr, sizeof(arr) / sizeof(arr[0]), count);
  cout << clock();
  return 0;
}