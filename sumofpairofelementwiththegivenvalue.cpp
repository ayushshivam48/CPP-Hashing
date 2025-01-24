#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findTwoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;  // Map to store the complement and its index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];  // Calculate the complement
        if (numMap.find(complement) != numMap.end()) {
            // If complement is found in the map, return the indices
            return {numMap[complement], i};
        }
        // Store the index of the current element
        numMap[nums[i]] = i;
    }
    // Return an empty vector if no solution is found
    return {};
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> result = findTwoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices of elements that sum up to the target: " 
             <<"{"<< result[0] << " , " << result[1] <<"}"<< endl;
    } else {
        cout << "No two elements sum up to the target." << endl;
    }

    return 0;
}
