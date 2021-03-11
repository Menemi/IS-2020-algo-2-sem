#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<int> > arr, arrTransp;
vector<int> result, component;
vector<char> used;

void firstDFS(int v) {
    used[v] = true;

    for (int i = 0; i < arr[v].size(); i++) {
        if (!used[arr[v][i]])
            firstDFS(arr[v][i]);
    }
    result.push_back(v);
}

void secondDFS(int v, int k) {
    component[v] = k;
    for (int i = 0; i < arrTransp[v].size(); i++) {
        if (component[arrTransp[v][i]] == -1)
            secondDFS(arrTransp[v][i], k);
    }
}

int main() {
    int n, m;
    ifstream fin("cond.in");
    ofstream fout("cond.out");

    fin >> n >> m;
    arr.resize(n, vector<int>(0));
    arrTransp.resize(n, vector<int>(0));
    component.resize(n, -1);
    used.resize(n, false);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        arr[temp1 - 1].push_back(temp2 - 1);
        arrTransp[temp2 - 1].push_back(temp1 - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i])
            firstDFS(i);
    }

    int k = 0;
    for (int i = result.size() - 1; i >= 0; i--) {
        if (component[result[i]] == -1) {
            secondDFS(result[i], k);
            k++;
        }
    }

    fout << k << "\n";
    for (int i = 0; i < n; i++)
        fout << component[i] + 1 << " ";
}