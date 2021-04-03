#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const int INF = INT_MAX;

int main() {
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");

    int n, m;
    fin >> n >> m;

    vector<vector<pair<long long, long long>>> graph(n);

    for (int i = 0; i < m; ++i) {
        int top1, top2, weight;
        fin >> top1 >> top2 >> weight;
        --top1;
        --top2;
        graph[top1].push_back(make_pair(top2, weight));
        graph[top2].push_back(make_pair(top1, weight));
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(dist[0], 0));

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

    for (int i = 0; i < n; ++i)
        fout << dist[i] << " ";
}