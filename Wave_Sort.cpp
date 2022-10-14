
#include<functional>
#include<iostream>
using namespace std;
#define ll long long int
using namespace std;
void waveSort(int arr[], int n)
{
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i += 2)
        swap(arr[i], arr[i + 1]);
}
int main(){
    int n = 5;
    int arr[5] = {12,76,33,12,34};
    waveSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
