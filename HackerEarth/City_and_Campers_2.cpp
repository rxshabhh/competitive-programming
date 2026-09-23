#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;

int par[N], sz[N];

multiset<int> ms;

void make(int v){
    par[v]=v;
    sz[v]=1;
    ms.insert(1);
}


int find(int v){

    if(par[v]==v) return par[v];

    return par[v]= find(par[v]);
}


void Union(int a,int b){

    ms.erase(ms.find(sz[a]));
    ms.erase(ms.find(sz[b]));

    ms.insert(sz[a]+sz[b]);
}

void merge(int a, int b){

    a=find(a);
    b=find(b);

    if(a==b) return;

    if(sz[a]<sz[b]){
        swap(a,b);
    }

    par[b]=a;

    Union(a,b);
    sz[a] += sz[b];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;

    for(int i=1;i<=n;i++) make(i);

    while(q--){

        int a,b; cin>>a>>b;

        merge(a,b);

        if(ms.size()==1) cout << 0 << "\n";
        else{  
            int mn=INT_MAX;

            // we use upper bound here to reduce the search space from N to sqrt N everytime
            // to skip duplicate sizes and jumpting to distinct values

            for(auto it=next(ms.begin()); it!=ms.end(); ){

                auto nxt = ms.upper_bound(*it);

                if(*it == *prev(it) || prev(nxt)!= it){
                    mn=0;
                    break;
                }

                mn = min(mn, (*it - *prev(it)));
            }

            cout << mn << "\n";
        }

    
    }

    

    return 0;
}