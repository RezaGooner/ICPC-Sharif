#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pages(n);
    for (int i = 0; i < n; ++i) cin >> pages[i];

    int totalPages = 0;

    for (int i = 0; i < n; ++i) {
        totalPages += pages[i];

        if (pages[i] % 2 == 1) {
            totalPages++;
        }
    }

    int sheets = (totalPages + 1) / 2;

    cout << sheets << endl;

    return 0;
}

