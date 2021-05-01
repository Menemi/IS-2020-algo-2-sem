#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string s;
    fin >> s;

    int n = (int) s.length();
    vector<int> prefixFunction(n);
    for (int i = 1; i < n; ++i) {
        int value = prefixFunction[i - 1];
        while (value > 0 && s[i] != s[value])
            value = prefixFunction[value - 1];

        if (s[i] == s[value])
            ++value;
        prefixFunction[i] = value;
    }

    for (int i : prefixFunction)
        fout << i << " ";
}