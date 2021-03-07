#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<int> result, color, checker;
int Start;

bool DFS(int u) {
    color[u] = 1;
    for (size_t i = 0; i < arr[u].size(); ++i) {
        int v = arr[u][i];
        if (color[v] == 0) {
            if (DFS(v))
                return true;
        } else if (color[v] == 1) {
            Start = v;
            return true;
        }
    }

    color[u] = 2;
    if (checker[u] == 0) {
        checker[u] = u + 1;
        result.push_back(u + 1);
    }
    return false;
}

int main() {
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");

    fin >> n >> m;

    arr.resize(n, vector<int>(0));
    color.resize(n, 0);
    checker.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        arr[temp1 - 1].push_back(temp2 - 1);
    }

    Start = -1;
    for (int i = 0; i < n; ++i) {
        if (DFS(i))
            break;
    }

    if (Start == -1) {
        for (int i = n - 1; i >= 0; i--) {
            fout << result[i] << " ";
        }
    } else {
        fout << -1;
    }
}