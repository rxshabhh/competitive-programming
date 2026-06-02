#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(int x){
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;

    for(int i=3;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int closestprime(int x){

    

    while(!isprime(x)){
        x++;
    }

    return x;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;

        int p1 = closestprime(1+n);
        int p2 = closestprime(p1+n);

        cout << 1LL*p1*p2 << "\n";
        
    }
    

    return 0;
}