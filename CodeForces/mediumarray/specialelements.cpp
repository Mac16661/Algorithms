#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        // Pre calculating all the possible sum combinations l and r
         // A boolean array handles up to N perfectly and uses virtually no memory
        vector<bool> possible_sum(n + 1, false);

        for (int j = 0; j < n; j++) {
            int sum = 0; 
            for (int k = j; k < n; k++) {
                sum += arr[k];

                // Optimization: if sum exceeds n, it can never match any arr[i]
                // Since arr[i] >= 1, further elements will only make it larger
                if (sum > n) {
                    break; 
                }

                // k > j ensures at least 2 elements are picked
                if (k > j) {
                    possible_sum[sum] = true;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // true O(1) check
            if (possible_sum[arr[i]]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
