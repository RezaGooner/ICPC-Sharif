#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0, prev, current;
    cin >> prev;
    
    for (int i = 1; i < n; i++) {
        cin >> current;

        if (current > prev) {
            result += current - prev;
            current = prev;
        }

        prev = current;
    }

    cout << result << endl ;
    return 0;
}
