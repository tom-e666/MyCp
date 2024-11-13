#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    //idea is wrong.
   //sliding window
    string input;
    cin >> input;
    int n = input.size();
    int res = INT_MIN;
    unordered_map<char, int> last_occupance;
    last_occupance['A'] = -1;
    last_occupance['C'] = -1;
    last_occupance['G'] = -1;
    last_occupance['T'] = -1;
    int start = 0;
    for (int i = 0;i < n;++i) {
        int last = last_occupance[input[i]];
        if (last >= start) {
            //unsafe
            start = last + 1;
        }
        //update
        res = max(res, i - start + 1);
        last_occupance[input[i]] = i;
    }
    cout << res;
    return 0;
}