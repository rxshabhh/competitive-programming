#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n;cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        int cnt=0;

        for(int val : a){
            if(val==1) cnt++;
        }

        if(cnt==0){
            
            int i=0;
            while(i<n && a[i]!=-1) i++;
            if(i<n) a[i]=1;
            int k=n-1;
            while(k>=0 && a[k]!=-1) k--;
            if(k>=0) a[k] = 1;

            for(int j=0;j<n;j++){
                if(a[j]==-1) a[j]=0;
            }



            for(int val : a){
                cout << val << " ";
            }
            cout << "\n";
        }

        else{

            int i=0;
            while(i<n && a[i]!=1) i++;

            for(int j=0;j<=i;j++){
                if(a[j]==-1){
                    a[j] = 1;
                    break;
                }
            }

            int k=n-1;
            while(k>=0 && a[k]!=1) k--;

            for(int j=n-1;j>=k;j--){
                if(a[j]==-1){
                    a[j]=1;
                    break;
                }
            }

            for(int j=0;j<n;j++){
                if(a[j]==-1) a[j]=0;
            }


            for(int val : a){
                cout << val << " ";
            }

            cout << "\n";

        }
    }

    return 0;
}