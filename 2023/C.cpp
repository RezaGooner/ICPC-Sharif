#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> list, middle;
    list.push_back(0);
    int reserve = 1, num, x, p;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> p >> x;
        int index = 0;

        for (int j = 0; j < list.size(); j++) 
            if (list[j] == p) {
                index = j;
                break;
            }
        

        if (x > 0)
            for (int j = 0; j < x; j++) 
                list.insert(list.begin() + index + 1 + j, reserve++) ;
        else {
            x = -x;
            for (int j = 0; j < x && index + 1 < list.size(); j++) 
                list.erase(list.begin() + index + 1);
        }

        int len = list.size();
        if (len % 2 == 0) 
            middle.push_back(list[(len / 2) - 1]);
        else 
            middle.push_back(list[len / 2]) ;
    }

    for (int i : middle) 
        cout << i << endl;
    

    return 0;
}
