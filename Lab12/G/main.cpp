#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("knapsack.in");
    ofstream fout("knapsack.out");

    int s, n;
    fin >> s >> n;
    vector<int> arr, answer(1e6, 0);
    answer[0] = 1;

    for (int i = 0; i < n; ++i) {
        int temp;
        fin >> temp;
        arr.push_back(temp);
    }

    for (int i : arr)
        for (int j = s; j > i - 1; --j)
            if (answer[j - i] == 1)
                answer[j] = 1;

    for (int i = s; i >= 0; --i)
        if (answer[i] == 1){
            fout << i;
            return 0;
        }
}