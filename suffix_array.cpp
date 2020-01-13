#include <bits/stdc++.h>
 
using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

template<typename T> void
counting_sort(vi& ps, const T& xs, size_t alphabet_size);
template<typename T> int
update_equivalence_classes(vi& cs, const vi& ps, const T& xs);
vector<int> suffix_array(const string& S);
 
int main()
{	
	string s;
	cin >> s;

	int N = s.size();
	auto sa = suffix_array(s);

	for(int i = 0; i < N; ++i)
		cout << sa[i] << '\t' << s.substr(sa[i]) << endl;

	return 0;
}

template<typename T> void
counting_sort(vi& ps, const T& xs, size_t alphabet_size)
{
	vi hs(alphabet_size, 0);

	for(auto x: xs)
		++hs[x];

	for(size_t i = 1; i < alphabet_size; ++i)
		hs[i] += hs[i-1];
	
	for(int i = ps.size()-1; i >= 0; --i)
		ps[--hs[xs[i]]] = i;
}
template<typename T> int
update_equivalence_classes(vi& cs, const vi& ps, const T& xs)
{
	int c = 0;
	cs[ps[0]] = c;

	for(size_t i = 1; i < ps.size(); ++i)
	{
		if(xs[ps[i-1]] != xs[ps[i]])
			++c;

		cs[ps[i]] = c;
	}

	return c+1;
}
vector<int> suffix_array(const string& S)
{
	auto s = S + "$";
	auto N = s.size();

	vi ps(N), cs(N), rs(N), xs(N);
	vii ys(N);

	counting_sort(ps, s, 256);
	int c = update_equivalence_classes(cs, ps, s);

	for(size_t mask = 1; mask < N; mask<<=1)
	{
		for(size_t i = 0; i< N; ++i)
		{
			rs[i] = (ps[i] + N - mask) % N;
			xs[i] = cs[rs[i]];
			ys[i] = ii(cs[i], cs[(i + mask) % N]);
		}

		counting_sort(ps, xs, c);

		for(size_t i = 0; i < N; ++i)
			ps[i] = rs[ps[i]];

		
		c = update_equivalence_classes(cs, ps, ys);
	}
	
	ps.erase(ps.begin());

	return ps;
}
