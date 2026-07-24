
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. COMPULSORY INTERACTIVE COMPONENTS
// ==========================================

// A dedicated function to handle all communication with the judge
bool query(int r1, int c1, int r2, int c2) {
    // Print the query in the required format
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl; 
    // Note: 'endl' is crucial here because it flushes the output stream!
    
    string response;
    cin >> response; // Read the judge's answer
    
    // If the judge returns something unexpected (like "BAD"), we can fail safely
    if (response != "YES" && response != "NO") {
        exit(0); 
    }
    
    return response == "YES";
}

// ==========================================
// 2. MAIN SOLUTION LOGIC
// ==========================================

int main() {
    // Fast I/O is often disabled in interactive problems to prevent buffering issues,
    // but if used, ensure cin.tie(NULL) is NOT used, so cout flushes before cin reads.
    
    int n;
    cin>>n;

    string path_forward = "";
    string path_backward = "";
    
    // --- Phase 1: Forward from (1, 1) to the antidiagonal ---
    int r = 1, c = 1;
    // We make exactly n - 1 moves to reach the antidiagonal
    for (int i = 0; i < n - 1; ++i) {
        // Greedily prioritize moving DOWN if (n, n) is still reachable
        if (r + 1 <= n && query(r + 1, c, n, n)) {
            path_forward += "D";
            r++;
        } else {
            path_forward += "R";
            c++;
        }
    }

    // --- Phase 2: Backward from (n, n) to the antidiagonal ---
    r = n; 
    c = n;
    // We make exactly n - 1 moves backward to meet the forward path
    for (int i = 0; i < n - 1; ++i) {
        // Greedily prioritize moving LEFT if the cell is reachable from (1, 1)
        if (c - 1 >= 1 && query(1, 1, r, c - 1)) {
            path_backward += "L";
            c--;
        } else {
            path_backward += "U";
            r--;
        }
    }

    // --- Phase 3: Merging the paths ---
    // Because we built the second path backwards, "L" means we came from the right ('R')
    // and "U" means we came from below ('D'). We must invert and reverse it.
    string true_path_backward = "";
    for (char ch : path_backward) {
        if (ch == 'L') true_path_backward += "R";
        else true_path_backward += "D";
    }
    reverse(true_path_backward.begin(), true_path_backward.end());

    // Print the final answer using the mandatory '!' format
    cout << "! " << path_forward << true_path_backward << endl;

    return 0;
}