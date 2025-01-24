#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to compute prefix sums using an unordered_map
unordered_map<int, int> computePrefixSums(const vector<int>& arr) {
    unordered_map<int, int> prefixSumMap;
    int cumSum = 0;

    // Insert the initial prefix sum (0) with index -1 into the map
    prefixSumMap[0] = -1;

    for (int i = 0; i < arr.size(); i++) {
        cumSum += arr[i];
        prefixSumMap[cumSum] = i;  // Store the latest index of each cumulative sum
    }

    return prefixSumMap;
}

// Function to find the subarray with a given sum
int findSubarraySum(const vector<int>& arr, int targetSum) {
    unordered_map<int, int> prefixSumMap;
    int cumSum = 0;
    int maxLength = 0;

    // Insert the initial prefix sum (0) with index -1 into the map
    prefixSumMap[0] = -1;

    for (int i = 0; i < arr.size(); i++) {
        cumSum += arr[i];
        int requiredSum = cumSum - targetSum;

        // Check if the required sum is in the map
        if (prefixSumMap.find(requiredSum) != prefixSumMap.end()) {
            int length = i - prefixSumMap[requiredSum];
            maxLength = max(maxLength, length);
        }

        // Store the index of the current cumulative sum if it's not already in the map
        if (prefixSumMap.find(cumSum) == prefixSumMap.end()) {
            prefixSumMap[cumSum] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Compute the prefix sums using the map
    unordered_map<int, int> prefixSumMap = computePrefixSums(arr);

    cout << "Prefix Sum Map:" << endl;
    for (const auto& pair : prefixSumMap) {
        cout << "Sum " << pair.first << " found at index " << pair.second << endl;
    }

    int targetSum;
    cout << "Enter the target sum for subarray query: ";
    cin >> targetSum;

    int length = findSubarraySum(arr, targetSum);
    if (length > 0) {
        cout << "The length of the longest subarray with sum " << targetSum << " is: " << length << endl;
    } else {
        cout << "No subarray with sum " << targetSum << " exists." << endl;
    }

    return 0;
}
