## Binary Search
The binary search is a clever algorithm that is much more efficient than the linear search. Its only requirement is that the values in the array be **sorted in order**.

&nbsp;
Given a table of records whose keys are in increasing order K1 < K2 < ... < Kn. This algorithm for a given key K.
1. [Initialize] Set l = 1, u = n.
2. [Get midpoint] if u < l, the algorithm terminates unsuccessfully. Otherwise, i = (l + u)/2, the appoximate midpoint of the relevant table area.
3. [Compare] if K < Ki, go to step (4). If K = Ki, the algorithm terminates successfully.
4. [Adjust] Set u = i - 1, and return to step (2).
5. [Adjust] Set l = i + 1, and return to step (2).

#### Time Complexity
If T(n) is the time taken by binary search algorithm to solve a size n problem, then T(n) = T(n/2) + O(1) = **O(log n)**

#### Code in C++
```C++
int binarySearch(const int array[], int n, int value) {
  int first = 0,
      last = n - 1,
      middle,
      position = -1;
  bool found = false;

  while(!found && first <= last) {
    middle = (first + last)/2;

    if (array[middle] == value) {
      found = true;
      position = middle;
    }
    else if (array[middle] > middle) {
      last = middle - 1;
    }
    else {
      first = middle + 1;
    }
  }
}
```
