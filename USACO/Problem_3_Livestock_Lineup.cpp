#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    int N = n*6;

    string a = "Beatrice", b="Bella", c="Belinda", d="Bessie",e="Betsy",f="Blue",g="Buttercup",h="Sue";

    vector<string> m;

    while(N--){
        
        string s; cin>>s;
        m.push_back(s);

    }


    // unordered_map<string,string> mpp; // it over-writes if a cow has 2 neighbours
    vector<pair<string,string>> rules;
    vector<string> temp;

    for(int i=0;i<m.size();i++){
        
        if(m[i]==a || m[i]==b || m[i]==c || m[i]==d || m[i]==e || m[i]==f || m[i]==g || m[i]==h){
            temp.push_back(m[i]);
        }

    }
//
    for(int i=0;i<temp.size();i+=2){
        rules.push_back({temp[i],temp[i+1]});
    }

    vector<string> result = {a,b,c,d,e,f,g,h};
    sort(result.begin(),result.end());

    do{
        
        // for(int i=1;i<result.size();i++){
        //     if((result[i-1]==mpp[i].first && result[i]==mpp[i].second) || (result[i-1]==mpp[i].second && result[i]==mpp[i].first)){
        //         break;
        //     }
        // }

        bool isValid = true;
        for(auto rule : rules){
            int pos1 = find(result.begin(),result.end(),rule.first) - result.begin();
            int pos2 = find(result.begin(),result.end(),rule.second) - result.begin();

            if(abs(pos1-pos2)!=1){
                isValid = false;
                break;
            }

        }

        if(isValid) break;
        
//
    }while(next_permutation(result.begin(),result.end()));

    for(auto val : result){
        cout << val << "\n";
    }

    

    return 0;
}