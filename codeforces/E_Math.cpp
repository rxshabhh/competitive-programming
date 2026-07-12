#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mxval = 1000005;
vector<int> spf(mxval+1,0);


// binary tree?
// dp? I tried greedy here



// ll makesquare(ll x){

//     ll n =x;

//     ll y=1;

//     for(ll p=2;p*p<=n;p++){
//         ll cnt =0;
//         while(x%p==0){
//             x/=p;
//             cnt++;
//         }

//         if(cnt&1){
//             y*=p;
//         }
//     }

//     if(x>1){
//         y*=x;
//     }

//     return n*y;
// }

// ll countdiv(ll n){

//     ll ans =1;
//     for(ll i=2;i*i<=n;i++){

//         int cnt=0;
//         while(n%i==0){
//             n/=i;
//             cnt++;
//         }

//         ans *= (cnt+1);
//     }

//     if(n>1) ans*= 2;
//     return ans;
// }

// bool perfect(ll x){

//     if(countdiv(x)%2==0){
//         return false;
//     }
//     return true;
// }


void sieve(){
    for(int i=1;i<=mxval;i++){
        spf[i]=i;
    }

    for(int i=2;i*i<=mxval;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=mxval;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    

    // ll ops=0;

    // ll mn =n;
    // set<ll> vis;

    // while(!vis.count(n)){
    //     vis.insert(n);

    //     mn = min(mn,n);

    //     if(perfect(n)){
    //         ops++;
    //         n = sqrt(n);
            
    //     }
    //     else{
    //         ops++;
    //         n = makesquare(n);
            
    //     }
    // }

    // cout << mn << " " << ops <<"\n";

    ll n; cin>>n;

    if(n==1){
        cout << 1 << " " << 0 << "\n";
        return 0;
    }



    map<int ,int> fact; // (factor : exponent) store like this

    ll x =n;
    while(x!=1){
        fact[spf[x]]++; // count the exponents
        x/=spf[x];
    }

    ll minval =1;
    int mxexpo =0;

    for(auto const& it : fact) {
        int prime = it.first;
        int expo = it.second;
        
        minval *= prime;
        mxexpo = max(mxexpo, expo);
    }

    int target_expo =1;
    int sqrt_ops=0;

    while(target_expo < mxexpo){
        target_expo *= 2;
        sqrt_ops++;
    }

    bool need = false;

    for(auto const& it : fact) {
        if(it.second != target_expo) {
            need = true;
            break;
        }
    }

    int ops = need + sqrt_ops;

    cout << minval << " " << ops << "\n";



    




    return 0;
}