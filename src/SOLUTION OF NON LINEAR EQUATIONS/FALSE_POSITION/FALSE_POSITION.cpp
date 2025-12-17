#include <bits/stdc++.h>
#define ld long double
using namespace std;
ld f(ld x, const vector<ld> &cof) {
    ld sum = 0.0;
    int n = cof.size();
    for (int i = 0; i < n; i++)
        sum += cof[i] * powl(x, n - 1 - i);
    return sum;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        cout << "Test Case : " << tt << "...\n\n";
        int degree;
        cin >> degree;
        vector<ld> cof(degree + 1);
        for (int i = 0; i <= degree; i++)
            cin >> cof[i];
        ld a, b, E;
        cin >> a >> b >> E;
        ld fa = f(a, cof);
        ld fb = f(b, cof);
        if (fa * fb >= 0) {
            cout << "Invalid initial guesses. f(a) and f(b) must have opposite signs.\n\n";
            continue;
        }
        cout << setw(10) << "Iteration"<< setw(15) << "a"<< setw(15) << "b"<< setw(15) << "c"<< setw(20) << "f(c)" << endl;
        ld c, fc;
        int iter = 0;
        do {
            c = (a * fb - b * fa) / (fb - fa);
            fc = f(c, cof);
            cout << setw(10) << ++iter<< setw(15) << fixed << setprecision(6) << a<< setw(15) << b<< setw(15) << c<< setw(20) << fc << endl;
            if (fa * fc < 0) {
                b = c;
                fb = fc;
            } else {
                a = c;
                fa = fc;
            }
        } while (fabsl(fc) > E);
        cout << "\nRoot is approximately: " << c << endl;
        cout << "Total iterations: " << iter << "\n\n";
    }
    return 0;
}
