#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (array[j] == query) {
                count++;
            }
        }
        cout << count <<" ";//RRRRR
    }
    
    return 0;
}
