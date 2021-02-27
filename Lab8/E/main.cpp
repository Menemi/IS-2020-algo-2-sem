#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int n, m;
ifstream fin("pathbge1.in");
ofstream fout("pathbge1.out");
vector<vector<int>> arr;
vector<int> dist;

void BFS(int start) {
    vector<string> color(n, "white");
    vector<int> prev(n, -1);

    color[start] = "gray";
    dist[start] = 0;
    prev[start] = -1;
    queue<int> Q;
    Q.push(start);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < arr[u].size(); i++) {
            int v = arr[u][i];
            if (color[v] == "white" && (dist[u] + 1) < dist[v]) {
                color[v] == "gray";
                dist[v] = dist[u] + 1;
                prev[v] = u;
                Q.push(v);
            }
        }
        color[u] = "black";
    }

    for (int i = 0; i < prev.size(); i++) {
        fout << dist[i] << " ";
    }
}

int main() {
    fin >> n >> m;
    dist.resize(n, n + 1);
    arr.resize(n, vector<int>(0));

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;

        arr[temp1 - 1].push_back(temp2 - 1);
        arr[temp2 - 1].push_back(temp1 - 1);
    }

    BFS(0);
}