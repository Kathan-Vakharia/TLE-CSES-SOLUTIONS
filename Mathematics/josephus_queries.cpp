#include <bits/stdc++.h>
using namespace std;

int child(int n, int k, int p) {
    int r = (n + p) / 2;
    if (k <= r) return 2 * k - p;
    int _p = n % 2 == 0 ? p : 1 - p;

    return child(n - r, k - r, _p) * 2 - 1 + p;
}  //* T:O(log(n)), S:O(log(n))

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        cout << child(n, k, 0) << "\n";
    }
}  //* T:O(q*logn), S:O(k)