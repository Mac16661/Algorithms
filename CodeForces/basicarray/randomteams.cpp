#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    // Minimum calculation
    ll k = n / m;
    ll r = n % m;
    ll min_pairs = r * (k + 1) * k / 2 + (m - r) * k * (k - 1) / 2;

    // Maximum calculation
    ll i = n - (m - 1);
    ll max_pairs = i * (i - 1) / 2;

    cout << min_pairs << " " << max_pairs << endl;

    return 0;
}
