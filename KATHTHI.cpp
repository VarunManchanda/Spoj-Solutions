#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
#define _fast_ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long 
#define ull unsigned long long
#define mod 1e9
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define gcd(a,b) __gcd(a,b)
#define count_ones(x) __builtin_popcount(x)
#define _for(k,s,e,inc) for(auto k=s; k<e; k+=inc)
#define _forr(k,s,e,dec) cor(auto k=s, k>=e; k-=dec)
#define PI acos(-1)


int bfs(int n, int m, vector<string> &mat)
{
	int dist[n][m];
	_for(i,0,n,1) _for(j,0,m,1) dist[i][j] = INT_MAX;
	deque<pair<int,int> > q;
	dist[0][0] = 1;
	q.push_front(make_pair(0,0));//insert (0,0) co-ordinate
	int ax[] = {-1,1,0,0};
	int ay[] = {0,0,1,-1};
	while(!q.empty())
	{
		auto node = q.front(); q.pop_front();
		if(node.first==(n-1) && node.second==(m-1)) break;
		_for(i,0,4,1)
		{
			int row = node.first + ax[i];
			int col = node.second + ay[i];
			if(row>=0 && row<n && col>=0 && col<m)
			{
				if(mat[node.first][node.second]==mat[row][col] && dist[node.first][node.second] < dist[row][col])
				{
					dist[row][col] = dist[node.first][node.second];
					q.push_front(make_pair(row,col));
				}
				else if(dist[node.first][node.second] < dist[row][col])
				{
					dist[row][col] = dist[node.first][node.second] + 1;
					q.push_back(make_pair(row,col));
				}
			}
		}
	}
	return dist[n-1][m-1] - 1;

}








int main()
{
    _fast_;
    int t; cin >> t;
    while(t--)
    {
    	int n, m; cin >> n >> m;
    	vector<string> mat(n);
    	_for(i,0,n,1) cin >> mat[i];
    	cout << bfs(n,m,mat) << endl;
    }
    return 0;
}