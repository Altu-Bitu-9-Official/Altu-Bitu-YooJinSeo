#include <iostream>
#include <set>

using namespace std;

int subString(string input){
    set<string> result;

    for(int len = 1; len <= input.size(); len++){      // 길이
        for(int start = 0; start <= input.size() - len; start++){  // 시작위치
            result.insert(input.substr(start, len)); //문자열.substr(시작 위치, 길이)
        }
    }

    return result.size();
}

int main(){
    string input;
    cin >> input;

    cout << subString(input) << '\n';

    return 0;
}