#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // ǥ������¿� ���� �Լ����� ���ǵǾ� ����
#include <stdlib.h> // ��������, ���ڿ� ���� ��ȯ, ���� �޸� ����
#include <time.h> // �ð� ���� �Լ��� ��Ƴ��� ex)clock, time, difftime
#include <string.h> // ���� ���ڿ�(�� ���� ���ڿ�)�� �ٷ�
#include<iostream> // ����� ���̺귯���� ���� �ҷ��ͼ� �ҽ��� ����
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
	srand(time(NULL)); // ������ �� �̱�
	select = rand() % num; // select�� �����ϰ� ���� �ܾ��� ��ȣ
						   // num�� ������ �ܾ��� ����
	string problem;
	string answer;
	char char_answer; // �ʱ�ȭ

	int len_answer;
	int count = 0;

	len_answer = words[select].size();
	problem = words[select];



	// ���ĺ� ���� ��ŭ �����(_)�� ǥ���� �� �ִ� for��
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
// Ʋ���� ��� hangman�� �׸��� �ϳ��� �߰���
void score(int count)
{
	if (count == 0)
	{
		printf("	  |_____|\n");
		printf("			|\n");
		printf("			|\n");
		printf("			|\n");
		printf("		   __\n");
	}
	else if (count == 1)
	{
		printf("	|_____|\n");
		printf("       0      |\n");
		printf("              |\n");
		printf("              |\n");
		printf("             __\n");
	}
	else if (count == 2)
	{
		printf("	|_____|\n");
		printf("       0      |\n");
		printf("       |      |\n");
		printf("              |\n");
		printf("             __\n");
	}
	else if (count == 3)
	{
		printf("	|_____|\n");
		printf("       0      |\n");
		printf("      <|      |\n");
		printf("              |\n");
		printf("             __\n");
	}
	else if (count == 4)
	{
		printf("	|_____|\n");
		printf("       0      |\n");
		printf("      <|>     |\n");
		printf("              |\n");
		printf("             __\n");
	}
	else if (count == 5)
	{
	printf("	|_____|\n");
	printf("       0      |\n");
	printf("      <|>     |\n");
	printf("       |      |\n");
	printf("             __\n");
	}
	else if (count == 6)
	{
	printf("	|_____|\n");
	printf("       0      |\n");
	printf("      <|>     |\n");
	printf("      | |     |\n");
	printf("             __\n");
	}


}
