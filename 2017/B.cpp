#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<bool> result;
    string cardNumber, tempEntry;

    while (true) {
        getline(cin, tempEntry) ;

        cardNumber = "" ;
        for (char c : tempEntry)
            if (c != ' ') cardNumber += c;

        if (cardNumber == "0000000000000000")
            break;

        int oddResult = 0 , evenResult = 0 ;
        for (int i = 0 ; i < 16 ; i++) {
            int digit = cardNumber[i] - '0' ;
            if (i % 2 == 0) {
                int tempOddResult = digit * 2 ;
                tempOddResult > 9 ? oddResult += tempOddResult - 9 : oddResult += tempOddResult ;
            } else
                evenResult += digit;
        }
        (evenResult + oddResult) % 10 == 0 ? result.push_back(true) : result.push_back(false) ;
    }
    for (bool res : result)
        res ? cout << "Yes" << endl : cout << "No" << endl ;

    return 0;
}
