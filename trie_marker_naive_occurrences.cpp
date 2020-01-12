#include <bits/stdc++.h>
 
using namespace std;
using Node = map<char, int>;
using Trie = vector<Node>;

Trie build_naive_with_marker(const string& s);
vector<int> occurrences(const Trie& trie, const string& s);
 
int main()
{
	string s,t;
	cin >> s >> t;
	auto ts = build_naive_with_marker(s);
	auto occ = occurrences(ts, t);
	cout << "occurrences: " << occ.size() << endl;
	cout << "occurrences positions: ";
	for(auto ans: occ)
		(ans == occ[0]) ? cout << ans : cout << " " << ans;
	cout << endl;
	return 0;
}

Trie build_naive_with_marker(const string& s)
{
	int root = 0, next = 0;
	Trie trie(1);

	for(int i = s.size()-1; i >= 0; --i)
	{
		string suffix = s.substr(i) + '#';
		int v = root;

		for(auto c: suffix)
		{
			if(c == '#')
			{
				trie[v][c] = i;
				break;
			}

			auto it	= trie[v].find(c);

			if(it != trie[v].end())
				v = it->second;
			else
			{
				trie.push_back({});
				trie[v][c] = ++next;
				v = next;
			}
		}
	}

	return trie;
}
vector<int> occurrences(const Trie& trie, const string& s)
{
	vector<int> is;
	int v = 0;

	for(auto c: s)
	{
		auto it = trie[v].find(c);

		if(it == trie[v].end())
			return is;

		v = it->second;
	}

	queue<int> q;
	q.push(v);

	while(not q.empty())
	{
		auto u = q.front();
		q.pop();

		for(auto [c, v]: trie[u])
			(c == '#') ? is.push_back(v) : q.push(v);
	}

	return is;
}
