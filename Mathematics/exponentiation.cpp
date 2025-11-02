#include <bits/stdc++.h>
using namespace std;

#define ll long long

//> Binary Exponentiation Iterative
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
}//* T:O(log(b))

//> Binary Multiplication Iterative
ll binmul(ll a, ll b, ll M) {
    //! needed when M <= 1e18
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = (res + a) % M;

        // get next power of 2
        a = (a + a) % M;
        b >>= 1;
    }

    return res;
}//* T:O(log(b))

int main() {
    int n;
    cin >> n;

    ll M = 1e9 + 7;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << binpow(a, b, M) << '\n';
    }
}  //* T: O(n*log(b)), S:O(1)