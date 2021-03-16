#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m;

    fin >> n >> m;
    vector<int> arr(n, 0);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        arr[temp1 - 1]++;
        arr[temp2 - 1]++;
    }
    for (int i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }
}