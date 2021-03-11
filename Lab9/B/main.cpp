#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<int> color, previous;
int Start, End;

bool DFS(int u) {
    color[u] = 1;
    for (size_t i = 0; i < arr[u].size(); ++i) {
        int v = arr[u][i];
        if (color[v] == 0) {
            previous[v] = u;
            if (DFS(v))
                return true;
        } else if (color[v] == 1) {
            Start = v;
            End = u;
            return true;
        }
    }

    color[u] = 2;
    return false;
}

int main() {
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");

    fin >> n >> m;

    arr.resize(n, vector<int>(0));
    color.resize(n, 0);
    previous.resize(n, -1);

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
        fout << "NO";
        return 0;
    } else {
        fout << "YES\n";
        vector<int> tempCycle;
        tempCycle.push_back(Start);

        for (int i = End; i != Start; i = previous[i]) {
            tempCycle.push_back(i);
        }

        for (int i = tempCycle.size() - 1; i >= 0; i--) {
            fout << tempCycle[i] + 1 << " ";
        }
    }
}