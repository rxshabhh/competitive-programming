#include <bits/stdc++.h>
using namespace std;

typedef long long ll;




int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n; cin>>n;
    vector<ll> a(n); for(auto &x : a) cin>>x;

    ll g=0;

    for(auto val : a){
        g = __gcd(g,val);
        
    }

    for(auto &x : a){
        x /= g;
    }

    

    ll MAX = *max_element(a.begin(),a.end());

    // to remove tle

    // whenever tle occurs, try to pre-compute things

    vector<ll> spf(MAX+1);

    for(int i=0;i<=MAX;i++){

        spf[i]=i;

    }

    for(int i=2;1LL*i*i<=MAX;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=MAX;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }


    vector<ll> freq(MAX+1);

    

    for(auto val : a){

        //ll k = val;

        // tle on 10th test case because of this
        // for(ll p=2;p*p<=k;p++){
        //     if(k%p==0){
        //         freq[p]++;
            

        //         while(k%p==0){
        //             k/=p;
        //         }
        //     }
        // }

        //if(k>1) freq[k]++;

        while(val>1){
            int p = spf[val];
            freq[p]++;

            while(val%p==0){
                val/=p;
            }
        }
    }

    ll mx =0;

    for(ll i=2;i<=MAX;i++){
        mx = max(mx,freq[i]);
    }

    if(mx==0){
        cout << -1<<"\n";
    }
    else cout << n-mx<<"\n";



    // wrong test case on 4
    //int cnt =0;


    // int g1 =0;
    // int ans =0;
    
    // for(int i=max;i>=1;i--){

    //     int cnt =0;
        
    //     for(int d=i;d<=max;d+=i){
    //         cnt += freq[d];
    //     }

    //     if(cnt>=2){
    //         g1 = i;
    //         ans = cnt;
    //         break;
    //     }
    // }

    // int c1=0;
    // for(int val : a){
    //     if(val==1) c1++;
    // }

    // if(c1>0){
    //     ans = c1;
    // }




    // if(g==g1){
    //     cout << -1 << "\n";
    // }
    // else{
    //     cout << ans << '\n';
    // }



    return 0;
}