#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    vector<int> a(n+1,0); 

    vector<vector<int>> b(n+1);

    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;

        a[x]++;
        b[x].push_back(y);
    }

    set<pair<int,int>> st;

    for(int i=1;i<=n;i++){
        st.insert({-a[i],i}); 
    }

    vector<int> ans(n+1);

    for(int k=1;k<=n;k++){


        st.erase({-a[k],k});

        for(auto val : b[k]){

            st.erase({-a[val],val});

            a[val]++;
            st.insert({-a[val],val});
        }

        ans[k] = st.begin()->second;

        
        for(auto val : b[k]){

            st.erase({-a[val],val});

            a[val]--;
            st.insert({-a[val],val});
        }

        st.insert({-a[k],k});


    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }


    




    return 0;
}