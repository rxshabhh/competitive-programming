#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> p(n),q(n); 
    for(auto &x : p) cin>>x;

    for(auto &x : q) cin>>x;

    int cnt =0;

    if(p<q){
        next_permutation(p.begin(),p.end());

        while(p<q){
            cnt++;

            next_permutation(p.begin(),p.end());
        }
    }

    cout << cnt << "\n";

    

    

    return 0;
}