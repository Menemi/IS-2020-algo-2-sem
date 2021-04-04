#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct edge {
    long long from;
    long long to;
    long long weight;
};

const long long INF = 9e18;

int main() {
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
    long long n;
    fin >> n;

    vector<edge> graph(n);
    vector<long long> dist(n, INF);
    vector<long long> parent(n, -1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int weight;
            fin >> weight;
            graph.push_back({i, j, weight});
        }

    dist[0] = 0;
    long long flag;
    for (int i = 0; i < n; i++) {
        flag = -1;
        for (edge j : graph)
            if (dist[j.to] > dist[j.from] + j.weight) {
                dist[j.to] = dist[j.from] + j.weight;
                parent[j.to] = j.from;
                flag = j.to;
            }
    }

    if (flag == -1)
        fout << "NO";
    else {
        fout << "YES\n";
        vector<long long> path;
        long long temp = flag;

        for (long long i = 0; i < n; ++i)
            temp = parent[temp];

        for (long long i = temp; i != temp || path.empty(); i = parent[i])
            path.push_back(i);

        path.push_back(temp);
        fout << path.size() << "\n";

        for (long long i = path.size() - 1; i >= 0; --i)
            fout << path[i] + 1 << " ";
    }
}