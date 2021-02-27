#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n, m;

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> n >> m;
    int** mas = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i)
        mas[i] = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        mas[temp1 - 1][temp2 - 1] += 1;
        mas[temp2 - 1][temp1 - 1] += 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mas[i][j] != 0 && mas[i][j] != 1 && mas[i][j] == mas[j][i]) {
                fout << "YES";
                return 0;
            }
        }
    }
    fout << "NO";
}