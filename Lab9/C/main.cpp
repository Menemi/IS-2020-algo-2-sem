#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> arr;
vector<int> color;

bool DFS(int index, int colour) {
    if (colour == 2)
        colour = 0;

    if (color[index] == -1)
        color[index] = colour;
    else if (color[index] != colour)
        return false;

    for (int i = 0; i < arr[index].size(); i++) {
        if (color[arr[index][i]] == -1) {
            if (!DFS(arr[index][i], colour + 1))
                return false;
        }
        if (color[arr[index][i]] == colour)
            return false;
    }
    return true;
}

int main() {
    int n, m;
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");

    fin >> n >> m;
    arr.resize(n, vector<int>(0));
    color.resize(n, -1);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        arr[temp1 - 1].push_back(temp2 - 1);
        arr[temp2 - 1].push_back(temp1 - 1);
    }

//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < arr[i].size(); j++){
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!DFS(i, 0)) {
                fout << "NO";
                return 0;
            }
        }
    }
    fout << "YES";
}