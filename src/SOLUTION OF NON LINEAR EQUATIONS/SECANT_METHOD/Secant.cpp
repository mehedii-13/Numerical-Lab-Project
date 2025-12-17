#include <bits/stdc++.h>
using namespace std;
int degree;
vector<double> coeffs;
double f(double x) {
    double result = coeffs[0];
    for (int i = 1; i <= degree; i++) {
        result = result * x + coeffs[i];
    }
    return result;
}
double secant(double x0, double x1, double tol = 0.0001, int maxIter = 100) {
    double x2;
    int iter = 0;
    while(abs(x2 - x1) > tol && iter < maxIter) {
        double f0 = f(x0);
        double f1 = f(x1);
        if(f1 - f0 == 0) return NAN;
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        x0 = x1;
        x1 = x2;
        iter++;
    }
    return x2;
}
int main() {
     freopen("input_sec.txt", "r", stdin);
    freopen("output_sec.txt", "w", stdout);
    cin >> degree;
    coeffs.resize(degree + 1);
    for (int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }
    double minRange, maxRange;
    cin >> minRange >> maxRange;
    double step = 0.1;
    double tol = 0.0001;
    vector<double> roots;
    for(double x = minRange; x < maxRange; x += step) {
        double x0 = x;
        double x1 = x + step;
        if(f(x0) * f(x1) <= 0) {
            double root = secant(x0, x1, tol);
            if(!isnan(root)) {
                roots.push_back(root);
            }
        }
    }
    cout << fixed << setprecision(6);
    for(double r : roots)
        cout << r << endl;
    return 0;
}
