#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> treeID;

int DSUget(int v) {
    if (v == treeID[v])
        return v;
    else
        treeID[v] = DSUget(treeID[v]);
}

void DSUunite(int firstT, int secondT) {
    firstT = DSUget(firstT);
    secondT = DSUget(secondT);

    if (firstT != secondT)
        treeID[firstT] = secondT;
}

int main() {
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");

    int n, m;
    long long result = 0;
    fin >> n >> m;

    vector<pair<long long, pair<long long, long long>>> graph;
    treeID.resize(n);

    for (int i = 0; i < m; i++) {
        int top1, top2, weight;
        fin >> top1 >> top2 >> weight;
        graph.push_back(make_pair(weight, make_pair(top1 - 1, top2 - 1)));
    }

    sort(graph.begin(), graph.end());

    for (int i = 0; i < n; ++i)
        treeID[i] = i;

    for (int i = 0; i < m; ++i) {
        int firstT = graph[i].second.first;
        int secondT = graph[i].second.second;
        int tempWeight = graph[i].first;

        if (DSUget(firstT) != DSUget(secondT)) {
            result += tempWeight;
            DSUunite(firstT, secondT);
        }
    }

    fout << result;
}