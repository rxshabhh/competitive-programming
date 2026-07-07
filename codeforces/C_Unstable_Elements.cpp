#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n,k; cin>>n>>k;
        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> freq(n+1);

        for(int i=0;i<n;){

            int j=i+1;
            while(j<n && a[i]==a[j]){
                j++;
            }
            freq[j-i]++;
            i=j;
        }

        int sum=0, total=0, ans=0;

        for(int i=n;i>=1;i--){

            if(freq[i]==0) continue;

            sum += i*freq[i];
            total += freq[i];

            int curr = sum - (i-1)*total;

            if(curr<=k && (k-curr)%total ==0){
                ans++;
            }


        }

        cout << ans <<"\n";


    }

    return 0;
}