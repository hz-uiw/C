#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRIALS 1000000	// 주사위 던지는 횟수

int main()
{
	/*
		크랩스 게임
		두 주사위 숫자의 합은 2에서 12까지 나올 수 있지만 확률이 가장 낮고
		7이 1-6, 2-5, 3-4, 4-3, 5-2, 6-1로 확률이 가장 높음
		랜덤하게 많은 횟수를 시도해보면 수학적으로 계산한 확률의 근사치를 구할 수 있음
		이를 몬테카를로 시뮬레이션 이라고 함
		주사위 두 개를 백만 번 던져서 나오는 두 주사위 숫자의 합을 배열에 저장하고 확률을 출력하는 프로그램
	*/

	int cnt[13] = { 0 };	// 2~12까지의 두 주사위 합을 저장하는 배열
	int rand_min = 1;		// 한 주사위의 최솟값
	int rand_max = 6;		// 한 주사위의 최대값
	int diceSum;			// 두 주사위의 합

	srand(time(0));		// 랜덤 시드 생성

	// 1~6 사이의 랜덤값을 계산할 때 사용되는 값
	int v = rand_max - rand_min + 1;

	// 1과 6사이의 랜덤값을 두 번 생성하고 더해서 diceSum 변수에 저장하고 cnt[diceSum]을 증가 시킴
	for (int i = 0; i < TRIALS; i++)
	{
		diceSum = (int)(rand() / ((double)RAND_MAX + 1) * v + rand_min);
		diceSum += (int)(rand() / ((double)RAND_MAX + 1) * v + rand_min);
		cnt[diceSum]++;
	}

	int total = 0;	// cnt[]에 저장된 숫자의 합을 계산하기 위함
	for (int i = 2; i <= 12; i++)
	{
		// 2~12까지 주사위의 값이 몇 번 나왔는지 횟수와 확률 출력
		printf("cnt[%2d] = %8d, %5.2f%%\n", i, cnt[i], (double)cnt[i] / TRIALS * 100);
		total += cnt[i];
	}
	printf("TRIALS = %d\n", total);
}
