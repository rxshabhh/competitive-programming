#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        string ans = "";

        vector<int> diff(n+1,0);

        for(int i=0;i<n;i++){

            if(a[i]==-1) continue;

            int l = max(0,i-a[i]+1);
            int r = min(n-1, i+a[i]-1);

            
            if(l<=r){
                diff[l] += 1;
                diff[r+1] -= 1;
            }



        }

        vector<bool> tres(n,false);

        int overlap=0;
        int total = 0;
        for(int j=0;j<n;j++){

            overlap += diff[j];

            if(overlap==0){
                tres[j] = true;
                total++;
            }


        }

        bool ok = true;

        if(total==0) ok = false;

        for(int i=0;i<n;i++){

            if(a[i]==-1) continue;

            int left = i-a[i];
            int right = i+a[i];

            bool hasLeft = (left>=0 && tres[left]);
            bool hasRight = (right<n && tres[right]);

            if(!hasLeft && !hasRight){
                ok = false;
                break;
            }
        }

        if(!ok){
            cout << -1 << "\n";
        }

        else{
            for(int i=0;i<n;i++){
                if(tres[i]){
                    ans += '1';
                }
                else ans+='0';
            }
            cout << ans << "\n";
        }

        




    }

    return 0;
}