#include <fstream>
int main() {std::ifstream fin("search1.in");std::ofstream fout("search1.out");std::string p, t, temp;fin >> p >> t;int m = p.length(), n = t.length(), size = 0;int *ans = new int[n];for (int i = 0; i <= n - m; ++i) {for (int j = i; j <= i + m - 1; ++j)temp += t[j];if (temp == p) {++size;ans[size - 1] = i + 1;}temp.clear();}fout << size << "\n";for (int i = 0; i < size; ++i)fout << ans[i] << " ";}