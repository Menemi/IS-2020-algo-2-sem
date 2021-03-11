#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<int> color, sort;

void DFS(int index, int n) {
    color[index] = 1;

    for (int i = 0; i < arr[index].size(); i++) {
        if (color[arr[index][i]] == 0)
            DFS(arr[index][i], n);
    }

    color[index] = 2;
    sort.push_back(index);
}

int main() {
    int n, m;
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");

    fin >> n >> m;

    arr.resize(n, vector<int>(0));
    color.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        arr[temp1 - 1].push_back(temp2 - 1);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] != 2)
            DFS(i, n);
    }

    bool flag = false;
    int temp1, temp2;

    if (!sort.empty()) {
        temp1 = sort[sort.size() - 1];
        sort.pop_back();
        flag = true;
    }

    while (!sort.empty() && flag) {
        temp2 = sort[sort.size() - 1];
        sort.pop_back();
        flag = false;

        for (int i = 0; i < arr[temp1].size(); i++) {
            if (arr[temp1][i] == temp2)
                flag = true;
        }
        temp1 = temp2;
    }

    if (flag)
        fout << "YES";
    else
        fout << "NO";
}