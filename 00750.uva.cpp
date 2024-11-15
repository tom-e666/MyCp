#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
struct solver
{
    vector<string> res;
    int position[9];
    bool urow[9], diag1[18], diag2[18];
    int uc;

    void Try(int c)
    {
        if (c == 9)
        {
            string sr;
            for (int i = 1; i <= 8; ++i)
            {
                sr += to_string(position[i]) + " ";
            }
            if(sr.size()) sr.pop_back();
            res.push_back(sr); // Store the solution
            return;
        }
        if (c == uc) // Skip column if it's the predefined column
        {
            Try(c + 1);
            return;
        }
        loop(r, 1, 9)
        {
            if (!urow[r] && !diag1[r + c] && !diag2[r - c + 8])
            {
                urow[r] = true;
                diag1[r + c] = true;
                diag2[r - c + 8] = true;
                position[c] = r;
                Try(c + 1);
                urow[r] = false;
                diag1[r + c] = false;
                diag2[r - c + 8] = false;
            }
        }
    }

    solver()
    {
        fill(position, position + 9, -1);
        fill(urow, urow + 9, false);
        fill(diag1, diag1 + 18, false);
        fill(diag2, diag2 + 18, false);
    }

    void solve(int a, int b)
    {
        urow[a] = true;
        uc = b;
        position[b] = a;
        diag1[a + b] = true;
        diag2[a - b + 8] = true;
        Try(1);
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ts;
    cin >> ts;
    int a, b;

    while (ts--)
    {
        cin >> a >> b;
        solver sl;
        sl.solve(a, b);
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n\n";
        int t=(sl.res.size()>9?9:sl.res.size());
        	loop(i, 0, t)
        		cout <<" "<<i+1<< "      " << sl.res[i] << "\n";
        if(sl.res.size()>8)
        	loop(i, 9, sl.res.size())
        	{
            	cout <<i+1<< "      " << sl.res[i] << "\n";
        	}
        if(ts!=0)
        {
        	cout<<"\n";
        }

    }

    return 0;
}
