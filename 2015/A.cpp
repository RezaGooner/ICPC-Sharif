#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> result ;
    int m , n , k ;

    while(true){
        cin >> m >> n >> k ;
        if (m == 0 && n == 0 && k == 0)
            break ;
        if (m % 2 == 0)
            if (k >= (m / 2))
                result.push_back(-1) ;
            else
                result.push_back(((m / 2) + 1) - n) ;
        else
            if (k >= (m / 2) + 1)
                result.push_back(-1) ;
            else
                result.push_back((( m / 2) + 1) - n) ;
    }

    for (int i : result){
        cout << i << endl ;
    }
    return 0;
}
