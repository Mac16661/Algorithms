#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n; 
	cin >> n;

	vector<int> arr(n);
	int sum = 0;
	for (auto i=0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum % n != 0) {
		cout << -1 << endl;
		return;
	}

	int t = sum / n;

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > t) k++;
	}

	cout << k << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
