#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    char op;
    int n1, n2, res;

    cout << "����� exit �Է��ϱ�" << endl;

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
            // ������ ����� �Ǽ��� ��� ���� ��� �ϳ��� �Ǽ��� ��ȯ�մϴ�.
            res = static_cast<double>(n1) / n2;
            break;
        default:
            cout << "�ùٸ� �����ڰ� �ƴմϴ�." << endl;
            continue;
        }
        cout << n1 << ' ' << op << ' ' << n2 << " = " << res << endl;
    }

    return 0;
}
