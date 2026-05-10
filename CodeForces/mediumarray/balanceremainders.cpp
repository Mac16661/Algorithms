#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 3]++;
    }

    int target = n / 3;
    int ans = 0;

    // Loop until all categories are balanced
    while (cnt[0] != target || cnt[1] != target || cnt[2] != target) {
        for (int i = 0; i < 3; i++) {
            if (cnt[i] > target) {
                int extra = cnt[i] - target;
                ans += extra;
                cnt[(i + 1) % 3] += extra;
                cnt[i] = target;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

