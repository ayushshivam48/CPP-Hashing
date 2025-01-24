#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<int, vector<int>> longestSubarrayWithZeroSum(vector<int>& nums) {
    unordered_map<int, int> sumMap;  // Map to store the first occurrence of a cumulative sum
    int maxLength = 0;               // Maximum length of the subarray with sum 0
    int startIndex = -1;             // Start index of the longest subarray with sum 0
    int cumSum = 0;                  // Cumulative sum

    for (int i = 0; i < nums.size(); i++) {
        cumSum += nums[i];  // Update the cumulative sum

        if (cumSum == 0) {
            // If cumSum is 0, the subarray from the start to the current index has sum 0
            maxLength = i + 1;
            startIndex = 0;
        }

        // If cumSum has been seen before, the subarray between the previous index and the current index has sum 0
        if (sumMap.find(cumSum) != sumMap.end()) {
            int prevIndex = sumMap[cumSum];
            int length = i - prevIndex;
            if (length > maxLength) {
                maxLength = length;
                startIndex = prevIndex + 1;
            }
        } else {
            // Store the first occurrence of the cumulative sum
            sumMap[cumSum] = i;
        }
    }

    vector<int> longestSubarray;
    if (startIndex != -1) {
        longestSubarray.assign(nums.begin() + startIndex, nums.begin() + startIndex + maxLength);
    }

    return {maxLength, longestSubarray};
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    auto [length, subarray] = longestSubarrayWithZeroSum(nums);
    if (length > 0) {
        cout << "The length of the longest subarray with sum 0 is: " << length << endl;
        cout << "The longest subarray with sum 0 is: ";
        for (int num : subarray) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No subarray with sum 0 exists." << endl;
    }

    return 0;
}
