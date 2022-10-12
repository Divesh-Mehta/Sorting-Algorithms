#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertion_sort(int arr[], int size)
{
    int current;
    int j;
    for (int i = 0; i < size; i++)
    {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }
}

int main()
{
    // example
    int arr[] = {5, 3, 11, 87, 12, 10, 16, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    print_array(arr, size);

    return 0;
}
