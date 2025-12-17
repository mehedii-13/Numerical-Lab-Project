#include<bits/stdc++.h>
using namespace std;
int degree;
vector<double> coeffs;
double func(double x) {
    double result = coeffs[0];
    for (int i = 1; i <= degree; i++) {
        result = result * x + coeffs[i];
    }
    return result;
}
int main() {
    freopen("input_3_8.txt" , "r" , stdin);
    freopen("output_3_8.txt" , "w" ,stdout);
    cout << "Newton's 3/8 Rule for Numerical Integration" << endl;
    cin >> degree;
    coeffs.resize(degree + 1);
    for (int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }
    double lower, upper;
    int n;
    cin >> lower;
    cin >> upper;
    cin >> n;
    if (n % 3 != 0) {
        cout << "Error: 'n' must be a multiple of 3 for Newton's 3/8 Rule." << endl;
        return 1;
    }
    double h = (upper - lower) / n;
    double sum = 0.0;
    sum = func(lower) + func(upper);
    for (int i = 1; i < n; i++) {
        double x = lower + i * h;
        if (i % 3 == 0) {
            // Multiplier is 2 for indices divisible by 3 (3, 6, 9...)
            sum += 2 * func(x);
        } else {
            // Multiplier is 3 for others (1, 2, 4, 5...)
            sum += 3 * func(x);
        }
    }
    // Apply the final 3h/8 factor
    double result = (3 * h / 8) * sum;
    cout << fixed << setprecision(6);
    cout << "The integral value is: " << result << endl;
    return 0;
}
