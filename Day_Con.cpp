#include <bits/stdc++.h>
using namespace std;
/*
solution: given Q queries, find optima L,R that sum[L,R] is largest.
split [1,N] into 3 parts: [1,L-1], [L,R], [R+1,N]
we can select the optima L,R by selecting L that [1,L-1] is smallest, given L belongs to (0,x)
and similar to R
code:
implementing DP : DP_L[x] indicate the pos between (0,x) where L=pos is optima
                  DP_R[x] indicate the pos between (y, N) where L=pos is optima
*/
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int n;
    int a[100000+5];
    for(int i=0;i<n;++i) cin>>a[i];
    int l[100000+5];
    int r[100000+5];
    long long sum=0;
    int pos=0;
    for(int i=0;i<n;++i){
        
    }
    
}