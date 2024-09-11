#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //rand()
#include <windows.h>  //키 입력을 할 수 있게 해줌

#define SIZE 10   //사이즈 정함 

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

	//const char * dialog[SIZE];
	//
	//dialog[0] = "안녕하세요?";
	//dialog[1] = "누구신가요?";
	//dialog[2] = "탐정입니다.";
	//dialog[3] = "저는 의뢰인입니다.";
	//dialog[4] = "수상한 사건있다고 해서 왔습니다.";
	//dialog[5] = "네 맞습니다..";
	//dialog[6] = "이 사건에 대해 아시는게 있나요?.";
	//dialog[7] = "조금 알고 있습니다..";
	//dialog[8] = "말씀해주세요.";
	//dialog[9] = "...........";
	//
	////탐정	 [5]  대사
	////의뢰인  [5]  대사
	//
	////스페이스를 누르면 다음 대화로 넘어감
	////키 넣는 방법 비동기 방식과 동기 방식이 있다.  
	//
	////sleep 이라는 방법도 있다. 실행되는 것에 딜레이를 주어 나타나는 것에 시간을 지연시킨 것이다. 
	////비동기는 내가 안 눌러도 자동적으로 진행이 된다. 
	//int o = 0;
	//while (o<SIZE)
	//{
	//	//0x0000: 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태  //이것은 매크로다.
	//
	//	//0x0001: 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
	//
	//	//0x8000: 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
	//
	//	//0x8001: 이전에 누른 적이 있고 호출 시점에도 눌러있는 상태
	//
	//	//             0x20            & 0x0001
	//	
	//
	//
	//	if (GetAsyncKeyState(VK_SPACE) & 0x0001)  //스페이스를 누를 때만 1번 실행 //GetAsyncKeySatate는 키 입력하는 것
	//		
	//	{
	//		if (o % 2 == 0)
	//		{
	//			printf("탐점 : %s\n", dialog[o]);
	//		}
	//		else
	//		{
	//			printf("의뢰인 : %s\n", dialog[o]);
	//		}
	//
	//		o++;
	//		}
	//	}
	//Sleep(3000); //3000은 3초 300은 0.3초 //딜레이
	//
	//printf("대화가 종료되었습니다.\n");
	//}

#pragma endregion



