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
        elements.resize(n,vector<T>(m,0));
    }
    Matrix(){
        Matrix(0,0);
    }
    ~Matrix(){
        elements.clear();
    }

    Matrix<T> operator+(const Matrix<T>&r){
        Matrix<T> ret(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ret.elements[i][j]=elements[i][j]+r.elements[i][j];
            }
        }
        return ret;
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
    ll n,m;
    cin>>n>>m;
    Matrix<double>A(n,m),B(n,m);
    cin>>A>>B;
    cout<<A+B;

    return 0;
}
