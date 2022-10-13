#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *, int);

int main(int argc, char ** argv)
{
  int arr[12] = {4, 8, 9, 6, 4, 2, 7, 11, 1, 21, 15, 10}, i;

  counting_sort(arr, 12);

  for (i = 0; i < 12; i++)
    printf("%d ", arr[i]);
  puts("");

  return 0;
}

void counting_sort(int * arr, int size)
{
  int * frequency, * temp, k, i;

  k = arr[0];

  for (i = 0; i < size; i++)
  {
    if (arr[i] > k)
      k = arr[i];
  }

  k++;

  frequency = calloc(k, sizeof(int));
  if (frequency == NULL)
  {
    puts("Can not allocate the memory.");
    exit(EXIT_FAILURE);
  }

  temp = malloc(size * sizeof(int));
  if (temp == NULL)
  {
    puts("Can not allocate the memory.");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < size; i++)
    frequency[arr[i]]++;

  for (i = 1; i < k; i++)
    frequency[i] += frequency[i - 1];

  for (i = size - 1; i >= 0; i--)
  {
    frequency[arr[i]]--;
    temp[frequency[arr[i]]] = arr[i];
  }

  for (i = 0; i < size; i++)
    arr[i] = temp[i];


  free(frequency);
  free(temp);
}
