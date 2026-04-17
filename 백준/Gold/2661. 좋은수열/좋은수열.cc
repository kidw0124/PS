#include<iostream>
using namespace std;
int n;
string s;
 
bool checking(int  m){
    bool c = 0;
    for (int i = 1; i <= m / 2; i++) {
        c = 0;
        for (int j = 0; j < i; j++) {
            if (s[m - j - 1] == s[m - i - j - 1])continue;
            else {
                c = 1;
                break;
            }
        }
        if (c == 0) {
            s.pop_back();
            break;
        }
    }
    return c;
}
 
bool func(int m) {
    if (n + 1 == m)return 1;
    int i, j;
    s += '1';
    bool c = checking(m);
    if (c || m == 1) {
        if (func(m + 1)) {
            return 1;
        }
        else {
            s.pop_back();
        }
    }
    s += '2';
    c = checking(m);
    if (c) {
        if (func(m + 1)) {
            return 1;
        }
        else {
            s.pop_back();
        }
    }
    s += '3';
    c = checking(m);
    if (c) {
        if (func(m + 1)) {
            return 1;
        }
        else {
            s.pop_back();
            return 0;
        }
    }
    else return 0;
}
 
int main() {
    cin >> n;
    func(1);
    cout << s;
}