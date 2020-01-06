#include <bits/stdc++.h>
 
#define ll long long
using namespace std;

const ll p = 31, q = 1000000007;
 
int f(char c);
int h(const string& s);
vector<ll> prefixes(const string& s);
ll fast_exp_mod(ll a, ll n);
vector<ll> inverses(ll N);
int H(int i, int j, const vector<ll>& ps, const vector<ll> is);
int unique_substrings(const string& s);
 
int main()
{
	cout << unique_substrings("tep") << endl;
	cout << unique_substrings("banana") << endl;
	cout << unique_substrings("aaaaa") << endl;
	
	return 0;
}

int f(char c)
{
	return c-'a'+1;
}
int h(const string& s)
{
	ll ans = 0;

	for(auto it = s.rbegin(); it != s.rend(); ++it)
	{
		ans = (ans * p) % q;
		ans = (ans + f(*it)) % q;
	}

	return ans;
}
vector<ll> prefixes(const string& s)
{
	int N = s.size();
	vector<ll> ps(N, 0);

	for(int i = 0; i < N; ++i)
		ps[i] = h(s.substr(0, i+1));
	
	return ps;
}
ll fast_exp_mod(ll a, ll n)
{
	ll res=1, base=a;

	while(n)
	{
		if(n & 1)
			res = (res * base) % q;

		base = (base * base) % q;
		n >>= 1;
	}

	return res;
}
vector<ll> inverses(ll N)
{
	vector<ll> is(N);
	ll base = 1;

	for(int i = 0; i < N; ++i)
	{
		is[i] = fast_exp_mod(base, q-2);
		base = (base * p) % q;
	}

	return is;
}
int H(int i, int j, const vector<ll>& ps, const vector<ll> is)
{
	auto diff = i ? ps[j] - ps[i-1] : ps[j];
	diff = (diff * is[i]) % q;

	return (diff + q) % q;
}
int unique_substrings(const string& s)
{
	set<ll> hs;
	int N = s.size();

	auto ps = prefixes(s);
	auto is = inverses(s.size());

	for(int i = 0; i < N; ++i)
	{
		for(int j = i; j < N; ++j)
		{
			auto hij = H(i, j, ps, is);
			hs.insert(hij);
		}
	}

	return hs.size();
}
