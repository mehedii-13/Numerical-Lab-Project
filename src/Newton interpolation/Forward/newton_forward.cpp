 #include <bits/stdc++.h>
using namespace std;

long long fact(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int main() {
     freopen("input_fw.txt" , "r" , stdin);
    freopen("output_fw.txt" , "w" ,stdout);
    int n;
    //cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    //cout << "Enter x values (equally spaced):\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    //cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    // Difference table
    vector<vector<double>> diff(n, vector<double>(n));
    for (int i = 0; i < n; i++) diff[i][0] = y[i];

    // forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }

    double xp;
    //cout << "Enter the value of x to interpolate: ";
    cin >> xp;

    double h = x[1] - x[0];      
    double s = (xp - x[0]) / h; 

    //  Newton forward formula
    double yp = y[0];
    double term = 1;

    for (int j = 1; j < n; j++) {
        term *= (s - (j - 1)); 
        yp += (term * diff[0][j]) / fact(j);
    }

    cout << "Interpolated value at x = " << xp << " is: " << yp << endl;
    return 0;
}

