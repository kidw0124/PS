#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin>>x;
    }
    int idx=min_element(arr.begin(),arr.end())-arr.begin();
    cout<<arr[idx]<<" ";
    int val=*max_element(arr.begin(),arr.end());
    cout<<val<<'\n';
}
