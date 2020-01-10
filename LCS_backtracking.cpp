#include <bits/stdc++.h>
 
using namespace std;
#define oo 100000000
const int MAX { 1000 };
int st[MAX][MAX], ps[MAX][MAX];

string LCS(const string& s, const string& t);

int main(){
	
	cout << LCS("casa", "nevasca") << endl;
	return 0;
}

string LCS(const string& s, const string& t)
{
	const int c_i = 0, c_r = 0, c_s = 1;
	int m = s.size(), n = t.size();

	for(int i = 0; i <= m; ++i)
	{
		st[i][0] = i*c_r;
		ps[i][0] = 'r';
	}

	for(int j = 1; j <= n; ++j)
	{
		st[0][j] = j*c_i;
		ps[0][j] = 'i';
	}

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
		{
			int insertion = st[i][j-1] + c_i;
			int deletion  = st[i-1][j] + c_r;
			int change    = st[i-1][j-1] + c_s*(s[i-1] == t[j-1] ? 1 : -oo);
			st[i][j] = max({ insertion, deletion, change });
			ps[i][j] = (insertion >= deletion and insertion >= change) ?
			           'i' : (deletion >= change ? 'r' : 's');
		}

	int i = m, j = n;
	string eq;

	while(i or j)
	{
		switch(ps[i][j])
		{
			case 'i':
				--j;
				break;

			case 'r':
				--i;
				break;

			case 's':
				if(s[i-1] == t[j-1])
					eq.push_back(s[i-1]);
				--i;
				--j;
		}
	}

	reverse(eq.begin(), eq.end());
	return eq;
}
