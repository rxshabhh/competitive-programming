#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;

    vector<int> k(q); for(auto &x : k) cin>>x;

    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[i] = i+1;
    }


    for(int i=0;i<k.size();i++){

        reverse(temp.begin(),temp.begin()+k[i]);

        for(int j=0;j<k[i];j++){
            temp[j] = -temp[j];
        }

    }

    for(auto val : temp){
        cout << val << "\n";
    }

    return 0;
}