#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int m = 1e7+5;
int spf[m+1];

void sieve(){
    for(int i=1;i<=m;i++){
        spf[i]=i;

    }

    for(int i=2;i*i<=m;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=m;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    sieve();

    vector<int> d1,d2;

    for(auto val : a){

        int p = spf[val];
        int x=val;
        int cnt =1;

        while(x%p==0){
            cnt *=p;
            x/=p;
        }

        if(x==1){
            d1.push_back(-1);
            d2.push_back(-1);
        }
        else{
            d1.push_back(cnt);
            d2.push_back(x);
        }

        
        
    }

    for(auto val : d1){
        cout << val << " ";
    }
    cout << "\n";
    for(auto val : d2){
        cout << val << " ";
    }





    return 0;
}