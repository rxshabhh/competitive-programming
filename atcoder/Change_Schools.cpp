#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 2*1e5 +5;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto &x : a) cin>>x;

    vector<int> freq(k+1,0);

    for(int i=1;i<=n;++i){
        freq[a[i-1]]++;
    }

    int mxx = *max_element(freq.begin(),freq.end());

    int cnt =0;

    for(int i=1;i<=k;i++){
        if(freq[i]>=mxx-1) cnt++;
    }

    cout << cnt;


    


    return 0;
}