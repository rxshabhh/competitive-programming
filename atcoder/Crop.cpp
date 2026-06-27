#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h,w; cin>>h>>w;

    vector<string> a(h);
    for(int i=0;i<h;i++) cin>>a[i];

    int top= h,bottom =-1;
    int right =-1, left=w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){

            if(a[i][j]=='#'){
                top = min(top,i);
                bottom = max(bottom,i);
                left = min(left,j);
                right=max(right,j);
            }
        }
    }

    for(int i=top;i<=bottom;i++){
        for(int j=left;j<=right;j++){
            cout << a[i][j];
        }

        cout << '\n';
    }


    return 0;
}