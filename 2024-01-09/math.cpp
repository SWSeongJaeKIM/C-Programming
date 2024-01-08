#include <iostream>

// 이항 계수 계산 함수
unsigned long long binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    else {
        unsigned long long result = 1;
        for (int i = 1; i <= k; i++) {
            result *= (n - i + 1);
            result /= i;
        }
        return result;
    }
}

// (x + a)^n을 전개하고 출력하는 함수
void expandBinomial(int n) {
    std::cout << "(" << 'x' << " + a)^" << n << " = ";

    for (int k = 0; k <= n; k++) {
        unsigned long long coefficient = binomialCoefficient(n, k);

        std::cout << coefficient << " * " << 'x' << "^" << n - k;
        if (k != 0) {
            std::cout << " * a^" << k;
        }

        if (k != n) {
            std::cout << " + ";
        }
        else {
            std::cout << "\n";
        }
    }
}

int main() {
    int math_order        ;
    std::cout << "몇 차수의 다항식을 전개하시겠습니까? ";
    std::cin >> math_order
        ;

    expandBinomial(math_order);

    return 0;
}
