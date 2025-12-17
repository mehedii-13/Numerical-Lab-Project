#include <bits/stdc++.h>
using namespace std;

// factorial function
long long fact(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int main() {

     freopen("input_bw.txt" , "r" , stdin);
    freopen("output_bw.txt" , "w" ,stdout);
    int n;
    //cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

   // cout << "Enter x values (equally spaced):\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    //cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    // Creating backward difference table
    vector<vector<double>> diff(n, vector<double>(n));
    for (int i = 0; i < n; i++) diff[i][0] = y[i];

    // Construct backward difference table
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
        }
    }

    double xp;
    //cout << "Enter value of x to interpolate: ";
    cin >> xp;

    double h = x[1] - x[0];
    double s = (xp - x[n-1]) / h;  // backward uses x_last

    // Newton backward formula
    double yp = y[n-1];  // start with last value
    double term = 1;

    for (int j = 1; j < n; j++) {
        term *= (s + (j - 1));  // s(s+1)(s+2)...
        yp += (term * diff[n-1][j]) / fact(j);
    }

    cout << "Interpolated value at x = " << xp << " is: " << yp << endl;

    return 0;
}
