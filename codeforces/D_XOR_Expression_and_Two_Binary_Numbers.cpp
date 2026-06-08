#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        string s; cin>>s;
        string z; cin>>z;


        ll a1=0,b1=0,c1=0;

        for(int i=0;i<n;i++){
            if(s[i] == '1') a1++;
            if(z[i] == '1') b1++;
            if(s[i]!=z[i]) c1++;
        }

        ll m = (1LL << k)+1;

        ll cntc = m/3, cnta=0, cntb=0;
        if(k%2!=0){
            cnta = cntc;
            cntb = cntc;
        }
        else{
            cnta = cntc +1;
            cntb = cntc +1;

        }

        cout << cnta*a1*(n-a1) + cntb*b1*(n-b1) + cntc*c1*(n-c1) << "\n";

        
    }

    
}