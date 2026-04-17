#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int ans=0;
	set<string>arr;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		arr.insert(str);
	}
	for(int i=0;i<m;i++){
		string str;
		cin>>str;
		if(arr.find(str)!=arr.end()){
			ans++;
		}
	}
	cout<<ans;
}