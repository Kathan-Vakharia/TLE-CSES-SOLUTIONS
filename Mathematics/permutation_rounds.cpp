
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

int dfs(int i, vector<int>& p, vector<int>& vis) {
    int len = 0, u = i;
    while (!vis[u]) {
        vis[u] = 1;
        u = p[u];
        len++;
    }
    return len;
}

ll lcm_mod(set<int>& nums) {
    map<int, int> mp;
    for (int n : nums) {
        for (int x = 2; x * x <= n; x++) {
            int c = 0;
            while (n % x == 0) n /= x, c++;
            mp[x] = max(mp[x], c);
        }
        if (n > 1) mp[n] = max(mp[n], 1);
    }
    ll res = 1;
    for (auto [pr, c] : mp) {
        while (c--) res = res * pr % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    set<int> cyc;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) cyc.insert(dfs(i, p, vis));
    }

    cout << lcm_mod(cyc) << "\n";
}  //* T:O(n*sqrt(n)), S:O(n)

/*
Time Complexity Analysis
DFS (Cycle Detection):

Each element visited exactly once across all DFS calls
O(n)

Finding All Cycles:

Loop through n elements, each processed once
O(n)

LCM Calculation:

For each cycle length c in set (at most n elements):

Prime factorization: O(√c) per number


Worst case: all cycle lengths are distinct primes near n
Total: O(k · √n) where k = number of cycles ≤ n
O(n√n) worst case

Building Result:

For each prime power in map:

Multiply cnt times with modulo


Max distinct primes in [1, n]: O(n/log n)
Max exponent for prime p: O(log n) (since p^x ≤ n)
Total multiplications: O(n)

Overall: O(n√n)
Space: O(n) for visited array, permutation, and cycle set.

For n ≤ 2×10^5:

Operations ≈ 2×10^5 × 450 ≈ 9×10^7
Runs comfortably within time limits (~0.1-0.2s)
*/