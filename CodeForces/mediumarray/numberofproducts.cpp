#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int nv = 0, pv = 0;

    for (int i = 0; i < n; i++) {
        long long prod = 1;
        for (int j = i; j < n; j++) {
            if (arr[j] > 0) {
                prod *= 1;
            } else {
                prod *= -1;
            }

            if (prod < 0)
                nv++;
            else
                pv++;
        }
    }

    cout<< nv << " " << pv << endl;

    return 0;
}