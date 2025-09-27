#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int sumG(string input){
    int sum = 0;
    for(char c: input){
        if(isdigit(c)){
            sum += (c - '0');  // 문자를 숫자로 변환
        }
    }

    return sum;
}

bool comp(const string& g1, const string& g2){ //false면 swap
    if(g1.length()!=g2.length()){
        return g1.length()<g2.length();
    }
    if(g1.length()==g2.length() && sumG(g1)!=sumG(g2)){
        return sumG(g1)<sumG(g2);
    }
    return g1<g2;

}

int main(){
    int n;
    cin >> n;

    vector<string> guitar(n);

    for(int i=0; i<n; i++){
        cin >> guitar[i];
    }

    sort(guitar.begin(), guitar.end(), comp);
    
    for(int i=0; i<n; i++){
        cout << guitar[i] << '\n';
    }

    return 0;
}