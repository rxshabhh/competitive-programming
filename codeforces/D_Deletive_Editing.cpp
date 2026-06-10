#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t; cin>>t;
    while(t--){
        
        string s,t; cin>>s>>t;

        int n=s.size();
        int m=t.size();

        vector<int> freq(26,0);

        for(int i=0;i<m;i++){
            freq[t[i]-'A']++;
        }

        for(int i=n-1;i>=0;i--){

            if(freq[s[i]-'A'] >0){
                freq[s[i]-'A']--;
            }
            else{
                s[i] = '.';
            }
        }

        string f = "";

        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                f+=s[i];
            }
        }

        if(f==t) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}