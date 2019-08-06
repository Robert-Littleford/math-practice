/* Written by: Robert Littleford, finished on October 14, 2012 */
/* Filename: math_problems.c */
/* Program to help learn and practice math */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* positive_reinforcement(unsigned int answer, char* name, char* str)
{
    char response1[9] = "Awesome!\0";
    char response2[15] = "You\'re a star!\0";
    char response3[11] = "Math whiz!\0";
    char response4[11] = "Cool job, \0";
    char response5[23] = "Wow, that is Mathwork!\0";

    if ((answer % 5) == 0)
    {
       strcat(str, response1);
       return str;
    }
    else if ((answer % 5) == 1)
    {
       strcat(str, response2);
       return str;
    }
    else if ((answer % 5) == 2)
    {
       strcat(str, response3);
       return str;
    }
    else if ((answer % 5) == 3)
    {
       strcat(response4, name);
       strcat(response4, "!");
       strcat(str, response4);
       return str;
    }
    else
    {
       strcat(str, response5);
       return str;
    }
}

char* encouragement(unsigned int answer, char* str)
{
    char response1[30] = "Sorry, the correct answer is \0";
    char response2[18] = "No, try this one!\0";
    char response3[34] = "You\'ll get the answer in no time!\0";
    char response4[25] = "Wow, close! Try another!\0";
    char response5[46] = "Nice number, but this is the correct answer: \0";

    char conans[4];

    if ((answer % 5) == 0)
    {
       strcat(str, response1);
       //itoa(answer, conans, 10);
       sprintf(conans, "%d", answer);
       strcat(str, conans);
       return str;
    }
    else if ((answer % 5) == 1)
    {
       strcat(str, response2);
       return str;
    }
    else if ((answer % 5) == 2)
    {
       strcat(str, response3);
       return str;
    }
    else if ((answer % 5) == 3)
    {
       strcat(str, response4);
       return str;
    }
    else
    {
       strcat(str, response5);
       //itoa(answer, conans, 10);
       sprintf(conans, "%d", answer);
       strcat(str, conans);
       return str;
    }
}

void getAdditionProblem(unsigned int* num1, unsigned int* num2, unsigned int* answer)
{
	*num1 = rand() % 1001;
	*num2 = rand() % 1001;
	*answer = (*num1) + (*num2);
	printf("%u + %u = ", (*num1), (*num2));
}

void getSubtractionProblem(unsigned int* num1, unsigned int* num2, unsigned int* answer)
{
	*num1 = rand() % 101;
	*num2 = rand() % 101;
	if ((*num1) >= (*num2))
	{
		*answer = (*num1) - (*num2);
		printf("%u - %u = ", (*num1), (*num2));
	}
	else
	{
		*answer = (*num2) - (*num1);
		printf("%u - %u = ", (*num2), (*num1));
	}
}

void getDivisionProblem(unsigned int* num1, unsigned int* num2, unsigned int* answer)
{
	unsigned int operand;
	*num1 = (rand() % 10) + 1;
	operand = (rand() % 10) + 1;
	*num2 = operand * (*num1);
	*answer = (*num2) / (*num1);
	printf("%u / %u = ", (*num2), (*num1));
}

void getMultiplicationProblem(unsigned int* num1, unsigned int* num2, unsigned int* answer)
{
	*num1 = rand() % 13;
	*num2 = rand() % 13;
	*answer = (*num1) * (*num2);
	printf("%u X %u = ", (*num1), (*num2));
}

void getMathProblem(unsigned int* num1, unsigned int* num2, unsigned int* answer, unsigned int* menu_option)
{
	switch ((*menu_option))
	{
		case 1: getAdditionProblem(num1, num2, answer);
			break;
		case 2: getSubtractionProblem(num1, num2, answer);
			break;
		case 3: getDivisionProblem(num1, num2, answer);
			break;
		case 4: getMultiplicationProblem(num1, num2, answer);
			break;
		default :
			break;
	}
}

int main()
{
    unsigned int num1, num2, answer, user_answer, number_of_questions, menu_option; /* Variables to store operands */
    unsigned int correct = 0, wrong = 0;
	int i = 0;
    char name[80];
    char str[50];

    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);

	printf("Welcome to the math practice program!\n");
	printf("Please enter your name: ");
	scanf ("%[^\n]s", name);

    do
    {
		printf("Please choose the type of Quiz you would like to take or enter menu option 5 to quit:\n");
		printf("1. Addition\n2. Subtraction\n3. Division\n4. Multiplication\n5. Quit\n");
		if ((scanf("%u", &menu_option) != 1) || !((1 <= menu_option) && (menu_option <= 5))) {
			  printf("That isn't a valid menu option! Let\'s try again!\n");
			  getchar();getchar();
			  continue;
		}

		if (menu_option != 5) {
			printf("Ok, %s, how many questions would you like to answer?", name);
			if (scanf("%u", &number_of_questions) != 1) {
				  printf("That isn't a number! Let\'s try again!\n");
				  getchar();
				  continue;
			}
			printf("Here we go, %s! Try to answer all %u questions correctly!\n", name, number_of_questions);

			for (i = 0; i < number_of_questions; i++)
			{
				getMathProblem(&num1, &num2, &answer, &menu_option);
				if (scanf("%u", &user_answer) != 1) {
					printf("That isn't a number! Let\'s try again!\n");
					getchar();
					continue;
				}		
				if (user_answer == answer) {
					str[0] = '\0';
					printf("%s\n\n", positive_reinforcement(answer, name, str));
					correct++;
				}
				else {
					str[0] = '\0';
					printf("%s\n\n", encouragement(answer, str));
					wrong++;			
				}
			}
			printf("%s, you got %u correct and %u incorrect!\nThat\'s %.2f percent!\n", name, correct, wrong, ((correct/(float)(correct + wrong))*100));
		}
		else break;
    } while ( menu_option != 5 );

    return 0;
}
