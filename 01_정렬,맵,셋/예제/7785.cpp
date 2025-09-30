#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    set<string> ppl;

    cin >> n;

    string name, input;

    for(int i=0; i<n; i++){
        cin >> name >> input;
        if(input=="enter"){
            ppl.insert(name);
        }else{
            ppl.erase(name);
        }
    }

    for (auto iter = ppl.rbegin(); iter!=ppl.rend(); iter++){ //rbegin: begin의 반대, rend: end의 반대
        cout << *iter <<'\n';
    }
}