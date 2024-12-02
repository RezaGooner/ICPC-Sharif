#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> result;

    while(true){
        int n, a, b, c;
        cin >> n;
        if (n == 0)
            break;

        cin >> a >> b >> c;
        int fail = 0;
        int carry = 0;

        for (int i = 0; i < n; i++){
            int aI = a % 10, bI = b % 10, cI = c % 10;

            int sum = aI + bI + carry;
            int tempCarry = carry ;
            carry = sum / 10;
            sum = sum % 10;

            if (sum != cI){
                carry = tempCarry ;
                fail++;
            }

            a = a / 10;
            b = b / 10;
            c = c / 10;
        }
        result.push_back(fail);
    }

    for (int i : result)
        cout << i << endl;
    

    return 0;
}
