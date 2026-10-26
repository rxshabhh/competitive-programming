#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/* 
    Intuition was if array contains all primes then the answer is NO always, then i saw that the array whose answer is NO
    have gcd != 1, and arrays with gcd = 1, answer was YES. Now, exception case is if all the same then YES

    observations: if all primes then straight no, product will not change but how to use this info,
    if we take divisors of all the numbers inside the array, the power of each distinct power should be even and >= len of array

*/

// bool isprime(int x){
//     for(int i=1;i*i<=x;i++){
//         if(x%i==0) return false;
//     }

//     return true;
// }



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        // vector<int> mpp(N); --> map is better
        
        map<int,int> mpp;

        for(int i=0;i<n;i++){

            int temp = a[i];

            for(int j=2;j*j<=temp;j++){
                
                while(temp%j==0){
                    mpp[j]++;
                    temp/=j;
                }
            }

            if(temp>1) mpp[temp]++;
        }

        bool ok = true;

        for(auto& it : mpp){
            if(it.second%n!=0){
                ok = false;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";

        

        // int g = 0;

        // for(int i=0;i<n;i++){
        //     g = __gcd(g,a[i]);
        // }
        
        // if(g!=1){
            
        //     bool ok = true;
        //     for(auto val : a){
        //         if(isprime(val) || val==1){
        //             ok = true;
        //         }
        //         else ok = false;


        //     }

        //     if(ok){cout << "NO\n"; continue;}

        //     bool all_equal = a.empty() || equal(a.begin() + 1, a.end(), a.begin());

        //     if(all_equal) cout << "YES\n";

        //     else cout << "NO\n";
        // }
        // else cout << "NO\n";
    }

    return 0;
}