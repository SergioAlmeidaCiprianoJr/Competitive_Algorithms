#include <bits/stdc++.h>
 
using namespace std;

int lis(const vector<int>& as);
int lcs(const string& s, const string& t);

int main(){
	
	cout << lcs("trapezio", "reticulado") << endl;
	return 0;
}

int lis(const vector<int>& as)
{
	vector<int> st(as.size()+1, -1);
	int n = 0;

	for(auto x: as)
	{
		if(x>st[n])
			st[++n] = x;
		else
		{
			auto it = lower_bound(st.begin()+1, st.begin()+n, x);
			*it = min(*it, x);
		}
	}

	return n;
}
int lcs(const string& s, const string& t)
{
	map<char, int> idx;

	for(size_t i = 0; i<t.size(); ++i)
		idx[t[i]] = i;

	vector<int> bs;
	
	for(const auto& c : s)
	{
		auto it = idx.find(c);

		if(it != idx.end())
			bs.push_back(it->second);
	}

	return lis(bs);
}
