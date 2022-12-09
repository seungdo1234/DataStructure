#include <stdio.h>
#include <stdlib.h>
void printNumber(int arr[], int start, int end, int sortType, int key) { 
    if (sortType == 2) printf("key : %d\nPartition  :    ", key);
    for (int i = start; i <= end; i++) printf("%d ", arr[i]);
    printf("\n");
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int left, int right)
{
    int pivot, low, high;

    low = left;
    high = right + 1;
    pivot = arr[left];
    do {
        do {
            low++;
        } while (low <= right && arr[low] < pivot);
        do {
            high--;
        } while (high >= left && arr[high] > pivot);
        if (low < high) swap(&arr[low], &arr[high]);
    } while (low < high);

    swap(&arr[left], &arr[high]);
    return high;
}
void randmoPivot(int arr[], int left, int right) {
    while (1) {
        int pivot = rand() % right;
        if (pivot > left) {
            printf("\nRandomPivot(%d)  ", arr[pivot]);
            swap(&arr[left], &arr[pivot]);
            printNumber(arr, left, right, 0, 0);
            break;
        }
    }
}
int Selection(int arr[], int left, int right, int key) {
    randmoPivot(arr, left, right);
    int q = partition(arr, left, right);
    printNumber(arr, left, right, 2, key);
    int s = q - left;
    if (key <= s) Selection(arr, left, q - 1, key);
    else if (key == s + 1) return arr[q];
    else  Selection(arr, q + 1, right, key - s - 1);
}
int main() {
    int arr[50], key;
    for (int i = 0; i < 50; i++) arr[i] = rand() % 100;
    printNumber(arr, 0, 49, 0, 0);
    printf("\n몇 번째 작은 수 :  ");
    scanf("%d", &key);
    printf("\n%d번째 작은 수는 %d 입니다. \n", key, Selection(arr, 0, 49, key));
    return 0;
}
