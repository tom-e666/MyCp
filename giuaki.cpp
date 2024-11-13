#include <bits/stdc++.h>
using namespace std;
struct ToaDo
{
    int x, y;
    ToaDo(int a = 0, int b) : x(a), y(b) {}
    friend istream &operator>>(istream &is, ToaDo &td)
    {
        is >> td.x >> td.y;
        return is;
    }
};
struct VoiPhun
{
    ToaDo o;
    int r;
    VoiPhun(ToaDo oo = {}, int rr = 0) : o(oo), r(rr) {}
    friend istream &operator>>(istream &is, VoiPhun &vp)
    {
        is >> vp.o >> vp.r;
        return is;
    }
    friend ostream &operator<<(ostream &os, VoiPhun vp)
    {
        cout << "(x";
        if (vp.o.x > 0)
        {
            cout << "-" << vp.o.x;
        }
        else if (vp.o.x < 0)
        {
            cout << "+" << abs(vp.o.x);
        }
        cout << ")^2+(y";
        if (vp.o.y > 0)
        {
            cout << "-" << vp.o.y;
        }
        else
        {
            cout << "+" << abs(vp.o.y);
        }
        cout << ")^2=";
        cout << vp.r * vp.r;
        return os;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<VoiPhun> v(n);
    for (auto &i : v)
        cin >> i;
    for (auto i : v)
        cout << i << "\n";
}