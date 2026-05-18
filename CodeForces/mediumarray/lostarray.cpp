#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> D(n + 1);
    for (int i = 1; i <=n; i++) {
        D[i] = a[i] - a[i-1];
    }

    vector<int> valid_k;

    // checking every possible len k
    for (int k = 1; k <=n; k++) {
        bool possible = true;
        for (int i = 1; i <= n-k; i++) {
            if (D[i] != D[i+k]) {
                possible = false;
                break;
            }
        }

        if (possible)
            valid_k.push_back(k);
    }

    // Step 3: Output the count and the valid k values
    cout << valid_k.size() << "\n";
    for (int i = 0; i < valid_k.size(); ++i) {
        cout << valid_k[i] << (i == valid_k.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}