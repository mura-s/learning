#include <iostream>
#include <vector>
using namespace std;

struct Operand {
    int l;
    int r;
};

Operand popOperand(vector<int> &vec) {
    int r = vec.back();
    vec.pop_back();
    int l = vec.back();
    vec.pop_back();

    return {l, r};
}

int main() {
    vector<int> vec;
    string s;
    while (cin >> s) {
        Operand op;
        int result;
        if (s == "+") {
            op = popOperand(vec);
            result = op.l + op.r;
            vec.push_back(result);
        } else if (s == "-") {
            op = popOperand(vec);
            result = op.l - op.r;
            vec.push_back(result);
        } else if (s == "*") {
            op = popOperand(vec);
            result = op.l * op.r;
            vec.push_back(result);
        } else {
            vec.push_back(stoi(s));
        }
    }
    cout << vec.back() << endl;
}
