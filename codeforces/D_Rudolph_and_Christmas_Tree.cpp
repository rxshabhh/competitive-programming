#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        double d,h; cin>>d>>h;

        vector<double> y(n); for(auto &x : y) cin>>x;

        double total_area = 0.5*n*d*h;

        double overlap_area =0;

        for(int i=1;i<n;i++){

            if((y[i]-y[i-1])<h){



                double h1= h- (y[i]-y[i-1]);
                double d1 = d*(h1/h);
                overlap_area += (0.5*h1*d1);
            }

        }

        cout << setprecision(15) << total_area - overlap_area << "\n";
    }

    return 0;
}