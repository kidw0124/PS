#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void preprocess() {
    ;
}

void solve() {
    ll i,j;
    ll n, m, p, q, r, tmp;
    cin >> n;
    vector<ll>arr(n),brr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    for(i=0;i<n;i++)cin>>brr[i];
    if(count(arr.begin(), arr.end(),1)==0 && count(arr.begin(), arr.end(),2)==0){
        cout<<"0 0\n";
        return;
    }
    else if(count(arr.begin(), arr.end(),1)==0){
        ll sum=0;
        for(i=0;i<n;i++)sum+=brr[i];
        cout<<"0 "<<sum<<"\n";
        return;
    }
    else if(count(arr.begin(), arr.end(),2)==0){
        ll sum=0;
        for(i=0;i<n;i++)sum+=brr[i];
        cout<<sum<<" 0\n";
        return;
    }
    vector<ll>ans(3);
    priority_queue<ll>pq;
    ll rot=0;
    while(arr[rot]!=1)rot++;
    rotate(arr.begin(),arr.begin()+rot,arr.end());
    rotate(brr.begin(),brr.begin()+rot,brr.end());
    arr.push_back(1);
    brr.push_back(0);
    for(i=0;i<n;){
        if(arr[i]) {
            ll now = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j])break;
            }
            if(arr[now]==arr[j]){
                for(i=now+1;i<j;i++){
                    arr[i]=arr[now];
                }
            }
            else{
                ll st=now+1,en=j-1;
                while(st<en){
                    arr[st++]=arr[now],arr[en--]=arr[j];
                }
                if(st==en){
                    pq.push(brr[st]);
                }
            }
            i=j;
        }
    }
    for(i=0;i<n;i++){
        ans[arr[i]]+=brr[i];
    }
    ll x=1;
    while(pq.size()){
        ll tmp=pq.top();
        pq.pop();
        ans[x]+=tmp;
        x=1+!(x-1);
    }
    cout<<ans[1]<<' '<<ans[2];

}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
}