#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// divisor trick for maximum gcd calculation

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;

        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            a[i] = i;
        }

        vector<int> freq(n+1,0);

        for(int val : a){
            freq[val]++;
        }

        for(int g =(n/2)+1;g>=1;g--){

            int cnt =0;
            for(int d=g;d<=n;d+=g){
                cnt += freq[d];
            }

            if(cnt>=2){
                cout << g << "\n";
                break;
            }
        }

        
    }

    return 0;
}