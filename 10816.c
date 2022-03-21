#include<stdio.h>
#include<stdlib.h>
int min = 0, max = 0;
void quickSort(long long arr[], int L, int R) {
    int left = L, right = R;
    int pivot = arr[(L + R) / 2];    // pivot ���� (���) 
    int temp;
    do
    {
        while (arr[left] < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
            left++;
        while (arr[right] > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
            right--;
        if (left <= right)    // left�� right���� ���ʿ� �ִٸ� ��ȯ 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
            left++;
            right--;
        }
    } while (left <= right);    // left�� right ���� �����ʿ� ���� ������ �ݺ� 

  /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // ���� �迭 ��������� �ݺ� 

    if (left < R)
        quickSort(arr, left, R);    // ������ �迭 ��������� �ݺ� 
}

int maxBinarySearch(long long* arr, int left, int right, long long key) {
    if (left > right)   return max;

    int mid;
    mid = (left + right) / 2;

    if (key < arr[mid]) {
        return maxBinarySearch(arr, left, mid - 1, key);
    }
    else {
        if (arr[mid] == key) {
            max = mid;
        }
        return maxBinarySearch(arr, mid + 1, right, key);
    }
}
int minBinarySearch(long long* arr, int left, int right, long long key) {
    if (left > right)   return min;

    int mid;
    mid = (left + right) / 2;

    if (key <= arr[mid]) {
        if (arr[mid] == key) {
            min = mid;
        }
        return minBinarySearch(arr, left, mid - 1, key);
    }
    else {
        return minBinarySearch(arr, mid + 1, right, key);
    }
}

int main() {
    int n, m, i;
    long long* arrn;
    long long arrm;
    int result;
    scanf("%d", &n);
    arrn = (long long*)malloc(sizeof(long long) * n);

    for (i = 0; i < n; i++) {
        scanf("%lld%*c", &arrn[i]);
    }

    quickSort(arrn, 0, n - 1);

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%lld", arrm);
        result = maxBinarySearch(arrn, 0, n - 1, arrm) - minBinarySearch(arrn, 0, n - 1, arrm) + 1;
        if(min == 0 && max == 0){
        	result--;
		}
        printf("%d ", result);
        min = 0;
        max = 0;
    }

    free(arrn);
    return 0;
}
