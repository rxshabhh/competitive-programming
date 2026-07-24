#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int a,b,c,d; cin>>a>>b>>c>>d;

    int n=48,m=50;

    vector<string> grid(n,string(m,' '));

    for(int i=0;i<12;i++) grid[i] = string(m,'A');
    for(int i=12;i<24;i++) grid[i] = string(m,'B');
    for(int i=24;i<36;i++) grid[i] = string(m,'C');
    for(int i=36;i<48;i++) grid[i] = string(m,'D');

    a--; 
    b--;
    c--;
    d--;

    for(int r=1;r<=9;r+=2){
        for(int col=1;col<m;col+=2){
            if(b>0){
                grid[r][col] = 'B';
                b--;
            }
        }
    }

    for(int r=13;r<=21;r+=2){
        for(int col=1;col<m;col+=2){
            if(a>0){
                grid[r][col] = 'A';
                a--;
            }
        }
    }

    for(int r=25;r<=33;r+=2){
        for(int col=1;col<m;col+=2){
            if(d>0){
                grid[r][col] = 'D';
                d--;
            }
        }
    }

    for(int r=37;r<=45;r+=2){
        for(int col=1;col<m;col+=2){
            if(c>0){
                grid[r][col] = 'C';   
                c--;
            }
        }
    }

    cout << n << " "<<m <<"\n";
    for(int i=0;i<n;i++){
        cout << grid[i]<<"\n";
    }





    return 0;
}