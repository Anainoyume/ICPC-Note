/*
    ManacherËã·¨
*/
#include <iostream>
#include <vector>
using namespace std;

// ÆÓËØËã·¨
vector<int> naiveAlgorithm(const string& s) {
    string handle = "$#";
    for (int i = 0; i < s.size(); ++i) {
        handle += s[i];
        handle += "#";
    }
    handle += "$";

    vector<int> res(handle.size()-2,0);
    for (int i = 1; i < handle.size()-1; ++i) {
        while (handle[i-res[i-1]] == handle[i+res[i-1]])
            res[i-1] += 1;
        res[i-1] -= 1;
    }

    return move(res);
}



// ManacherËã·¨
vector<int> Manacher(const string& s) {
    string handle = "$#";
    for (int i = 0; i < s.size(); ++i) {
        handle += s[i];
        handle += "#";
    }
    handle += "^";

    vector<int> res(handle.size(),0);

    int center = 0, r = 0;
    for (int i = 1; i < res.size()-1; ++i) {
        if (i <= r) res[i] = min(r - i, res[2 * center - i]);
        while (handle[i-res[i]-1] == handle[i+res[i]+1])
            res[i] += 1;
        if (res[i] + i > r) {
            r = res[i] + i;
            center = i;
        }
    }

    return move(res);
}

int main()
{
    string s = "110110110011";

    cout << "$ # ";
    for (auto c : s) {
        cout << c << " # ";
    }
    cout << "^" << endl;

    vector<int> ans = Manacher(s);
    for (auto&& i : ans) {
        cout << i << " ";
    }

    system("pause");
    return 0;
}