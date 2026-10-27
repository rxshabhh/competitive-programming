#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;

    vector<int> a(n); for(auto &x : a) cin>>x;

    unordered_map<int,int> freq;
    freq[0]=0;
    int pre=0, cnt=0;

    int x=0;

    for(int i=0;i<n;i++){

        pre = (a[i]+pre)%k;

        if(freq.count(pre) && freq[pre]>=x){
            cnt++;
            x = i;
        }

        freq[pre] =i;



    }

    cout << cnt;

    return 0;
}