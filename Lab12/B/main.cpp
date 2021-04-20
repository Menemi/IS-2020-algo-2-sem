#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

using namespace std;

int main() {
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> d(n + 1, INF), p(n, 0), pos(n + 1, 0);
    d[0] = -INF;
    pos[0] = -1;
    int length = d[0];

    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(d.begin(), d.end(), arr[i]) - d.begin());
        if ((d[j - 1] < arr[i]) && (arr[i] < d[j])) {
            d[j] = arr[i];
            p[i] = pos[j - 1];
            pos[j] = i;
            length = max(length, j);
        }
    }

    vector<int> answer;
    int newP = pos[length];
    while (newP != -1) {
        answer.push_back(arr[newP]);
        newP = p[newP];
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (int i : answer)
        cout << i << " ";
}