#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool areIsomorphic(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, char> mapS1toS2;
    unordered_map<char, char> mapS2toS1;

    for (int i = 0; i < s1.length(); i++) {
        char c1 = s1[i];
        char c2 = s2[i];

        // Check mapping from s1 to s2
        if (mapS1toS2.find(c1) != mapS1toS2.end()) {
            if (mapS1toS2[c1] != c2) {
                return false;
            }
        } else {
            mapS1toS2[c1] = c2;
        }

        mapS1toS2.clear();
        // Check mapping from s2 to s1
        if (mapS2toS1.find(c2) != mapS2toS1.end()) {
            if (mapS2toS1[c2] != c1) {
                return false;
            }
        } else {
            mapS2toS1[c2] = c1;
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

    if (areIsomorphic(s1, s2)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}
