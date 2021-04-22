#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<vector<int>> answer;
vector<int> numbers;

void Tree(int index) {
    answer[index][0] = 0;
    answer[index][1] = numbers[index];

    for (int i : tree[index])
        Tree(i);

    for (int i : tree[index]) {
        answer[index][0] += max(answer[i][0], answer[i][1]);
        answer[index][1] += answer[i][0];
    }
}

int main() {
    ifstream fin("selectw.in");
    ofstream fout("selectw.out");

    int n, root;
    fin >> n;
    tree.resize(n);
    numbers.assign(n, 0);
    answer.assign(n, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        int temp;
        fin >> temp >> numbers[i];

        if (temp != 0)
            tree[temp - 1].push_back(i);
        else
            root = i;
    }

    Tree(root);
    fout << max(answer[root][0], answer[root][1]);
}