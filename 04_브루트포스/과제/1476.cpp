#include <iostream>

using namespace std;

int calYear(int E, int S, int M){
    for(int year=1; year<=7980; year++){
        int e = (year-1)%15+1;
        int s = (year-1)%28+1;
        int m = (year-1)%19+1;

        if(e==E && s==S && m==M) return year;
    }

    return -1;
}

int main(){
    int E, S, M;
    cin >> E >> S >> M;

    cout << calYear(E, S, M) << "\n";

    return 0;
}