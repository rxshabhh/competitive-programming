#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// binary tree?
// dp? I tried greedy here



ll makesquare(ll x){

    ll n =x;

    ll y=1;

    for(ll p=2;p*p<=n;p++){
        ll cnt =0;
        while(x%p==0){
            x/=p;
            cnt++;
        }

        if(cnt&1){
            y*=p;
        }
    }

    if(x>1){
        y*=x;
    }

    return n*y;
}

ll countdiv(ll n){

    ll ans =1;
    for(ll i=2;i*i<=n;i++){

        int cnt=0;
        while(n%i==0){
            n/=i;
            cnt++;
        }

        ans *= (cnt+1);
    }

    if(n>1) ans*= 2;
    return ans;
}

bool perfect(ll x){

    if(countdiv(x)%2==0){
        return false;
    }
    return true;
}




int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;

    ll ops=0;

    ll mn =n;
    set<ll> vis;

    while(!vis.count(n)){
        vis.insert(n);

        mn = min(mn,n);

        if(perfect(n)){
            ops++;
            n = sqrt(n);
            
        }
        else{
            ops++;
            n = makesquare(n);
            
        }
    }

    cout << mn << " " << ops <<"\n";



    return 0;
}