#include <vector>
#include <queue>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canTransform(vector<int>& initial, vector<int>& target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        priority_queue<int> pq(target.begin(), target.end());
        long long sum = accumulate(target.begin(), target.end(), 0LL);

        // Calculate initial sum for comparison
        long long initialSum = accumulate(initial.begin(), initial.end(), 0LL);

        // Initial array length must match the target array length
        if (initial.size() != target.size()) {
            return false;
        }

        while (true) {
            int curr = pq.top();
            pq.pop();
            sum -= curr;

            // If the current number matches the corresponding initial array element, continue
            if (find(initial.begin(), initial.end(), curr) != initial.end()) {
                continue;
            }

            // If the remaining sum is 0 or curr is less than or equal to remaining sum, return false
            if (curr <= sum || sum < 1) {
                return false;
            }

            // Calculate next value to push into the heap
            int next = curr % sum;

            // If next is 0 or next matches initial array element, continue
            if (next == 0 || find(initial.begin(), initial.end(), next) != initial.end()) {
                return false;
            }

            // Update the sum and push the new value into the heap
            sum += next;
            pq.push(next);
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> initial = { 1, 2, 3 }; // Example initial array
    vector<int> target = { 9, 3, 5 };  // Example target array

    bool result = sol.canTransform(initial, target);
    cout << (result ? "Possible" : "Impossible") << endl;

    return 0;
}
