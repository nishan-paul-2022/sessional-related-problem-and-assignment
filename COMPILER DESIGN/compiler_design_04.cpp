#include <bits/stdc++.h>
using namespace std;


int main()
{
    int road[4][2];
    road[0][0] = 1;
    road[0][1] = 0;
    road[1][0] = 1;
    road[1][1] = 2;
    road[2][0] = 1;
    road[2][1] = 3;
    road[3][0] = 1;
    road[3][1] = 0;

    string roadmap = "0";
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        int current = (int) roadmap[i] - (int) '0';
        int idx = (int) str[i] - (int) 'a';
        int next = road[current][idx];
        roadmap += to_string(next);
    }

    if(roadmap.back() == '3')
        cout << roadmap << endl;
    else
        cout << "reject" << endl;

    return 0;
}