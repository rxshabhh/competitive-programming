#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;

int spf[N];

void sieve(){

    for(int i=1;i<N;i++) spf[i]=i;

    for(int i=2;i*i<N;i++){

        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    
}

void solve(){

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    for(int i=0;i<n;i++){

        int p = a[i];
        while(spf[p]!=p) p++;
        cout<<p<<" ";
    }
    cout<<"\n";


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t; cin>>t;
    while(t--){

        solve();
    }

    return 0;
}