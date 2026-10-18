#include <iostream>
#include <string>

using namespace std;

int main() {
    string S1, S2;
    cin >> S1 >> S2;
    
    string S = S1 + S2;
    
    if ((S[0] == 'A' && S[3] == 'D') || (S[0] == 'D' && S[3] == 'A')) {
        cout << "No\n";
    } else if ((S[1] == 'A' && S[2] == 'D') || (S[1] == 'D' && S[2] == 'A')) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    
    return 0;
}