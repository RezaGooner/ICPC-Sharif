#include <iostream>

using namespace std;

int main() {
    int n ;
    cin >> n ;

    int result , temp , entry ;
    bool isFirst = true ;
    for (int i = 0 ; i < n ; i++){
        if (!isFirst) temp = entry ;
        cin >> entry ;
        if (isFirst) temp = entry ;
        isFirst = false ;
        entry > temp ? result += entry - temp : result += 0 ;
    }

    cout << result << endl ;
    return 0;
}
