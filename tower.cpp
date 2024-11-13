#include <bits/stdc++.h>
using namespace std;
int n;
string ss = " ABC";
vector<stack<int>> v(4);

void move(int root, int des, int size)
{
	if (size != 1)
	{
		move(root, 6 - root - des, n - 1);
		move(root, des, 1);
		move(6 - root - des, des, n - 1);
	}
	else
	{
		v[des].push(v[root].top());
		v[root].pop();
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = n; i >= 1; --i)
		v[1].push(i);
	cin >> n;
	move(1, 3, n);
}