#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef kidw0124
constexpr bool isdbg = true;
#else
constexpr bool isdbg = false;
#endif
#define debug(x) if(isdbg)cerr << #x << " = " << x << endl
#define debugp(x) if(isdbg)cerr << #x << " = " << x.first << " " << x.second << endl
#define debugv(x) if(isdbg){cerr << #x << " = "; for(auto i : x)cerr << i << " "; cerr << endl;}
//gp_hash_table<int, int> table;
using namespace __gnu_pbds;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using LL = __int128;
using pll = pair<ll, ll>;
using ld = long double;

template <uint32_t mod> class Mint{
private:
    using  mint = Mint;

    static constexpr uint  get_r()  {
        uint  ret = mod;
        for(int i=0 ; i<4 ; ++i )  ret *= 2 - mod * ret;
        return  ret;
    }

    static constexpr uint  reduce( const ull &b )  {
        return ( b + ull( uint( b ) * uint( -r ) ) * mod ) >> 32;
    }

    // CLASS MEMBER DATA
    static constexpr uint  r  = get_r();
    static constexpr uint  n2 = -ull( mod ) % mod;
    uint                   a;

    static_assert( r * mod == 1, "invalid, r * mod != 1" );
    static_assert( mod < (1 << 30), "invalid, mod >= 2 ^ 30" );
    static_assert( (mod & 1) == 1, "invalid, mod % 2 == 0" );

public:
    constexpr Mint() : a( 0 ) {}
    constexpr Mint( ll b )
            : a( reduce( ull( b % mod + mod ) * n2 ) ) {};

    constexpr mint &operator += ( const mint &b )  {
        if( int( a += b.a - 2 * mod ) < 0 )   a += 2 * mod;
        return  *this;
    }

    constexpr mint &operator -= ( const mint &b )  {
        if( int( a -= b.a ) < 0 )   a += 2 * mod;
        return  *this;
    }

    constexpr mint &operator *= ( const mint &b )  {
        a = reduce( ull( a ) * b.a );
        return  *this;
    }

    constexpr mint &operator /= ( const mint &b )  {
        *this *= b.inverse();
        return  *this;
    }

    constexpr mint operator  + (const mint &b) const { return mint(*this) += b; }
    constexpr mint operator  - (const mint &b) const { return mint(*this) -= b; }
    constexpr mint operator  * (const mint &b) const { return mint(*this) *= b; }
    constexpr mint operator  / (const mint &b) const { return mint(*this) /= b; }
    constexpr bool operator == (const mint &b) const {
        return ( a >= mod ? a - mod : a ) == ( b.a >= mod ? b.a - mod : b.a );
    }
    constexpr bool operator != (const mint &b) const  {
        return ( a >= mod ? a - mod : a ) != ( b.a >= mod ? b.a - mod : b.a );
    }
    constexpr mint operator - () const {  return mint() - mint(*this); }
    mint& operator ++ ()  { return  *this += mint( 1 ); }
    mint& operator -- ()  { return  *this -= mint( 1 ); }
    mint  operator ++ (int)  { mint  ret( *this );  ++*this;  return  ret; }
    mint  operator -- (int)  { mint  ret( *this );  --*this;  return  ret; }

    constexpr mint  pow( ull n ) const  {
        mint  ret( 1 ), mul( *this );
        while( n > 0 )  { if( n & 1 )  ret *= mul;   mul *= mul;  n >>= 1; }
        return  ret;
    }

    constexpr mint  inverse() const { return  pow( mod - 2 ); }

    friend ostream &operator << ( ostream &os, const mint &b )  {
        return  os << b.get();
    }

    friend istream &operator >> ( istream &is, mint &b )  {
        int64_t  t;  is >> t;
        b = Mint<mod>( t );
        return  is;
    }

    constexpr uint  get() const  {
        uint  ret = reduce( a );
        return  ret >= mod ? ret - mod : ret;
    }

    static constexpr uint  get_mod()  { return mod; }
};

template < typename T, bool any = false >
class FormalPowerSeries
{
public:
    using  LL    = int64_t;
    using  FPS   = FormalPowerSeries<T, any>;
    using  VPoly = vector<FPS>;

    vector<T>  a;

public:
    FormalPowerSeries( size_t sz = 0 )  { a.resize( sz, 0 ); }
    FormalPowerSeries( const initializer_list<T>  v )  { a = v; }
    FormalPowerSeries( const vector<T>  &v )  { a = v; }
    FormalPowerSeries( size_t sz, T val )  { a.resize( sz, val ); }
    size_t  size() const { return a.size(); }
    void  resize( size_t sz, T m = 0 )  { (*this).a.resize( sz, m ); }

    FPS  operator - ( const FPS &a ) const { return  FPS(*this) -= a; }
    FPS  operator + ( const FPS &a ) const { return  FPS(*this) += a; }
    FPS  operator * ( const LL a )   const { return  FPS(*this) *= a; }
    FPS  operator * ( const FPS &a ) const { return  FPS(*this) *= a; }
    FPS  operator / ( const FPS &a ) const { return  FPS(*this) /= a; }
    FPS  operator % ( const FPS &a ) const { return  FPS(*this) %= a; }
    FPS  &operator += ( const FPS &r )  {
        this->resize( max( this->size(), r.size() ) );
        for( size_t i=0 ; i<r.size() ; ++i )  this->a[i] += r.a[i];
        return  *this;
    }
    FPS  &operator -= ( const FPS &r )  {
        this->resize( max( this->size(), r.size() ) );
        for( size_t i=0 ; i<r.size() ; ++i )  this->a[i] -= r.a[i];
        return  *this;
    }
    FPS  &operator *= ( const LL v )  {
        for( size_t i=0 ; i<this->size() ; ++i )  this->a[i] *= v;
        return  *this;
    }
    FPS  &operator *= ( const FPS &r )  {
        this->convolution_inplace( r );
        return  *this;
    }
    FPS  &operator /= ( const FPS &r )  {  // = Q OF POLY DIVISION
        if( size() < r.size() )   return *this = FPS( 0 );
        int  n = this->size() - r.size() + 1;
        return *this = ( (*this).rev().low( n ) * r.rev().inverse( n ) ).low( n ).rev();
    }
    FPS  &operator %= ( const FPS &Q )  {
        if( Q.size() > size() )  return *this;
        if( Q.size() < 128 ) {
            int  dQ = Q.size() - 1;
            while( dQ  &&  Q[dQ] == 0 )  --dQ;
            assert( Q[dQ] != 0 );
            for( int i=size()-1 ; i>=dQ ; --i ) {
                if( a[i] == 0 )  continue;
                T  x = a[i] / Q[dQ];
                a[i] = 0;
                for( int j=1 ; j<=dQ ; ++j )
                    a[i-j] -= x * Q[dQ - j];
            }
            shrink();
            return  *this;
        }
        FPS  P = (*this) / Q;
        P *= Q;
        int  dR = -1;
        for( int i=0 ; i<Q.size()-1 ; ++i )  {
            P.a[i] = a[i] - P[i];
            if( P[i] != 0 )  dR = i;
        }
        a.resize( dR + 1 );
        for( int i=0 ; i<=dR ; ++i )  a[i] = P[i];
        shrink();
        return  size() == 0 ? (*this) = FPS( { 0 } ) : (*this );
    }
    FPS  low( int s ) const  {
        return FPS( { a.begin(), a.begin() + min( max( s, 1 ), int( size() ) ) } );
    }
    void shrink()  { while( a.size()  &&  a.back() == 0 )  a.pop_back(); }
    FPS  rev() const  {
        FPS  ret( *this );
        reverse( ret.a.begin(), ret.a.end() );
        return ret;
    }
    FPS  shift( int x )  {
        FPS  ret = *this;
        if( x >= 0 )   ret.a.insert( begin( ret.a ), x, 0 );
        else  ret.a.erase( begin( ret.a ), begin( ret.a ) - x );
        return  ret;
    }
    T  &operator [] ( size_t  x )  {
        assert( x < this->a.size() );
        return  a[x];
    }
    const T  &operator [] ( size_t  x ) const {
        assert( x < this->a.size() );
        return  a[x];
    }
    friend std::ostream &operator << ( std::ostream &os, const FPS &p )  {
        for( auto &v : p.a )   os << v << " ";
        return  os;
    }
    friend istream& operator >> ( istream& is, FPS &p )  {
        for( auto &v : p.a )  { LL w;  is >> w;  v = w; }   return  is;
    }

private:
    void ntt( bool inverse )  {
        static bool  first = true;
        static T  dw[30], idw[30];
        if( first )  {
            first = false;
            T  root = 2;
            unsigned  mod = T::get_mod();
            while( root.pow( (mod - 1) / 2) == 1 )   ++root;
            for( size_t i=0 ; i<30 ; ++i )
                dw[i]  = -root.pow( (mod - 1) >> (i + 2) ),
                        idw[i] = T(1) / dw[i];
        }
        size_t  n = this->size();
        assert( (n & (n - 1) ) == 0 );
        if( not inverse )  {
            for( size_t m=n ; m >>= 1 ; )  {
                T  w = 1;
                for( size_t s=0, k=0 ; s<n ; s+=2*m )  {
                    for( size_t i=s, j=s+m ; i<s+m ; ++i, ++j )  {
                        T  x = a[i],  y = a[j]*w;
                        a[i] = x + y,  a[j] = x - y;
                    }
                    w *= dw[__builtin_ctz( ++k )];
                }
            }
        } else {
            for( size_t m=1 ; m<n ; m*=2 )  {
                T  w = 1;
                for( size_t s=0, k=0 ; s<n ; s+=2*m )  {
                    for( size_t i=s, j=s+m ; i<s+m ; ++i, ++j )  {
                        auto  x = a[i], y = a[j];
                        a[i] = x + y,  a[j] = x - y,  a[j] *= w;
                    }
                    w *= idw[__builtin_ctz( ++k )];
                }
            }
        }
        auto  c = T( 1 ) / T( inverse ? n : 1 );
        for( auto&& e : this->a )  e *= c;
    }

    FPS  convolution_brute( FPS &a, FPS &b ) const  {
        size_t  n = a.size(),  m = b.size();
        FPS  ans( n + m - 1 );
        if( n < m )
            for( size_t j=0 ; j<m ; ++j )
                for( size_t i=0 ; i<n ; ++i )   ans[i+j] += a[i]*b[j];
        else
            for( size_t i=0 ; i<n ; ++i )
                for( size_t j=0 ; j<m ; ++j )   ans[i+j] += a[i]*b[j];
        return ans;
    }

    FPS&  convolution_inplace( FPS b )  {
        if( this->size() == 0  ||  b.size() == 0 )  {
            this->a.clear();  return  *this; }


        size_t  n = this->size(),  m = b.size(),  sz = 1 << __lg( 2*(n+m-1) - 1 );
        if( min( n, m ) <= 60 )   return  *this = convolution_brute( *this, b );
        resize( sz ),       ntt( false );
        b.resize( sz ),   b.ntt( false );
        for( size_t i=0 ; i<sz ; ++i )   a[i] *= b[i];
        ntt( true );  resize( n + m - 1 );
        return  *this;
    }


public:
    // f'(x)
    FPS&  differential_inplace()  {
        const size_t  n = this->a.size();
        assert( n > 0 );
        for( size_t i=1 ; i<n ; ++i )   a[i-1] = a[i] * i;
        a[n-1] = 0;
        return  *this;
    }
    FPS  differential() const { return  FPS( *this ).differential_inplace(); }

    // integral f(x)dx
    FPS&  integral_inplace() {
        const size_t  n = this->a.size();
        assert( n > 0 );
        this->a.insert( this->a.begin(), 0 );
        vector<T>  inv( n + 1 );   inv[1] = 1;
        unsigned  mod = T::get_mod();
        for( size_t i=2 ; i<=n ; ++i )  inv[i] = -inv[mod %i]*( mod/i );
        for( size_t i=2 ; i<=n ; ++i )  this->a[i] *= inv[i];
        return  *this;
    }
    FPS  integral() const { return FPS( *this ).integ_inplace(); }

    // exp(f(x))
    FPS&  exp_inplace( int deg = -1 )  {
        size_t  n = this->size();
        assert( n > 0  &&  a[0] == 0 );
        if( deg == -1 )  deg = int( n );
        FPS  g( { 1 } ),  g_fft;
        this->resize( deg );
        this->a[0] = 1;
        FPS  h_drv = this->differential();
        for( size_t m=1 ; m<deg ; m*=2 )  {
            FPS  f_fft( { a.begin(), a.begin() + m } );
            f_fft.resize( 2*m ), f_fft.ntt( false );
            T  invm = T( 1 ) / m;

            if( m > 1 )  {
                FPS  _f( m );
                for( size_t i=0 ; i<m ; ++i )  _f[i] = f_fft[i] * g_fft[i];
                _f.ntt( true );
                _f.a.erase( _f.a.begin(), _f.a.begin() + m/2 );
                _f.resize( m ),  _f.ntt( false );
                for( size_t i=0 ; i<m ; ++i )  _f[i] *= g_fft[i];
                _f.ntt( true );
                _f.resize( m/2 );
                for( size_t i=0 ; i<m/2 ; ++i )  _f[i] = -_f[i];
                g.a.insert( g.a.end(), _f.a.begin(), _f.a.begin() + m/2 );
            }

            FPS  t( { a.begin(), a.begin() + m } );
            t.differential_inplace();
            {
                FPS  r( { h_drv.a.begin(), h_drv.a.begin() + m - 1 } );
                r.resize( m );  r.ntt( false );
                for( size_t i=0 ; i<m ; ++i )  r[i] *= f_fft[i];
                r.ntt( true );
                t -= r;
                t.a.insert( t.a.begin(), t.a.back() );  t.a.pop_back();
            }

            t.resize( 2*m );  t.ntt( false );
            g_fft = g;  g_fft.resize( 2*m );  g_fft.ntt( false );
            for( size_t i=0 ; i<2*m ; ++i )  t[i] *= g_fft[i];
            t.ntt( true );
            t.resize( m );

            FPS  v( { a.begin() + m, a.begin() + min( deg, int( 2*m ) ) } );
            v.resize( m );
            t.a.insert( t.a.begin(), m-1, 0 );  t.a.push_back( 0 );

            t.integral_inplace();

            for( size_t i=0 ; i<m ; ++i )    v[i] -= t[m+i];
            v.resize( 2*m );  v.ntt( false );
            for( size_t i=0 ; i<2*m ; ++i )  v[i] *= f_fft[i];
            v.ntt( true );
            v.resize( m );

            for( size_t i=0 ; i<min( deg-m, m ) ; ++i )  a[m+i] = v[i];
        }
        return  *this;
    }
    FPS  exp( const int deg = -1 ) const { return  FPS( *this ).exp_inplace( deg ); }

    // log(f(x))
    FPS&  log_inplace( int deg = -1 )  {
        size_t  n = this->size();
        assert( n > 0  &&  this->a[0] == 1 );
        if( deg == -1 )  deg = n;
        if( deg < n )    this->resize( deg );
        FPS  f_inv = this->inverse();
        this->differential_inplace();
        *this *= f_inv;
        this->resize( deg );
        this->integral_inplace();
        this->resize( deg );
        return  *this;
    }
    FPS  log( const int deg = -1 ) const { return FPS( *this ).log_inplace( deg ); }

    // f(x)^-1
    FPS  inverse( int dgr = -1 ) const  {
        size_t  n = this->size();
        assert( n != 0  &&  a[0] != 0 );
        size_t  deg = ( dgr == -1 ) ? n : size_t( dgr );
        FPS  r( { T( 1 ) / a[0] } );

        for( size_t m=1 ; m<deg ; m*=2 )  {
            size_t  twoM = m << 1;
            FPS  f( { a.begin(), a.begin() + min( n, twoM ) } );
            FPS  g( r );
            f.resize( twoM ),  f.ntt( false );
            g.resize( twoM ),  g.ntt( false );
            for( size_t i=0 ; i<twoM ; ++i )  f[i] *= g[i];
            f.ntt( true );
            f.a.erase( f.a.begin(), f.a.begin() + m );
            f.resize( twoM ),  f.ntt( false );
            for( size_t i=0 ; i<twoM ; ++i )  f[i] *= g[i];
            f.ntt( true );
            for( size_t i=0 ; i<twoM ; ++i )  f[i] = -f[i];
            r.a.insert( r.a.end(), f.a.begin(), f.a.begin() + m );
        }
        return  r.low( deg );
    }

    // f(x)^k
    FPS&  pow_inplace( int64_t k )  {
        int64_t  deg = this->size();
        if( k == 0 )  {
            this->a.assign( deg, 0 );
            this->a[0] = 1;
            return  *this;
        }

        int64_t  l = 0;
        while( this->a[l] == 0 )   ++l;
        if( l >= (deg-1)/k + 1 )   return  *this = FPS( deg );
        T  ic = a[l].inverse();
        T  pc = a[l].pow( k );
        a.erase( a.begin(), a.begin() + l );
        *this *= ic.get();
        this->log_inplace();
        *this *= k;
        this->exp_inplace();
        *this *= pc.get();
        this->a.insert( this->a.begin(), l*k, 0 );
        this->resize( deg );
        return  *this;
    }
    FPS  pow( LL k ) const { return FPS(*this).pow_inplace( k ); }
};

const unsigned  mod  = 998244353;
using  FPS  = FormalPowerSeries< Mint<mod> >;

bool isprimitive(Mint<mod> n){
    static vector<ll>divs={499122176, 142606336, 58720256};
    return (n.pow(divs[0])!=1 && n.pow(divs[1])!=1 && n.pow(divs[2])!=1);
}

ll discreate_log(Mint<mod> g,Mint<mod> x){
    ll n=mod-1;
    ll m=sqrt(n)+1;
    unordered_map<ll,ll>mp;
    Mint<mod>now=1;
    for(ll i=0;i<m;i++){
        mp[now.get()]=i;
        now*=g;
    }
    Mint<mod>inv=now.pow(mod-2);
    Mint<mod>base=x;
    for(ll i=0;i<m;i++){
        if(mp.count(base.get())){
            return i*m+mp[base.get()];
        }
        base*=inv;
    }
    return -1;
}

const int two_23=1<<23;
const int seven=7;
const int seventeen=17;

array<vector<int>, seven> croot_7;
array<vector<int>, seventeen> croot_17;

void preprocess() {
    for(int i=0;i<seven;i++) {
        croot_7[i * i * i % seven].push_back(i);
    }
    for(int i=0;i<seventeen;i++) {
        croot_17[i * i * i % seventeen].push_back(i);
    }
}

inline int crt(int x, int y, int z){
//    debug(x);
//    debug(y);
//    debug(z);
    // x mod 2^23, y mod 7, z mod 17
    return (x*981467137ll
            +y*427819008ll
            +z*587202560ll)%(mod-1);
}
void solve() {
    ll i,j;
    ll n,m,l,q=1e18;
    cin>>n>>m>>l;
    FPS x(m+1);
    Mint<mod> now=1;
    ll st=0;

    for(auto &v:x.a) {
        v=Mint<mod>(3).pow(st*st*st);
        now*=Mint<mod>(3);
        if(st++>l){
            v=0;
            break;
        }
    }
//    debug(x);
    FPS y=x.pow(n);
//    debug(y);
//    debug(y.a[m]);
    int a=discreate_log(3,y.a[m])%(mod-1);
//    debug(a);
    if(croot_7[a%seven].empty() || croot_17[a%seventeen].empty()){
        cout<<-1<<'\n';
        return;
    }
    ll ans=mod;
    vector<int>tmp;
    tmp.reserve(32768);
    for(i=(a&1);i<two_23;i+=2) {
        if(i*i%two_23*i%two_23==a%two_23){
            tmp.push_back(i);
        }
    }
    for(const auto &u:tmp){
        for(const auto &v:croot_7[a%seven]){
            for(const auto &w:croot_17[a%seventeen]){
                ans=min(ans,(u*981467137ll
                             +v*427819008ll
                             +w*587202560ll)%(mod-1));
            }
        }
    }
    if(ans==mod){
        cout<<-1<<'\n';
        return;
    }
    cout<<ans<<'\n';
//    if(ans==0) {
//        cerr<<"Error\n";
//        return;
//    }
//    cout<<ans<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}