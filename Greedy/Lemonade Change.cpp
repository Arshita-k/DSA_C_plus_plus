class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> count; // Store number of bills: 5, 10, 20...

        for (int bill : bills) {
            count[bill]++; // Accept the customer's bill

            int change = bill - 5; // You need to return this much change

            // Give change using largest possible bills first
            for (auto it = count.rbegin(); it != count.rend() && change > 0; ++it) {
                int billValue = it->first;
                int billCount = it->second;

                int numBillsToUse = min(change / billValue, billCount);
                change -= numBillsToUse * billValue;
                it->second -= numBillsToUse; // remove used bills
            }

            if (change != 0) return false; // Can't give proper change
        }

        return true; // Change successfully given to all customers
    }
};
