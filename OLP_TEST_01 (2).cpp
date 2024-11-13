#include <iostream>
#include <vector>

using namespace std;

long long minAbsDiffSum(vector<vector<int>>& matrix, int m, int n, long long A, long long B) {
    long long left = min(A, B);
    long long right = max(A, B);
    
    while (left < right) {
        long long mid = (left + right) / 2;
        long long sumA = 0, sumB = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                long long diff = matrix[i][j] - mid;
                sumA += abs(diff - A);
                sumB += abs(diff - B);
            }
        }
        
        if (sumA <= sumB) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return min(abs(left - A) + abs(left - B), abs(right - A) + abs(right - B));
}

int main() {
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
    int m, n;
    long long A, B;
    
    cin >> m >> n >> A >> B;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    long long result = minAbsDiffSum(matrix, m, n, A, B);
    
    cout << result << endl;
    
    return 0;
}
