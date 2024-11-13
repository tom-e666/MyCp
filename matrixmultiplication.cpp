#include <bits/stdc++.h>
using namespace std;
#define mat vector<vector<int>>
void Resize(mat &a, int m, int n)
{
	a.resize(m, vector<int>(n, 0));
}
void Input(mat &a)
{
	for (auto &line : a)
		for (auto &mem : line)
			cin >> mem;
}
mat mult(const mat &a, const mat &b)
{
	int ma = a.size();
	int na = a[0].size();
	int mb = b.size();
	int nb = b[0].size();
	if (na != mb)
	{
		return mat();
	}
	mat res;
	Resize(res, ma, nb);
	for (int i = 0; i < ma; ++i)
		for (int j = 0; j < nb; ++j)
		{
			int sum = 0;
			for (int k = 0; k < na; ++k)
			{
				sum += a[i][k] * b[k][j];
			}
			res[i][j] = sum;
		}
	return res;
}
void Print(mat &a)
{
	for (auto &line : a)
	{
		for (auto &mem : line)
			cout << mem << " ";
		cout << "\n";
	}
}
int main()
{
	int m, n;
	mat a, b;
	cin >> m >> n;
	Resize(a, m, n);
	Input(a);
	cin >> m >> n;
	Resize(b, m, n);
	Input(b);
	mat c = mult(a, b);
	Print(c);
	return 0;
}