#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<int> par;

vector<int> len;
vector<int> ranks;

int comp_cnt, max_size;

int find(int x){
    
    if(par[x]!=x){
        par[x] = find(par[x]);
    }

    return par[x];

}

void merge(int a, int b){

    int l =find(a);
    int r =find(b);

    if(l!=r){

        if(ranks[l]>ranks[r]){
            par[r] = l;
            len[l] += len[r];
        }
        else if(ranks[l]<ranks[r]){
            par[l] = r;
            len[r]+= len[l];
        }
        else{
            par[l]=r;
            ranks[r]++;
            len[r] += len[l];
        }


        comp_cnt--;
        max_size = max({len[r],len[l],max_size});
    }

    



}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    par.resize(n+1);
    ranks.resize(n+1,0);
    len.resize(n+1,1);

    for(int i=1;i<=n;i++){
        par[i] =i;
    }

    comp_cnt=n;
    max_size = 1;

    for(int i=0;i<m;i++){

        int x,y; cin>>x>>y;

        merge(x,y);

        cout << comp_cnt << " " << max_size << "\n";
    }

    



    return 0;
}