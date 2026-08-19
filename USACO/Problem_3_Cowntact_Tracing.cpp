#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(int pat,int k, int n, string s, vector<vector<int>>& a){

    vector<bool> infect(n+1,false);
    vector<int> handshakes(n+1,0);


    infect[pat] = true;

    for(int i=0;i<a.size();i++){
        int x = a[i][1];
        int y = a[i][2];

        bool xinf = infect[x];
        bool yinf = infect[y];

        if(xinf) handshakes[x]++;
        if(yinf) handshakes[y]++;

        if(xinf && handshakes[x]<=k) infect[y]=true;
        if(yinf && handshakes[y]<=k) infect[x]=true;




    }

    for(int i=1;i<=n;i++){
        bool okay = (s[i-1]=='1');
        if(infect[i]!=okay) return false;
    }
    return true;
}

int main() {

    freopen("tracing.in","r",stdin);
    freopen("tracing.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t; cin>>n>>t;
    string s; cin>>s;
    vector<vector<int>> a(t,vector<int>(3));


    // int T = t;
    // while(T--){
    //     int x,y,z; cin>>x>>y>>z;
    //     a.push_back({x,y,z});
    // }

    // int cnt =0; // value for x
    // int kmin=1,kmax=1;
    
    // int i=0;
    // bool isthere = false;
    
    // for(int i=0;i<n;){
    //     if(s[i]=='1'){
    //         cnt++;
    //         int j=i;
    //         while(j<n && s[j]==1) j++;
    //         kmin = min(kmin,j-i);
    //         kmax = max(kmax,j-i);
    //         i=j+1;
    //     }
    //     else i++;
    // }

    // if(kmin == kmax){
    //     cout << cnt << " " << kmin << " " << "Infinity";
    // }
    // else cout << cnt << " " << kmin << " " << kmax;

    for(int i=0;i<t;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    sort(a.begin(),a.end());

    int min_k=300;
    int max_k=-1, cnt=0;

    for(int p=1;p<=n;p++){
        bool ok = false;
        for(int k=0;k<=251;k++){
            if(isValid(p,k,n,s,a)){
                ok=true;
                min_k =min(min_k,k);
                max_k =max(max_k,k);
            }
        }

        if(ok) cnt++;
    }

    cout << cnt << " " << min_k << " ";
    if(max_k==251) cout << "Infinity";
    else cout << max_k;


    

    return 0;
}