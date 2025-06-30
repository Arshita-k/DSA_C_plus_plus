class Solution {
public:
    // Helper function to find all combinations
    void findComb(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, int n, vector<int>& ds) {
        // Base case: if we've considered all elements
        if (ind == n) {
            // If the remaining target is 0, we found a valid combination
            if (target == 0) {
                ans.push_back(ds);  // Add the current combination to the answer
            }
            return;
        }

        // Choice 1: Pick the current element if it's not greater than the target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);  // Include arr[ind] in the current combination
            // Recurse with the same index (since we can reuse the same element)
            findComb(ind, target - arr[ind], arr, ans, n, ds);
            ds.pop_back();  // Backtrack: remove the last added element
        }

        // Choice 2: Skip the current element and move to the next
        findComb(ind + 1, target, arr, ans, n, ds);
    }

    // Main function to be called
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;  // To store all valid combinations
        vector<int> ds;              // Temporary list to store current combination
        int n = candidates.size();   // Total number of elements
        findComb(0, target, candidates, answer, n, ds);  // Start recursion
        return answer;
    }
};
