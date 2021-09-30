#include <stdio.h>

int whereIsHospital(int a[], int n) {
    int ave_sum;
    int minimum = 100000;
    int index;
    for (int i = a[n - 1]; i >= 0; i--) {
        ave_sum = 0;
        for (int j = 0; j < n; j++) {
            if (i >= a[j]) {
                ave_sum = ave_sum + i - a[j];
            }
            else {
                ave_sum = ave_sum + a[j] - i;
            }
        }
        if (ave_sum <= minimum) {
            index = i;
            minimum = ave_sum;
        }
    }
    return index;
}

void sorted(int a[], int n) {
    int temp;
    for (int i = 0; i < n; i++)   
    {
        for (int j = 0; j < n - 1; j++)   
        {
            if (a[j] > a[j + 1])          
            {                                
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;           
            }
        }
    }
}

int main() {
    int loc;
    float total = 0;
    float ave;
    int n;
    int a[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sorted(a, n);
    loc = whereIsHospital(a, n);
    for (int i = 0; i < n; i++) {
        if (loc >= a[i]) {
            total = total + (loc - a[i]);
        }
        else {
            total = total + (a[i] - loc);
        }
    }
    ave = total / n;
    printf("%d %.2f", loc, ave);
}