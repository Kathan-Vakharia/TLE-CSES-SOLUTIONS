#include <bits/stdc++.h>
using namespace std;
#define ll long long

//> Binary Exponentiation to find (a^b) % M
ll binpow(ll a, ll b, ll M) {
    a = a % M;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % M;

        a = a * a % M;
        b >>= 1;
    }

    return res;
}  //* T: O(log b)

//- Global Variables
const ll maxN = 1e6 + 10;
ll M = 1e9 + 7;
vector<ll> fact(maxN + 1, 1);
vector<ll> invFact(maxN + 1, 1);

//> Function to calculate MMI of x % M
ll calc_inv(ll x) {
    return binpow(x, M - 2, M);
}
//> Function to calculate nCr % M
ll calc_nCr(ll n, ll r) {
    return fact[n] * invFact[r] % M * invFact[n - r] % M;
}

ll calculate_using_inclusion_exclusion(ll n) {
    //> n! - Σ ( C(n, k) * (n-k)! * -1^(k+1)) for k=1 to n
    ll deragements = fact[n];
    for (ll k = 1; k <= n; k++) {
        ll term = calc_nCr(n, k) * fact[n - k] % M;
        if (k % 2 == 1)
            deragements = (deragements - term + M) % M;
        else
            deragements = (deragements + term) % M;
    }
    return deragements;
}  //* T: O(n) as factorials and inverse factorials are precomputed

ll calculate_using_dp(ll n) {
    vector<ll> derangements(n + 1, 0);
    derangements[1] = 0;
    derangements[2] = 1;
    for (ll i = 3; i <= n; i++) {
        //> Recurrence Relation: D(n) = (n-1) * (D(n-1) + D(n-2))
        derangements[i] = (i - 1) * (derangements[i - 1] + derangements[i - 2]) % M;
    }
    return derangements[n];
}  //* T: O(n) as we compute derangements up to n, S:O(n) for dp array

//* Task: Calculate number of derangements of n items
int main() {
    //> Precompute Factorials and Inverse Factorials
    for (int i = 1; i <= maxN; i++) {
        fact[i] = fact[i - 1] * i % M;
    }
    invFact[maxN] = calc_inv(fact[maxN]);
    for (int i = maxN - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % M;
    }

    ll n;
    cin >> n;

    //> Method 1: using Principle of Inclusion-Exclusion
    cout << calculate_using_inclusion_exclusion(n) << "\n";

    //> Method 2: using Recurrence Relation (Dynamic Programming)
    // cout << calculate_using_dp(n) << "\n";
}