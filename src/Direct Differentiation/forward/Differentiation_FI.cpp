#include<bits/stdc++.h>
using namespace std;

double evaluatePolynomial(int degree, vector<double>& coeffs, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coeffs[i] * pow(x, degree - i);
    }
    return result;
}

int main() {
    freopen("input_diff_fwd.txt", "r", stdin);
    freopen("output_diff_fwd.txt", "w", stdout);

    int degree, n;
    double lower, upper, p;
    
    // Input
    cin >> degree;
    vector<double> coeffs(degree + 1);
    for(int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }
    cin >> lower >> upper >> n >> p;

    double h = (upper - lower) / n;
    vector<double> x_val(n + 1);
    vector<vector<double>> diff(n + 1, vector<double>(n + 1));

    for (int i = 0; i <= n; i++) {
        x_val[i] = lower + i * h;
        diff[i][0] = evaluatePolynomial(degree, coeffs, x_val[i]);
    }

    //Forward Difference Table
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    int p_index = -1;
    double min_dist = 1e10;
    for(int i = 0; i <= n; i++) {
        double dist = abs(x_val[i] - p);
        if(dist < min_dist) {
            min_dist = dist;
            p_index = i;
        }
    }

    double first_derivative = 0;

    // Derivative 
    int max_order = min(degree, n - p_index);
    if (max_order >= 1) {
        double term_sum = 0;
        for(int i = 1; i <= max_order; i++) {
            double term = diff[p_index][i] / i;
            if (i % 2 == 0) term_sum -= term; 
            else term_sum += term;            
        }
        first_derivative = (1.0 / h) * term_sum;
    }

    cout << "Point p: " << p << endl;
    cout << "First Derivative: " << fixed << setprecision(6) << first_derivative << endl;

    return 0;
}