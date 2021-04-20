#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
//    ifstream cin("in.txt");
//    ofstream cout("out.txt");

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> d(n), p(n);
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; ++j)
            if ((arr[j] < arr[i]) && (1 + d[j] > d[i])) {
                d[i] = 1 + d[j];
                p[i] = j;
            }
    }

    int length = d[0], pos = 0;
    for (int i = 0; i < n; ++i)
        if (d[i] > length) {
            length = d[i];
            pos = i;
        }

    vector<int> answer;
    while (pos != -1) {
        answer.push_back(arr[pos]);
        pos = p[pos];
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (int i : answer)
        cout << i << " ";
}