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
}  //* T: O(1)

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
    cin >> n;  //- Total Number of Brackets
    string s;
    cin >> s;
    ll k = s.size();

    //> Invalid Case 1: n is odd
    if (n % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }

    ll left = 0, right = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '(')
            left++;
        else
            right++;

        //> Invalid Case 2: if any moment right cnt > left cnt; Invalid Sequence
        if (right > left) {
            cout << 0 << "\n";
            return 0;
        }
    }

    //> Invalid Case 3: Left Brackets > no. of pairs
    if (left > n / 2) {
        cout << 0 << "\n";
        return 0;
    }

    ll total = a_choose_b(n - left - right, n / 2 - left);
    ll invalid = 0;
    if (left != n / 2)
        invalid = a_choose_b(n - left - right, n / 2 - left - 1);
    cout << ((total - invalid) % M + M) % M << "\n";

}  //* T: O(maxN) where maxN=O(1e6), S: O(maxN)