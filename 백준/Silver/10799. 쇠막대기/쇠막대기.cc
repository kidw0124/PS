#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    //freopen("../input.txt", "r", stdin);
    char input;
    char old;
    int result = 0;
    int cnt = 0;
 
    for (int n = 0; cin >> input; n++) {
        if (input == '(')
            cnt++;
        else {
            cnt--;
            if (old == '(')
                result += cnt;
            else
                result++;
        }
        old = input;
    }
    cout << result;
 
    return 0;
}
