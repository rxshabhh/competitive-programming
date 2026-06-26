
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        n--;
        
        ll x = n/3;
        ll y =n/5;
        ll z =n/15;
        
        ll sum3 = 3LL * x*(x+1) /2;
        ll sum5= 5LL *y*(y+1)/2;
        ll sum15 = 15LL *z*(z+1)/2;
        
        cout << sum3+sum5-sum15 <<"\n";
    }
    return 0;
}

