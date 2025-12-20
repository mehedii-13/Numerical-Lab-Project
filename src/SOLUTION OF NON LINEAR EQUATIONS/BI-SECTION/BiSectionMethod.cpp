#include<bits/stdc++.h>
using namespace std;

int degree;
vector<double> coeffs;

//polynomial
float find(float x){
    double result = coeffs[0];
    for (int i = 1; i <= degree; i++) {
        result = result * x + coeffs[i];
    }
    return result;
}

float biSection(float x, float y){
    if (find(x) == 0) return x;
    if (find(y) == 0) return y;

    if(find(x) * find(y) > 0) return -1; 

    float p;
    while(abs(y - x) > 0.0001){ 
        p = (x + y) / 2;
        float val = find(p);
        
        if (val == 0) return p;

        if(val * find(x) < 0) 
            y = p;
        else 
            x = p;
    }
    return (x + y) / 2;
}

int main() {

    freopen("input_bs.txt" , "r" , stdin);
    freopen("output_bs.txt" , "w" ,stdout);

    cout << "Bisection Method for Root Finding " << endl;

    cin >> degree;
    if (degree < 1) return 1;

    coeffs.resize(degree + 1);
    for (int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }

    float min_range, max_range;
    cin >> min_range >> max_range;

    set<float> roots;
    float step = 0.1;

    for (float x = min_range; x < max_range; x += step) {
        float x1 = x;
        float x2 = x + step;

        if (find(x1) * find(x2) <= 0) {
            float result = biSection(x1, x2);
            if (result != -1) {
                float rounded = round(result * 10000) / 10000;
                roots.insert(rounded);
            }
        }
    }

    if (roots.empty()) {
        cout << "No roots found." << endl;
    } else {
        cout << "Found " << roots.size() << " root(s):" << endl;
        for (auto r : roots) {
            cout << fixed << setprecision(6) << r << endl;
        }
    }
}