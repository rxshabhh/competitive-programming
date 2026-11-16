#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> a(n), b(n); 
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    int l=0,r=n-1;

    while(l<n && a[l]==b[l]) l++;
    while(r>=0 && a[r]==b[r]) r--;

    if(l>r){

        cout << "Yes\n";
        return 0;
    }

    vector<int> ls = a;
    rotate(ls.begin()+l,ls.begin()+l+1,ls.begin()+r+1);
    
    vector<int> rs = a;
    rotate(rs.begin()+l,rs.begin()+r,rs.begin()+r+1);

    if(ls == b || rs==b){
        cout << "Yes\n";
    }
    else cout << "No\n";

    // bool okay = true;

    // for(int i=0;i<n;i++){
    //     if(a[i]!=b[i]){
    //         okay = false;
    //         break;
    //     }
    // }

    // sort(a.begin(),a.end());
    // sort(b.begin(),b.end());


    // bool ok1 = true;
    // for(int i=0;i<n;i++){
    //     if(a[i]!=b[i]){
    //         ok1 = false;
    //         break;
    //     }
    // }

    

    // if(okay || ok1) cout << "Yes";
    // else cout << "No";

    return 0;
}