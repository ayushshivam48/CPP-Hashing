#include <iostream>
#include <map>

using namespace std;

int main() {
    // Create and initialize a map
    map<int, string> myMap;
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Cherry";

    // Size
    cout << "Size of the map: " << myMap.size() << endl;

    // Max size
    cout << "Max size of the map: " << myMap.max_size() << endl;

    // Find
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        cout << "Found element with key 2: " << it->second << endl;
    }

    // Count
    cout << "Count of elements with key 2: " << myMap.count(2) << endl;

    // Lower bound
    it = myMap.lower_bound(2);
    if (it != myMap.end()) {
        cout << "Lower bound of key 2: " << it->first << " => " << it->second << endl;
    }

    // Upper bound
    it = myMap.upper_bound(2);
    if (it != myMap.end()) {
        cout << "Upper bound of key 2: " << it->first << " => " << it->second << endl;
    }

    // Begin
    cout << "First element: " << myMap.begin()->first << " => " << myMap.begin()->second << endl;

    // End (end() points to one past the last element, so we decrement the iterator)
    cout << "Last element: " << prev(myMap.end())->first << " => " << prev(myMap.end())->second << endl;

    // Reverse begin
    cout << "First element in reverse: " << myMap.rbegin()->first << " => " << myMap.rbegin()->second << endl;

    // Reverse end (rend() points to one before the first element, so we decrement the iterator)
    cout << "Last element in reverse: " << prev(myMap.rend())->first << " => " << prev(myMap.rend())->second << endl;

    // Swap (swap contents with another map)
    map<int, string> anotherMap;
    anotherMap[10] = "X";
    anotherMap[20] = "Y";
    anotherMap[30] = "Z";
    myMap.swap(anotherMap);

    cout << "After swapping, myMap contains:\n";
    for (const auto& pair : myMap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Erase (erase element with key 20)
    myMap.erase(20);
    cout << "After erasing key 20, myMap contains:\n";
    for (const auto& pair : myMap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Clear
    myMap.clear();
    cout << "After clearing, is myMap empty? " << (myMap.empty() ? "Yes" : "No") << endl;

    return 0;
}
