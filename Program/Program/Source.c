#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //rand()

void Shuffle(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int seed = rand() % size; //size가 10을 안 넘으므로 10이 넘는 값이 나올 수 없다.

		int temporary = array[seed];
		array[seed] = array[i];

		array[i] = temporary;
	}
}
int main()
{
#pragma region 셔플 함수
	//srand(time(NULL));
	//int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//
	//int size = sizeof(list) / sizeof(int);
	//
	//
	//Shuffle(list, size);
	//
	//for (int i = 0; i < size; i++)
	//{
	//	printf("list[%d]의 값 : %d\n", i, list[i]);
	//}
	//
	//return 0;
#pragma endregion

#pragma region 포인터 배열

	const char * dialog[3];

	dialog[0] = "안녕하세요?";
	dialog[1] = "누구신가요?";
	dialog[2] = "탐정입니다.";

	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", dialog[i]); //%s 문자열을 그대로 출력해줌
	}



#pragma endregion



}