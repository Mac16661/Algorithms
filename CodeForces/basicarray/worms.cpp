#include <bits/stdc++.h>

using namespace std;

int linear(vector<int>& arr, int q) {
    int ans = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] >= q)
            ans = i;
    }   

    // cout <<"\n\n" << ans+1 << " - > " << arr[ans] << endl;
    return ans+1;
}

int binarySrch(vector<int>& arr, int q) {
    int l = 0;
    int r = arr.size() - 1;
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] >= q) {
            ans = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    return ans + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> pref(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        if (i == 0)
            pref[i] = arr[i];
        else
            pref[i] = pref[i - 1] + arr[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int qs;
        cin >> qs;
        cout << binarySrch(pref, qs) << endl;
    }

    return 0;
}