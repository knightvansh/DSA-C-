
#include<unordered_map>
#include <string>
using namespace std;

int main() {
    // creation
      unordered_map<string,int>m;

    // insert operations
    //1
    m["tv"] = 100;
    m["laptop"] = 100;
    m["headphone"] = 50;
    cout<<m["tv"]<<endl;












//     m.insert({"tablet", 50});
//     m.emplace("camera", 25);
//     m.insert(pair<string, int>("speaker", 75));

//     cout << "Initial map contents:\n";
//     for (const auto &p : m) {at("tv") << "\n";

//     auto it = m.find("laptop");
//     if (it != m.end()) {
//         cout << "found laptop with value " << it->second << "\n";
//     }

//     // erase operation
//     m.erase("camera");
//     cout << "\nAfter erase(\"camera\"):\n";
//     for (const auto &p : m) {
//         cout << p.first << " " << p.second << '\n';
//     }

//     // lower_bound / upper_bound / equal_range
//     auto lb = m.lower_bound("h");
//     if (lb != m.end()) {
//         cout << "lower_bound(\"h\") -> " << lb->first << " " << lb->second << "\n";
//     }

//     auto ub = m.upper_bound("h");
//     if (ub != m.end()) {
//         cout << "upper_bound(\"h\") -> " << ub->first << " " << ub->second << "\n";
//     }

//     auto range = m.equal_range("headphone");
//     cout << "equal_range(\"headphone\"): ";
//     if (range.first != m.end()) {
//         cout << "first=" << range.first->first << " ";
//     }
//     if (range.second != m.end()) {
//         cout << "second=" << range.second->first;
//     }
//     cout << "\n";

//     // remaining operations not present earlier
//     m.insert_or_assign("speaker", 80);
//     m.try_emplace("headphone", 55);
//     m.try_emplace("charger", 20);
//     m.emplace_hint(m.begin(), "tablet", 60);

//     cout << "\nAfter insert_or_assign / try_emplace / emplace_hint:\n";
//     for (const auto &p : m) {
//         cout << p.first << " " << p.second << '\n';
//     }

//     cout << "max_size = " << m.max_size() << "\n";
//     auto kc = m.key_comp();
//     cout << "key_comp(\"headphone\", \"laptop\") = " << boolalpha << kc("headphone", "laptop") << "\n";
//     if (m.size() > 1) {
//         auto vc = m.value_comp();
//         auto it1 = m.begin();
//         auto it2 = next(it1);
//         cout << "value_comp compares first two pairs = " << boolalpha << vc(*it1, *it2) << "\n";
//     }

//     cout << "\nReverse order:\n";
//     for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
//         cout << rit->first << " " << rit->second << '\n';
//     }

//     // swap and clear
//     map<string, int> other;
//     other["phone"] = 200;
//     other["watch"] = 150;
//     m.swap(other);

//     cout << "\nAfter swap, m contains:\n";
//     for (const auto &p : m) {
//         cout << p.first << " " << p.second << '\n';
//     }

//     other.clear();
//     cout << "\nother.empty() after clear = " << boolalpha << other.empty() << "\n";

//  

return 0;

}
