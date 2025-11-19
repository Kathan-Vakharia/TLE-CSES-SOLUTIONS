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
int main() {
    string s;
    cin >> s;
    int n = s.size();

    //> Precompute Factorials
    for (int i = 1; i <= maxN; i++) {
        fact[i] = fact[i - 1] * i % M;
    }

    //> Count frequency of each character: f1, f2, f3,...,f26
    map<char, int> mp;
    for (auto ch : s)
        mp[ch]++;

    ll num = fact[n];  //> n!
    ll den = 1;        // > f1! * f2! * ... * f26!
    for (auto& [c, f] : mp)
        den = den * fact[f] % M;

    // > Result: n! / (f1! * f2! * ... * f26!) % M
    cout << num * binpow(den, M - 2, M) % M << "\n";

}  //* T: O(n + log M) = O(1e6), S:O(26); n = O(1e6), M = 1e9+7
   //* where O(1e6) for precomputing factorials, and O(log M) for modular inverse calculation