#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    multimap<string, int> m;

    // insert operations
    m.emplace("tv",100);
   m.emplace("tv",100);
   m.emplace("tv",100);
   m.emplace("tv",100);
   m.emplace("tv",100);
   
    cout << "Initial map contents:\n";
    for (const auto &p : m) {