#include<bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
    pt(int a=0, int b=0) {
        x = a, y = b;
    }
};

int Size(pt a, pt b) { // diagonal
    return abs(a.x - b.x) * abs(a.y - b.y);
}

bool a[1001][1001];

void color(pt pt1, pt pt2, bool b) { // diagonal
    for (int i = pt1.x; i <= pt2.x; ++i)
        for (int j = pt1.y; j <= pt2.y; ++j)
            a[i][j] = b;
}

int cont(pt pt1, pt pt2) {
    int cnt = 0;
    for (int i = pt1.x; i <= pt2.x; ++i)
        for (int j = pt1.y; j <= pt2.y; ++j)
            if (!a[i][j]) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pt a1, a2, b1, b2, c1, c2;
    cin >> a1.x >> a1.y;
    cin >> a2.x >> a2.y;
    cin >> b1.x >> b1.y;
    cin >> b2.x >> b2.y;
    cin >> c1.x >> c1.y;
    cin >> c2.x >> c2.y;

    color(c1, c2, 1);
    cout << cont(a1, a2) + cont(b1, b2);

    return 0;
}
