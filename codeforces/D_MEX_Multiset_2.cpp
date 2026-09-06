#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        string s = "";

        int cnt=0;
        for(auto val : a){
            if(val==0) cnt++;
        }

        if(cnt==1){
            cout << "NO\n";
        }

        else{
            cout << "YES\n";


            if(cnt==0){
                for(int i=0;i<n;i++){
                    s+='A';
                }
            }

            else{

                bool ok = false;

                for(int i=0;i<n;i++){

                    if(!ok && a[i]==0){
                        s += 'A';
                        ok = true;
                    }

                    else if(ok && a[i]==0){
                        s += 'B';
                    }
                    else s+='C';
                }
            }

            cout << s << "\n";
        }
    }

    return 0;
}