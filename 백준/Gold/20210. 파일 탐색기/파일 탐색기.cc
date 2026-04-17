#include<bits/stdc++.h>
using namespace std;

vector<string> v;
map<char,int> m;
map<string,int> sCnt;

void init()
{
	int cnt = 10;
	
	for(char c = 'A'; c <= 'Z'; c++)
	{
		m[c] = cnt;
		cnt += 2;
	}
	
	cnt = 11;
	
	for(char c = 'a'; c <= 'z'; c++)
	{
		m[c] = cnt;
		cnt += 2;
	}
	
	for(char c = '0'; c <= '9'; c++)
		m[c] = (c - '0');
}

int zeroCount(const string & s)
{
	int idx = 0;
	
	while(idx < s.length() && s[idx] == '0')
		idx++;
	
	return idx;
}

int compareBigInteger(string a, string b)
{
	int zCnt1 = zeroCount(a), zCnt2 = zeroCount(b);
	
	int dist = a.length() - b.length();
	int gap = abs(dist);
	
	if(a.length() > b.length())
		for(int i = 0; i < gap; i++)
			b = '0' + b;
	else if(a.length() < b.length())
		for(int i = 0; i < gap; i++)
			a = '0' + a;
	
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] < b[i])
			return true;
		else if(a[i] > b[i])
			return false;
	}
	
	if(zCnt1 == zCnt2)
		return -1;
	
	return zCnt1 < zCnt2;
}

bool isCharNum(char c)
{
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

bool cmp(const string & a, const string & b)
{
	int curIdx = 0;
	int idx;
	int lnA, lnB;
	
	while(true)
	{
		idx = curIdx;
		lnA = -1, lnB = -1;

		if(a.length() <= idx)
			return true;
		else if(b.length() <= idx)
			return false;
		
		while(a[idx] == b[idx])
		{
			if((idx == curIdx || idx != curIdx && a[idx - 1] > '9') && isCharNum(a[idx]))
				lnA = idx;
			else if(a[idx] > '9')
				lnA = -1;

			if((idx == curIdx || idx != curIdx && b[idx - 1] > '9') && isCharNum(b[idx]))
				lnB = idx;
			else if(b[idx] > '9')
				lnB = -1;

			idx++;

			if(idx >= a.length() || idx >= b.length())
			{
				if(lnA != -1 && lnB != -1)
					break; // 둘다 끝이 숫자면 그냥 진행
				else
					return a.length() < b.length();
			}
		}

		if(lnA == -1 && isCharNum(a[idx]) && lnB == -1 && isCharNum(b[idx]))
		{
			lnA = idx;
			lnB = idx;
		}

		if(a[idx] != b[idx])
		{
			if(lnA != -1 && lnB != -1)
			{
				int ret = -1;

				string tempA, tempB;
				int idx1,idx2;

				for(idx1 = lnA; a[idx1] >= '0' && a[idx1] <= '9'; idx1++)
					tempA += a[idx1];

				for(idx2 = lnB; b[idx2] >= '0' && b[idx2] <= '9'; idx2++)
					tempB += b[idx2];

				ret = compareBigInteger(tempA,tempB);

				if(ret == -1)
				{	
					if(a.length() == idx1)
						return true;
					else if(b.length() == idx2)
						return false;

					curIdx = idx1;
					continue;
				}

				return ret;
			}
			else
				return m[a[idx]] < m[b[idx]];
		}
		else
			return true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		string str;
		
		cin >> str;
		
		
		if(sCnt[str])
			sCnt[str] += 1;
		else
		{
			v.push_back(str);
			sCnt[str] = 1;
		}
	}
	
	init();

	if(v.size() != 1)
		sort(v.begin(), v.end(),cmp);
	
	for(int i = 0; i < v.size(); i++)
		for(int j = 0; j < sCnt[v[i]];j++)
			cout << v[i] << '\n';
	
	return 0;
}