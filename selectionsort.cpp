#include <iostream>
using namespace std;

void selectionsort(int * arr, int len){
    for (int i = 0; i < len - 1; i++){
        int min = i;
        for (int j = i; j < len; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(){
    int a[10] = {1, -1, 99, 75, 54, 36, 76, 45, 54, 30};
    selectionsort(a, 10);
    for (int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}