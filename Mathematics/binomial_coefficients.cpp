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

const ll maxN = 1e6 + 10;
ll M = 1e9 + 7;
vector<ll> fact(maxN + 1, 1);
vector<ll> inv_fact(maxN + 1, 1);

void print_a_choose_b() {
    ll a, b;
    cin >> a >> b;
    //> Recall: Operator Precedence and Associativity
    cout << fact[a] * inv_fact[a - b] % M * inv_fact[b] % M << "\n";
}

int main() {
    //> Precompute Factorials and Inverse Factorials
    for (int i = 1; i <= maxN; i++) {
        fact[i] = fact[i - 1] * i % M;
    }
    inv_fact[maxN] = binpow(fact[maxN], M - 2, M);
    for (int i = maxN - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % M;
    }

    int n = 1;
    cin >> n;
    while (n--)
        print_a_choose_b();
}  //* T: O(n + maxN) where n=O(1e5), maxN=O(1e6)