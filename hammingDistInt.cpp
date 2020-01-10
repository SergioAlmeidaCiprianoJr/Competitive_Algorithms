#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int n1, int n2);

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	cout << hammingDistance(n1, n2) << endl;
	return 0;
}

int hammingDistance(int n1, int n2)
{
	int x = n1 ^ n2;
	int setBits = 0;

	while(x)
	{
		setBits += x & 1;
		x >>= 1;
	}

	return setBits;
}

