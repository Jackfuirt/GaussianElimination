#include <stdio.h>
#include <math.h>

#define MAX_SIZE 2 //δ֪������

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

 //�������Ԫ�غ���
void inputMatrix(double a[MAX_SIZE][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        printf("�������%d ��:", i + 1);
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
}

// ��˹��Ԫ����
void gaussianElimination(double a[MAX_SIZE][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        int f = 1;
        int bj = 0;
        double count;
        double bs;

        // ȷ���Խ�Ԫ�ط���
        if (a[i][i] == 0) {
            f = 0;
            for (int k = i + 1; k < n; k++) {
                if (a[k][i] != 0) {
                    bj = k;
                    f = 1;
                }
            }

            if (f == 1) {
                // ������
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

        // ��Ԫ
        for (int k = i + 1; k < n; k++) {
            bs = a[k][i] / a[i][i];
            for (int j = 0; j < n + 1; j++) {
                a[k][j] = a[k][j] - bs * a[i][j];
            }
        }
    }
}

// ��⺯��
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

// ��ӡ������
void printMatrix(double a[MAX_SIZE][MAX_SIZE + 1], int n) {
    printf("�����Ǿ���Ϊ��\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%.3lf ", a[i][j]);
        }
        printf("\n");
    }
}

// ��ӡ�⺯��
void printSolution(double x[MAX_SIZE], int n) {
    printf("��Ϊ��\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]=%.3lf\n", i + 1, x[i]);
    }
}
