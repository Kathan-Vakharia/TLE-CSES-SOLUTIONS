#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

const int maxN = 2e5 + 10;
vector<int> spf(maxN + 1, 1e9);
vector<bool> isPrime(maxN + 1, true);
void init_spfs() {
    for (ll i = 2; i <= maxN; i++) {
        if (!isPrime[i])
            continue;

        //> i is a prime
        spf[i] = i;
        for (ll j = i * i; j <= maxN; j += i) {
            isPrime[j] = false;
            spf[j] = min(spf[j], (int)i);
        }
    }
}

int dfs(int i, vector<int>& p, vector<int>& vis) {
    int len = 0, u = i;
    while (!vis[u]) {
        vis[u] = 1;
        u = p[u];
        len++;
    }
    return len;
}

void in_sqrtN(int n, map<int, int>& mp) {
    for (int x = 2; x * x <= n; x++) {
        int c = 0;
        while (n % x == 0) n /= x, c++;
        mp[x] = max(mp[x], c);
    }
    if (n > 1) mp[n] = max(mp[n], 1);
}

void in_logN(int n, map<int, int>& mp) {
    while (n != 1) {
        int x = spf[n], c = 0;
        while (n % x == 0) n /= x, c++;
        mp[x] = max(mp[x], c);
    }
}

ll lcm_mod(set<int>& nums) {
    map<int, int> mp;
    for (int n : nums) {
        // in_sqrtN(n,mp);
        in_logN(n, mp);
    }
    ll res = 1;
    for (auto [pr, c] : mp) {
        while (c--) res = res * pr % MOD;
    }
    return res;
}

int main() {
    // Find Smallest Prime Factors using Sieve
    init_spfs();

    int n;
    cin >> n;
    vector<int> p(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    // Find all cycles
    set<int> cyc;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) cyc.insert(dfs(i, p, vis));
    }

    // Calculate LCM of cycle lengths modulo MOD
    cout << lcm_mod(cyc) << "\n";
}
/*
⏰ Time Complexity Analysis
* Finding All Cycles using DFS: O(n)
    - Loop through n elements, each processed once
    - Each element visited exactly once across all DFS calls


* LCM Calculation:
    > Way 1: Prime Factorization using Trial Division: O(n√n)
    For each cycle length c in set (at most n elements):
        - Prime factorization: O(√c) per number
        - Worst case: all cycle lengths are distinct primes near n
        - Total: O(k · √n) where k = number of cycles ≤ n
        - O(n√n) worst case

    > Way 2: Prime Factorization using Precomputed SPFs: O(n log n) + maxN(log log maxN)
    For each cycle length c in set:
        - Prime factorization: O(log c) per number using SPFs
        - Worst case: all cycle lengths are distinct primes near n
        - Total: O(k · log n) where k = number of cycles ≤ n
        - O(n log n) worst case

* Building Result: O(n)
For each prime power in map:
    - Multiply 'cnt' times with modulo
    - Max distinct primes in [1, n]: O(n/log n)
    - Max exponent for prime p: O(log n) (since p^x ≤ n)
    - Total multiplications: O(n)

* Overall: O(n√n) or O(n log n) depending on factorization method
* Space: O(n) for visited array, permutation, and cycle set.
*/