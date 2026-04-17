#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>arr[100005];
long long ans;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int i,j;
    for(i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        arr[t2].push_back(t1);
    }
    for(i=1;i<=n;i++){
        sort(arr[i].begin(),arr[i].end());
        if(arr[i].size()<=1)continue;
        else{
            int s=arr[i].size();
            for(j=0;j<s;j++){
                if(j==0)ans+=arr[i][1]-arr[i][0];
                else if(j==s-1)ans+=arr[i][s-1]-arr[i][s-2];
                else ans+=min(arr[i][j+1]-arr[i][j],arr[i][j]-arr[i][j-1]);
            }
        }
    }
    cout<<ans;


    return 0;
}
