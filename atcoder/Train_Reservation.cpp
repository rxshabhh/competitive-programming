#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n; cin>>n;
    char s; cin>>s;

    int op = 0;
    if(s=='A') op =1;
    else if(s=='B') op =2;
    else if(s=='C') op =3;
    else if(s=='D') op =4;
    else op =5;

    bool ok = false;

    while(n--){
        string st; cin>>st;
        

        for(int i=0;i<st.size();i++){
        
            if(st[op-1]=='o'){
                ok=true;
                break;
            }
        }

        if(ok) break;
    }


    

    if(ok) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}