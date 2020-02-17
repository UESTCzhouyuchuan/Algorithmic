#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define FILLER '.'

void generate_random_walk(char a[N][N]);
void print_array(char a[N][N]);
int main(void)
{
  char a[N][N], letter = 'A';
  int x, y, direction, moves_tried, new_x, new_y;

  srand((unsigned) time(NULL));
  generate_random_walk(a);
  x = 0;
  y = 0;
  a[x][y] = letter++;
  direction = rand() % 4;
  moves_tried = 0;

  while (moves_tried < 4 && letter <= 'Z') {
    switch ((direction + moves_tried) % 4) {
      case 0: new_x = x; new_y = y + 1; break;
      case 1: new_x = x; new_y = y - 1; break;
      case 2: new_x = x + 1; new_y = y; break;
      case 3: new_x = x - 1; new_y = y; break;
    }
    if (0 <= new_x && new_x < N &&
        0 <= new_y && new_y < N &&
        a[new_x][new_y] == FILLER) {
      x = new_x;
      y = new_y;
      a[x][y] = letter++;
      direction = rand() % 4;
      moves_tried = 0;
    } else
      moves_tried++;
  }
  print_array(a);
  return 0;
}

void generate_random_walk(char a[N][N]){
	int x,y;
	for (x = 0; x < N; x++)
    for (y = 0; y < N; y++)
      a[x][y] = FILLER;
}
void print_array(char a[N][N]){
	int x,y;
	for (x = 0; x < N; x++) {
    for (y = 0; y < N; y++)
      printf("%c ", a[x][y]);
    printf("\n");
}
}
