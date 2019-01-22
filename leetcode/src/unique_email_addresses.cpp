//
// Created by ljx on 1/21/19.
//

#include "unique_email_addresses.h"

using namespace std;



int numUniqueEmails(std::vector<std::string> &emails) {
    unordered_set<string> actualEmails;
    for(string email: emails){
        string actualEmail;
        bool fix=true;
        for(string::iterator it=email.begin();it<email.end();++it){
            if(*it=='@')
                fix=false;
            if(fix){
                if(*it=='.')
                    continue;
                if(*it=='+'){
                    while(*(it+1)!='@')
                        ++it;
                    continue;
                }
            }
            actualEmail.push_back(*it);
        }
        actualEmails.insert(actualEmail);
    }
    return actualEmails.size();
}
