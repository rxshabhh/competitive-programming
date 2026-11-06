#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx = 100005+5;
int a[mx];
int pre[mx];
int suff[mx];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;

    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    pre[0]=0;
    suff[n+1]=0;

    for(int i=1;i<=n;i++){
        pre[i] = __gcd(pre[i-1],a[i]);
    }

    for(int i=n;i>=1;i--){
        suff[i] = __gcd(suff[i+1],a[i]);
    }

    int res = 0;

    for(int i=1;i<=n;i++){
        res =max(res,__gcd(pre[i-1],suff[i+1]));
    }

    cout << res <<"\n";


    return 0;
}