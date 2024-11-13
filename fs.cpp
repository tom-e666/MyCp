#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int x;
    
    // Input numbers into the vector
    while (cin >> x) {
        v.emplace_back(x);
    }
    
    // Sort the vector
    sort(begin(v), end(v));
    
    vector<string> res;
    int n = v.size();
    
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && v[i + 1] == v[i]) {
            // If the next element is equal to the current one, merge them
            if (res.empty()) {
                res.push_back(to_string(v[i]) + " " + to_string(v[i + 1]));
            } else {
                res.back() += " " + to_string(v[i + 1]);
            }
            i++;
        } else {
            // Otherwise, add the current element to the result vector
            res.push_back(to_string(v[i]));
        }
    }
    
    // Define the comparison lambda function
    auto cmp = [](const string& x, const string& y) -> bool {
        int r1 = accumulate(begin(x), end(x), 0, [](int sum, char c) { return sum + (c - '0'); });
        int r2 = accumulate(begin(y), end(y), 0, [](int sum, char c) { return sum + (c - '0'); });
        return r1 < r2;
    };
    
    // Find the element with the maximum sum of digits
    auto maxElem = *max_element(begin(res), end(res), cmp);
    
    // Output the result
    cout << maxElem << endl;

    return 0;
}
