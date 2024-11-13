#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        a[i] = 1LL * i * i * (i * i - 1) / 2 - 4LL * (i - 1) * (i - 2);
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << "\n";
    }

    return 0;
}
