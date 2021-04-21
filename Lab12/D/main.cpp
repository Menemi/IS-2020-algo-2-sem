#include <fstream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;

int knightsMove(int i, int j) {
    if (((i >= 0) && (i < n)) && ((j >= 0) && (j < m))) {
        if (arr[i][j] == 0) {
            arr[i][j] = knightsMove(i + 2, j + 1) + knightsMove(i + 2, j - 1) +
                        knightsMove(i + 1, j + 2) + knightsMove(i - 1, j + 2);
        }
    } else
        return 0;
    return arr[i][j];
}

int main() {
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");

    fin >> n >> m;

    arr.assign(n, vector<int>(m, 0));
    arr[n - 1][m - 1] = 1;

    fout << knightsMove(0, 0);
}