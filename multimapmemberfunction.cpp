#include <iostream>
#include <map>

using namespace std;

int main() {
    // Create and initialize a multimap
    multimap<int, string> myMultimap;
    myMultimap.insert({1, "Apple"});
    myMultimap.insert({2, "Banana"});
    myMultimap.insert({2, "Blueberry"});
    myMultimap.insert({3, "Cherry"});

    // Size
    cout << "Size of the multimap: " << myMultimap.size() << endl;

    // Max size
    cout << "Max size of the multimap: " << myMultimap.max_size() << endl;

    // Find
    auto it = myMultimap.find(2);
    if (it != myMultimap.end()) {
        cout << "Found element with key 2: " << it->second << endl;
    }

    // Count
    cout << "Count of elements with key 2: " << myMultimap.count(2) << endl;

    // Lower bound
    it = myMultimap.lower_bound(2);
    if (it != myMultimap.end()) {
        cout << "Lower bound of key 2: " << it->first << " => " << it->second << endl;
    }

    // Upper bound
    it = myMultimap.upper_bound(2);
    if (it != myMultimap.end()) {
        cout << "Upper bound of key 2: " << it->first << " => " << it->second << endl;
    }

    // Begin
    cout << "First element: " << myMultimap.begin()->first << " => " << myMultimap.begin()->second << endl;

    // End (end() points to one past the last element, so we decrement the iterator)
    cout << "Last element: " << prev(myMultimap.end())->first << " => " << prev(myMultimap.end())->second << endl;

    // Reverse begin
    cout << "First element in reverse: " << myMultimap.rbegin()->first << " => " << myMultimap.rbegin()->second << endl;

    // Reverse end (rend() points to one before the first element, so we decrement the iterator)
    cout << "Last element in reverse: " << prev(myMultimap.rend())->first << " => " << prev(myMultimap.rend())->second << endl;

    // Swap (swap contents with another multimap)
    multimap<int, string> anotherMultimap;
    anotherMultimap.insert({10, "X"});
    anotherMultimap.insert({20, "Y"});
    anotherMultimap.insert({30, "Z"});
    myMultimap.swap(anotherMultimap);

    cout << "After swapping, myMultimap contains:\n";
    for (const auto& pair : myMultimap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Erase (erase element with key 20)
    myMultimap.erase(20);
    cout << "After erasing key 20, myMultimap contains:\n";
    for (const auto& pair : myMultimap) {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Clear
    myMultimap.clear();
    cout << "After clearing, is myMultimap empty? " << (myMultimap.empty() ? "Yes" : "No") << endl;

    return 0;
}
