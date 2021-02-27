#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, m;
    bool flag = true;

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> n;
    int **mas = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
        mas[i] = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> mas[i][j];

            if (i == j) {
                if (mas[i][j] == 1) {
                    fout << "NO";
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mas[i][j] != mas[j][i]) {
                fout << "NO";
                return 0;
            }
        }
    }

    fout << "YES";
}