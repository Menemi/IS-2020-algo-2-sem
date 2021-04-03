#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int INF = INT_MAX;

int main() {
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");

    int n, m;
    fin >> n >> m;
    vector<vector<pair<long long, long long>>> graph(n);
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    for (int i = 0; i < m; ++i) {
        int top1, top2, weight;
        fin >> top1 >> top2 >> weight;
        --top1;
        --top2;
        graph[top1].push_back(make_pair(top2, weight));
        dist[top1][top2] = weight;
    }

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < dist[i].size(); ++j) {
            fout << dist[i][j] << " ";
        }
        fout << "\n";
    }
}