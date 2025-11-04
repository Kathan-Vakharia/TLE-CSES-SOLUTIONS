#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 5;
vector<int> cnt(maxN, 0);

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    //> Find largest 'x' with atleast two multiples
    for (int i = maxN; i >= 1; i--) {
        int tot = 0;
        for (int j = i; j <= maxN; j += i) {
            tot += cnt[j];
            if (tot >= 2) {
                cout << i << '\n';
                return 0;
            }
        }
    }
}  //* T:O(maxN*log(maxN)), S:O(maxN) where maxN = O(1e6)