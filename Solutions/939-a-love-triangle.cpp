// https://codeforces.com/problemset/problem/939/A
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5000;
int f[NMAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin>>f[i];
		--f[i];
	}
	bool isLt = false;
	if(n>2)
	{
		for (int i = 0; i < n; ++i)
		{
			if(f[f[f[i]]] == i)
			{
				isLt = true;
				break;
			}
		}
	}
	
	if(isLt)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"NO";
	}

	return 0;
}
