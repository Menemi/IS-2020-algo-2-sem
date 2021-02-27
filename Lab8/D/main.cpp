#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream fin("components.in");
ofstream fout("components.out");
int n, m, numComponents = 0;
vector<vector<int>> arr;
vector<int> mark;
bool flag = false;

void DFS(int i) {
    mark[i] = numComponents + 1;
    cout << "\n";
    if (arr[i].size() != 0) {
        for (auto j = arr[i].begin(); j != arr[i].end(); j++) {
            cout << mark[*j] << " ";
            if (mark[*j] == 0) {
                DFS(*j);
            }
        }
    }
}

int main() {
    fin >> n >> m;
    arr.resize(n, vector<int>(0));
    mark.resize(n, 0);

    for (int i = 1; i <= m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        arr[temp1 - 1].push_back(temp2 - 1);
        arr[temp2 - 1].push_back(temp1 - 1);
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < arr[i].size(); j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            DFS(i);
            numComponents++;
        }
    }

    fout << numComponents << "\n";
    for (int i = 0; i < n; i++)
        fout << mark[i] << " ";
}