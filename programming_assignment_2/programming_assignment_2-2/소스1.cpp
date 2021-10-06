#include <stdio.h>
#include <stdlib.h>

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

int finder(int* a, int n) {

}

int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    
}