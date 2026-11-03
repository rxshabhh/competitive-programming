#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
    Observation before Hint 1: i think the solution of this problem will focus on position of the bits set, 
    like we have to solve position wise, i have to club numbers for position i, for producing same results if yes then continue
    for more is or no

    Obs after hint: what if i maintain a freq vector where i can keep a count of the index appearance, and if any count == n then
    the answer has to be yes else no
*/

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;

        //int N = n;
        // vector<int> freq(36,0);
        map<int,int> freq; // used for constraints

        // while(n--){
        //     int k; cin>>k;
        //     //vector<int> idx;
        //     while(k--){
        //         int x; cin>>x;
        //         freq[x]++;
        //     }

        // }

        vector<vector<int>> a(n);

        for(int i=0;i<n;i++){
            int k; cin>>k;
            a[i].resize(k);
            
            for(int j=0;j<k;j++){cin>>a[i][j]; freq[a[i][j]]++;}
        }


        // for(auto val : freq){
        //     cout << val << " ";
        // }

        bool found = false;

        for(int i=0;i<n;i++){

            bool drop = true;
            for(auto bit : a[i]){

                if(freq[bit]==1){
                    drop = false;
                    break;
                }


            }

            if(drop){
                found = true;
                break;
            }

            
        }



        // for(int i=0;i<freq.size();i++){
        //     if(freq[i]==N){
        //         found = true;
        //         break;
        //     }
        // }

        if(found) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}