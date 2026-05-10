#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    set<char> distinct_chars(s.begin(), s.end());

    if (distinct_chars.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }
    
    return 0;
}
