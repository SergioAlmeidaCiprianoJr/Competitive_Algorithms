#include <bits/stdc++.h>
 
using namespace std;
using Node = map<char, int>;
using Trie = vector<Node>;

Trie build_naive(const string& s);
bool search(const Trie& trie, const string& s);
 
int main()
{
	string s,t;
	cin >> s >> t;
	auto ts = build_naive(s);
	cout << search(ts, t) << endl;
	return 0;
}

Trie build_naive(const string& s)
{
	int root = 0, next = 0;

	Trie trie(1); // empty root node

	for(int i = s.size()-1; i >= 0; --i)
	{
		string suffix = s.substr(i);
		int v = root;

		for(auto c: suffix)
		{
			auto it = trie[v].find(c);

			if(it != trie[v].end())
				v = it->second;
			else
			{
				trie.push_back({ });
				trie[v][c] = ++next;
				v = next;
			}
		}
	}

	return trie;
}
bool search(const Trie& trie, const string& s)
{
	int v = 0;

	for(auto c: s)
	{
		auto it = trie[v].find(c);

		if(it == trie[v].end())
			return false;

		v = it->second;
	}

	return true;
}
