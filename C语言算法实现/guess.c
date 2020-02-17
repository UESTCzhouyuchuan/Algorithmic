#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int win;

int random_number(int a,int random)
{
	
	if (a > random) {
		printf("Too high.Try again.\n");
		return 1;
	}
	else if (a < random) {
		printf("Too low.Try again.\n");
		return 1;
	}
	else
	{
		printf("Your win in %d guesses\n", win);
		return 0;
	}

}

bool play_game(void)
{
	char ch;
	line:
	printf("Play again? (Y/N)");
	scanf(" %c",&ch);
	if (ch == 'Y')
		return true;
	else if (ch == 'N')
		return false;
		else 
		{
			printf("Error.");
			goto line;
		}
	

}


int main(void)
{
	int n;
	printf("Guess the secret number between 1 and 100.\n");
	do {
		win = 0;
		int random;
        srand(time(NULL));
	    random = rand() % 100 + 1;
		do{
		printf("A new number has been chosen.\n");
		printf("Enter guess: ");
		scanf("%d", &n);
		win++;
 	}while (random_number(n,random)); 
		
	} while (play_game());

	return 0;
}
