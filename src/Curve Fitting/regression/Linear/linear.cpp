#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input_lin.txt" , "r" , stdin);
    freopen("output_lin.txt" , "w" ,stdout);
    int n;
    //cout << "Enter number of data points: ";
    cin >> n;
    vector<double> x(n), y(n);
    //cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];
    //cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    cout << "i\t x\t  y\t  xy\t   x^2\n";
    for (int i = 0; i < n; i++) {
        double xy = x[i] * y[i];
        double x2 = x[i] * x[i];
        cout << i+1 << "\t "
             << x[i] << "\t  "
             << y[i] << "\t  "
             << xy << "\t   "
             << x2 << endl;
        sumX += x[i];
        sumY += y[i];
        sumXY += xy;
        sumX2 += x2;
    }
    cout << "\nsum x   = " << sumX;
    cout << "\nsum y   = " << sumY;
    cout << "\nsum xy  = " << sumXY;
    cout << "\nsum x(square) = " << sumX2 << endl;

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;
    cout << "\nRegression Line: y = " << a << " + " << b << "x\n";
    return 0;
}