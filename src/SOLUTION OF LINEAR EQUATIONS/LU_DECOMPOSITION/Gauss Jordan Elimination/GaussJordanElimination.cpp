#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define EPS (ld)(1e-12)
bool gaussJordan(vector<vector<ld> > &A, vector<ld> &B, vector<ld> &x)
{
    int n = A.size();
    // [A | B]
    // Forward elimination
    // Canonical form
    for(int i = 0; i < n; i++)
    {
        // Pivoting : find row with max A[row][i]
        int pivot = i;
        for(int row = i + 1; row < n; row++)
        {
            if(fabs(A[row][i]) > fabs(A[pivot][i])) pivot = row;
        }
        if(pivot != i)
        {
            swap(A[i], A[pivot]);
            swap(B[i], B[pivot]);
        }
        // check for zero pivot
        if(fabs(A[i][i]) < EPS) return false;
        // make pivot = 1
        ld pivotval = A[i][i];
        for(int j = 0; j < n; j++) A[i][j] /= pivotval;
        B[i] /= pivotval;
        // Eliminate all other entries in this column
        for(int row = 0; row < n; row++)
        {
            if(row == i) continue;
            ld factor = A[row][i];
            for(int col = 0; col < n; col++) A[row][col] -= factor * A[i][col];
            B[row] -= factor * B[i];
        }
    }

    // finding solution
    x = B;
    return true;
}
void fun()
{
    int n;

    cin >> n;
    vector<vector<ld> > A(n, vector<ld> (n));
    vector<ld> B(n);

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> A[i][j];

    for(int i = 0; i < n; i++) cin >> B[i];
    vector<ld> x;

    // bool check = gaussianElimination(A, B, x);
    bool check = gaussJordan(A, B, x);

    if(check)
    {
        cout << fixed << setprecision(6) << "Solution is :\n";
        for(auto it : x) cout << it << '\n';
        cout << "Augmented Mstrix:\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) cout << A[i][j] << ' ';
            cout << B[i] << '\n';
        }
    }
    else
    {
        for(int k = 0; k < n; k++)
        {
            for(int i = k + 1; i < n; i++)
            {
                ld factor = B[k] / B[i];
                for(int j = 0; j < n; j++)
                {
                    if(factor != A[k][j] / A[i][j])
                    {
                        cout << "No solution\n";
                        return;
                    }
                }
            }
        }
        cout << "Infinitely many solutions\n";
    }
}
int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;

    cin >> test;
    for(int i = 1; i <= test; i++)
    {
        cout << "\nTest case : " << i << "...\n\n";
        fun();
    }
}
