#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 표준입출력에 관한 함수들이 정의되어 있음
#include <stdlib.h> // 난수생성, 문자열 형식 변환, 동적 메모리 관리
#include <time.h> // 시간 관련 함수를 모아놓음 ex)clock, time, difftime
#include <string.h> // 형식 문자열(널 종료 문자열)을 다룸
#include<iostream> // 입출력 라이브러리를 먼저 불러와서 소스에 포함
using namespace std;

int hangman();

void score(int);
void main()
{
	printf("***Game Start!***\n\n");
	hangman();

}
int hangman() {
	int select;
	int num = 25;
	 string words[25] = {
		{"dog"},{"cat"},{"tiger"},{"rabbit"},
		{"duck"},{"turtle"},{"cow"},{"chicken"},
		{"lion"},{"snake"},{"horse"},{"mouse"},
		{"giraffe"},{"penguin"},{"whale"},{"deer"},
		{"sheep"},{"goat"},{"wolf"},{"fox"},{"elephant"},
		{"bear"},{"camel"},{"dolphin"} };
	srand(time(NULL)); // 무작위 값 뽑기
	select = rand() % num; // select은 랜덤하게 뽑힐 단어의 번호
						   // num은 지정된 단어의 개수
	string problem;
	string answer;
	char char_answer; // 초기화

	int len_answer;
	int count = 0;

	len_answer = words[select].size();
	problem = words[select];



	// 알파벳 개수 만큼 언더바(_)를 표시할 수 있는 for문
	for (int i = 0; i < len_answer; i++) {
		answer.push_back('_');
		cout << '_';
	}
	cout << endl;
	while (1)
	{
		printf("\nPlease type in alphant: ");
		cin >> char_answer;
		cin.ignore();
		cin.clear();
		int right = 0;

		for (int i = 0; i < len_answer; i++) {
			if (problem[i] == char_answer)
			{
				answer[i] = problem[i];
				right = 1;
			}
		}
		if (right == 0)
		{
			printf("wrong!\n");
			count++;
			score(count);
		}
		for (int i = 0; i < len_answer; i++)
		{
			printf("%c", answer[i]);
		}
		printf("\n");
		if (answer == problem)
		{
			printf("*** You Win ***\n");
			break;
		}
		if (count == 6)
		{
			printf("You died...Try again.\n");
			cout << "The answer is " << problem << endl;
			break;
		}
	}
	return 0;
}
// 틀렸을 경우 hangman의 그림이 하나씩 추가됨
void score(int count)
{
	if (count == 0)
	{
		printf("	  |_____|");
		printf("			|");
		printf("	|");
		printf("	|");
		printf("		   __");
	}
	else if (count == 1)
	{
		printf("	|_____|");
		printf("    0	  |");
		printf("		  |");
		printf("          |");
		printf("         __");
	}
	else if (count == 2)
	{
		printf("	|_____|");
		printf("    0	  |");
		printf("	|     |");
		printf("	      |");
		printf("		 __");
	}
	else if (count == 3)
	{
		printf("	|_____|");
		printf("    0	  |");
		printf("   /|     |");
		printf("	      |");
		printf("		 __");
	}
	else if (count == 4)
	{
		printf("	|_____|");
		printf("    0	  |");
		printf("   <|>    |");
		printf("	      |");
		printf("		 __");
	}
	else if (count == 5)
	{
		printf("	|_____|");
		printf("    0	  |");
		printf("   <|>	  |");
		printf("    |     |");
		printf("		 __");
	}
	else if (count == 6)
	{
		printf("	|_____|");
		printf("    0	  |");
		printf("   <|>	  |");
		printf("   | |    |");
		printf("		 __");
	}


}
