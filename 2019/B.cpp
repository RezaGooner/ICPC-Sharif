#include <iostream>
#include <vector>

using namespace std;

int main() {
    int balance, period;
    cin >> balance >> period;

    vector<int> prices(period);
    for (int i = 0; i < period; i++) 
        cin >> prices[i];
    
    int gold = 0;

    for (int i = 0; i < period; i++) {
        if (i == period - 1) {
            balance += gold * prices[i];
            gold     = 0;
        }
        else if (prices[i] < prices[i + 1]) {
            int coinsToBuy = balance / prices[i];
            gold += coinsToBuy;
            balance -= coinsToBuy * prices[i];
        }
        else if (gold > 0 && prices[i] >= prices[i + 1]) {
            balance += gold * prices[i];
            gold = 0;
        }
    }

    cout << balance << endl;

    return 0;
}
