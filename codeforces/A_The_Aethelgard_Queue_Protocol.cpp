#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// int stress(queue<int> q){  //

//     vector<int> temp;

//     if(q.size()<3) return 0;

//     while(!q.empty()){
//         int it = q.front(); //
//         q.pop();
//         temp.push_back(it);
//     }

//     int sum = accumulate(temp.begin(),temp.end(),0);
//     int mx = *max_element(temp.begin(),temp.end());
//     int mn = *min_element(temp.begin(),temp.end());

//     int res = sum - mx - mn;
//     return res;
// }

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        ll s; cin>>s;

        vector<int> a(n); for(auto &x : a) cin>>x;

    

        int left = 0;

        int ans =0;

        ll currsum =0;
        deque<int> max_q, min_q;

        for(int right =0;right<n;right++){
            
            currsum += a[right];

            // max deque implementation

            while(!max_q.empty() && max_q.back()<a[right]){
                max_q.pop_back();
            }

            max_q.push_back(a[right]);

            // min deque implementation

            while(!min_q.empty() && min_q.back()>a[right]){
                min_q.pop_back();
            }
            min_q.push_back(a[right]);

            ll stress;

            if(right-left+1<3) stress =0;
            else stress = currsum - max_q.front() - min_q.front();

            while(stress>s){
            // implementation
                if(a[left]==max_q.front()) max_q.pop_front();
                if(a[left] == min_q.front()) min_q.pop_front();

                currsum -= a[left];
                left++;

                if(right-left+1 < 3){
                    stress =0;
                }
                else{
                    stress = currsum - max_q.front() - min_q.front();
                }
            }
            ans = max(ans, right-left+1);


        }
        

        cout << ans << "\n";
    }



    // queue<int> q;

    // int mn = INT_MIN, mx=INT_MAX;


    // int i=0;
    // while(i<n && stress(q)<=s){  //

    //     q.push(a[i]);

    //     i++;
    // }

    // int ans=0;

    // if(stress(q)<=s){
    //     ans = q.size();
    // }

    // cout << ans << "\n";



    return 0;
}