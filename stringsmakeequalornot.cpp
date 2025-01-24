#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

bool canMakeEqual(vector<string> &v) {
    unordered_map<char, int> m;

    // Iterate over each string in the vector
    for (auto &str : v) {
        // Iterate over each character in the string
        for (char c : str) {
            m[c]++;
        }
    }

    int n = v.size();
    for (auto &ele : m) {
        if (ele.second % n != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Print "Yes" or "No" based on the result
    cout << (canMakeEqual(v) ? "Yes" : "No") << endl;

    return 0;
}
