// O(log(n)), executa no pior caso log(n) mais um iterações
// Sendo n o expoente

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const ll p = 31, q = 1000000007;

ll fast_exp_mod(ll a, ll n);

int main(){

	int a, n;
	cin >> a >> n;
	cout << fast_exp_mod(a, n) << endl;
	
	return 0;
}

ll fast_exp_mod(ll a, ll n)
{
	ll res = 1, base = a;

	while(n)
	{
		if (n & 1)
			res = (res*base) % q;

		base = (base * base) % q;
		n >>= 1;
	}

	return res;
}

