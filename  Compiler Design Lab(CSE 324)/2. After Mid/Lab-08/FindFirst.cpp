#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<string>> productions;
unordered_set<char> nonTerminals;
unordered_set<char> nullable;

unordered_set<char> first(char nonTerminal) {
    unordered_set<char> firstSet;

    if (!nonTerminals.count(nonTerminal)) {
        firstSet.insert(nonTerminal);
        return firstSet;
    }

    for (auto production : productions[nonTerminal]) {
        bool flag = true;
        for (char symbol : production) {
            if (nonTerminals.count(symbol)) {
                auto firstSymbol = first(symbol);
                firstSet.insert(firstSymbol.begin(), firstSymbol.end());
                if (!nullable.count(symbol)) {
                    flag = false;
                    break;
                }
            } else {
                firstSet.insert(symbol);
                flag = false;
                break;
            }
        }
        if (flag) {
            firstSet.insert('@');
        }
    }
    return firstSet;
}

int main() {
    productions['E'] = {"TX"};
    productions['X'] = {"+TX", "@"};
    productions['T'] = {"FY"};
    productions['Y'] = {"*FY", "@"};
    productions['F'] = {"(E)", "i"};

    nonTerminals = {'E', 'X', 'T', 'Y', 'F'};


    nullable = {'X', 'Y'};

    for (char nonTerminal : nonTerminals) {
        cout << "First(" << nonTerminal << ") = { ";
        auto firstSet = first(nonTerminal);
        for (char symbol : firstSet) {
            cout << symbol << " ";
        }
        cout << "}\n";
    }

    return 0;
}

