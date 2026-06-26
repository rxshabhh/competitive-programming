#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n,k,b,s; cin>>n>>k>>b>>s;

        vector<ll> a(n);

        if(s < (1LL*b*k) || s>((1LL*b*k)+(k-1)*n*1LL)){
            cout << -1 << "\n";
            continue;
        }

        else{

            a[0] = 1LL*b*k;

            ll diff = (s-a[0]);
            for(int i=0;i<n && diff>0;i++){

                
                ll add  = min(k-1LL,diff);
                a[i] += add;
                diff -= add;
                

            
            }


        }

        for(auto val : a){
            cout << val << " ";
        }
        cout << "\n";



    }


    return 0;
}