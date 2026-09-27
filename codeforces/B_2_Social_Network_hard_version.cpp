#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;

    vector<int> id(n); for(auto &x : id) cin>>x;

    deque<int> q;
    set<int> st;

    for(int i=0;i<n;i++){


        if(st.find(id[i]) == st.end()){

            if(q.size()==k){
                st.erase(q.back());
                q.pop_back();
            }

            st.insert(id[i]);
            q.push_front(id[i]);

        }
    }

    cout << q.size() << "\n";

    while(!q.empty()){


        cout << q.front() << " ";
        q.pop_front();
    }

    return 0;
}