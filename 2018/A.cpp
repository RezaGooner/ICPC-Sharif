#include <iostream>
using namespace std;

int main() {
    int perspolis_home, esteghlal_away;
    cin >> perspolis_home >> esteghlal_away;

    int esteghlal_home, perspolis_away;
    cin >> esteghlal_home >> perspolis_away;

    if ((perspolis_home + perspolis_away) > (esteghlal_home + esteghlal_away)) 
        cout << "Persepolis" ;
    else if ((esteghlal_home + esteghlal_away) > (perspolis_home + perspolis_away)) 
        cout << "Esteghlal" ;
    else if (esteghlal_away < perspolis_away) 
        cout << "Persepolis" ;
    else if (esteghlal_away > perspolis_away) 
        cout << "Esteghlal" ;
    else cout << "Penalty" ;
    
    cout << endl ;
    

    return 0;
}
