#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Create and initialize an unordered_multimap
    unordered_multimap<int, string> myUnorderedMultimap;
    myUnorderedMultimap.insert({1, "Apple"});
    myUnorderedMultimap.insert({2, "Banana"});
    myUnorderedMultimap.insert({2, "Blueberry"});
    myUnorderedMultimap.insert({3, "Cherry"});

    // Size
    cout << "Size of the unordered_multimap: " << myUnorderedMultimap.size() << endl;

    // Max size
    cout << "Max size of the unordered_multimap: " << myUnorderedMultimap.max_size() << endl;

    // Find
    auto it = myUnorderedMultimap.find(2);
    if (it != myUnorderedMultimap.end()) {
        cout << "Found element with key 2: " << it->second << endl;
    }

    // Count
    cout << "Count of elements with key 2: " << myUnorderedMultimap.count(2) << endl;

    // Lower bound
    auto range = myUnorderedMultimap.equal_range(2);
    if (range.first != myUnorderedMultimap.end()) {
        cout << "Elements with key 2:\n";
        for (auto itr = range.first; itr != range.second; ++itr) {
            cout << itr->first << " => " << itr->second << endl;
        }
    }

    // Upper bound: not applicable directly, we use equal_range instead
    // Begin
    cout << "First element: " << myUnorderedMultimap.begin()->first << " => " << myUnorderedMultimap.begin()->second << endl;

    // Swap (swap contents with another unordered_multimap)
    unordered_multimap<int, string> anotherUnorderedMultimap;
    anotherUnorderedMultimap.insert({10, "X"});
    anotherUnorderedMultimap.insert({20, "Y"});
    anotherUnorderedMultimap.insert({30, "Z"});
    myUnorderedMultimap.swap(anotherUnorderedMultimap);

    cout << "After swapping, myUnorderedMultimap contains:\n";
    for (const auto& pair : myUnorderedMultimap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Erase (erase all elements with key 20)
    myUnorderedMultimap.erase(20);
    cout << "After erasing key 20, myUnorderedMultimap contains:\n";
    for (const auto& pair : myUnorderedMultimap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Clear
    myUnorderedMultimap.clear();
    cout << "After clearing, is myUnorderedMultimap empty? " << (myUnorderedMultimap.empty() ? "Yes" : "No") << endl;

    return 0;
}
