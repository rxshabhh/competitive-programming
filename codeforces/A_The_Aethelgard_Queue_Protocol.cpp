#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int stress(queue<int>& q){

    vector<int> temp;

    if(q.size()<3) return 0;

    while(!q.empty()){
        int it = q.top();
        q.pop();
        temp.push_back(it);
    }

    int sum = accumulate(temp.begin(),temp.end(),0);
    int mx = *max_element(temp.begin(),temp.end());
    int mn = *min_element(temp.begin(),temp.end());

    int res = sum - mx - mn;
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,s; cin>>n>>s;

    vector<int> a(n); for(auto &x : a) cin>>x;

    queue<int> q;

    int mn = INT_MIN, mx=INT_MAX;


    int i=0;
    while(stress(q)<=s){

        q.push(a[i]);

        i++;
    }

    int ans=0;

    if(stress(q)<=s){
        ans = q.size();
    }

    cout << ans << "\n";



    return 0;
}