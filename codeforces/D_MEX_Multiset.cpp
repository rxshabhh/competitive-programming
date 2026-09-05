#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ll mex(multiset<int>& a){

//     int n=a.size();

//     sort(a.begin(),a.end());

//     vector<int> actual;
//     for(int i=0;i<n;i++){
//         actual.push_back(i);
//     }

//     ll res = -1;

//     for(int i=0;i<n;i++){
//         if(a[i]!=actual[i]){
//             res = (ll) actual[i];
//             break;
//         }
//     }

//     if(res==-1){
//         return a[n-1]+1;
//     }
//     else return res;

// }

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        int cnt =0;
        for(auto val : a){

            if(val==0) cnt++;
        }

        vector<int> freq(n+1,0);

        for(int i=0;i<n;i++){
            if(a[i]<n) freq[a[i]]++;
        }

        if(cnt==1){
            cout << "NO\n";
        }

        else if(cnt==0){
            cout << "YES\n";

            string s ="";
            for(int i=0;i<n-1;i++){
                s += 'A';
            }
            s+='B';
            cout << s << "\n";


        }

        else{

            int k=0;
            while(freq[k]>=2) k++;

            bool ok = true;

            for(int i=0;i<k;i++){
                if(freq[i]<3){
                    ok = false;
                    break;
                }
            }

            vector<int> B(k,1), C(k,1);

            bool ok1 = (freq[k]==1 && ok);

            string s="";


            for(int i=0;i<n;i++){

                int val = a[i];

                if(val<k && B[val]==1){
                    s += 'B';
                    B[val] = 0;
                }

                else if(val<k && C[val]==1){
                    s+='C';
                    C[val]=0;
                }

                else if(val==k && ok1){
                    s+='B';
                    ok1=false;
                }

                else s+='A';
            }

            cout << "YES\n";
            cout << s << "\n";








        }

        // multiset<int> A,B,C;

        // string s ="";

        // for(int i=0;i<n;i++){

        //     if(A.count(a[i])==0){
        //         A.insert(a[i]);
        //         s[i]+='A';
        //     }
        //     else if(B.count(a[i])==0) {B.insert(a[i]); s[i]+='B';}

        //     else{
        //         C.insert(a[i]);
        //         s[i]+='C';
        //     }
        // }

        // int c1=0,c2=0,c3=0;

        // c1 = mex(A); c2 =mex(B); c3=mex(C);

        // if((c1+c2+c3) >= (2* max(c1,max(c2,c3)))){
        //     cout << "YES\n";
        //     cout << s << "\n";
        // }
        // else cout << "NO\n";

        

        


    }

    return 0;
}