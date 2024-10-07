#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    string input;
    cin >> input;
    vector<int> cnt(26);
    for(auto x:input){
        if(islower(x))cnt[x-'a']++;
        else if(isupper(x))cnt[x-'A']++;
    }
    int max_cnt = *max_element(cnt.begin(), cnt.end());
    int how_many = count(cnt.begin(), cnt.end(),max_cnt);
    if (how_many == 1) {
        cout << char(max_element(cnt.begin(), cnt.end())-cnt.begin()+'A');
    } else {
        cout << "?";
    }
}
