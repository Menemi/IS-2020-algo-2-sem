#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct edge {
    long long to;
    long long weight;
};

const long long INF = 9e18;

void DFS(long long index, vector<bool> &mark, vector<vector<edge>> &graph) {
    mark.at(index) = true;
    for (auto i : graph[index])
        if (!mark[i.to])
            DFS(i.to, mark, graph);
}

int main() {
    ifstream fin("path.in");
    ofstream fout("path.out");

    long long n, m, s;
    fin >> n >> m >> s;
    --s;

    vector<vector<edge>> graph(n);
    vector<bool> mark(n, false);
    vector<bool> markSecond(n, false);
    vector<long long> dist(n, INF);

    for (long long i = 0; i < m; ++i) {
        long long from, to, weight;
        fin >> from >> to >> weight;
        --from;
        --to;
        graph[from].push_back({to, weight});
    }

    DFS(s, mark, graph);
    dist[s] = 0;
    for (long long i = 0; i < n; ++i)
        for (long long j = 0; j < n; ++j)
            for (auto k : graph[j])
                if (dist[k.to] > dist[j] + k.weight) {
                    dist[k.to] = max(-INF, dist[j] + k.weight);
                    if (i == n - 1 && mark[k.to])
                        DFS(k.to, markSecond, graph);
                }

    for (long long i = 0; i < n; ++i) {
        if (markSecond[i] || dist[i] <= -INF)
            fout << "-\n";
        else if (!mark[i])
            fout << "*\n";
        else
            fout << dist[i] << "\n";
    }
}