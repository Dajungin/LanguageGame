#include <stdio.h>
#include <Windows.h>
#include <conio.h> //키 입력이 들어왔을 때 확인하기 위해 추가해야함 
#include <string.h> //문자열 관련 함수 사용할 수 있게 해줌

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int screenIndex; //전역변수이기에 자동적으로 시작 시 0의 값이 들어감
HANDLE screen[2];   //구조체임

void Initialize()
{
	CONSOLE_CURSOR_INFO cursor;

	//화면 버퍼를 2개 생성합니다. 
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
	COORD position = { 0,0 };  //구조체

	DWORD dword;                //구조체 : 데이터 주고 받기 쉽게 해주는 것 

	FillConsoleOutputCharacter
	(
		screen[screenIndex], ' ', 50 * 20, position, &dword);

}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

void Render(int x, int y, const char* string)  //출력하는 것
{
	DWORD dword;
	COORD position = { x,y };

	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], string, strlen(string), &dword, NULL);
}

void Position(int x, int y)
{
	//X와 Y축을 설정하는 구조체입니다. 
	COORD position = { x,y };  //COORD는 구조체다. 

	//콘솔 커서의 좌표를 설정하는 함수입니다.
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

		if (_kbhit())  //블로킹 안 걸리게 하는 법
		{
			key = _getch(); //블로킹이 들어간다. //이걸로 키 입력을 받을 거임

			if (key == -32)
			{
				key = _getch();
			}
			switch (key)
			{
			case LEFT:
				x -= 2;   //별은 2바이트여서 1바이트는 움직이는게 작다.
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
		Render(x, y, "☆");
	}

	return 0;
}
