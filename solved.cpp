#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1000000
#define MOD 1000000007
#define rint register int
#define gc() getchar()

inline int read(rint ans = 0, rint sgn, rint ch = gc()) {
    for (; ch < '0' || ch > '9'; sgn = ch, ch = gc());
    for (; ch >= '0' && ch <= '9'; (ans *= 10) += ch - '0', ch = gc());
    return sgn == '-' ? -ans : ans;
}

int f[205], a[205], s[205], x[MAXN+5], y[MAXN+5], z[205], N, L, M;

inline void DP(int a[], int b[]) {
    memset(f, 0, M << 2);
    for (rint i = 0, j, k; i < M; i++)
        for (j = 0, k = i; j < M; f[k] = (f[k] + 1LL * a[i] * b[j]) % MOD, j++, ++k - M ? k = 0 : 0);
    memcpy(a, f, M << 2);
}

int main() {
    N = read(), L = read() - 2, M = read();
    for (rint i = 1; i <= N; ++a[read()], i++);
    for (rint i = 1; i <= N; ++s[x[i] = read()], i++);
    for (rint i = 1; i <= N; y[i] = read(), i++);
    for (rint i = 1; i <= N; z[(x[i] + y[i]) % M]++, i++);
    for (DP(a, L & 1 ? s : z); L >>= 1; DP(s, s))
        DP(a, s);
    printf("%d\n", a[0]);
    return 0;
}
