#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxN = 1e6 + 10;
ll M = 1e9 + 7;
vector<ll> fact(maxN + 1, 1);
vector<ll> inv_fact(maxN + 1, 1);

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

ll mm_inv(ll x) {
    return binpow(x, M - 2, M);
}  //* T: O(log M)

ll a_choose_b(ll a, ll b) {
    //> Recall: Operator Precedence and Associativity
    return fact[a] * inv_fact[a - b] % M * inv_fact[b] % M;
}//* T: O(1) 

int main() {
    //> Precompute Factorials and Inverse Factorials
    for (int i = 1; i <= maxN; i++) {
        fact[i] = fact[i - 1] * i % M;
    }
    inv_fact[maxN] = binpow(fact[maxN], M - 2, M);
    for (int i = maxN - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % M;
    }

    ll n;
    cin >> n;
    if (n % 2 == 1) {
        // odd number of brackets cannot form a valid sequence
        cout << 0 << "\n";
    } else {
        ll N = n / 2;
        // number of valid bracket sequences of length n is given by the Nth Catalan number
        // which is given by C(2N, N)/(N+1)
        ll catalanN = a_choose_b(2 * N, N) * mm_inv(N + 1) % M;
        cout << catalanN << "\n";
    }
}  //* T: O(maxN) where maxN=O(1e6), S: O(maxN)