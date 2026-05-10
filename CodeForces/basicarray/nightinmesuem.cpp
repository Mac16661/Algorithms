#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    
    char current = 'a';
    int total_rotations = 0;
    
    for (char target : s) {
        int difference = abs(target - current);

        total_rotations += min(difference, 26 - difference);

        current = target;
    }
    
    cout << total_rotations << endl;
    
    return 0;
}
