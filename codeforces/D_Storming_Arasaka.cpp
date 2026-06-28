#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkprime(ll n){
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
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

    if(n>1 ) ans*=2;
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    
    int t;cin>>t;
    while(t--){

        ll n; cin>>n;

        vector<ll> div;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0 && i!=1){
                div.push_back(i);
                if(i!=(n/i)&&((n/i)!=1)) div.push_back(n/i);
            }
        }


        
        ll temp=n;
        ll sum =0;
        ll x=0;
        for(ll i=2;i*i<=temp;i++){
            if(temp%i==0){
                x++;
                while(temp%i==0){
                    temp/=i;
                    sum++;
                }
            }
        }

        if(temp>1){
            x++;
            sum++;
        }

        cout << x+sum-1 <<"\n";






    }

    return 0;
}