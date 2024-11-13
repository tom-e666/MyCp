#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int>& v, int l, int r) {
    int i = l, j = r;
    if (l >= r) return;
    while (i <= j) {
        int m = l + (r - l) / 2;
        int x = v[m];
        while (v[i] < x) i++;
        while (v[j] > x) j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    for (int k = 0; k < v.size(); k++) cout << v[k] << " ";
    cout << endl;
    quicksort(v, l, j);
    quicksort(v, i, r);
}
void quicksortIterative(std::vector<int>& nums) {
    if (nums.empty()) return;

    int low = 0;
    int high = nums.size() - 1;

    std::stack<std::pair<int, int>> stack;
    stack.push({ low, high });

    while (!stack.empty()) {
        auto [start, end] = stack.top();
        stack.pop();

        if (start < end) {
            int pivot = nums[end];
            int pIndex = start;

            for (int i = start; i < end; i++) {
                if (nums[i] <= pivot) {
                    std::swap(nums[i], nums[pIndex]);
                    pIndex++;
                }
            }
            std::swap(nums[pIndex], nums[end]);

            stack.push({ start, pIndex - 1 });
            stack.push({ pIndex + 1, end });
        }
    }
}

int main() {
    vector<int> v;
    int x;
    while (cin >> x) {
        v.push_back(x);
    }
    quicksortIterative(v);
    for (auto i : v) cout << i << " ";

    return 0;
}
