#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	pair<int,int> pl[n];
    for(int i=0;i<n;i++){
        cin>>pl[i].first>>pl[i].second;
    }
    sort(pl,pl+n);
    for(int i=0;i<n;i++){
        cout<<pl[i].first<<' '<<pl[i].second<<'\n';
    }
}
