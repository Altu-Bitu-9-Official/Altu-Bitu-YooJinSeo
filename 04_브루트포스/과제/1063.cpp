#include <iostream>
#include <vector>

using namespace std;

int alphaToNum(char c){
    return c - 'A' + 1;
}

char numToAlpha(int n){
    return 'A' + (n - 1);
}

bool inRange(int x, int y){
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

pair<int,int> dir(string input){
    if (input == "L") return {-1, 0};
    if (input == "R") return {1, 0};
    if (input == "B") return {0, -1};
    if (input == "T") return {0, 1};
    if (input == "LB") return {-1, -1};
    if (input == "LT") return {-1, 1};
    if (input == "RB") return {1, -1};
    if (input == "RT") return {1, 1};
    return {0, 0};
}

void moveKing(string input, pair<int,int> arr[2]){
    pair<int,int> d = dir(input);
    int nx = arr[0].first + d.first;
    int ny = arr[0].second + d.second;

    if (!inRange(nx, ny)) return; // 범위 밖이면 무시

    // 킹이 돌과 겹침
    if (nx == arr[1].first && ny == arr[1].second) {
        int rx = arr[1].first + d.first;
        int ry = arr[1].second + d.second;

        // 돌이 범위를 벗어나면 둘 다 움직이지 않음
        if (!inRange(rx, ry)) return;

        // 돌 먼저 이동
        arr[1].first = rx;
        arr[1].second = ry;
    }

    // 킹 이동
    arr[0].first = nx;
    arr[0].second = ny;
}

int main(){
    int n;
    string k_p, r_p, input;

    cin >> k_p >> r_p >> n;
    pair<int,int> arr[2];

    arr[0].first=alphaToNum(k_p[0]);
    arr[0].second=k_p[1]-'0';

    arr[1].first=alphaToNum(r_p[0]);
    arr[1].second=r_p[1]-'0';

    while(n--){
        cin >> input;
        moveKing(input, arr);
    }

    cout << numToAlpha(arr[0].first) << arr[0].second << "\n";
    cout << numToAlpha(arr[1].first) << arr[1].second << "\n";

    return 0;
}