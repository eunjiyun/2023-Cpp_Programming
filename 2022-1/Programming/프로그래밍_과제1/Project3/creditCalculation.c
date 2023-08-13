// 반복적으로 점수를 입력하면 학점을 계산하는 프로그램을
//작성하시오.
// 예,
//$ 점수를 입력하시오 : 93
//학점은 A 입니다.
//$ 점수를 입력하시오 : 83
//학점은 B 입니다.
//$ 점수를 입력하시오 : 79
//학점은 C + 입니다.
//$ 점수를 입력하시오 : -1
//종료합니다.



#include<stdio.h>

int main(void)
{
	int score=0;

	while (score != -1)//score가 -1일때 종료
	{
		printf("점수를 입력하시오: ");
		scanf_s("%d", &score);

		switch (score / 10)//score의 십의자리수로 학점 판별
		{
		case 9:case 10:
			printf("학점은 A 입니다.\n");
			break;
		case 8:
			printf("학점은 B 입니다.\n");
			break;
		case 7:
			printf("학점은 C+ 입니다.\n");
			break;
		case 6:
			printf("학점은 D 입니다.\n");
			break;
		case 5:case 4:case 3:case 2:	case 1:case 0:
			if(score==-1)
				printf("종료합니다.\n");
			else
				printf("학점은 F 입니다.\n");
			break;
		default:
			printf("잘못된 입력입니다.\n");//위의 선택지를 모두 제외하면 잘못된 입력으로 처리
			break;
		}
	}

	return 0;
}