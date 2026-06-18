#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        int n,p; cin>>n>>p;

        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> b(n); for(auto &x:b) cin>>x;

        // vector<int> ratio(n);
        // for(int i=0;i<n;i++){
        //     ratio[i] = (b[i]/a[i]);
        // }

        // int mini = *min_element(ratio.begin(),ratio.end());

        
        // vector<int> minimum_idx;

        // int tl = 0;

        // for(int i=0;i<n;i++){
        //     if(ratio[i] == mini){
        //         cnt++;
        //         minimum_idx.push_back(i);
        //         tl += a[i];
        //     }
        // }

        // int cnt = minimum_idx.size();

        // int cost = p*cnt;
        // int left = n-cnt; // left to inform
        // for(int i=0;i<n;i++){
            
        //     if(tl>=left){
                
        //         // sort minimum_idx by b[i] and add that idx a[i]*b[i] into cost
        //         // and subtract its a[i] from tl
        //     }

        //     else{
        //         // how to pick the other value
        //     }
        // }

        // cout << min(p*n,cost) << "\n";

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({b[i],a[i]});
        }

        sort(v.begin(),v.end());


        ll cost = p;


        int need = n-1;
        int take =0;
        for(auto val : v){

            if((val.first) >= p){
                break;
            }
            
            take = min(val.second,need);
            cost += 1LL* take * (val.first);
            need -= take;
            if(need==0) break;
            
            
        }

        cost += (1LL*need*p);
        

        cout << cost << "\n";


        
    }

    return 0;
}