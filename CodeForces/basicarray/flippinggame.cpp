#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxCnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            int currentCnt = 0;
            for (int k = 0; k < n; k++) {
                int val = a[k];

                if (k >= i && k <= j) {
                    val = 1 - val;
                }

                if (val == 1) {
                    currentCnt++;
                }
            }

            maxCnt = max(maxCnt, currentCnt);            
        }
    }

    cout << maxCnt << endl;
    return 0;
}
