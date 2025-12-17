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

double f_prime(double x) {
    double result = degree * coeffs[0];
    for (int i = 1; i < degree; i++) {
        result = result * x + (degree - i) * coeffs[i];
    }
    return result;
}

int main() {
    freopen("input_nr.txt" , "r" , stdin);
    freopen("output_nr.txt" , "w" ,stdout);
    cout << "Newton-Raphson Method for Root Finding" << endl;

    
    //cout << "\nEnter the degree of polynomial: ";
    cin >> degree;
    
    if (degree < 1) {
        cout << "Error: Degree must be at least 1." << endl;
        return 1;
    }
    
    coeffs.resize(degree + 1);
    //cout << "Enter " << (degree + 1) << " coefficients (from a_" << degree << " to a_0):" << endl;
    for (int i = 0; i <= degree; i++) {
        //cout << "Coefficient a_" << (degree - i) << ": ";
        cin >> coeffs[i];
    }
    
    double x0;       
    double tol;     
    int max_iter;   
    //cout << "\nEnter initial guess: ";
    cin >> x0;
    //cout << "Enter tolerance: ";
    cin >> tol;
    //cout << "Enter maximum iterations: ";
    cin >> max_iter;

    double x1;
    int iter = 0;


    while (iter < max_iter) {
        double fx = f(x0);
        double fpx = f_prime(x0);
        
        if (fabs(fpx) < 1e-10) {
            cout << "Error: Derivative too close to zero. Method fails." << endl;
            return 1;
        }
        
        x1 = x0 - fx / fpx;

        cout << "Iteration " << (iter + 1) << ": x = " << x1 << endl;

        if (fabs(x1 - x0) < tol) {
            break;
        }
        x0 = x1;
        iter++;
    }

    cout << "Root = " << x1 << endl;
    cout << "Iterations = " << iter + 1 << endl;

    return 0;
}
