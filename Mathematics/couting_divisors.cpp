#include <bits/stdc++.h>
using namespace std;

int solve_in_sqrt_x(int x) {
    int div_cnt = 0;

    for (int i = 1; i * i <= x; i++) {
        //> add contribution of {i, n/i}
        if (x % i == 0) {
            div_cnt++;
            if (x / i != i)
                div_cnt++;
        }
    }
    return div_cnt;
}  //* T:O(sqrt(x)), S:O(1)

const int maxN = 1e6 + 5;
vector<int> div_cnt(maxN, 0);

int main() {
    int n;
    cin >> n;

    //> Precomputation of divisor_cnt
    for (int i = 1; i <= maxN; i++) {
        for (int j = i; j <= maxN; j += i) {
            div_cnt[j]++;
        }
    }  //* T: O(maxN(log(maxN))) = O(1e6*log(1e6)) = O(2e7)

    while (n--) {
        int x;
        cin >> x;
        // cout << solve_in_sqrt_x(x) << '\n';
        cout << div_cnt[x] << '\n';
    }
}