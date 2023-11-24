#include <stdio.h>
#include <math.h>

#define MAX_SIZE 2 //未知数个数

void inputMatrix(double a[MAX_SIZE][MAX_SIZE + 1], int n);
void gaussianElimination(double a[MAX_SIZE][MAX_SIZE + 1], int n);
void backSubstitution(double a[MAX_SIZE][MAX_SIZE + 1], int n, double x[MAX_SIZE]);
void printMatrix(double a[MAX_SIZE][MAX_SIZE + 1], int n);
void printSolution(double x[MAX_SIZE], int n);

int main(void) {
    double a[MAX_SIZE][MAX_SIZE + 1];
    double x[MAX_SIZE];

    inputMatrix(a, MAX_SIZE);
    gaussianElimination(a, MAX_SIZE);
    printMatrix(a, MAX_SIZE);
    backSubstitution(a, MAX_SIZE, x);
    printSolution(x, MAX_SIZE);

    return 0;
}

 //输入矩阵元素函数
void inputMatrix(double a[MAX_SIZE][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        printf("请输入第%d 行:", i + 1);
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
}

// 高斯消元函数
void gaussianElimination(double a[MAX_SIZE][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        int f = 1;
        int bj = 0;
        double count;
        double bs;

        // 确保对角元素非零
        if (a[i][i] == 0) {
            f = 0;
            for (int k = i + 1; k < n; k++) {
                if (a[k][i] != 0) {
                    bj = k;
                    f = 1;
                }
            }

            if (f == 1) {
                // 交换行
                for (int q = 0; q < n + 1; q++) {
                    count = a[bj][q];
                    a[bj][q] = a[i][q];
                    a[i][q] = count;
                }
            } else {
                printf("Error: Diagonal element is zero, unable to perform Gaussian elimination.");
                return;
            }
        }

        // 消元
        for (int k = i + 1; k < n; k++) {
            bs = a[k][i] / a[i][i];
            for (int j = 0; j < n + 1; j++) {
                a[k][j] = a[k][j] - bs * a[i][j];
            }
        }
    }
}

// 求解函数
void backSubstitution(double a[MAX_SIZE][MAX_SIZE + 1], int n, double x[MAX_SIZE]) {
    for (int i = n - 1; i >= 0; i--) {
        double count = a[i][n];

        for (int j = i + 1; j < n; j++) {
            count -= a[i][j] * x[j];
        }

        if (fabs(a[i][i]) < 1e-10) {
            printf("Error: Singular matrix, back substitution not possible.");
            return;
        }

        x[i] = count / a[i][i];
    }
}

// 打印矩阵函数
void printMatrix(double a[MAX_SIZE][MAX_SIZE + 1], int n) {
    printf("上三角矩阵为：\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%.3lf ", a[i][j]);
        }
        printf("\n");
    }
}

// 打印解函数
void printSolution(double x[MAX_SIZE], int n) {
    printf("解为：\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]=%.3lf\n", i + 1, x[i]);
    }
}
