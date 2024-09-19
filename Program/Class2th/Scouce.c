#include <stdio.h>
#include <Windows.h>
#include <conio.h> //Ű �Է��� ������ �� Ȯ���ϱ� ���� �߰��ؾ��� 
#include <string.h> //���ڿ� ���� �Լ� ����� �� �ְ� ����

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int screenIndex; //���������̱⿡ �ڵ������� ���� �� 0�� ���� ��
HANDLE screen[2];   //����ü��

void Initialize()
{
	CONSOLE_CURSOR_INFO cursor;

	//ȭ�� ���۸� 2�� �����մϴ�. 
	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);
	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);

	cursor.dwSize = 1;
	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);

}

void Flip()
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	screenIndex = !screenIndex;
}

void Clear()
{
	COORD position = { 0,0 };  //����ü

	DWORD dword;                //����ü : ������ �ְ� �ޱ� ���� ���ִ� �� 

	FillConsoleOutputCharacter
	(
		screen[screenIndex], ' ', 50 * 20, position, &dword);

}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

void Render(int x, int y, const char* string)  //����ϴ� ��
{
	DWORD dword;
	COORD position = { x,y };

	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], string, strlen(string), &dword, NULL);
}

void Position(int x, int y)
{
	//X�� Y���� �����ϴ� ����ü�Դϴ�. 
	COORD position = { x,y };  //COORD�� ����ü��. 

	//�ܼ� Ŀ���� ��ǥ�� �����ϴ� �Լ��Դϴ�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	char key = 0;

	int x = 0;
	int y = 0;

	Initialize();


	while (1)
	{
		Flip();
		Clear();

		if (_kbhit())  //���ŷ �� �ɸ��� �ϴ� ��
		{
			key = _getch(); //���ŷ�� ����. //�̰ɷ� Ű �Է��� ���� ����

			if (key == -32)
			{
				key = _getch();
			}
			switch (key)
			{
			case LEFT:
				x -= 2;   //���� 2����Ʈ���� 1����Ʈ�� �����̴°� �۴�.
				break;
			case RIGHT:
				x += 2;
				break;
			case UP:
				y -= 2;
				break;
			case DOWN:
				y += 2;
				break;
			default:printf("exception\n");
				break;
			}
		}
		Render(x, y, "��");
	}

	return 0;
}
