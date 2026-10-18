#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// had to learn again

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    if (!(cin >> N)) return 0;

    ll total_good_sequences = 0;

    // 1. Iterate over length L
    for (int L = 3; L <= 19; L++) {
        
        // 2. Iterate over start value a
        for (ll a = 1; ; a++) {
            
            // Base check: Safely check if minimum product (d=1) exceeds N
            ll min_product = 1;
            bool over = false;
            for (int i = 0; i < L; i++) {
                ll term = a + i * 1LL;
                
                // Safe overflow check using division
                if (min_product > N / term) {
                    over = true;
                    break;
                }
                min_product *= term;
            }
            if (over) break; 
            
            // 3. Binary Search to find the maximum valid d
            ll low = 1, high = 1000000000LL, max_d = 0;
            
            while (low <= high) {
                ll mid = low + (high - low) / 2;
                
                ll current_product = 1;
                bool exceeds = false;
                
                for (int i = 0; i < L; i++) {
                    ll term = a + i * mid;
                    
                    // Safe overflow check using division
                    if (current_product > N / term) {
                        exceeds = true;
                        break;
                    }
                    current_product *= term;
                }
                
                if (!exceeds) {
                    max_d = mid;     // This d works, check higher
                    low = mid + 1;
                } else {
                    high = mid - 1;  // Product too big, check lower
                }
            }
            
            total_good_sequences += max_d;
        }
    }

    cout << total_good_sequences << "\n";
    return 0;
}