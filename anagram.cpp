#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, int> charCount;

    // Increment the count for characters in the first string
    for (char c : s1) {
        charCount[c]++;
    }

    // Decrement the count for characters in the second string
    for (char c : s2) {
        if(charCount.find(c)==charCount.end()){
            return false;
        }else{
        charCount[c]--;
        }
    }

    // Check if all counts are zero
    for (auto &entry : charCount) {
        if (entry.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (areAnagrams(s1, s2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
