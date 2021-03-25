#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

//Can u help me, Mr. Goose?
//░░░░▄▀▀▀▄░░░░░░░░
//▄██▀░◐░░░▌░░░░░░░
//░░░▌░░░░░▐░░░░░░░
//░░░▐░░░░░▐░░░░░░░
//░░░▌░░░░░▐▄▄░░░░░
//░░░▌░░░░▄▀▒▒▀▀▀▀▄
//░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
//░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
//░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀
//░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄
//░░░░░░░░░░▌▌░▌▌░░░░░
//░░░░░░░░░░▌▌░▌▌░░░░░
//░░░░░░░░▄▄▌▌▄▌▌░░░░░
//YEP YEP YEP

int main() {
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");
    fout.precision(10);

    int n;
    fin >> n;

    const int INF = INT_MAX;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> minE(n, INF), x(n), y(n);
    vector<bool> used(n);
    double result = 0;

    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (x[i] - x[j]) * (x[i] - x[j]) +
                          (y[i] - y[j]) * (y[i] - y[j]);
        }
    }

    minE[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;

        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || minE[j] < minE[v]))
                v = j;

        used[v] = true;
        for (int j = 0; j < n; j++) {
            if (!used[j] && graph[v][j] < minE[j] && v != j)
                minE[j] = graph[v][j];
        }
    }

    for (int i = 0; i < n; i++) {
        result += sqrt(minE[i]);
    }

    fout << result;
}