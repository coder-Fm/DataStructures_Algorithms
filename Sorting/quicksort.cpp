void quickSort(int set[], int styart, int end) {
  int pivotPoint;
  if (start < end) {
    pivotPoint = partition(set, start, end);  // get pivotPoint
    quickSort(set, start, pivotPoint - 1);    // sort sublist 1
    quickSort(set, pivotPoint + 1, end);      // sort sublist 2
  }
}

// partition function returns the subscript of the pivot element
// partition function controls the rearranging of the other values in the list
int partition(int set[], int start, int end) {
  int pivotValue, pivotIndex, mid;

  mid = (start + end)/2;
  swap(set[start], set[mid]);
  pivotIndex = start;
  pivotValue = set[start];

  for (int scan = start + 1; scan <= end; scan++)  {
    if (set[scan] < pivotValue) {
      pivotIndex++;
      swap(set[pivotIndex], set[scan]);
    }
  }
  swap(set[start], set[pivotIndex]);
  return pivotIndex;
}

//swap function: swap the values found in any two elements of the list
void swap(int &val1, nt &val2) {
  int temp = val1;
  val1 = val2;
  val2 = temp;
}
