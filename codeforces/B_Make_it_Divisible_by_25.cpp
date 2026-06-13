#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cost(string s, string target){
    
    int ops = 0;

    int j=1; // length = 2 : 0 1 indexes

    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==target[j]){
            j--;
            if(j<0) return ops;
        }
        else{
            ops++;
        }
    }

    return INT_MAX;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;

    vector<string> last = {"00","50","75","25"};
    while(t--){
        string n; cin>>n;

        int ans = INT_MAX;
        for(string l : last){
            ans = min(ans,cost(n,l));
        }

        cout << ans << "\n";

        
    }

    return 0;
}