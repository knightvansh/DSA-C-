#include <iostream>
#include <vector>
using namespace std;


int main() {
  Dynamic Allocation & Deallocation
    //Example -  // 1
    int *ptr = new int;
    *ptr = 100;
    cout << *ptr << endl;
    delete ptr;



      //1D Dynamic Array
    int size;
    cout << "enter size of array : ";
    cin >> size;
    int *arr = new int[size];

    for(int i=0; i<size; i++) {
        arr[i] = i+1;
        cout << arr[i] << " ";
    }
}



//     << endl;//

    
