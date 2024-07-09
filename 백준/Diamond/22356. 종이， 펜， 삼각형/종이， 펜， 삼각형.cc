#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void fft(vector<complex<ld>> &a, bool inv){
    int n = a.size();
    for(int i=1,j=0;i<n;i++){
        int bit = n>>1;
        for(;j>=bit;bit>>=1)j-=bit;
        j+=bit;
        if(i<j)swap(a[i],a[j]);
    }
    for(int i=1;i<n;i<<=1){
        ld x = inv?-1:1;
        complex<ld> w = {cos(acos(-1)*x/i),sin(acos(-1)*x/i)};
        for(int j=0;j<n;j+=i<<1){
            complex<ld> th = {1,0};
            for(int k=0;k<i;k++){
                complex<ld> tmp = a[i+j+k]*th;
                a[i+j+k] = a[j+k]-tmp;
                a[j+k] += tmp;
                th *= w;
            }
        }
    }
    if(inv){
        for(int i=0;i<n;i++)a[i]/=n;
    }
}

vector<ll> multiply_fft(vector<ll>a, vector<ll>b){
    vector<ll> ret(a.size()+b.size()-1);
    int n = 1;
    while(n<a.size()+b.size())n<<=1;
    vector<complex<ld>> A(n), B(n);
    for(int i=0;i<a.size();i++)A[i]=a[i];
    for(int i=0;i<b.size();i++)B[i]=b[i];
    fft(A,0);
    fft(B,0);
    for(int i=0;i<n;i++)A[i]*=B[i];
    fft(A,1);
    for(int i=0;i<ret.size();i++)ret[i]=round(A[i].real());
    return ret;
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    ll i,j;
    ll n,m;
    cin>>m>>n;
    vector<vector<ll>> arr(3,vector<ll>(m+1)), sum(3,vector<ll>(m+1));
    arr[0][0]=arr[1][0]=arr[2][0]=sum[0][0]=sum[1][0]=sum[2][0]=1;
    for(i=0;i<n;i++){
        ll d, l;
        cin>>d>>l;
        if(d==120)l=m-l;
        arr[d/60][l]++;
    }
    for(i=0;i<3;i++){
        for(j=1;j<=m;j++){
            sum[i][j]=sum[i][j-1]+arr[i][j];
        }
    }
    ll ans=sum[0][m/2]*sum[1][m/2]*sum[2][m/2];
    for(i=m/2+1;i<=m;i++){
        ans+=arr[0][i]*sum[1][m-i]*sum[2][m-i];
        ans+=arr[1][i]*sum[0][m-i]*sum[2][m-i];
        ans+=arr[2][i]*sum[0][m-i]*sum[1][m-i];
    }
    ans-= multiply_fft(multiply_fft(arr[0],arr[1]),arr[2])[m];
    cout<<ans;

}