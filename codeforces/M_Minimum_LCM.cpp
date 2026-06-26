#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkprime(ll x){

    if(x==1) return false;

    bool ok = true;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            ok = false;
            break;
        }
    }

    return ok;
}


ll func(ll x){

    if(x%2==0) return 2;
    for(ll i=3;i*i<=x;i+=2){
        if(x%i==0) return i;
    }

    return x;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n; cin>>n;

        ll a,b;
        
        if(checkprime(n)){
            a = 1;
            b =n-1;
        }
        else{

            ll p = func(n);
            a = n/p;
            b = n -(n/p);
            
        }

        cout << a << " " << b << "\n";


    }

    return 0;
}