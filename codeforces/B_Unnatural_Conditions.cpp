#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    // Wrong on test case 3
    
    // cout << n << "\n";
    // cout << n << "\n";


    // wrong on test case 1

    // string a ="",b="";
    // for(int i=0;i<n;i++){
    //     a+='1';
    //     b+='1';
    // }

    // int x = stoi(a);
    // int y = stoi(b);

    // cout << x<<"\n";
    // cout << y << "\n";


    // Wrong on tc 1

    // int k = n/4;
    // string a = "", b = "";

    // for (int i = 0; i <= k+1; i++){
    //     a += to_string(m);
    // }

    // for (int i =0;i<=max(0,k-1)+1;i++){
    //     b += to_string(m - 1);
    // }

    // cout << a << "\n";
    // cout << b << "\n";

    string a="";
    for(int i=0;i<2229;i++){
        a+='8';
    }
    a+='9';

    string b="";
    for(int i=0;i<=2229;i++){
        b+='1';
    }

    cout << a << "\n";
    cout <<b<<"\n";

    return 0;
}