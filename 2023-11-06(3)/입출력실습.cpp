#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    char op;
    int n1, n2, res;

    cout << "종료는 exit 입력하기" << endl;

    while (1)
    {
        cout << "? ";
        getline(cin, s);
        if (s == "exit") break;

        int index = 0;

        index = s.find(' ');
        n1 = stoi(s.substr(0, index));
        op = s[index + 1];

        index = s.find(' ', index + 1);
        n2 = stoi(s.substr(index + 1));

        switch (op)
        {
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            // 나눗셈 결과를 실수로 얻기 위해 적어도 하나를 실수로 변환합니다.
            res = static_cast<double>(n1) / n2;
            break;
        default:
            cout << "올바른 연산자가 아닙니다." << endl;
            continue;
        }
        cout << n1 << ' ' << op << ' ' << n2 << " = " << res << endl;
    }

    return 0;
}
