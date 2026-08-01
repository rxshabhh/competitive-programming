#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) {
        string s; 
        cin >> s;

        int n = s.size();
        
        int zero = s.find('0');
        if(zero != string::npos){
            s.erase(zero,1);
        }

        int one = s.find('1');
        if(one != string::npos){
            s.erase(one,1);
        }

        cout << s << "\n";
    }

    return 0;
}