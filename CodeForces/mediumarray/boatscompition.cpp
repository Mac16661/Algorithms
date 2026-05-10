#include<bits/stdc++.h>

using namespace std;

// void solve() {
//     int n;
//     cin >> n;

//     int sum = 0;
//     vector<int> nums(n);
//     unordered_map<int, int> mpMain;
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//         sum += nums[i];
//         mpMain[nums[i]]++;
//     }
//     int Mcnt = 0;
//     // may not need to go till sum (can start form min as well)
//     for (int i = 0; i <= sum/2; i++) {
//         unordered_map<int, int> mp = mpMain;
//         int t = i;
//         int cnt = 0;
//         for (int t1 : nums) {
//             // player already been taken
//             if (mp[t1] == 0)
//                 continue;

//             int t2 = t - t1;
//             mp[t1]--;

//             // search for second teammate
//             if (mp.count(t2) && mp[t2] > 0) {
//                 cnt++;
//                 mp[t2]--;
//             }else {
//                 mp[t1]++;
//             }
//         }
//         Mcnt = max(Mcnt, cnt);
//     }

//     cout << Mcnt << endl;
// }

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        cnt[w]++;
    }

    int max_teams = 0;
    // Possible sums range from 2 to 2n
    for (int s = 2; s <= 2 * n; s++) {
        int current_teams = 0;
        // Check weight pairs (i, s-i)
        for (int i = 1; i < (s + 1) / 2; i++) {
            if (s - i <= n) {
                current_teams += min(cnt[i], cnt[s - i]);
            }
        }
        // Handle the case where the two weights are the same (e.g., s=6, i=3)
        if (s % 2 == 0 && s / 2 <= n) {
            current_teams += cnt[s / 2] / 2;
        }
        max_teams = max(max_teams, current_teams);
    }

    cout << max_teams << endl;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}