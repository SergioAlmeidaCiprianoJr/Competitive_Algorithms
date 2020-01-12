#include <bits/stdc++.h>
 
using namespace std;
using Node = map<char, int>;
using Trie = vector<Node>;

Trie build_naive_with_marker(const string& s);
size_t unique_substrings(const Trie& trie);
 
int main()
{
	string s;
	cin >> s;
	auto ts = build_naive_with_marker(s);
	cout << unique_substrings(ts) << endl;
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
size_t unique_substrings(const Trie& trie)
{
	size_t count = 0;
	queue<int> q;
	q.push(0);

	while(not q.empty())
	{
		auto u = q.front();
		q.pop();

		for(auto [c, v]: trie[u])
			if(c != '#')
			{
				++count;
				q.push(v);
			}
	}

	return count;
}
