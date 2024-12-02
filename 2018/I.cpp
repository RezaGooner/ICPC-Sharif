#include <iostream>
#include <set>
#include <string>

using namespace std;

int calculateTime(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return hour * 60 + minute;
}

int main() {
    int n;
    cin >> n;
    set<int> times;

    for (int i = 0; i < n; i++) {
        string tempClock;
        cin >> tempClock;
        int clock = calculateTime(tempClock);
        if (clock >= 390 && clock <= 1140) {
            times.insert(clock);
        }
    }

    if (times.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int firstSeen = *times.begin();
    int lastSeen = *times.rbegin();

    int charge = 0;
    if (firstSeen >= 390 && firstSeen <= 600) {
        if (lastSeen <= 960) {
            charge = 24000;
        } else {
            charge = 36000;
        }
    } else if (firstSeen >= 601 && firstSeen <= 960) {
        if (lastSeen <= 960) { 
            charge = 16800;
        } else {
            charge = 24000;
        }
    }

    cout << charge << endl;
    return 0;
}
