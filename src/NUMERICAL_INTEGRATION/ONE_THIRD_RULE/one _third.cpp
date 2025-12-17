#include <bits/stdc++.h>
using namespace std;
int degree;
vector<double> coeffs;
double f(double x)
{
    double result = coeffs[0];
    for (int i = 1; i <= degree; i++) {
        result = result * x + coeffs[i];
    }
    return result;
}
int main() {
    freopen("input1_3.txt", "r", stdin);
    freopen("output1_3.txt", "w", stdout);
    cin >> degree;
    coeffs.resize(degree + 1);
    for (int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }
    double a, b;
    cin >> a;
    cin >> b;
    int n;
    cin >> n;
    if (n % 2 != 0) {
        cout << "\nError: Number of intervals (n) must be even for Simpson's 1/3 Rule." << endl;
        cout << "You entered n = " << n << endl;
        return 1;
    }
    double h = (b - a) / n;
    double sumev = 0, sumodd = 0;
    vector<double> x(n+1), y(n+1);
    x[0] = a;
    y[0] = f(a);
    for(int i = 1; i <= n; i++)
    {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    for(int i = 1; i < n; i++)
    {
        if(i % 2 == 0)
            sumev += y[i];
        else
            sumodd += y[i];
    }
    double finalval = (h / 3.0) * ((y[0] + y[n]) + 4 * sumodd + 2 * sumev);
    cout << "Simpson's 1/3 Rule Integration" << endl;
    cout << "Integration value: " << fixed << setprecision(6) << finalval << endl;
    return 0;
}
