#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to find all unique combinations
    void findComb(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Loop through the array starting from current index
        for (int i = ind; i < arr.size(); i++) {
            // Skip duplicates: only pick the first occurrence at each level
            if (i > ind && arr[i] == arr[i - 1]) continue;

            // If current element exceeds target, no point in exploring further
            if (arr[i] > target) break;

            // Include current element
            ds.push_back(arr[i]);

            // Recurse with next index (i + 1) since each element can be used only once
            findComb(i + 1, target - arr[i], arr, ans, ds);

            // Backtrack: remove the last added element
            ds.pop_back();
        }
    }

    // Main function to be called
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};

// Driver code
int main() {
    vector<int> v{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution obj;
    vector<vector<int>> comb = obj.combinationSum2(v, target);

    cout << "[\n";
    for (const auto& vec : comb) {
        cout << "  [ ";
        for (int num : vec) cout << num << " ";
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}
