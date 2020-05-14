/*
 * https://github.com/luciocf/Problems/blob/master/CCO/CCO%202018/boring.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , k , q ;
int a [1000009] ; 
pi que [100009] ;
int done [1000009] , Mx [1000009] , ans [100009] ; 
inline int solve () {
	int ret = 0 ;
	deque < pi > dq ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		while ( dq .size () && i - dq .front () .se  >= k ) dq .pop_front () ;
		if ( done [i] ) {
			if ( dq .size() ) Mx [i] = max ( Mx [i] , dq .front () .fi ) ;
			C ; 
		}
		if ( dq .size () ) ret = max ( ret , a [i] + dq .front () .fi ) ;
		while ( dq .size () && a [i] >= dq .back () .fi ) dq .ppb () ; 
		dq .pb ( { a[i] , i } ) ;
	}
	dq .clear () ;
	for ( int i = n-1 ; i >= 0  ; i -- ) {
                while ( dq .size () && dq .front () .se - i >= k ) dq .pop_front () ;
                if ( done [i] ) {
                        if ( dq .size () ) Mx [i] = max ( Mx [i] , dq .front () .fi ) ;
                        C ;
                }
                if ( dq .size () ) ret = max ( ret , a [i] + dq .front () .fi ) ;
                while ( dq .size () && a [i] >= dq .back () .fi ) dq .ppb () ;
                dq .pb ( { a[i] , i } ) ;
        }
	return ret ; 
}
void scan(int &x)
{
    int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

inline void print(int n)
{
	if (n == 0)
	{
		putchar_unlocked('0');
		putchar_unlocked('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while (n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while (buf[i] != '\n') putchar_unlocked(buf[++i]);
	}
}
int main () {
	scan(n) , scan(k) , scan(q) ; 
	q ++ ;
	for ( int i = 0 ; i < n ; i ++ ) scan(a[i]) ; 
	que [0] = { 0 , a [0] } ;
	for ( int i = 1 ; i < q ; i ++ ) {
		scan(que[i].fi) , scan(que[i].se);
		que [i] .fi -- ; 
	}
	for ( int i = 0 ; i < q ; i += sqr ) {
		int Q = min ( ( ( i / sqr ) + 1 ) * sqr , q ) ; 
		vi v ;
		for ( int j = i ; j < Q ; j ++ ) {
			if ( ! done [ que [j] . fi ] ) v .pb ( que [j] . fi ) ;
			done [ que [j] . fi ] = 1 ;	
		}
		sort ( all ( v ) ) ;
		int least = solve () ; 
		for ( int j = i ; j < Q ; j ++ ) {
			ans [j] = least ;
			a [ que [j] .fi ] = que [j] .se ;
			done [ que [j] .fi ] = 0 ;
			deque < pi > dq ;
			for ( auto u : v ) {
				while ( dq .size () && u - dq .front () .se >= k ) dq .pop_front () ;
				if ( dq .size () ) ans [j] = max ( ans [j] , a [u] + dq .front () .fi ) ;
				while ( dq .size () && a [u] >= dq . back () .fi ) dq .ppb () ;
				dq .pb ( { a [u] , u } ) ;
			}
			dq .clear () ;
			for ( int it = v .size () -1 ; it >= 0 ; it -- ) {
				int u = v [it] ; 
				while ( dq .size () && dq .front () .se - u >= k ) dq .pop_front () ;
                                if ( dq .size () ) ans [j] = max ( ans [j] , a [u] + dq .front () .fi ) ;
                                while ( dq .size () && a [u] >= dq . back () .fi ) dq .ppb () ;
                                dq .pb ( { a [u] , u } ) ;
			}
			for ( int it = i ; it < Q ; it ++ ) {
				ans [j] = max ( ans [j] , Mx [ que [it] .fi ] + a [ que [it] .fi ] ) ;
			}
		}
		for ( int j = i ; j < Q ; j ++ ) Mx [ que[j].fi ] = 0 ;
	}
	for ( int i = 0 ; i < q ; i ++ ) print(ans[i]); 
}
