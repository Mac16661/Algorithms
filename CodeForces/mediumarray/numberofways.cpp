// #include <bits/stdc++.h>

// using namespace std;

// // int solve(int idx, vector<int>& arr, vector<int>& ans, int target) {
// //     // Base case: all elements placed
// //     if (idx == arr.size()) {
// //         return (ans[0] == target && ans[1] == target && ans[2] == target);
// //     }

// //     int count = 0;
// //     for (int i = 0; i < 3; i++) {
// //         ans[i] += arr[idx];
// //         count += solve(idx + 1, arr, ans, target);
// //         ans[i] -= arr[idx]; // Backtrack
        
// //         // Optimization: If current bucket is empty, don't try other empty buckets
// //         if (ans[i] == 0) break; 
// //     }
// //     return count;
// // }

// long long dp[500005][3]; 

// long long solve(int idx, int bucket_idx, long long current_sum, int target, vector<int>& arr) {
//     // Base Case: If we filled 2 buckets and are on the 3rd
//     if (bucket_idx == 2) {
//         // The remaining elements MUST sum to the target
//         // Usually, it's easier to pre-calculate the total remaining sum
//         return 1; // Simplified for logic
//     }
    
//     if (idx >= arr.size()) return 0;
//     if (dp[idx][bucket_idx] != -1) return dp[idx][bucket_idx];

//     long long count = 0;
//     current_sum += arr[idx];

//     // Choice 1: Stay in the same bucket and move to next element
//     count += solve(idx + 1, bucket_idx, current_sum, target, arr);

//     // Choice 2: If current sum matches target, we CAN finish this bucket
//     if (current_sum == target) {
//         count += solve(idx + 1, bucket_idx + 1, 0, target, arr);
//     }

//     return dp[idx][bucket_idx] = count;
// }



// int main () {
//     int n;
//     cin >> n;

//     int sum = 0;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin>> arr[i];
//         sum += arr[i];
//     }

//     if (sum%3 !=0)
//         return 0;

//     vector<int> ans(3);
//     vector<bool> taken(n, false);
//     solve(0, 0, 0, sum/3, arr);

//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    if (total_sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long target = total_sum / 3;
    long long current_sum = 0;
    long long count_s1 = 0; // Number of valid first cut points found so far
    long long total_ways = 0;

    // We iterate to n-1 because the third part must contain at least one element.
    for (int i = 0; i < n - 1; i++) {
        current_sum += a[i];

        // If we hit 2/3 of the sum, it could be the end of the second part.
        // It can be paired with any 1/3 sum point we saw EARLIER.
        // i > 0 ensures there's at least one element in the first part.
        if (current_sum == 2 * target && i > 0) {
            total_ways += count_s1;
        }

        // If we hit 1/3 of the sum, increment count of potential first parts.
        if (current_sum == target) {
            count_s1++;
        }
    }

    cout << total_ways << endl;
    return 0;
}
