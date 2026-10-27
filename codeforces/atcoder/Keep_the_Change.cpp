#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n; cin>>n;
    vector<ll> a,b;
    vector<string> s;

    ll N=n;
    while(N--){
        ll x,y;
        string st;
        cin>>x>>y>>st;

        a.push_back(x);
        b.push_back(y);
        s.push_back(st);

    }

    ll sum1 =0;
    ll total = 10000;

    for(ll i=0;i<n;i++){
        if(s[i]=="take"){
            sum1+= a[i];
        }
        else{
            sum1+= b[i];
        }
    }

    sum1 = total-sum1; // variable


    ll sum2 = accumulate(a.begin(),a.end(),0ll); // change mila
    sum2 = total - sum2;

    cout << sum2-sum1 << "\n";


    return 0;
}