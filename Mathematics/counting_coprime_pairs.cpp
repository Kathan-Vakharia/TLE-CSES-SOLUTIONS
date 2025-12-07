#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6;

int main() {
    //> tracks frequency of product combination
    vector<int> total_pc(N + 1);
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& a : arr) cin >> a;
    vector<int> pfactors;
    auto find_pfactors = [&](int x) {
        //- ensure vector is empty
        pfactors.clear();

        for (int f = 2; f * f <= x; f++) {
            if (x % f == 0) {
                pfactors.emplace_back(f);
                while (x % f == 0) x /= f;
            }
        }
        if (x != 1) pfactors.emplace_back(x);
    };

    ll res = 0;
    for (int i = 0; i < n; i++) {
        //> 1. Find factors of arr[i]
        find_pfactors(arr[i]);
        int k = pfactors.size();  // k <= 7

        // Find all a[j]; j<i s.t a[i],a[j] share a prod combination
        //> Go through all the prod combination
        for (int b = 1; b < (1 << k); b++) {
            int prod = 1;
            for (int i = 0; i < k; i++) {
                // take contribution of p
                if (b & (1 << i))
                    prod *= pfactors[i];
            }

            int term = total_pc[prod];
            //> if ther are odd number of 1s in 'b'
            if (__builtin_parity(b) == 0) term = -term;
            res += term;

            //* Update frequency of this prod comb
            total_pc[prod]++;
        }
    }

    cout << (n * 1LL * (n - 1)) / 2 - res << '\n';

    return 0;
}  //* T: n*(sqrt(xi) + k*2^k ) = 1e5(1e3 + 1e3) ~ 1e8