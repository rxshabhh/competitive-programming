#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int fact(int x){

    if(x==0 || x==1) return 1;
    return x*fact(x-1);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> a(n); for(auto &x : a) cin>>x;

    map<int,int> cnt; // cnt[x] = freq of x to the left already

    ll ans =1; // base case = normal array

    for(int i=0;i<n;i++){
        if(i>0 && a[i] != a[i-1]){
            ans += (i-cnt[a[i]]); // i = i elements before i, exclude cnt[a[i]] = dublicates
        }

        cnt[a[i]]++;
    }

    cout << ans;

    // set<int> st;
    // for(auto val : a) st.insert(val);

    // int dist = st.size();

    // int f = fact(dist);

    // cout << f * (n/dist);

    

    return 0;
}