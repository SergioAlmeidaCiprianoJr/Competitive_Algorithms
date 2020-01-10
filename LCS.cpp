#include <bits/stdc++.h>
 
using namespace std;
#define oo 1000000000
const int MAX { 1000 };
int st[MAX][MAX];
 
int LCS(const string& s, const string& t);
 
int main(){
	
	cout << LCS("casa", "nevasca") << endl;
	return 0;
}

int LCS(const string& s, const string& t)
{
	const int c_i = 0, c_r = 0, c_s = 1;
	int m = s.size(), n = t.size();

//	for(int i = 0; i <= m; ++i)
//		st[i][0] = i*c_r;
//	
//	for(int j = 1; j <= n; ++j)
//		st[0][j] = j*c_i;

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
		{
			int insertion = st[i][j-1] + c_i;
			int deletion  = st[i-1][j] + c_r;
			int change    = st[i-1][j-1] + c_s*(s[i-1] == t[j-1] ? 1 : -oo);
			st[i][j]      = max({ insertion, deletion, change });
		}
	
	return st[m][n];
}
