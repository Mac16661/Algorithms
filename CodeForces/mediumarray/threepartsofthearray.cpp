#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    long long maxi = 0;
    long long left = 0, right = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (left == right)
            maxi = max(left, maxi);

        if (left <= right) {
            left += arr[i];
            i++;
        } else {
            right += arr[j];
            j--;
        }
    }

    if (left == right) {
        maxi = max(left, maxi);
    }

    // FIX 2: Always print maxi instead of checking left == right post-loop
    cout << maxi << "\n";

    return 0;
}