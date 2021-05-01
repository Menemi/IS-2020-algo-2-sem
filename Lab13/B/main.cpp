#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int SIMPLE_NUM = 29;

int main() {
    ifstream fin("search2.in");
    ofstream fout("search2.out");

    string p, t;
    fin >> p >> t;


    vector<long long> numPow(max(p.length(), t.length()));
    numPow[0] = 1;

    for (int i = 1; i < numPow.size(); ++i)
        numPow[i] = numPow[i - 1] * SIMPLE_NUM;

    vector<long long> hashT(t.length());
    for (int i = 0; i < t.length(); ++i) {
        hashT[i] = (t[i] - 'a' + 1) * numPow[i];

        if (i)
            hashT[i] += hashT[i - 1];
    }

    long long hashP = 0;
    for (int i = 0; i < p.length(); ++i)
        hashP += (p[i] - 'a' + 1) * numPow[i];

    vector<int> result;
    for (int i = 0; i + p.length() - 1 < t.length(); ++i) {
        long long currentHash = hashT[i + p.length() - 1];

        if (i)
            currentHash -= hashT[i - 1];

        if (currentHash == hashP * numPow[i])
            result.push_back(i + 1);
    }

    fout << result.size() << "\n";
    for (int i : result)
        fout << i << " ";
}