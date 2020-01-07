#include <bits/stdc++.h>
 
#define ll long long

using namespace std;

vector<int> borders(const string& P);
int MP(const string& S, const string& P);
 
int main(){
	
	cout << MP("aaaaaaaaaaaab", "ab") << endl;
	return 0;
}

vector<int> borders(const string& P)
{
	int m = P.size(), t = -1;
	vector<int> bs(m+1, -1);

	for(int j = 0; j < m; ++j)
	{
		while(t>-1 and P[t] != P[j])
			t = bs[t];

		bs[j+1] = ++t;
	}

	return bs;
}
int MP(const string& S, const string& P)
{
	int n = S.size(), m = P.size(), i = 0, j = 0, occ = 0;
	vector<int> bords = borders(P);

	while(i <= n-m)
	{
		while(j < m and P[j] == S[i+j])
			++j;

		if(j == m) ++occ;

		i += j-bords[j];
		j  = max(0, bords[j]);
	}
	return occ;
}
