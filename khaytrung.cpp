#include <bits/stdc++.h>
/*baktrack optimized:
    nếu (abcd..) là một solution thì tất cả hoán vị k! đều là solution
    tìm các đáp án dạng abcd... với a<b<c<d <... và các đáp án có thứ tự(phân biệt được)
    rồi nhân với k!
    abcd.. chưa biết đếm, dùng backtrack để đếm
    a->b->c->d
    hoặc dùng theo cách thông thường? k chuỗi xét
*/
int n, k;
queue<int> q;
void cal()
{
    // solution for the last egg to be laid(a,b,c,d)
    for (int i = 0; i < 4; ++i)
        q.push(1);

    for (int i = 0; i < n; ++i)
    {
        int tmp = 0;
        for (int j = 0; j < 4; ++j)
        {
            tmp += q.front(); // first element is dd
            q.pop();
            q.push(tmp);
        }
    }
}
long long A(int n)
{
    long long res = 1;
    for (int i = 1; i <= n; ++i)
        res *= i;
    return res;
}
using namespace std;
int main()
{

    cin >> n >> k;
    cal();
    long long t = accumulate(q.begin(), q.end(), 0);
    t *= A(n);
    cout << t;
}
