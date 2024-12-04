#include <iostream>
#include <string>
#include <vector>

using namespace std;

int timeToMinutes(const string& time) {
    if (time.empty()) throw invalid_argument("Empty string");

    char sign = time[0];
    if (sign != '+' && sign != '-') throw invalid_argument("Invalid sign");

    size_t colonPos = time.find_first_of(".:");
    int hours = 0, minutes = 0;

    if (colonPos == string::npos) {
        if (time.size() > 1)
            hours = stoi(time.substr(1));
    } else {
        if (colonPos > 1)
            hours = stoi(time.substr(1, colonPos - 1));
        if (colonPos + 1 < time.size())
            minutes = stoi(time.substr(colonPos + 1));
    }

    int total = hours * 60 + minutes;
    return sign == '-' ? -total : total;
}

string minutesToTime(int totalMinutes) {
    int hours = totalMinutes / 60;
    int minutes = abs(totalMinutes % 60);
    return to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
}

int main() {
    string line;
    vector<string> results;
    int totalMinutes = 0;

    while (getline(cin, line)) {
        if (line == "###"){
            results.push_back(minutesToTime(totalMinutes));
            break;
        }

        if (line == "$$$") {
            results.push_back(minutesToTime(totalMinutes));
            totalMinutes = 0;
        } else {
            try {
                totalMinutes += timeToMinutes(line);
            } catch (const invalid_argument& e) {
                cerr << "Invalid input: " << line << endl;
            }
        }
    }

    for (string res : results) {
        cout << res << endl;
    }

    return 0;
}
