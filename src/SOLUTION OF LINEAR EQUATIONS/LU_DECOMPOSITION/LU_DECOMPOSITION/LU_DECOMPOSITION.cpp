#include <bits/stdc++.h>
using namespace std;
void displayMatrix(const vector<vector<double>> &matrix, string matrixName) {
    cout << "\nCurrent state of " << matrixName << " matrix:\n";
    for (auto &row : matrix) {
        for (auto val : row)
            cout << setw(10) << fixed << setprecision(4) << val << " ";
        cout << "\n";
    }
    cout << "---------------------------------------------\n";
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;
    cin >> test;
    for(int tt = 1; tt <= test; tt++)
    {
        cout << "Test Case : " << tt << "...\n\n";
        int n;
        cout << "Enter number of equations: ";
        cin >> n;
        vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
        cout << "Enter the augmented matrix (coefficients + constants):\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++)
                cin >> augmentedMatrix[i][j];
        // Separate coefficient matrix and constants
        vector<vector<double>> coeffMatrix(n, vector<double>(n));
        vector<double> constants(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                coeffMatrix[i][j] = augmentedMatrix[i][j];
            constants[i] = augmentedMatrix[i][n];
        }
        vector<vector<double>> lowerTri(n, vector<double>(n, 0));
        vector<vector<double>> upperTri(n, vector<double>(n, 0));
        cout << "\nPerforming LU Decomposition...\n";
        for (int i = 0; i < n; i++) {
            // Compute upper triangular matrix
            for (int j = i; j < n; j++) {
                double sum = 0;
                for (int k = 0; k < i; k++)
                    sum += lowerTri[i][k] * upperTri[k][j];
                upperTri[i][j] = coeffMatrix[i][j] - sum;
            }
            // Compute lower triangular matrix
            for (int j = i; j < n; j++) {
                if (i == j)
                    lowerTri[i][i] = 1; // diagonal element
                else {
                    double sum = 0;
                    for (int k = 0; k < i; k++)
                        sum += lowerTri[j][k] * upperTri[k][i];

                    if (fabs(upperTri[i][i]) < 1e-9) {
                        cout << "\nZero pivot encountered — system may have no or infinite solutions.\n";
                        return 0;
                    }
                    lowerTri[j][i] = (coeffMatrix[j][i] - sum) / upperTri[i][i];
                }
            }
            displayMatrix(lowerTri, "L");
            displayMatrix(upperTri, "U");
        }
        // Check determinant (product of diagonal elements of U)
        double determinant = 1;
        for (int i = 0; i < n; i++)
            determinant *= upperTri[i][i];
        if (fabs(determinant) < 1e-9) {
            cout << "\nDeterminant = 0 → No unique solution (infinite or none).\n";
            return 0;
        }
        cout << "\nLU Decomposition completed successfully!\n";
        displayMatrix(lowerTri, "Final L");
        displayMatrix(upperTri, "Final U");
        // Forward substitution: L*y = constants
        vector<double> intermediate(n);
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += lowerTri[i][j] * intermediate[j];
            intermediate[i] = constants[i] - sum;
        }
        cout << "\nForward Substitution (L*y = b):\n";
        for (int i = 0; i < n; i++)
            cout << "y" << i + 1 << " = " << intermediate[i] << "\n";
        // Back substitution: U*x = intermediate
        vector<double> solution(n);
        for (int i = n - 1; i >= 0; i--) {
            double sum = 0;
            for (int j = i + 1; j < n; j++)
                sum += upperTri[i][j] * solution[j];
            solution[i] = (intermediate[i] - sum) / upperTri[i][i];
        }
        cout << "\nBack Substitution (U*x = y):\n";
        cout << "Solution Vector (x):\n";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << solution[i] << "\n";
    }
    return 0;
}

