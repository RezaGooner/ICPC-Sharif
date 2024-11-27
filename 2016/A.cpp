#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> result ;
    int entry ;

    while (true){
        cin >> entry ;
        if (entry == 0)
            break ;
        else if (entry <= 1000000)
            result.push_back(entry);
        else if (entry <= 5000000)
            result.push_back(entry * 0.9) ;
        else
            result.push_back(entry * 0.8) ;
    }

    for (int i : result)
        cout << i << endl ;

    return 0;
}
