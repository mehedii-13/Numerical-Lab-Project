#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> calculateDifferenceTable(int pointCount, const vector<double>& xData, const vector<double>& yData) {
    vector<vector<double>> differenceTable(pointCount, vector<double>(pointCount, 0.0));

    for (int i = 0; i < pointCount; ++i) {
        differenceTable[i][0] = yData[i];
    }

    for (int j = 1; j < pointCount; ++j) {
        for (int i = 0; i < pointCount - j; ++i) {
            double diffTop = differenceTable[i + 1][j - 1] - differenceTable[i][j - 1];
            double diffBottom = xData[i + j] - xData[i];
            differenceTable[i][j] = diffTop / diffBottom;
        }
    }
    return differenceTable;
}

double getInterpolatedValue(double targetValue, int pointCount, const vector<double>& xData, const vector<vector<double>>& differenceTable) {
    double finalValue = differenceTable[0][0];
    double termProduct = 1.0;

    for (int i = 1; i < pointCount; ++i) {
        termProduct *= (targetValue - xData[i - 1]);
        finalValue += differenceTable[0][i] * termProduct;
    }
    return finalValue;
}

double estimateError(double targetValue, int pointCount, const vector<double>& xData, const vector<vector<double>>& differenceTable) {
    int lastIndex = pointCount - 1;
    double errorCoefficient = differenceTable[0][lastIndex];
    
    double termProduct = 1.0;
    for (int i = 0; i < lastIndex; ++i) {
        termProduct *= (targetValue - xData[i]);
    }
    
    return fabs(errorCoefficient * termProduct);
}

void displayTable(int pointCount, const vector<vector<double>>& differenceTable) {
    cout << "\nDifferenceTable:\n\n";
    for (int i = 0; i < pointCount; ++i) {
        for (int j = 0; j < pointCount; ++j) {
            cout << differenceTable[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void processTestCase() {
    int polynomialDegree;
    cin >> polynomialDegree;
    
    int totalPoints = polynomialDegree + 1;
    vector<double> xValues(totalPoints), yValues(totalPoints);

    for (int i = 0; i < totalPoints; ++i) cin >> xValues[i];
    for (int i = 0; i < totalPoints; ++i) cin >> yValues[i];

    double queryX;
    cin >> queryX;

    vector<vector<double>> differenceTable = calculateDifferenceTable(totalPoints, xValues, yValues);
    double result = getInterpolatedValue(queryX, totalPoints, xValues, differenceTable);
    double error = estimateError(queryX, totalPoints, xValues, differenceTable);

    cout << fixed << setprecision(4);
    cout << "n: " << polynomialDegree << "\n";
    
    cout << "x: "; 
    for (auto val : xValues) cout << val << " ";
    cout << "\ny: "; 
    for (auto val : yValues) cout << val << " ";
    cout << "\nX: " << queryX << endl;

    displayTable(totalPoints, differenceTable);

    cout << "Interpolation: " << result << endl;
    cout << "Truncation error: " << error << endl << endl;
}

int main() {
    freopen("input_div.txt", "r", stdin);
    freopen("output_div.txt", "w", stdout);

    processTestCase();
    return 0;
}