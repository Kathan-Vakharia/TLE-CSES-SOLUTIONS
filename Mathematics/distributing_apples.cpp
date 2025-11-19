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
const ll maxN = 2e6 + 10; //> Increased size to handle (n+m-1) up to 2e6
ll M = 1e9 + 7;
vector<ll> fact(maxN + 1, 1);

//> Function to calculate MMI of x % M
ll calc_inv(ll x) {
    return binpow(x, M - 2, M);
}
//> Function to calculate nCr % M
ll calc_nCr(ll n, ll r) {
    return fact[n] * calc_inv(fact[r] * fact[n - r] % M) % M;
}

int main() {
    //> Precompute Factorials and Inverse Factorials
    for (int i = 1; i <= maxN; i++) {
        fact[i] = fact[i - 1] * i % M;
    }

    ll n, m;
    cin >> n >> m;

    //> Result: C(n+m-1, m)
    cout << calc_nCr(n + m - 1, m) << "\n";
}  //* T: O(n + log M) where n=O(1e6), M=1e9+7
   //* where O(1e6) for precomputing factorials, and O(log M) for modular inverse calculation