#include <bits/stdc++.h>
 
using namespace std;

vector<int> z(const string& s);
int search(const string& s, const string& p, char delim);
string rev(const string& s);
 
int main(){
	
	cout << search("banana", "ana", '#') << endl;
	return 0;
}

vector<int> z(const string& s)
{
	int n = s.size(), L = 0, R = 0;
	vector<int> zs(n, 0);

	for(int i = 1; i < n; i++)
	{
		if(i <= R)
			zs[i] = min(zs[i-1], R - i + 1);

		while(zs[i] + i < n && s[zs[i]] == s[i + zs[i]])
			zs[i]++;

		if(R < i+ zs[i] - 1)
			L = i, R = i + zs[i] - 1;
	}

	return zs;
}
string rev(const string& s)
{
	auto P { s };
	reverse(P.begin(), P.end());
	return P;
}
int search(const string& s, const string& p, char delim)
{
	string t { p + delim + s};
	string r { rev(p) + delim + rev(s) };
	auto zt = z(t), zr = z(r);
	int occ = 0, n = s.size(), m = p.size();

	for(int i = 0; i < n; i++)
		occ += (zt[i + m + 1] + zt[n - i + 1] >= m - 1) ? 1 : 0;

	return occ;
}
