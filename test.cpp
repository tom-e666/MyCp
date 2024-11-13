// sample 271 ms submission
// #pragma GCC optimize("03")
// static const int _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#include<bits/stdc++.h>
using namespace std;

class NumArray
{
public:
    vector<int> sgt;
    int n;

    NumArray(vector<int> &nums)
    {
        n = nums.size();
        sgt.resize(2 * n);

        for(int i = 0; i < n; ++i)
        {
            sgt[n + i] = nums[i];
        }

        for(int i = n - 1; i > 0; --i)
        {
            sgt[i] = sgt[i * 2] + sgt[i * 2 + 1];
        }
    }

    void update(int index, int val)
    {
        index += n;
        sgt[index] = val;

        while(index > 1)
        {
            index /= 2;
            sgt[index] = sgt[2 * index] + sgt[2 * index + 1];
        }
    }

    int sumRange(int left, int right)
    {
        left += n;
        right += n;
        int res = 0;

        while(left <= right)
        {
            if(left & 1)
            {
                res += sgt[left];
                    ++left;
            }

            if(!(right & 1))
            {
                res += sgt[right];
                --right;
            }

            left /= 2;
            right /= 2;
        }

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
**/
int main(){
    vector<int> t{1,2,3,4,5};
    NumArray cls(t);
    cout<<cls.sumRange(0,2);
}