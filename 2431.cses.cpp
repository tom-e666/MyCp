#include <bits/stdc++.h>
using namespace std;

long long pow10(int length) {
    long long result = 1;
    while (--length > 0) {
        result *= 10;
    }
    return result;
}

char query(long long x) {
    long long length = 1;
    long long count = 9;
    while (x > length * count) {
        x -= length * count;
        length++;
        count *= 10;
    }
    
    long long start = pow10(length);
    long long number = start + (x - 1) / length;
    string s = to_string(number);
    return s[(x - 1) % length];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        cout << query(x) << "\n";
    }

    return 0;
}
