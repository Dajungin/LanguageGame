#include <stdio.h>
#include <Windows.h>

void Position(int x, int y)
{
	//X�� Y���� �����ϴ� ����ü�Դϴ�. 
	COORD position = { x,y };  //COORD�� ����ü��. 

	//�ܼ� Ŀ���� ��ǥ�� �����ϴ� �Լ��Դϴ�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	while (1)
	{
		Position(10, 10);
		printf("��");

		Position(5, 5);
		printf("��");

		system("cls"); //ȭ���� ����� �� �̷� ���� ȭ���� ������ �׷ȴٸ� �ݺ�

		
	}
	
	return 0;
}
