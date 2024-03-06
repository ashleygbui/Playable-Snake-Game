#include "state.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snake_utils.h"

/* Helper function definitions */
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch);
static bool is_tail(char c);
static bool is_head(char c);
static bool is_snake(char c);
static char body_to_tail(char c);
static char head_to_body(char c);
static unsigned int get_next_row(unsigned int cur_row, char c);
static unsigned int get_next_col(unsigned int cur_col, char c);
static void find_head(game_state_t* state, unsigned int snum);
static char next_square(game_state_t* state, unsigned int snum);
static void update_tail(game_state_t* state, unsigned int snum);
static void update_head(game_state_t* state, unsigned int snum);

/* Task 1 */
game_state_t* create_default_state() {
  // TODO: Implement this function.
  
  game_state_t *snake_game;

  snake_game= malloc(sizeof(game_state_t)); 
  
  //snake_game->snakes [10];
  //snake_game->snakes[0] = snake;
 
  snake_game->num_rows = 18;
  snake_game->board = malloc((18* sizeof(char*)));  // columns = 20
  snake_game->num_snakes = 1;

  for(int i = 0; i < snake_game->num_rows; ++i )  // i row, j column
  {
    char* row_of_map = malloc(21 * sizeof(char)); 
    for(int j = 0; j < 21; ++j)
    {
      if(j == 19)
      {
        row_of_map [j]= '#';
      }
      else if(j == 20)
      {
        row_of_map [j] = '\0';
      }
      else if (i == 0 || i == snake_game->num_rows - 1|| j == 0)
      {
        
        row_of_map [j] = '#'; //the boarder
        //printf("%s","#");
      }
      else if(i == 2 && j == 9) // fruit
      {
        row_of_map [j] = '*'; 

      }
      else if(i == 2 && j == 2) // tail
      {
        row_of_map [j] = 'd'; 
      }
      else if(i == 2 && j == 4) // head
      {
        row_of_map [j] = 'D'; 
      }
      else if(i == 2 && j < 4 && j >2) // body
      {
        row_of_map [j] = '>'; 
      }
      else if(i ==17 && j == 1)
      {
        row_of_map [j] = 'X'; 
      }
      else
      {
        row_of_map [j]= ' ';
      }
      
    }
    // printf("%s\n",row_of_map);
    snake_game->board[i] = row_of_map;

  }
  //free(row_of_map); //do we need to do this
  
  //FINAL SNAKE
  snake_t *snake;
  snake = malloc(sizeof(snake_t)); 
  snake->head_col = 4;
  snake->head_row = 2;
  snake->tail_col = 2;
  snake->tail_row = 2;
  snake->live = true;

  snake_game->snakes = snake; //connecting board and snake

  
  return snake_game;
}

/* Task 2 */
void free_state(game_state_t* state) {
  // TODO: Implement this function.
  //free(state);
  for(int i = 0; i < state->num_rows; ++i )  // i row, j column
  {
    free(state->board[i]);

  }
  free(state->board);
  free(state->snakes);
  free(state);

  return;
}

/* Task 3 */
void print_board(game_state_t* state, FILE* fp) {
  // TODO: Implement this function.
  for(int i = 0; i < state->num_rows; ++i)
  {
    fprintf(fp, "%s\n", state->board[i]);
  }
}

/*
  Saves the current state into filename. Does not modify the state object.
  (already implemented for you).
*/
void save_board(game_state_t* state, char* filename) {
  FILE* f = fopen(filename, "w");
  print_board(state, f);
  fclose(f);
}

/* Task 4.1 */

/*
  Helper function to get a character from the board
  (already implemented for you).
*/
char get_board_at(game_state_t* state, unsigned int row, unsigned int col) {
  return state->board[row][col];
}

/*
  Helper function to set a character on the board
  (already implemented for you).
*/
static void set_board_at(game_state_t* state, unsigned int row, unsigned int col, char ch) {
  state->board[row][col] = ch;
}

/*
  Returns true if c is part of the snake's tail.
  The snake consists of these characters: "wasd"
  Returns false otherwise.
*/
static bool is_tail(char c) {
  // TODO: Implement this function.
  if (c == 'w' || c == 'a' || c == 's' || c == 'd')
  {
    return true;
  }
  else
  {
    return false;
  }
  
}

/*
  Returns true if c is part of the snake's head.
  The snake consists of these characters: "WASDx"
  Returns false otherwise.
*/
static bool is_head(char c) {
  // TODO: Implement this function.
   if (c == 'W' || c == 'A' || c == 'S' || c == 'D' || c == 'x')
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*
  Returns true if c is part of the snake.
  The snake consists of these characters: "wasd^<v>WASDx"
*/
static bool is_snake(char c) {
  // TODO: Implement this function.
  if (is_tail(c) || is_head(c) || c == '^' || c == '<'|| c == 'v' || c == '>')// ^<v> make comparison to this
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*
  Converts a character in the snake's body ("^<v>")
  to the matching character representing the snake's
  tail ("wasd").
*/
static char body_to_tail(char c) {
  // TODO: Implement this function.
  if(c == '^')
  {
    return 'w';
  }
  else if(c == '<')
  {
    return 'a';
  }
  else if(c == 'v')
  {
    return 's';
  }
  else if(c == '>')
  {
    return 'd';
  }
  else
  {
    return ' ';
  }
}

/*
  Converts a character in the snake's head ("WASD")
  to the matching character representing the snake's
  body ("^<v>").
*/
static char head_to_body(char c) {
  // TODO: Implement this function.
  if(c == 'W')
  {
    return '^';
  }
  else if(c == 'A')
  {
    return '<';
  }
  else if(c == 'S')
  {
    return 'v';
  }
  else if(c == 'D')
  {
    return '>';
  }
  else
  {
    return ' ';
  }
}

/*
  Returns cur_row + 1 if c is 'v' or 's' or 'S'.
  Returns cur_row - 1 if c is '^' or 'w' or 'W'.
  Returns cur_row otherwise.
*/
static unsigned int get_next_row(unsigned int cur_row, char c) {
  // TODO: Implement this function.
  if(c == 'v' || c == 's' || c == 'S')
  {
    return cur_row + 1;
  }
  else if(c == '^' || c == 'w' || c == 'W')
  {
    return cur_row - 1;
  }
  else
  {
    return cur_row;
  }
  
}

/*
  Returns cur_col + 1 if c is '>' or 'd' or 'D'.
  Returns cur_col - 1 if c is '<' or 'a' or 'A'.
  Returns cur_col otherwise.
*/
static unsigned int get_next_col(unsigned int cur_col, char c) {
  // TODO: Implement this function.
  if(c == '>' || c == 'd' || c == 'D')
  {
    return cur_col + 1;
  }
  else if(c == '<' || c == 'a' || c == 'A')
  {
    return cur_col - 1;
  }
  else
  {
    return cur_col;
  }
}

/*
  Task 4.2

  Helper function for update_state. Return the character in the cell the snake is moving into.

  This function should not modify anything.
*/
static char next_square(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  char snakeHead = state->board[state->snakes[snum].head_row][state->snakes[snum].head_col];
  unsigned int nextRow = get_next_row(state->snakes[snum].head_row, snakeHead);
  unsigned int nextCol = get_next_col(state->snakes[snum].head_col, snakeHead);
  return get_board_at(state, nextRow, nextCol); 

}

/*
  Task 4.3

  Helper function for update_state. Update the head...

  ...on the board: add a character where the snake is moving

  ...in the snake struct: update the row and col of the head

  Note that this function ignores food, walls, and snake bodies when moving the head.
*/
static void update_head(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.

  snake_t snake = state->snakes[snum];
  char snakeHead = state->board[snake.head_row][snake.head_col];
  //updating head on board
  unsigned int nextRow = get_next_row(snake.head_row, snakeHead);
  unsigned int nextCol = get_next_col(snake.head_col, snakeHead);

  state->board[nextRow][nextCol] = snakeHead; //moving head next row

  state->board[snake.head_row][snake.head_col] = head_to_body(snakeHead); //changing head to body

   
  //updating snake_t
  state->snakes[snum].head_row = nextRow; //updating head row
  state->snakes[snum].head_col = nextCol; //updating head col
  return;

}

/*
  Task 4.4

  Helper function for update_state. Update the tail...

  ...on the board: blank out the current tail, and change the new
  tail from a body character (^<v>) into a tail character (wasd)

  ...in the snake struct: update the row and col of the tail
*/
static void update_tail(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  snake_t snake = state->snakes[snum];
  char snakeTail = state->board[snake.tail_row][snake.tail_col];
  //updating tail on board
  unsigned int nextRow = get_next_row(snake.tail_row, snakeTail);
  unsigned int nextCol = get_next_col(snake.tail_col, snakeTail);
    //moving tail 
  char directionOfbody = state->board[nextRow][nextCol];
  snakeTail = body_to_tail(directionOfbody);
  
  state->board[nextRow][nextCol] = snakeTail; //moving tail next row
  state->board[snake.tail_row][snake.tail_col] = body_to_tail(snakeTail); //changing body to tail

  //updating snake_t
  state->snakes[snum].tail_row = nextRow; //updating head row
  state->snakes[snum].tail_col = nextCol; //updating head col
  return;
}

/* Task 4.5 */
void update_state(game_state_t* state, int (*add_food)(game_state_t* state)) {
  // TODO: Implement this function.
  for (int i = 0; i < state->num_snakes; i++) {
    char n = next_square(state, i);
    if ((n == '#') | is_snake(n))
    {
      state->snakes[i].live = false;
      set_board_at(state, state->snakes[i].head_row, state->snakes[i].head_col, 'x');
    } 
    else if (n == '*')
    {
      update_head(state, i);
      add_food(state);
    }
    else 
    {
      update_head(state, i);
      update_tail(state, i);
    }
  }
  return;
}

/* Task 5 */
game_state_t* load_board(char* filename) {
  // TODO: Implement this function.
  FILE* f = fopen(filename, "r");
  if (f == NULL) {
    return NULL;
  }
  game_state_t* game = malloc(sizeof(game_state_t));
  if (game == NULL) {
    return NULL;
  }
  game->num_snakes = 0;
  game->snakes = NULL;
  game->board = NULL;
  unsigned int num_rows = 0;
  int c = fgetc(f);
  int row_len;
  while (!feof(f)) {
    game->board = realloc(game->board, (num_rows + 1) * sizeof(void*));
    (game->board)[num_rows] = NULL;
    row_len = 0;
    while (c != '\n') {
      row_len++;
      (game->board)[num_rows] = realloc((game->board)[num_rows], row_len * sizeof(char));
      (game->board)[num_rows][row_len-1] = c;
      c = fgetc(f);
    }
    (game->board)[num_rows] = realloc((game->board)[num_rows], (row_len+1) * sizeof(char));
    (game->board)[num_rows][row_len] = '\0';
    c = fgetc(f);
    num_rows++;
  }
  game->num_rows = num_rows;
  fclose(f);
  return game;
}

/*
  Task 6.1

  Helper function for initialize_snakes.
  Given a snake struct with the tail row and col filled in,
  trace through the board to find the head row and col, and
  fill in the head row and col in the struct.
*/
static void find_head(game_state_t* state, unsigned int snum) {
  // TODO: Implement this function.
  if (state == NULL) {
    return;
  }
  char **board = state->board;
  unsigned int curr_x = ((state->snakes)[snum]).tail_col;
  unsigned int curr_y = ((state->snakes)[snum]).tail_row;
  char curr = board[curr_y][curr_x];
  while (!is_head(curr)) {
    if(curr == 'v' || curr == 's' || curr == 'S') {
      curr_y += 1;
    }
    else if(curr == '^' || curr == 'w' || curr == 'W') {
      curr_y -= 1;
    }
    else if(curr == '>' || curr == 'd' || curr == 'D') {
      curr_x += 1;
    }
    else if(curr == '<' || curr == 'a' || curr == 'A') {
      curr_x -= 1;
    }
    else { 
      printf("This shouldn't be happening");
      return;
    }
    curr = board[curr_y][curr_x];
  }
  ((state->snakes)[snum]).head_col = curr_x;
  ((state->snakes)[snum]).head_row = curr_y;
  return;
}

/* Task 6.2 */
game_state_t* initialize_snakes(game_state_t* state) {
  char **board = state->board;
  state->snakes = NULL;
  unsigned int curr_row = 0;
  unsigned int num_snakes = 0;
  while (curr_row < state->num_rows) {
    char* row = board[curr_row];
    unsigned int curr_col = 0;
    while (row[curr_col] != '\0') {
      if (is_tail(row[curr_col])) {
        num_snakes++;
        state->snakes = realloc(state->snakes, sizeof(snake_t) * num_snakes);
        ((state->snakes)[num_snakes-1]).tail_col = curr_col;
        ((state->snakes)[num_snakes-1]).tail_row = curr_row;
        find_head(state, num_snakes-1);
      }
      curr_col++;
    }
    curr_row++;
  }
  state->num_snakes = num_snakes;
  return state;
}
