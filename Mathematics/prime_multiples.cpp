#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    int k;
    cin >> n >> k;

    vector<ll> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    ll ans = 0;
    for (int b = 1; b < (1 << k); b++) {
        // b's bit combination represents a subset

        ll prod = 1;
        bool not_possible = false;
        for (int i = 0; i < k; i++) {
            // take contribution of primes in this subset
            if (b & (1 << i)) {
                if (primes[i] > n / prod) {
                    not_possible = true;
                    break;
                    //- no numbers are divisible by every one of these subset of primes
                }
                prod *= primes[i];
            }
        }

        if (not_possible) continue;

        ll term = n / prod;
        //> if even number of 1s
        if (__builtin_parity(b) == 0) term = -term;
        ans += term;
    }
    cout << ans << '\n';
    return 0;
}//* T:O(k*2^k), S:O(2^k)