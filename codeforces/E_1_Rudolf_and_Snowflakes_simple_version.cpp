#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
    I thought that i can build an array for number of vertices existed for a particular index, and i'll simply check that. but that
    approach will be wrong as it said atleast once not atmost once, so for a particular k
    the series will

    1 , k+1, k^2+k+1, k^3+k^2+k+1, ..... and if the given input can be expressed as these then it's sorted

    so n can be expressed as 1+k+k^2+k^3+.... = (1-k)^-1, so k = 1 - (1/n); so k >1 and integer

    this assumption was also failed, as this is an infinite GP, and number of vertices should be integer
*/
 
// const int N = 20;

set<ll> st;

void precompute(){

    for(ll k=2;k<=1000;k++){

        ll sum =1+k;

        ll temp =k;
        while(sum<=1e6){


            temp *= k;
            sum += temp;
            st.insert(sum);
        }
    }

}

void solve(){

    // vector<int> a(N+1);

    // for(int i=2;i<=N;i++){
    //     a[i] = (i*(i+1))+1;
    // }

    ll n; cin>>n;






    if(st.count(n)) cout << "YES\n";
    else cout << "NO\n";

    // bool ok = false;

    // for(int i=1;i<=a.size();i++){
    //     if(a[i]==n){
    //         ok = true;
    //         break;
    //     }
    // }

    // if(ok) cout << "YES\n";
    // else cout << "NO\n";

    // vector<int> pre(101);

    // for(int k=1;k<=100;k++){
    //     pre[k] = (k*k) + (k) +1;
    // }

    // bool ok = false;
    // for(int i=1;i<=100;i++){
    //     if(pre[i]==n){
    //         ok=true;
    //         break;
    //     }
    // }

    // (ok) ? cout << "YES\n" : cout << "NO\n";


    




}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    precompute();
    while(t--){
        solve();
    }
    


    return 0;
}