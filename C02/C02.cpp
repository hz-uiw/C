#include<stdio.h>
#include<stdlib.h>  // 랜덤 시드를 설정하는 srand와 랜덤 숫자를 반환하는 rand 함수가 정의 되어있는 라이브러리
#include<time.h>    // 현재 시각을 가져오는 time(0)은 프로그램이 실행될 때 마다 다른 값이 나오게 설정하기 위한 수단

int main()
{
    /*
        주사위를 30번 던졌을 때 나오는 숫자를 시뮬레이션하기 위해 1~6까지의 정수를 랜덤하게 30개 만들어 배열에 저장하고 확인
    */
    int arr[10];
    int dice[30];
    int rand_min = 1;
    int rand_max = 6;

    srand(time(0)); // 현재 시간으로 랜덤 시드 설정

    // 10번 반복하여 랜덤값을 생성하여 배열에 저장
    for (int i = 0; i < 10; i++) 
        arr[i] = rand();

    // 최댓값 16진수, 10진수 출력
    printf("RAND_MAX: %x, %d", RAND_MAX, RAND_MAX);

    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);

    for (int i = 0; i < 30; i++)
    {
        dice[i] = (double)rand() / RAND_MAX * (rand_max - rand_min + 1) + rand_min;
        //dice[i] = rand() % rand_max + rand_min    // 이 방법도 가능
    }

    for (int i = 0; i < 30; i++)
    {
        printf("%d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n');
    }
}