#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--){

        int n;cin>>n;
        string a; cin>>a;
        string b; cin>>b;
        
        int ae=0,ao=0;
        int be=0,bo=0;

        for(int i=0;i<n;i++){
            if(i%2){
                if(a[i]=='1') ao++;
                if(b[i]=='1') bo++;
            }
            else{
                if(a[i]=='1') ae++;
                if(b[i]=='1') be++;
            }
        }

        if(ae==be && ao==bo){
            cout << "YES\n";
        }
        else cout << "NO\n";
        
    }
    
    return 0;
}