#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define len(x) int((x).size())
#define ll long long

int count_digits(ll n) {
    if (n == 0) return 1;
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

void solve() {
    int q;
    cin >> q;

    while (q--) {
        ll k;
        cin >> k;

        ll digits = 1;  // Current digit length
        ll count = 9;   // Count of numbers with 'digits' digits
        ll start = 1;   // Starting position for numbers with 'digits' digits

        // Find which digit-length group contains position k
        while (k > start + digits * count - 1) {
            start += digits * count;  // Move to next group's starting position
            digits++;                 // Increment digit length
            count *= 10;              // Next group has 10x more numbers
        }

        // Now we know k is in the group of 'digits'-digit numbers
        ll first_num = pow(10, digits - 1);  // First number with 'digits' digits
        ll offset = (k - start) / digits;    // Which number in this group
        ll target_num = first_num + offset;  // The actual number containing position k

        // Find which digit within target_num
        string num_str = to_string(target_num);
        ll pos_in_num = (k - start) % digits;

        cout << num_str[pos_in_num] << "\n";
    }
}

/*





*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
}