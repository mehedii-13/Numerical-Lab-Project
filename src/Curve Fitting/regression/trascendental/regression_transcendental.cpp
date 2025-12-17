#include<bits/stdc++.h>
using namespace std;
 
pair<double , double> regression(vector<double>vx , vector<double>vy)
{
    double n = vx.size();
    double sx=0 , sy=0 , sxy=0 ,sx2=0;
    for(int i=0;i<n;i++)
    {
        double nx= exp(vx[i]/4);
        sx+= nx;
        sy+= vy[i];
        sxy+= nx*vy[i];
        sx2+= nx*nx;
    }
    double q = (n* sxy - sx*sy)/ (n *sx2 - sx*sx);
    double p = (sy - q*sx) /n;
    return {p , q};
 
}
 
int main(){
    freopen("input_trans.txt", "r", stdin);
    freopen("output_trans.txt", "w", stdout);
    int n;
    //cout << "Enter number of data points: ";
    cin >> n;
    
    vector<double>vz(n) , vy(n);
    //cout << "Enter z and y values (z y pairs):" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> vz[i] >> vy[i];
    }

    auto [p , q] = regression(vz , vy);
    
    cout << "\nCalculated Parameters:" << endl;
    cout << "p = " << p << "  q = " << q << endl;
    cout << "Equation: y = " << p << " + " << q << "e^(z/4)" << endl;

    double z;
    cout << "\nEnter z to predict: ";
    cin >> z;
    
    double y = p + q * exp(z/4);
    cout << "Estimated y: " << y << endl;
 
}
 