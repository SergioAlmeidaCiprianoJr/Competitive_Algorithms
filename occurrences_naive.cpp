#include <bits/stdc++.h>
 
using namespace std;
 
int occurrences(const string& P, const string& S);
 
int main(){
	
	string P, S;
	cin >> P >> S;
	cout << occurrences(P, S) << endl;
	
	return 0;
}

int occurrences(const string& P, const string& S){

	int occ=0,m = P.size(),n = S.size();
	for (int i = 0; i <= n - m; ++i)
		occ += (P == S.substr(i, m) ? 1 : 0);
	
	return occ;
}
