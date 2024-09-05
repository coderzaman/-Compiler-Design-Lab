#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<string>> productions;
int main() {
    string line;
    cout << "Enter your input: ";
    getline(cin, line);

    productions['X'] = {"xYx"};
    productions['Y'] = {"yY", "ε"};

    string stack = "X$";
    string input = line+"$";
    cout << "Stack         " <<"      Input:" << endl;
    bool ok = true;
    int y = 0;
    while (ok)
    {
        cout << stack << "                   " << input  <<endl;
        if(stack == "$" || input == "$"){
            break;
        }else if(stack[0] == input[0]){
            stack.erase(0, 1);
            input.erase(0, 1);
        }else if(input == "x$"){
            stack.erase(0, 1);
        }else if(stack[0] == 'X'){
            stack.erase(0, 1);
            stack = productions['X'][0] + stack;
        }else if(stack[0] == 'Y'){
            stack.erase(0, 1);
            stack = productions['Y'][0] + stack;
        }
        y++;

    }
    return 0;
}
