// https://codeforces/problemset/problem/1201/A
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef set<char> sc; 
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/


// *************************************** MY CODE TIME COMPLEXITY O(N * M) ***************************************** 
void solve(ll test_case)
{
    ll n, m; 
    cin >> n >> m; 
    ll maxScore = 0; 

    vector <string> ans; 
    for (ll i = 0; i < n; i++) {
        string a; 
        cin >> a; 
        ans.push_back(a); 
    }

    vector <int> points; 
    for (ll i = 0; i < m; i++) {
        ll p; 
        cin >> p; 
        points.push_back(p); 
    }

    // for each question calculate the max similar ans 
    map<char, int> ansCount; 
    vector<int> maxCount(m); 

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            ansCount['A'] += ans[i][j] == 'A' ? 1 : 0;
            ansCount['B'] += ans[i][j] == 'B' ? 1 : 0;
            ansCount['C'] += ans[i][j] == 'C' ? 1 : 0;
            ansCount['D'] += ans[i][j] == 'D' ? 1 : 0;
            ansCount['E'] += ans[i][j] == 'E' ? 1 : 0;
        }

        for (auto x: ansCount) {
            maxCount[j] = max(maxCount[j], x.second); 
        }
        maxScore += maxCount[j] * points[j];
        
        for (auto x: ansCount) {
            ansCount[x.first] = 0; 
        }
    }
    
    cout << maxScore; 
}

// **********OPTIMIZED CODE WITH GPT TIME COMPLEXITY STILL O(N * M) ******************************* 
void solve(ll test_case)
{
    ll n, m; 
    cin >> n >> m; 

    vector<string> ans(n); 
    for (ll i = 0; i < n; i++) cin >> ans[i]; 

    vector<int> points(m); 
    for (ll i = 0; i < m; i++) cin >> points[i]; 

    ll maxScore = 0; 

    for (int j = 0; j < m; j++) {
        ll cnt[5] = {0}; // A B C D E

        for (int i = 0; i < n; i++) {
            cnt[ans[i][j] - 'A']++;
        }

        ll best = 0; 
        for (int k = 0; k < 5; k++) {
            best = max(best, cnt[k]); 
        }

        maxScore += best * points[j]; 
    }

    cout << maxScore;
}
// MAIN FUNCTION 

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, t1 = 0;
    // cin >> t;
    t = 1; 
    while (t1 < t)
    {
        solve(t1 + 1);
        t1++;
    }
}
