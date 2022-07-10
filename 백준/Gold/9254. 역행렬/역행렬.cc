#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

template<typename T>class Matrix;
template<typename T>Matrix<T>eyes(size_t);
template<typename T>class Matrix
{
public:
    Matrix(size_t n, size_t m):n(n),m(m){
        elements.resize(n,vector<T>(m));
    }
    Matrix(){
        Matrix(0,0);
    }
    ~Matrix(){
        elements.clear();
    }
    template<typename T1>void operator=(const Matrix<T1>&r){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                this->elements[i][j]=r.elements[i][j];
            }
        }
    }
    Matrix<T> operator+(const Matrix<T>&r)const{
        Matrix<T> ret(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ret.elements[i][j]=elements[i][j]+r.elements[i][j];
            }
        }
        return ret;
    }

    Matrix<T> operator*(const Matrix<T>&r)const{
        Matrix<T> ret(n,r.m);
        for(int i=0;i<n;i++){
            for(int j=0;j<r.m;j++){
                for(int k=0;k<m;k++){
                    ret.elements[i][j]+=elements[i][k]*r.elements[k][j];
                }
            }
        }
        return ret;
    }

    template<typename T1>Matrix<T> operator%(const T1&r)const{
        Matrix<T> ret(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ret.elements[i][j]=elements[i][j]%r;
            }
        }
        return ret;
    }

    Matrix<T> operator^(const ll&r)const{
        if(!r){
            return eyes<T>(n);
        }
        else{
            Matrix<T> half=(*this)^(r>>1);
            if(r&1){
                return half*half*(*this);
            }
            else return half*half;
        }
    }
    pair<bool,Matrix<long double>>inverse()const{
        if(n!=m)return{false,Matrix<long double>()};
        Matrix<long double>org(n,n),ret(n,n);
        org=*this;
        ret.init();
        for(int i=0;i<n;i++){
            int nonz=n;
            for(int j=i;j<n;j++){
                if(org.elements[j][i]){
                    nonz=j;
                    break;
                }
            }
            if(nonz==n)return {false,Matrix<long double>()};
            swap(org.elements[i],org.elements[nonz]);
            swap(ret.elements[i],ret.elements[nonz]);
            long double div=org.elements[i][i];
            for(int j=0;j<n;j++){
                org.elements[i][j]/=div;
                ret.elements[i][j]/=div;
            }
            for(int j=i+1;j<n;j++){
                long double mul=org.elements[j][i];
                for(int k=0;k<n;k++){
                    ret.elements[j][k]-=mul*ret.elements[i][k];
                    org.elements[j][k]-=mul*org.elements[i][k];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                long double mul=org.elements[j][i];
                for(int k=0;k<n;k++){
                    ret.elements[j][k]-=mul*ret.elements[i][k];
                    org.elements[j][k]-=mul*org.elements[i][k];
                }
            }
        }
        return {true,ret};
    }

    Matrix<T> POW(const ll&r,const ll&mod)const{
        if(!r){
            return eyes<T>(n);
        }
        else{
            Matrix<T> half=this->POW(r>>1,mod);
            if(r&1){
                return half*half*(*this)%mod;
            }
            else return half*half%mod;
        }
    }

    Matrix<T> operator+=(const Matrix<T>&r)const{
        return (*this)+r;
    }

    Matrix<T> operator*=(const Matrix<T>&r)const{
        return (*this)*r;
    }
    template<typename T1>Matrix<T> operator%=(const T1&r)const{
        return (*this)%r;
    }
    Matrix<T> operator^=(const ll&r)const{
        return (*this)^r;
    }
    void resize(size_t n, size_t m){
        this->n=n,this->m=m;
        elements.resize(n,vector<T>(m,0));
    }
    void init(){
        for(int i=0;i<min(n,m);i++){
            elements[i][i]=1;
        }
    }

    istream &input(istream&is){
        for(auto&k:elements)for(auto&kk:k)is>>kk;
        return is;
    }

    ostream &print(ostream&os)const{
        for(const auto k:elements){
            for(const auto kk:k){
                os<<kk<<' ';
            }
            os<<'\n';
        }
        return os;
    }
    size_t n,m;
    vector<vector<T>>elements;

protected:
private:
};

template<typename T>Matrix<T>eyes(size_t n){
    Matrix<T> ret(n,n);
    ret.init();
    return ret;
}

template<typename T>istream& operator>>(istream&is, Matrix<T>&M){
    return M.input(is);
}
template<typename T>ostream& operator<<(ostream&os, const Matrix<T>&M){
    return M.print(os);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m,k;
    cin>>n;
    Matrix<ll>A(n,n);
    cin>>A;
    bool b;
    Matrix<long double>AI;
    tie(b,AI)=A.inverse();
    if(b)cout<<fixed<<setprecision(6)<<AI;
    else cout<<"no inverse";
    return 0;
}
