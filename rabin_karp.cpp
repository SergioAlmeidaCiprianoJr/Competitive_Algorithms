#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
const ll p {31}, q {1000000007};

int f(char c);
int h(const string& S, int size);
ll fast_exp_mod(ll a, ll n);
int rabin_karp(const string& S, const string& P);

int main(){
	
	cout << rabin_karp("teptep", "tep") << '\n';
	return 0;
}
int f(char c){ return c - 'a' + 1; }
int h(const string& S, int size)
{
	ll ans = 0;
	for(int i = size-1; i>=0; i--)
	{
		ans = (ans * p) % q;
		ans = (ans + f(S[i])) % q;
	}
	return ans;
}
ll fast_exp_mod(ll a, ll n)
{
	ll res = 1, base = a;
	while(n)
	{
		if(n & 1)
			res = (res * base) % q;

		base = (base * base) % q;
		n >>= 1;
	}
	return res;
}
int rabin_karp(const string& S, const string& P)
{
	int n = S.size(), m = P.size(), occ = 0, hs = h(S, m), hp = h(P, m);
	ll femq = fast_exp_mod(p, q-2), femm = fast_exp_mod(p, m-1);
	for(int i = 0; i < n-m+1 ; ++i)
	{
		occ += (hs == hp) ? 1 : 0;
		if(i != n-m)
		{
			hs = (hs - f(S[i]) + q) % q;
			hs = (hs * femq) % q;
			hs = (hs + f(S[i+m]) * femm) % q;
		}
	}
	return occ;
}
