#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //rand()

void Shuffle(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int seed = rand() % size; //size�� 10�� �� �����Ƿ� 10�� �Ѵ� ���� ���� �� ����.

		int temporary = array[seed];
		array[seed] = array[i];

		array[i] = temporary;
	}
}
int main()
{
#pragma region ���� �Լ�
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
	//	printf("list[%d]�� �� : %d\n", i, list[i]);
	//}
	//
	//return 0;
#pragma endregion

#pragma region ������ �迭

	const char * dialog[3];

	dialog[0] = "�ȳ��ϼ���?";
	dialog[1] = "�����Ű���?";
	dialog[2] = "Ž���Դϴ�.";

	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", dialog[i]); //%s ���ڿ��� �״�� �������
	}



#pragma endregion



}