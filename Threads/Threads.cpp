#include <iostream>
#include <thread>
#include <algorithm>
using namespace std;
void Sort(int* begin, int* end) {
    sort(begin, end);
}

int* DivArr(int* arr, int size) {
    if (size != 8) {
        cerr << "Array size must be 8!" << endl;
        return nullptr;
    }

    int* arr1 = new int[4];
    int* arr2 = new int[4];

    copy(arr, arr + 4, arr1);
    copy(arr + 4, arr + 8, arr2);
    sort(arr1, arr1+4);
    thread thread1(Sort, arr1, arr1 + 4);
    thread thread2(Sort, arr2, arr2 + 4);
    thread1.join();
    thread2.join();
    int* arr_fin = new int[8];
    copy(arr1, arr1 + 4, arr_fin);
    copy(arr2, arr2 + 4, arr_fin + 4);
    delete[] arr1;
    delete[] arr2;
    return arr_fin;
}

int main() {
    int arr[] = { 2, 5, 0, -2, 6, 8, 10, 1 };
    int* arr_sorted = DivArr(arr, sizeof(arr) / sizeof(arr[0])); 

    if (arr_sorted) {
        for (int i = 0; i < 8; i++) {
            cout << arr_sorted[i] << "\t";
        }
        cout << endl;
        delete[] arr_sorted;
    }
    return 0;
}

