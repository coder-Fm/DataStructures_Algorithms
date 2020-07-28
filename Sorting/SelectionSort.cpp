#include <iostream>
using namespace std;

void selectionSort(int [], int);
void displayArray(const int [], int);

int main() {
  const int SIZE = 10;
  int vals[SIZE] = {6, 9, 1, 5, 4, 7, 2, 3, 8, 10};

  cout << "Array: \n";
  displayArray(vals, SIZE);

  selectionSort(vals, SIZE);

  cout << "Selection sort: \n";
  displayArray(vals, SIZE);

  return 0;
}

void selectionSort(int arr[], int size) {
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size-1); startScan++) {
    minIndex = startScan;
    minValue = arr[startScan];
    for(int index = startScan + 1; index < size; index++) {
      if (arr[index] < minValue) {
        minValue = arr[index];
        minIndex = index;
      }
    }
    arr[minIndex] = arr[startScan];
    arr[startScan] = minValue;
  }
}

void displayArray(const int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
