#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> z(const string& s);
int search(const string& s, const string& p, char delim);
 
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
			zs[i] = min(zs[i-L], R-i+1);

		while(zs[i] + i < n && s[zs[i]] == s[i + zs[i]])
			zs[i]++;

		if(R < i + zs[i] - 1)
			L = i, R = i + zs[i] - 1;
	}

	return zs;
}

int search(const string& s, const string& p, char delim)
{
	string t { p + delim + s };
	auto zs = z(t);
	int occ = 0, m = p.size();

	for(const auto x : zs)
		occ += (x == m ? 1 : 0);
	
	return occ;
}
