#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t; cin>>t;
    while(t--){

        int n,r,b; cin>> n>>r>>b;

        string s;

        int red = (r/(b+1));
        int extra = r % (b+1);

        for(int i=1;i<=b+1;i++){

            for(int i=0;i<red;i++){
                s += 'R';
            }

            if(extra>0){
                s += 'R';
                extra--;
            }

            if(i!=(b+1)){
                s+='B';

            }
        }
        cout << s << "\n";
    }

    return 0;
}