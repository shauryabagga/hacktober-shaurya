#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll infinity = 1000000000;
#define mp make_pair

void prll(ll x[], ll n)
{
	for(ll i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;
	while(t--)
	{
		vector<pair<ll, ll> > graph[10009];
		//         dest, weight
		ll dist[10009];
		ll vis[10009];
		memset(vis, 0, sizeof vis);
		ll v, k, a, b, c, root, dest;
		cin >> v >> k;
		for(ll i = 0; i < k; i++)
		{
			cin >> a >> b >> c;
			graph[a].push_back(pair<ll, ll>(b, c));
			//                     dest, wght
		}
		cin >> root >> dest;
		priority_queue<pair<ll, ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > q;
		dist[root] = 0;
		q.push(mp(0, root));
		for(ll i = 1; i <= v; i++)
			dist[i] = infinity;
		dist[root] = 0;
		while(!q.empty())
		{
			pair<ll, ll> u = q.top();
			q.pop();
			if(vis[u.second]==0)
			{
				vis[u.second] = 1;
				for(auto p: graph[u.second])
				{
					if(u.first + p.second < dist[p.first])
					{
						dist[p.first] = u.first + p.second;
						q.push(mp(u.first+p.second, p.first));
					}
				}
			}
		}
		if(dist[dest] != infinity)
			cout << dist[dest] << endl;
		else
			cout << "NO\n";
	}

	return 0;
}
