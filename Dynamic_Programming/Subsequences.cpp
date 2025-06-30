#include <bits/stdc++.h>
using namespace std;

// 1. Check if any subsequence sums to target
bool isSubsetSum(int ind, int currSum, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (currSum == target) return true;
    if (ind == arr.size() || currSum > target) return false;
    if (dp[ind][currSum] != -1) return dp[ind][currSum];

    bool take = isSubsetSum(ind + 1, currSum + arr[ind], target, arr, dp);
    bool skip = isSubsetSum(ind + 1, currSum, target, arr, dp);

    return dp[ind][currSum] = take || skip;
}

bool checkSubsequenceSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return isSubsetSum(0, 0, target, arr, dp);
}

// 2. Count all subsequences that sum to target
int countSubsets(int ind, int currSum, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == arr.size()) return currSum == target ? 1 : 0;
    if (dp[ind][currSum] != -1) return dp[ind][currSum];

    int take = 0, skip = 0;
    if (currSum + arr[ind] <= target)
        take = countSubsets(ind + 1, currSum + arr[ind], target, arr, dp);
    skip = countSubsets(ind + 1, currSum, target, arr, dp);

    return dp[ind][currSum] = take + skip;
}

int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return countSubsets(0, 0, target, arr, dp);
}

// 3. Count subsequences with given difference
int countDiffSubsets(vector<int>& arr, int diff) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if ((total + diff) % 2 != 0) return 0;
    int target = (total + diff) / 2;

    vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= arr.size(); ++i) {
        for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[arr.size()][target];
}

// 4. Count subsequences with sum divisible by k
int countDivisibleSubsets(int ind, int sum, int k, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == arr.size()) return sum % k == 0 ? 1 : 0;
    if (dp[ind][sum % k] != -1) return dp[ind][sum % k];

    int take = countDivisibleSubsets(ind + 1, sum + arr[ind], k, arr, dp);
    int skip = countDivisibleSubsets(ind + 1, sum, k, arr, dp);

    return dp[ind][sum % k] = take + skip;
}

int countSubsequencesDivByK(vector<int>& arr, int k) {
    vector<vector<int>> dp(arr.size(), vector<int>(k, -1));
    return countDivisibleSubsets(0, 0, k, arr, dp);
}

// 5. Print all subsequences
void printAllSubsequences(int ind, vector<int>& arr, vector<int>& temp) {
    if (ind == arr.size()) {
        for (int x : temp) cout << x << " ";
        cout << "\n";
        return;
    }

    temp.push_back(arr[ind]);
    printAllSubsequences(ind + 1, arr, temp);
    temp.pop_back();
    printAllSubsequences(ind + 1, arr, temp);
}

// Driver
int main() {
    vector<int> arr = {2, 3, 5};
    int target = 5;
    int diff = 1;
    int k = 5;

    cout << "Check if any subsequence sums to " << target << ": "
         << (checkSubsequenceSum(arr, target) ? "Yes" : "No") << "\n";

    cout << "Count of subsequences summing to " << target << ": "
         << perfectSum(arr, target) << "\n";

    cout << "Count of subsequences with difference " << diff << ": "
         << countDiffSubsets(arr, diff) << "\n";

    cout << "Count of subsequences with sum divisible by " << k << ": "
         << countSubsequencesDivByK(arr, k) << "\n";

    cout << "All subsequences:\n";
    vector<int> temp;
    printAllSubsequences(0, arr, temp);

    return 0;
}
