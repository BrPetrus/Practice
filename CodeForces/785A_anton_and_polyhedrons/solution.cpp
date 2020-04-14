#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> vals;
    vals["Tetrahedron"] = 4;
    vals["Cube"] = 6;
    vals["Octahedron"] = 8;
    vals["Dodecahedron"] = 12;
    vals["Icosahedron"] = 20;

    int res = 0;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        res += vals[s];
    }

    cout << res << endl;
    return 0;
}


