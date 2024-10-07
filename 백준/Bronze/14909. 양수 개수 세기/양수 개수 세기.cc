#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    vector<int>arr;
    int tmp;
    while(cin>>tmp){
        arr.push_back(tmp);
    }
    cout<<count_if(arr.begin(),arr.end(),[](int x){
        return x>0;
    });
}
