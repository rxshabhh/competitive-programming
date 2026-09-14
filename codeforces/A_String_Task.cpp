#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    set<char> st = {'a','e','o','u','i','y','A','E','O','U','I','Y'};

    string ans = "";

    for(int i=0;i<s.size();i++){

        if(!st.count(s[i])) ans += s[i];
    }

    for(int i=0;i<ans.size();i++){
        cout << "." << static_cast<char>(std::tolower(ans[i]));
    }


    return 0;
}