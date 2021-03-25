#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");

    int n, m;
    double result = 0;
    fin >> n >> m;
    vector<pair<long long int, pair<int, int>>> graph;
    vector<pair<int, int>> res;
    vector<int> treeID(n);

    for (int i = 0; i < m; i++) {
        int top1, top2, weight;
        fin >> top1 >> top2 >> weight;
        graph.push_back(make_pair(weight, make_pair(top1 - 1, top2 - 1)));
    }

    sort(graph.begin(), graph.end());

    for (int i = 0; i < n; i++)
        treeID[i] = i;

    for (int i = 0; i < m; i++) {
        int firstT = graph[i].second.first;
        int secondT = graph[i].second.second;
        int tempWeight = graph[i].first;

        if (treeID[firstT] != treeID[secondT]) {
            result += tempWeight;

            int oldID = treeID[secondT];
            int newID = treeID[firstT];
            for (int j = 0; j < n; j++)
                if (treeID[j] == oldID)
                    treeID[j] = newID;
        }
    }

    fout << result;
}