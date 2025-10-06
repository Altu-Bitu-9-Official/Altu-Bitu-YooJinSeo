#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, s, p=0;
    char c;
    cin >> n >> k;

    vector<char> v(n,'?');

    for(int i=0; i<k; i++){
        cin >> s >> c;

        p=(p-s%n+n)%n;

        // 1) 다른 글자가 이미 있을 때
        if (v[p] != '?' && v[p] != c) {
            cout << "!";
            return 0;
        }

        // 2) 같은 글자가 다른 칸에 있을 때
        for (int j = 0; j < n; j++) {
            if (v[j] == c && j != p) {
                cout << "!";
                return 0;
            }
        }

        v[p]=c;
    }

    for(int i=p; i<p+n; i++){
        cout << v[i%n];
    }

    return 0;
}