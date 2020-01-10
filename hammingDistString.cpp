#include<bits/stdc++.h>
using namespace std;

int hammingDist(string str1, string str2);

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	cout << hammingDist(str1, str2) << endl;
	return 0;
}

int hammingDist(string str1, string str2)
{ 
	int i = 0, count = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			count++;
		i++;
	}
	return count;
}
