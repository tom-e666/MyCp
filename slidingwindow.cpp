#include <bits-stdc++.h>
using namespace std;
int maximumUniqueSubarray(vector<int>& nums)
{
    // initialize
    int n = nums.size();
    int start = -1;
    int res = INT_MIN;
    unordered_map<int, int> prev;
    vector<int> sum(n, 0);

    sum[0] = nums[0];
    prev[nums[0]] = 0;
    res = sum[0];

    // for loop
    for (int i = 1; i < n; ++i)
    {
        // confirm the start pos
        if (auto it = prev.find(nums[i]);
            it != prev.end())
        { // if do exist
            start = max(start, it->second);
        }
        // calculate the answer;
        sum[i] = sum[i - 1] + nums[i];
        prev[nums[i]] = i;
        //update res
        if (start == -1)
        {
            res = max(res, sum[i]);
        }
        else
        {
            res = max(res, sum[i] - sum[start]);
        }
    }
    return res;
}
int main()
{
    vector<int> nums;
    int x;
    while (cin >> x)
        nums.emplace_back(x);
    cout << maximumUniqueSubarray(nums);
}