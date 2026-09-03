#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans[11];

void solve(int curr, int rem, int n, int k){

    if(n==curr){

        if(rem % curr==0){
            ans[curr] = (rem/curr);

            for(int i=1;i<=n;i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }

        return;
    }

    for(int i=0;i*curr<=rem;i++){

        ans[curr] = i;
        solve(curr+1,rem-(i*curr),n,k);
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;

    solve(1,k,n,k);

    

    

    return 0;
}