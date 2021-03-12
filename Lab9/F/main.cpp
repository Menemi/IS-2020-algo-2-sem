#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<int> color;
vector<bool> visited;

void DFS(int index) {
    bool status = false;
    visited[index] = true;

    for (int i : arr[index]) {
        if (!visited[i])
            DFS(i);
        if (color[i] == 0)
            status = true;
    }
    color[index] = status;
}

int main() {
    int n, m, s;
    ifstream fin("game.in");
    ofstream fout("game.out");

    fin >> n >> m >> s;
    arr.resize(n, vector<int>(0));
    color.resize(n, 0);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        arr[temp1 - 1].push_back(temp2 - 1);
    }

    DFS(s - 1);

    if (color[s - 1] == 1)
        fout << "First player wins";
    else
        fout << "Second player wins";
}