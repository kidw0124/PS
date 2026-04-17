#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

LL n;

vector<int> data;

int main(){
    int i,j;

    cin>>n;

    LL k=floor(log2(n-1.0))+1;
    cout<<k<<endl;
    for(i=0;i<k;i++){
        data.clear();
        for(j=1;j<=n;j++){
            if(j/(1<<i)%2){
                data.push_back(j);
            }
        }
        cout<<data.size()<<' ';
        while(!data.empty()){
            cout<<data.back()<<' ';
            data.pop_back();
        }
        cout<<endl;
    }

    return 0;
}
