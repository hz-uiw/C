#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    // 배열, 최솟값, 최댓값, 합
    int arr[10], min, max, sum = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("%d번째 정수 입력 >>> ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%6d\n", arr[i]);
    }

    min = max = arr[0];

    for (int i = 1; i < 10; i++)
    {
        sum += arr[i];
        if (arr[i] < min) min = arr[i];
        else if (arr[i] > max) max = arr[i];
    }

    printf("평균값: %.2f, 최솟값: %d, 최댓값: %d", sum / 10.0, min, max);
}

