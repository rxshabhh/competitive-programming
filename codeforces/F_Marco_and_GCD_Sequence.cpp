#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;

    vector<int> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i];

    int min_val = s[0];

    for (int i = 0; i < m; i++) {
        if (s[i] % min_val != 0) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << 2 * m << "\n";
    for (int i = 0; i < m; i++)
        cout << s[i] << " " << min_val << " ";
    cout << "\n";
}