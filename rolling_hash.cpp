#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int rolling_hash(const string& s);
 
int main(){
	
	string s;
	cin >> s;
	cout << rolling_hash(s) << endl;
	return 0;
}

int rolling_hash(const string& s)
{
	ll ans = 0, p = 31, q = 1000000000+7;
	for(auto it = s.rbegin(); it != s.rend(); ++it)
	{
		ans = (ans * p) % q;
		ans = (ans + (*it - 'a' + 1)) % q;
	}
	return ans;
}
