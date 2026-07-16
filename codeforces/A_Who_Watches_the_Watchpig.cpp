#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;cin>>t;
	while(t--){

        int n,k; cin>>n>>k;

        string s; cin>>s;

        if(2*k>n){
            cout << -1 << "\n";
            continue;


        }

        int sum =0;

        for(int i=0;i<k;i++){
            if(s[i]=='L'){
                sum++;
            }
        }

        for(int i=n-k;i<n;i++){
            if(s[i]=='R'){
                sum++;
            }
        }

        cout << sum <<"\n";
	    
	}

}
