#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        int one=0, ok=0;
        int i=0;

        for(i=0;i<n;i++){
            if(a[i]==1) one++;

            if(one >= (i+1-one)){  // i+1 used for first part
                ok |= 1;
                i++;

                while(i<n && a[i]==3){

                    if(one < (i+1-one)) break; 
                    i++;
                }
                break;

            }
        }


        // middle part

        int cnt=0, c12=0;

        for(;i<n;i++){

            cnt++; // elements in middle part

            if(a[i]!=3) c12++;

            if(c12 >= (cnt-c12)){  // cnt used for middle part size
                ok |= 2;
                i++;
                break;
            }
        }

        if(ok==3 && i<n){
            cout << "YES\n";
        }
        else cout <<"NO\n";

    }

    return 0;
}