#include <iostream>
#include <string>

using namespace std;

bool isRightStr(string strToCheck) {
    char activeBracket = ' ';
    string prevReverseBrackets;
    char activeReverseBracket = ' ';
    for (char symbol : strToCheck) {
        if (symbol == '[') {
            activeBracket = symbol;
            activeReverseBracket = ']';
            prevReverseBrackets.push_back(activeReverseBracket);

        }
        if (symbol == '{') {
            activeBracket = symbol;
            activeReverseBracket = '}';
            prevReverseBrackets.push_back(activeReverseBracket);
        }
        if (symbol == '(') {
            activeBracket = symbol;
            activeReverseBracket = ')';
            prevReverseBrackets.push_back(activeReverseBracket);
        }
        if (symbol == ']' || symbol == ')' || symbol == '}') {
            if (activeReverseBracket == symbol) { 
                activeReverseBracket = prevReverseBrackets[prevReverseBrackets.length() - 1];
                prevReverseBrackets.pop_back();
                continue; 
            }
            else return false;
        }
    }
    return !(prevReverseBrackets.length());
}

int main()
{
    cout << isRightStr("(()");
}
