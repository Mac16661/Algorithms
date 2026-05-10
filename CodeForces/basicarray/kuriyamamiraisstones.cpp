#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    // Use long long to prevent overflow
    vector<int> arr(n);
    vector<long long> prefix(n + 1, 0), stPrefix(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) {
        stPrefix[i] = stPrefix[i - 1] + arr[i - 1];
    }
    
    int m; 
    cin >> m;

    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;

        long long sum = 0;
        if (type == 1) {
            sum = prefix[r] - prefix[l - 1];
        } else {
            sum = stPrefix[r] - stPrefix[l - 1];
        }
        cout << sum << endl;
    }

    return 0;
}
