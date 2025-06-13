#include <bits/stdc++.h>

using namespace std;
#define nl '\n'  // newline
#define sp ' '   // space
#define ll long long

void solve() {
    ll x, y;
    cin >> x >> y;

    // find spiral no
    ll spiral_no = max(x, y);
    // 1 3 5 7 9
    ll total_ele = 1 + (spiral_no - 1) * 2;

    // find bounds
    ll m = spiral_no - 1;
    ll start = (m * (2 + (m - 1) * 2)) / 2 + 1;
    ll end = start + total_ele - 1;

    // taking even or odd into consideration
    if (spiral_no % 2 == 0) swap(start, end);

    // find answer
    if (x >= y) {
        if (spiral_no % 2 == 0)
            cout << start - y + 1 << nl;
        else
            cout << start + y - 1 << nl;
    } else {
        if (spiral_no % 2 == 0)
            cout << end + x - 1 << nl;
        else
            cout << end - x + 1 << nl;
    }
}

/* Time : O(t) = O(1e5), Space : O(1)
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
