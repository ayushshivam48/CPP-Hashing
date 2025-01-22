#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Create and initialize an unordered_map
    unordered_map<int, string> myUnorderedMap;
    myUnorderedMap[1] = "Apple";
    myUnorderedMap[2] = "Banana";
    myUnorderedMap[3] = "Cherry";

    // Size
    cout << "Size of the unordered_map: " << myUnorderedMap.size() << endl;

    // Max size
    cout << "Max size of the unordered_map: " << myUnorderedMap.max_size() << endl;

    // Find
    auto it = myUnorderedMap.find(2);
    if (it != myUnorderedMap.end()) {
        cout << "Found element with key 2: " << it->second << endl;
    }

    // Count
    cout << "Count of elements with key 2: " << myUnorderedMap.count(2) << endl;

    // Begin
    cout << "First element: " << myUnorderedMap.begin()->first << " => " << myUnorderedMap.begin()->second << endl;

    // Swap (swap contents with another unordered_map)
    unordered_map<int, string> anotherUnorderedMap;
    anotherUnorderedMap[10] = "X";
    anotherUnorderedMap[20] = "Y";
    anotherUnorderedMap[30] = "Z";
    myUnorderedMap.swap(anotherUnorderedMap);

    cout << "After swapping, myUnorderedMap contains:\n";
    for (const auto& pair : myUnorderedMap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Erase (erase element with key 20)
    myUnorderedMap.erase(20);
    cout << "After erasing key 20, myUnorderedMap contains:\n";
    for (const auto& pair : myUnorderedMap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Clear
    myUnorderedMap.clear();
    cout << "After clearing, is myUnorderedMap empty? " << (myUnorderedMap.empty() ? "Yes" : "No") << endl;

    return 0;
}
