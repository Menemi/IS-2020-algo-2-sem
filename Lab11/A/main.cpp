#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const long long INF = INT64_MAX;

int main() {
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");

    int n, s, f;
    fin >> n >> s >> f;
    s--;
    f--;
    vector<vector<pair<long long, long long>>> graph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            fin >> weight;
            if (weight != -1 && weight != 0)
                graph[i].push_back(make_pair(j, weight));
        }
    }

    vector<long long> dist(n, INF);
    dist[s] = 0;
    set<pair<long long, long long>> q;
    q.insert(make_pair(dist[s], s));

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (int j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first;
            int length = graph[v][j].second;
            if (dist[v] + length < dist[to]) {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[v] + length;
                q.insert(make_pair(dist[to], to));
            }
        }
    }

    if (dist[f] == INF)
        fout << -1;
    else
        fout << dist[f];
}