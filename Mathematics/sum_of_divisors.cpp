#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;
ll INV_2;

ll binpow(ll a, ll b, ll M) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a % M;

        // get next power
        a = a * a % M;
        b >>= 1;
    }

    return res;
}  //* T: O(log b)

ll range_sum(ll left, ll right) {
    return (left + right) % M * ((right - left + 1) % M) % M * INV_2 % M;
}

int main() {
    //> calculate MMI(2)
    INV_2 = binpow(2, M - 2, M);
    ll n;
    cin >> n;

    ll res = 0;
    //> Region 1: Small k (≤ sqrt(n)), large quotients (≥ sqrt(n))
    // Each k is processed individually
    for (ll k = 1; k * k <= n; k++)
        res = (res + k * (n / k) % M) % M;

    //> Region 2: Large k (> sqrt(n)), small quotients (< sqrt(n))
    // Iterate over quotient values q from 1 to sqrt(n)-1
    for (ll q = 1; n / q > q; q++) {
        // Find range of k values where floor(n/k) = q
        ll k_left = n / (q + 1) + 1;
        ll k_right = n / q;
        // Each k in [k_left, k_right] contributes q times
        res = (res + q * range_sum(k_left, k_right) % M) % M;
    }

    cout << res << '\n';
}  //* T: O(sqrt(n)), S:O(1)