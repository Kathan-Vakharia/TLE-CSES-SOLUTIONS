#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9 + 7;

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

ll mm_inv(ll x) {
    return binpow(x, M - 2, M);
}  //* T: O(log M)

int main() {
    int n;
    cin >> n;

    vector<ll> x(n), k(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
    }

    //> 1. Number of Divisors
    ll div_cnt = 1;
    for (int i = 0; i < n; i++) {
        div_cnt = div_cnt * (k[i] + 1) % M;
    }

    //> 2. Sum of Divisors
    ll div_sum = 1;
    for (int i = 0; i < n; i++) {
        div_sum = div_sum * (binpow(x[i], k[i] + 1, M) - 1) % M;
        div_sum = div_sum * mm_inv(x[i] - 1) % M;
    }

    //> 3. Product of divisors
    ll expo = 1;  // [N(d) for perfect square; else N(d)/2] MOD (M-1)
    bool is_ps = true;
    for (int i = 0; i < n; i++) {
        if (is_ps && k[i] % 2 == 1) {
            is_ps = false;  // not a perfect square; first odd power
            expo *= (k[i] + 1) / 2;
        } else {
            expo *= (k[i] + 1);
        }
        expo %= (M - 1);  //? Recall Exponentiation II Question
    }
    ll div_prod = 1;
    for (int i = 0; i < n; i++) {
        if (is_ps) k[i] /= 2;  //- if perfect square then power halved
        div_prod = div_prod * binpow(binpow(x[i], k[i], M), expo, M) % M;
    }

    //! Note: a = a*b%M is what we need NOT a *= b%M
    cout << div_cnt << " " << div_sum << " " << div_prod << "\n";
    return 0;
}  //* T:O(n), S:O(1)