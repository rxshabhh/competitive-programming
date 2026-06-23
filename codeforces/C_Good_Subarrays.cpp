#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx = 100005 + 5;
int a[mx];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s; cin>>s;



        for(int i=0;i<n;i++){
            a[i+1] = s[i]-'0';
            
        }
        int pre[mx];
        pre[0]=0;

        unordered_map<int,int> freq;
        freq[0]=1;


        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1]+a[i];
        }

        ll cnt =0;
        for(int i=1;i<=n;i++){

            int key = pre[i]-i;
            cnt += freq[key];
            freq[key]++;
        }



        

        cout << cnt <<"\n";

        



        
    }

    return 0;
}