#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidCarNumber(const string& carNumber) {
    if (carNumber.length() != 8) return false;

    if (carNumber[0] < '1' || carNumber[0] > '9' || carNumber[1] != carNumber[0]) return false;

    if (carNumber[2] < '1' || carNumber[2] > '9' || carNumber[3] < '1' || carNumber[3] > '9') return false;

    if (carNumber[4] < 'A' || carNumber[4] > 'Z') return false;

    if (carNumber[5] < '1' || carNumber[5] > '9' || carNumber[6] < '1' || carNumber[6] > '9' || carNumber[7] < '1' || carNumber[7] > '9') return false;

    return true;
}

int main() {
    int num;
    cin >> num;

    vector<string> wrongCarNumbers;

    for (int i = 0; i < num; i++) {
        string carNumber;
        cin >> carNumber;

        if (!isValidCarNumber(carNumber)) {
            wrongCarNumbers.push_back(carNumber);
        }
    }

    for (string i : wrongCarNumbers) {
        cout << i << endl;
    }

    return 0;
}
