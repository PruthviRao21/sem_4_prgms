#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt;

void merge(int arr[], int s, int m, int e) {
    int len = e - s;
    int *temp = (int *)malloc(sizeof(int) * len);
    int i = s, j = m, k = 0;

    while (i < m && j < e) {
        cnt++;
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i < m)
        temp[k++] = arr[i++];

    while (j < e)
        temp[k++] = arr[j++];

    for (int l = 0; l < len; l++)
        arr[s + l] = temp[l];

    free(temp);
}

void mergesort(int arr[], int s, int e) {
    if (e - s <= 1)
        return;

    int m = s + (e - s) / 2;

    mergesort(arr, s, m);
    mergesort(arr, m, e);
    merge(arr, s, m, e);
}

void worst_case(int *arr, int n) {
    if (n <= 1)
        return;

    int mid = n / 2;
    int *left = (int *)malloc(sizeof(int) * mid);
    int *right = (int *)malloc(sizeof(int) * (n - mid));

    for (int i = 0; i < mid; i++)
        left[i] = arr[i * 2];

    for (int i = 0; i < n - mid; i++)
        right[i] = arr[i * 2 + 1];

    worst_case(left, mid);
    worst_case(right, n - mid);

    for (int i = 0; i < mid; i++)
        arr[i] = left[i];
    for (int i = 0; i < n - mid; i++)
        arr[mid + i] = right[i];

    free(left);
    free(right);
}

void tester() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    cnt = 0;
    mergesort(arr, 0, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Steps for merge operations: %d\n", cnt);

    free(arr);
}

void plotter() {
    FILE *f_best = fopen("mergesortbest.txt", "w");
    FILE *f_avg = fopen("mergesortavg.txt", "w");
    FILE *f_worst = fopen("mergesortworst.txt", "w");
    FILE *f_worst_data = fopen("worstData.txt", "w");

    srand(time(NULL));

    for (int n = 2; n <= 1024; n *= 2) {
        int *arr = (int *)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        cnt = 0;
        mergesort(arr, 0, n);
        fprintf(f_best, "%d\t%d\n", n, cnt);

        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        worst_case(arr, n);
        for (int i = 0; i < n; i++)
            fprintf(f_worst_data, "%d ", arr[i]);
        fprintf(f_worst_data, "\n");

        cnt = 0;
        mergesort(arr, 0, n);
        fprintf(f_worst, "%d\t%d\n", n, cnt);

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000;
        cnt = 0;
        mergesort(arr, 0, n);
        fprintf(f_avg, "%d\t%d\n", n, cnt);

        free(arr);
    }

    fclose(f_best);
    fclose(f_avg);
    fclose(f_worst);
    fclose(f_worst_data);
}

int main() {
    int choice;
    do {
        printf("1. Tester\n2. Plotter\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tester();
                break;
            case 2:
                plotter();
                break;
            case 0:
                printf("Exited from the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}


