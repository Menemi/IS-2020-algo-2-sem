#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("search1.in");
    ofstream fout("search1.out");

    string p, t, temp;
    fin >> p >> t;
    vector<int> ans;
    int m = p.length(), n = t.length();

    for (int i = 0; i <= n - m; ++i) {
        for (int j = i; j <= i + m - 1; ++j)
            temp += t[j];
        if (temp == p)
            ans.push_back(i + 1);
        temp.clear();
    }

    fout << ans.size() << "\n";
    for (int i : ans)
        fout << i << " ";
}