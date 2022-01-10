/*이진탐색을 이용한 숫자 맞추기 게임*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* 인용은 한 사이트에서만 했습니다. */
/* 웹 주소: https://butter-shower.tistory.com/8 */

int search(int list[], int n, int key, int* first, int* final, int* half); /* n은 정수 배열의 크기*/

void main()
{
	int array[100];   /*1부터 100까지의 배열*/
	for (int i = 0; i < 100; i++)
		array[i] = i + 1;
	int decide = 0;   /*-1 or 1*/
	int answer;  /*사람이 고른 값*/
	int count = 0;   /*C의 숫자 맞추기 반복 횟수*/
	int low = 0, high = 99;
	int mid = 0;

	while (1)
	{
		printf("Me가 고른 숫자 (0 입력하면 게임 종료): ");
		scanf("%d", &answer);  /*0입력하면 게임 종료*/
		if (answer != 0)
		{
			printf("Me: 1에서 100까지의 숫자를 생각하고 있습니다. 맞춰보세요.\n");
			while (1)
			{
				decide = search(array, 100, answer, &low, &high, &mid);
				while (decide == -1 || decide == 1)
				{
					if (decide == -1)
					{
						printf("Me: 아닙니다. 더 작습니다.\n");
						count++;
						break;
					}
					else
					{
						printf("Me: 아닙니다. 더 높습니다.\n");
						count++;
						break;
					}
				}
				if (decide != -1 && decide != 1)
					break;

			}
			count++;
			printf("Me: 네 맞습니다. %d번만에 정답을 맞추었습니다.\n\n", count);
			decide = 0, answer = 0, count = 0;   
			low = 0, high = 99, mid = 0;
		}
		else
			break;
	}
}

/* 인용 시작*/
int search(int list[], int n, int key, int *first, int *final, int *half)
{
	*half = (*first + *final) / 2;

	while (*first <= *final)
	{
		if (key < list[*half])
		{
			*final = *half - 1;
			printf("C: %d입니까?\n", *half + 1);
			return -1;
		}
		else if (key > list[*half])
		{
			*first = *half + 1;
			printf("C: %d입니까?\n", *half + 1);
			return 1;
		}
		else
		{
			printf("C: %d입니까?\n", *half + 1);
			return *half + 1;
		}
	}
}
/* 인용 끝*/