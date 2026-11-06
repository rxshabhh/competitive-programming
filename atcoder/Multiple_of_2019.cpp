#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    int n=s.size();

    map<int,int> freq;
    freq[0]=1;

    int suff =0, cnt=0;
    int pow =1;

    for(int i=n-1;i>=0;i--){
        int d = s[i]-'0';
        
        suff = (suff + d*pow)%2019;
        
        

        int key = suff;
        cnt += freq[key];
        pow = (pow*10)%2019;
        freq[key]++;
    }

    cout << cnt;

    return 0;
}