#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
}

int main() {
    int n;
    cin >> n;

    ll M = 1e9 + 7;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, M - 1), M) << '\n';
    }
}  //* T: O(n*(log(b) + log(c))), S:O(1)