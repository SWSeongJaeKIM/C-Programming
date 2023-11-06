#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double eucdis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int num = 100;
    int tar_1 = 30;
    int tar_2 = 30;

    for (int i = 0; i < num; i++)
    {
        int random_number = std::rand() % (num + 1);

        double distanceToTarget1 = eucdis(random_number, tar_1, 0, 0);
        double distanceToTarget2 = eucdis(random_number, tar_2, 0, 0);

        if (distanceToTarget1 <= 10)
        {
            cout << "Number " << random_number << " satisfies the condition for tar1." << endl;
        }
        if (distanceToTarget2 <= 5)
        {
            cout << "Number " << random_number << " satisfies the condition for tar2." << endl;
        }
    }

    return 0;
}
