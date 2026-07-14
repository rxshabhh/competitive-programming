#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxval = 100000;
const int mxv = 18;
int dp[mxv][mxval+5];

int f(int y){  // y to 0
    if(y==0) return 0;

    return __builtin_popcount(y) + 31 - __builtin_clz(y);

    //  31 - __builtin_clz(y) is same for floor of log(y) base 2

}

void func(){  // precompute func
    for(int v=0;v<mxv;v++){

        for(int i=0;i<=mxval;i++){
            dp[v][i] = 1e9; // intitialization
        }
        int step = (1<<v); // ai should be the multiple of this 

        for(int y=(v==0?1:step);y<=mxval;y+=step){
            dp[v][y] = y+f(y);
        }

        for(int x=mxval-1;x>=1;x--){  // for minimum x and y pair
            dp[v][x] = min(dp[v][x],dp[v][x+1]);
        }
        
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    func();

    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        // int ops =0;

        // for(int val : a){
        //     if(val==1) ops++;

        //     if(val&(val-1) == false){
        //         ops += (val/(1<<val))+1;
        //     }
        //     if(val%2==0){
        //         while(val>1){
        //             ops++;
        //             val/=2;
        //         }

        //         ops++;
        //     }

        //     if(val%2){
        //         ops++;
        //         val--;
        //     }
        // }

        // int cntodd=0;
        // for(int val : a){

        //     if(val%2){
        //         cntodd++;
        //     }
        // }

        // if(cntodd!=0){
        //     ops += cntodd;
        // }

        // else{
        //     for(int val : a){
            

        //         if(val&(val-1) == false){
        //             ops += (val/(1<<val))+1;
        //         }
        //         if(val%2==0){
        //             while(val>1){
        //                 ops++;
        //                 val/=2;
        //             }

        //             ops++;
        //         }

        //         if(val%2){
        //             ops++;
        //             val--;
        //         }
        //     }
        // }




        // cout << ops << "\n";

        ll moves = 2e18;

        for(int v=0;v<mxv;v++){
            ll currcost=0;

            for(int i=0;i<n;i++){
                currcost += dp[v][a[i]]-a[i]; // y+f(y)-x or (y-x)+f(y)
            }

            currcost -= 1ll*(n-1)*v; // extra

            moves = min(moves,currcost);
        }


        cout << moves << "\n";

         
    }

    return 0;
}