#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //rand()
#include <windows.h>  //Ű �Է��� �� �� �ְ� ����

#define SIZE 10   //������ ���� 

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

	//const char * dialog[SIZE];
	//
	//dialog[0] = "�ȳ��ϼ���?";
	//dialog[1] = "�����Ű���?";
	//dialog[2] = "Ž���Դϴ�.";
	//dialog[3] = "���� �Ƿ����Դϴ�.";
	//dialog[4] = "������ ����ִٰ� �ؼ� �Խ��ϴ�.";
	//dialog[5] = "�� �½��ϴ�..";
	//dialog[6] = "�� ��ǿ� ���� �ƽô°� �ֳ���?.";
	//dialog[7] = "���� �˰� �ֽ��ϴ�..";
	//dialog[8] = "�������ּ���.";
	//dialog[9] = "...........";
	//
	////Ž��	 [5]  ���
	////�Ƿ���  [5]  ���
	//
	////�����̽��� ������ ���� ��ȭ�� �Ѿ
	////Ű �ִ� ��� �񵿱� ��İ� ���� ����� �ִ�.  
	//
	////sleep �̶�� ����� �ִ�. ����Ǵ� �Ϳ� �����̸� �־� ��Ÿ���� �Ϳ� �ð��� ������Ų ���̴�. 
	////�񵿱�� ���� �� ������ �ڵ������� ������ �ȴ�. 
	//int o = 0;
	//while (o<SIZE)
	//{
	//	//0x0000: ������ ���� ���� ���� ȣ�� �������� �������� ���� ����  //�̰��� ��ũ�δ�.
	//
	//	//0x0001: ������ ���� ���� �ְ� ȣ�� �������� �������� ���� ����
	//
	//	//0x8000: ������ ���� ���� ���� ȣ�� �������� �����ִ� ����
	//
	//	//0x8001: ������ ���� ���� �ְ� ȣ�� �������� �����ִ� ����
	//
	//	//             0x20            & 0x0001
	//	
	//
	//
	//	if (GetAsyncKeyState(VK_SPACE) & 0x0001)  //�����̽��� ���� ���� 1�� ���� //GetAsyncKeySatate�� Ű �Է��ϴ� ��
	//		
	//	{
	//		if (o % 2 == 0)
	//		{
	//			printf("Ž�� : %s\n", dialog[o]);
	//		}
	//		else
	//		{
	//			printf("�Ƿ��� : %s\n", dialog[o]);
	//		}
	//
	//		o++;
	//		}
	//	}
	//Sleep(3000); //3000�� 3�� 300�� 0.3�� //������
	//
	//printf("��ȭ�� ����Ǿ����ϴ�.\n");
	//}

#pragma endregion



