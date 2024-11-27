#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> result1 ,  result2 ;

    int a , m , n , b , i = 0;

    while (true){
        cin >> a >> m >> n >> b ;
        if (a == 0 && m == 0 && n == 0 && b == 0)
            break ;
        result1.push_back(n - m);
        result2.push_back(b - a);
        i++ ;
    }

    for (int j = 0 ; j < i ; j++)
        cout << result1[j] << " " << result2[j] << endl ;
    

    return 0;
}
