#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 21;
int main() {
    vector<ll> fact(maxN, 1);
    for (int i = 1; i < maxN; i++)
        fact[i] = i * fact[i - 1];

    int t;
    cin >> t;

    while (t--) {
        int q, n;
        cin >> q >> n;
        ll f = fact[n];
        // Initialize p with the sequence [1, 2, ..., n]
        vector<ll> p(n);
        iota(p.begin(), p.end(), 1);
        if (q == 1) {
            ll k;
            cin >> k;
            k--;
            for (int i = 0; i < n; i++) {
                f = f / (n - i);
                int idx = k / f;
                cout << p[idx] << " ";
                k = k % f;
                p.erase(p.begin() + idx);
            }
            cout << "\n";

        } else {
            ll k = 1;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                f = f / (n - i);
                auto it = find(p.begin(), p.end(),x);
                k += (it - p.begin()) * f;
                p.erase(it);
            }
            cout << k << "\n";
        }
    }
    return 0;
}  //* T:(t*n*n) = O(4e5), S:O(n)