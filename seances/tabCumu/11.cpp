#include <bits/stdc++.h>

#ifndef DEBUG
#define DEBUG 0
#endif

#define pb push_back
#define endl "\n"
#define PI 3.14159265359
#define LL_MAX std::numeric_limits<long long>::max()

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define IN(v,n) REP(i,n) cin >> v[i];
#define TRACE(x) if(DEBUG) cout << #x << " = " << x << endl
#define SORT(v) sort(v.begin(), v.end())
#define REVERSE(v) reverse(v.begin(), v.end())
#define _ << " " <<

typedef int int_32;
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


int_32 main() {
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> t(n);
	IN(t,n);

	vector<int> s(n+1);
	REP(i,n) s[i+1] = s[i] + t[i];

	int p;
	cin >> p;
	REP(ir,p) {
		int i,j;
		cin >> i >> j;
		cout << s[j] - s[i];
		cout << endl;
	}

	return 0;
}
