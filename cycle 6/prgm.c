/*Implement Quick Sort algorithm and perform its analysis for worst case,
best-case and average inputs.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt;

void quicksort(int arr[], int st, int en)
{
    if (st >= en)
        return;
    int pivot = arr[st];
    int low = st;
    int high = en;
    while (low <= high)
    {
       while (low <= high && arr[low] < pivot) {
        cnt++;
        low++;
        }
        cnt++;  // Count the failed comparison

       while (low <= high && arr[high] > pivot) {
        cnt++;
        high--;
    }
    cnt++;

        if (low <= high)
        {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    quicksort(arr, st, high);
    quicksort(arr, low, en);
}

void tester()
{
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
    quicksort(arr, 0, n - 1);

    printf("After sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Steps for operations: %d\n", cnt);

    free(arr);
}

void plotter()
{
    srand(time(NULL));
    FILE *f1, *f2, *f3;
    f1 = fopen("quicksortavg.txt", "a");
    f2 = fopen("quicksortbest.txt", "a");
    f3 = fopen("quicksortworst.txt", "a");
    int n = 2;
    while (n <= 1024)
    {
        int *arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        cnt = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, cnt);
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
        cnt = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, cnt);
        for (int i = 0; i < n; i++)
            arr[i] = 5;
        cnt = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, cnt);
        n *= 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    int choice;
    do
    {
        printf("1. Tester\n2. Plotter\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
