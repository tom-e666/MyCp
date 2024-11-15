#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>

// Define ordered_set with pair<int, int>
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    pii arr[n];
    loop(i, 0, n) {
        cin >> arr[i].F >> arr[i].S;
    }

    sort(arr, arr + n, [](const pii &a, const pii &b) -> bool {
        return a.F == b.F ? a.S > b.S : a.F < b.F;
    });

    ordered_set os;
    os.insert({0, -1}); // Initialize with a dummy pair if necessary

    // First task: Counting contained ranges
    loop(i, 0, n) {
        os.insert({arr[i].S, i}); // Insert pair (b, index)
    }
    loop(i, 0, n) {
        int t = os.order_of_key({arr[i].S, i}); // Use {b, index} for unique key
        cout << t << " ";
        os.erase({arr[i].S, i});
    }
    cout << "\n";
    os.clear();

    // Second task: Counting containing ranges
    loop(i, 0, n) {
        os.insert({arr[i].S, i});
    }
    sort(arr, arr + n, [](const pii &a, const pii &b) -> bool {
        return a.F == b.F ? a.S < b.S : a.F > b.F;
    });
    loop(i, 0, n) {
        int t = os.order_of_key({arr[i].S, i});
        cout << os.size() - t-1 << " ";
        os.erase({arr[i].S, i});
    }
}
