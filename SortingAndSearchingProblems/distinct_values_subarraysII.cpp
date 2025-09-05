#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long
#define vi vector<int>
#define len(x) int(x.size())

void solve() {
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mp;   //> tracks unique counts
    multiset<int> ele;  //> tracks actual counts
    ll ans = 0;
    int i = 0, j = 0;
    while (j < n) {
        mp[arr[j]]++;
        ele.insert(arr[j]);

        //> shrink the window until we have atmost 'k' unique elements in [i...j]
        while (len(mp) > k) {
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);
            ele.erase(ele.find(arr[i]));
            i++;
        }

        ans += len(ele);
        j++;
    }

    cout << ans << nl;
}  //* T: O(n*logn), S: O(n)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}