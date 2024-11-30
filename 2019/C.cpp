#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int num;
    cin >> num;
    set<string> validEmails;

    for (int i = 0; i < num; i++) {
        string email;
        cin >> email;

        size_t atPosition = email.find('@');
        if (atPosition != string::npos) {
            string username = email.substr(0, atPosition);
            string domain = email.substr(atPosition + 1);

            string processedUsername;
            bool dot = false, invalid = false, hasConsecutiveDots = false;
            for (size_t i = 0; i < username.size(); i++) {
                char c = username[i];
                if (isalnum(c) || c == '_') {
                    processedUsername += tolower(c);
                    dot = false;
                } else if (c == '.' && !dot) {
                    processedUsername += c;
                    dot = true;
                } else {
                    invalid = true;
                    break;
                }

                if (i > 0 && username[i] == '.' && username[i - 1] == '.') 
                    hasConsecutiveDots = true;
            }

            if (invalid || hasConsecutiveDots || processedUsername.empty() || processedUsername.size() < 6 || processedUsername.size() > 30) 
                continue;

            if (processedUsername.front() == '.' || processedUsername.back() == '.') 
                continue;

            string processedDomain;
            dot = false;
            invalid = false;
            for (size_t i = 0; i < domain.size(); i++) {
                char c = domain[i];
                if (isalnum(c) || c == '-') {
                    processedDomain += tolower(c);
                    dot = false;
                } else if (c == '.' && !dot) {
                    processedDomain += c;
                    dot = true;
                } else {
                    invalid = true;
                    break;
                }
            }

            if (invalid || processedDomain.empty() || processedDomain.size() < 3 || processedDomain.size() > 30) 
                continue;

            if (processedDomain.front() == '.' || processedDomain.back() == '.') 
                continue ;

            string finalUsername;
            for (char c : processedUsername) 
                if (c != '.') 
                    finalUsername += c;
            
            string finalDomain;
            for (char c : processedDomain) 
                if (c != '.') 
                    finalDomain += c;
                

            string repairedEmail = finalUsername + "@" + finalDomain;
            validEmails.insert(repairedEmail);
        }
    }

    cout << validEmails.size() << endl;

    return 0;
}
