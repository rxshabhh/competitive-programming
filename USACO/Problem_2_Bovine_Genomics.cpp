#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);

    int n,m; cin>>n>>m;

    int M=m;


    int cnt=0;
    vector<vector<char>> cows(2*n,vector<char>(m));

    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++){
            cin >> cows[i][j];
        }
    }

    set<char> st;

    int j=0;
    while(j<m){

        for(int i=0;i<n;i++){
        
    
            st.insert(cows[i][j]);

        }
        bool ok = true;
        for(int i=n;i<2*n;i++){
            int temp=0;
            
            if(st.count(cows[i][j])){
                ok = false;
                break;
            }
        
            
        }

        if(ok) cnt++;
        st.clear();
        j++;
    }

    cout << cnt << "\n";



    return 0;
}