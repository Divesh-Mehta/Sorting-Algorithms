// C++ implementation of Cocktail Sort
#include <iostream>

// Sorts array a[0..n-1] using Cocktail sort
void CocktailSort(int a[], int n) {
  bool swapped = true;
  int start = 0;
  int end = n - 1;

  while (swapped) {
    // reset the swapped flag on entering
    // the loop, because it might be true from
    // a previous iteration.
    swapped = false;

    // loop from left to right same as
    // the bubble sort
    for (int i = start; i < end; ++i) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        swapped = true;
      }
    }

    // if nothing moved, then array is sorted.
    if (!swapped)
      break;

    // otherwise, reset the swapped flag so that it
    // can be used in the next stage
    swapped = false;

    // move the end point back by one, because
    // item at the end is in its rightful spot
    --end;

    // from right to left, doing the
    // same comparison as in the previous stage
    for (int i = end - 1; i >= start; --i) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        swapped = true;
      }
    }

    // increase the starting point, because
    // the last stage would have moved the next
    // smallest number to its rightful spot.
    ++start;
  }
}

/* Prints the array */
void printArray(int a[], int n) {
  for (int i = 0; i < n; i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;
}

int main() {
  int arr[] = {5, 2, 7, 2, 9, 0, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  CocktailSort(arr, n);
  printf("Sorted array :\n");
  printArray(arr, n);
  return 0;
}
