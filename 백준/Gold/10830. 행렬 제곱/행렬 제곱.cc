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
            Matrix<T> eyes(n,n);
            for(int i=0;i<n;i++)eyes.elements[i][i]=1;
            return eyes;
        }
        else{
            Matrix<T> half=(*this)^(r>>1);
            if(r&1){
                return half*half*(*this);
            }
            else return half*half;
        }
    }

    Matrix<T> POW(const ll&r,const ll&mod)const{
        if(!r){
            Matrix<T> eyes(n,n);
            for(int i=0;i<n;i++)eyes.elements[i][i]=1;
            return eyes;
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
        return *this+r;
    }

    Matrix<T> operator*=(const Matrix<T>&r)const{
        return *this*r;
    }

    void resize(size_t n, size_t m){
        this->n=n,this->m=m;
        elements.resize(n,vector<T>(m,0));
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

protected:
private:
    size_t n,m;
    vector<vector<T>>elements;
};

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
    cin>>n>>m;
    Matrix<ll>A(n,n);
    cin>>A;
    cout<<A.POW(m,1000);

    return 0;
}
