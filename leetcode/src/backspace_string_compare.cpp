//
// Created by ljx on 1/21/19.
//

#include "backspace_string_compare.h"

using namespace std;

bool backspaceCompare(std::string S, std::string T) {
    string newS, newT;
    for (char c:S) {
        if (c == '#') {
            if (!newS.empty())
                newS.pop_back();
        }
        else
            newS.push_back(c);
    }

    for (char c:T) {
        if (c == '#') {
            if (!newT.empty())
                newT.pop_back();
        }
        else
            newT.push_back(c);
    }
    return newS == newT;
}
