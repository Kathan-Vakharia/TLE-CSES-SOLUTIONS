#include <bits/stdc++.h>
using namespace std;
#define ll long long

//> Enumerating Primes using Sieve in O(maxN)
const int maxN = 1e6 + 10;
vector<ll> primes_list;
vector<bool> is_prime(maxN, true);
void init_primes() {
    for (int i = 2; i * i <= maxN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxN; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= maxN; i++)
        if (is_prime[i])
            primes_list.push_back(i);
}
/*
? Why i only goes till sqrt(N)??
- Every composite number ≤ N has at least one prime factor ≤ √N.
- By the time you reach √N:
- Every composite number ≤ N has already been marked by one of its smaller prime factors
- Any number still marked as prime beyond √N is actually prime (because if it were composite, we would have marked it already)

> Concrete Example: N = 100
> √100 = 10, so we only check i = 2, 3, 5, 7 (primes up to 10)

*/
//> Primality Check: Go through all the 8e4 primes
bool is_prime_sot(ll num) {
    for (auto p : primes_list) {
        if (p < num && num % p == 0) return false;
    }
    return true;
}

//> optimised primality check: sqrt(n)
bool is_prime_sqrtn(ll num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (ll i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    //- enumerate primes
    init_primes();

    while (t--) {
        ll num;
        cin >> num;
        for (ll x = num + 1;; x++) {
            //* or is_prime_sqrtn(x)
            if (is_prime_sot(x)) {
                cout << x << '\n';
                break;
            }
        }
    }

}  //* Time for is_prime_sqrtn: O(t*gap*sqrt(1e12))
   //* Time for is_prime_sot: O(t*gap*8e4) + O(1e6)