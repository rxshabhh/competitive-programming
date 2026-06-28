#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    vector<int> color(n+1,0);

    int total=0;
    vector<vector<int>> bird(n);

    for(int i=0;i<n;i++){
        int a,d,b; cin>>a>>d>>b;

        bird[i]={d,a,b};


    }

    sort(bird.begin(),bird.end());

    for(int i=0;i<n;i++){
        int col= bird[i][1];

        if(color[col]==0) total++;
        color[col]++;
    }

    int p=0;

    for(int day=1;day<=m;day++){
        while(p<n && bird[p][0]==day){
            int old = bird[p][1], nw=bird[p][2];

            color[old]--;
            if(color[old]==0) total--;
            if(color[nw]==0) total++;

            color[nw]++;
            p++;
        }

        cout << total <<'\n';
    }


    

    

    return 0;
}