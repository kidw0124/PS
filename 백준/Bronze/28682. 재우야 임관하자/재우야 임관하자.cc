#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> domain({"swimming","bowling","soccer"});
    int r=1500;
    cin>>r;
    vector<int> arr(r),brr(r);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> uid(0,2);
    for(int i=0;i<r;i++){
        arr[i]=uid(rng);
        cout<<domain[arr[i]]<<' ';
    }
    cout<<'\n';
    cout<<flush;
    for(int i=0;i<r;i++){
        string s;
        cin>>s;
        brr[i]=find(domain.begin(),domain.end(),s)-domain.begin();
    }
    for(int i=0;i<r;i++){
        cout<<domain[3-arr[i]-brr[i]]<<' ';
    }
    cout<<'\n';
    cout<<flush;
}