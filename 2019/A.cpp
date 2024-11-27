#include <iostream>

using namespace std;

int main() {
    int need, investment, quota, cost;
    cin >> need;
    cin >> investment;

    if (need <= investment) 
        cout << need * 1500 << endl;
    else {
        int remaining = need - investment;
        quota = min(remaining, 60);
        int additional = remaining - quota;

        cost = (investment * 1500) + (quota * 1500) + (additional * 3000);
        cout << cost << endl;
    }

    return 0;
}
