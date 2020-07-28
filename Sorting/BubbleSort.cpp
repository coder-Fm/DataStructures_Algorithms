#include <iostream>
using namespace std;

void BubbleSort(int [], int);
void displayArray(const int [], int);

int main() {
  int vals[10] = {6, 9, 1, 5, 4, 7, 2, 3, 8, 10};

  cout << "Array: \n";
  displayArray(vals, 10);

  BubbleSort(vals, 10);

  cout << "Bubble sort: \n";
  displayArray(vals, 10);

  return 0;
}

void BubbleSort(int arr[], int size) {
  bool swap;
  int temp;
  do {
    swap = false;
    for (int i = 0; i < (size-1); i++) {
      if (arr[i] > arr[i+1]) {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swap = true;
      }
    }
  } while (swap);
}

void displayArray(const int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
