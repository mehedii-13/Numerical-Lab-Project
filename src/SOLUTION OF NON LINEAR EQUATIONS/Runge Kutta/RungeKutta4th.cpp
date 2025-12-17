#include <bits/stdc++.h>
using namespace std;
using ld = long double;

// Polynomial derivative function: dy/dx = f(x)
ld dydx(ld x, const vector<ld> &cof) {
    ld sum = 0.0;
    int n = cof.size();
    for (int i = 0; i < n - 1; i++) { // last term is constant
        sum += cof[i] * (n - 1 - i) * powl(x, n - 2 - i);
    }
    return sum;
}

// Runge-Kutta 4th order method (dy/dx = f(x))
ld rungeKutta(ld x0, ld y0, ld xEnd, ld h, const vector<ld> &cof) {
    int n = (int)((xEnd - x0) / h);
    ld y = y0;

    cout << fixed << setprecision(6);
    cout << "Step\t x\t y\n";

    for (int i = 0; i <= n; i++) {
        cout << i << "\t" << x0 << "\t" << y << "\n";
        
        if (i < n) {  // Only update if not at the last step
            ld k1 = h * dydx(x0, cof);
            ld k2 = h * dydx(x0 + h/2.0, cof);
            ld k3 = h * dydx(x0 + h/2.0, cof);
            ld k4 = h * dydx(x0 + h, cof);

            y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
            x0 += h;
        }
    }

    return y;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    for(int tt = 1; tt <= test; tt++)
    {
        
        cout << "\nTest Case " << tt << "...\n\n";
        int degree;
        //    cout << "Enter degree of polynomial: ";
        cin >> degree;
        
        vector<ld> cof(degree + 1);
        //    cout << "Enter coefficients from highest degree to constant:\n";
        for (int i = 0; i <= degree; i++) cin >> cof[i];
        
        ld x0, y0, xEnd, h;
        //    cout << "Enter initial x0, initial y0, final x, and step h:\n";
        cin >> x0 >> y0 >> xEnd >> h;
        
        ld yFinal = rungeKutta(x0, y0, xEnd, h, cof);
        cout << "\nFinal value: y(" << xEnd << ") = " << yFinal << "\n";
    }

    return 0;
}
