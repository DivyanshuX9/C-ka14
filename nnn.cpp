#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        double r;
        cin >> u >> v >> r;
        adj[u].push_back({v, -log(r)});
    }
    int s, t;
    cin >> s >> t;
    vector<double> dist(n, 1e18);
    dist[s] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    pq.push({0, s});
    vector<int> parent(n, -1);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
    }
    vector<int> path;
    for (int v = t; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";
}
