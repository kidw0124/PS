#include<bits/stdc++.h>
using namespace std;

int main(){
//    string s; cin >> s;
//    int n = s.size();
//    vector p(2 * n + 1, 0);
//    for (int i = 1; i <= n; i++) {
//        char c = s[i - 1];
//        if (c == '(') p[i] = p[i + n] = 1;
//        else p[i] = p[i + n] = -1;
//    }
//    for (int i = 1; i <= 2 * n; i++) p[i] += p[i - 1];
//
//    multiset<int> ms;
//    for (int i = 1; i <= n; i++) ms.insert(p[i]);
//
//    auto sol = [&]() {
//        for (int i = 1; i < n; i++) {
//            if (p[i] == 0 && *ms.begin() == 0) return i;
//            ms.erase(ms.find(p[i]));
//            ms.insert(p[i + n]);
//        }
//        return -1;
//    };
//
//    int res = sol();
//    cout << res << '\n';
//    if (res == -1) cout << "no" << '\n';
//    else {
//        for (int i = res; i < n; i++) cout << s[i];
//        for (int i = 0; i < res; i++) cout << s[i];
//    }
    string str;
    cin>>str;
    int n=str.size();
    if(n==1){
        cout<<stoi(str)+1;
    }
    else{
        string tmp;
        for(int i=0;i<n;i++){
            tmp+=str[0];
        }
        if(str>=tmp){
            cout<<(n-1)*10+str[0]-'0';
        }
        else cout<<(n-1)*10+str[0]-'0'-1;
    }
}