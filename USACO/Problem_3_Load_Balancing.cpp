#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);

    int n,b; cin>>n>>b;

    vector<int> x,y;

    int ans=INT_MAX;
    int N=n;
    while(N--){
        int xi,yi; cin>>xi>>yi;
        
        x.push_back(xi);
        y.push_back(yi);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            int a= x[i]+1;
            int b= y[j]+1;

            int topleft=0,topright=0,bottomleft=0,bottomright=0;

            for(int k=0;k<n;k++){
                if(x[k] > a && y[k] > b){
                    topright++;
                }
                else if(x[k] < a && y[k] > b){
                    topleft++;
                }
                else if(x[k] > a && y[k] < b){
                    bottomright++;
                }
                else if(x[k] < a && y[k] < b){
                    bottomleft++;
                }
            }

            int current_max = max({topleft, topright, bottomleft, bottomright});

            ans = min(ans,current_max);
        }
    }

    cout << ans << "\n";
    

    return 0;
}