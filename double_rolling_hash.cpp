#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int hi(const string& s);
pair<int, int> h(const string& s);
 
int main(){
	
	string s;
	cin >> s;
	auto hs = h(s);
	cout << hs.first << endl;
	cout << hs.second << endl;
	return 0;
}

int hi(ll pi, ll qi, const string& s)
{
	ll ans = 0;
	for(auto it = s.rbegin(); it != s.rend(); ++it)
	{
		ans = (ans * pi) % qi;
		ans = (ans + (*it - 'a' + 1)) % qi;
	}
	return ans;
}

pair<int, int> h(const string& s)
{
	const ll p1 = 31, q1 = 1000000007;
	const ll p2 = 29, q2 = 1000000009;

	return make_pair(hi(p1, q1, s), hi(p2, q2, s));
}
