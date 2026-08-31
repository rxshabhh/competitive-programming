#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double func(int a,int b, int c, int d){
    double ans = 0.000000000;

    double xx = (c-a);
    xx *= xx;

    double yy = (d-b);
    yy *= yy;

    double r = xx + yy;
    ans = sqrt(r);

    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){

        int xa,ya,xb,yb; cin>>xa>>ya>>xb>>yb;
        int n; cin>>n;

        int N=n;
        vector<pair<int,int>> v(n);

        while(N--){
            int x,y; cin>>x>>y;
            v.push_back({x,y});
        }

        double mn = INT_MAX;

        for(int i=0;i<n;i++){
            int it1 = v[i].first;
            int it2 = v[i].second;
            double res = max(res, func(xa,ya,it1,it2));

            mn = min(mn,res);
        }

        for(int i=0;i<n;i++){
            int it1 = v[i].first, it2 = v[i].second;

            double res1 = max(res1, func(xb,yb,it1,it2));

            mn = min(mn,res1);
        }

        cout << mn << "\n";



    }

    return 0;
}