#include <iostream>
using namespace std;

void countSort(int * a, int len){
    int max = a[0];
    for (int i = 0; i < len; i++){
        if (a[i] > max){
            max = a[i];
        }
    }

    int * buffer = new int[max + 1];
    for (int i = 0; i <= max; i++){
        buffer[i] = 0;
    }
    
    for (int i = 0; i < len; i++){
        buffer[a[i]]++;
    }
    
    int index = 0;

    for (int i = 1; i <= max; i++){
        if (buffer[i] > 0){
            while ((buffer[i]--) > 0){
                a[index++] = i;
            }
        }
    }
}

int main(){
    int a[5] = {2, 4, 2, 3, 3};
    countSort(a, 5);
    for (int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}