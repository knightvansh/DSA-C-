#include<iostream>
#include<map>
using namespace std;

int main() {
    // Declare a map with key as string and value as int
    map<string, int> myMap;

    // Insert elements
    myMap["apple"] = 10;
    myMap["banana"] = 20;
    myMap.insert(make_pair("cherry", 30));

    // Access elements
    cout << "Apple: " << myMap["apple"] << endl;

    // Iterate through the map
    for(auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Check if key exists
    if(myMap.find("banana") != myMap.end()) {
        cout << "Banana found!" << endl;
    }

    // Erase an element
    myMap.erase("apple");

    cout << "After erasing apple:" << endl;
    for(auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
