#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asserts.h"
// Necessary due to static functions in state.c
#include "state.c"

/* Look at asserts.c for some helpful assert functions */

int greater_than_forty_two(int x) {
  return x > 42;
}

bool is_vowel(char c) {
  char* vowels = "aeiouAEIOU";
  for (int i = 0; i < strlen(vowels); i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

/*
  Example 1: Returns true if all test cases pass. False otherwise.
    The function greater_than_forty_two(int x) will return true if x > 42. False otherwise.
    Note: This test is NOT comprehensive
*/
bool test_greater_than_forty_two() {
  int testcase_1 = 42;
  bool output_1 = greater_than_forty_two(testcase_1);
  if (!assert_false("output_1", output_1)) {
    return false;
  }

  int testcase_2 = -42;
  bool output_2 = greater_than_forty_two(testcase_2);
  if (!assert_false("output_2", output_2)) {
    return false;
  }

  int testcase_3 = 4242;
  bool output_3 = greater_than_forty_two(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  return true;
}

/*
  Example 2: Returns true if all test cases pass. False otherwise.
    The function is_vowel(char c) will return true if c is a vowel (i.e. c is a,e,i,o,u)
    and returns false otherwise
    Note: This test is NOT comprehensive
*/
bool test_is_vowel() {
  char testcase_1 = 'a';
  bool output_1 = is_vowel(testcase_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }

  char testcase_2 = 'e';
  bool output_2 = is_vowel(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }

  char testcase_3 = 'i';
  bool output_3 = is_vowel(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char testcase_4 = 'o';
  bool output_4 = is_vowel(testcase_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char testcase_5 = 'u';
  bool output_5 = is_vowel(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }

  char testcase_6 = 'k';
  bool output_6 = is_vowel(testcase_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }

  return true;
}

/* Task 4.1 */

bool test_is_tail() {
  // TODO: Implement this function.
  char testcase_1 = 'w';
  bool output_1 = is_tail(testcase_1);
  if (!assert_true("output_1", output_1)) { 
    return false;
  }
  char testcase_2 = 'a';
  bool output_2 = is_tail(testcase_2);
  if (!assert_true("output_2", output_2)) { 
    return false;
  }

  char testcase_3 = 's';
  bool output_3 = is_tail(testcase_3);
  if (!assert_true("output_3", output_3)) { 
    return false;
  }

  char testcase_4 = 'd';
  bool output_4 = is_tail(testcase_4);
  if (!assert_true("output_4", output_4)) { 
    return false;
  }
  
  char testcase_5 = 'z';
  bool output_5 = is_tail(testcase_5);
  if (!assert_false("output_5", output_5)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  return true;
}

bool test_is_head() {
  // TODO: Implement this function.
  char testcase_1 = 'W';
  bool output_1 = is_head(testcase_1);
  if (!assert_true("output_1", output_1)) { 
    return false;
  }
  char testcase_2 = 'A';
  bool output_2 = is_head(testcase_2);
  if (!assert_true("output_2", output_2)) { 
    return false;
  }

  char testcase_3 = 'S';
  bool output_3 = is_head(testcase_3);
  if (!assert_true("output_3", output_3)) { 
    return false;
  }

  char testcase_4 = 'D';
  bool output_4 = is_head(testcase_4);
  if (!assert_true("output_4", output_4)) { 
    return false;
  }
  
  char testcase_5 = 'x';
  bool output_5 = is_head(testcase_5);
  if (!assert_true("output_5", output_5)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }

  char testcase_6 = 'z';
  bool output_6 = is_head(testcase_6);
  if (!assert_false("output_6", output_6)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  return true;
}

bool test_is_snake() {
  // TODO: Implement this function.
  char testcase_1 = 'w';
  bool output_1 = is_snake(testcase_1);
  if (!assert_true("output_1", output_1)) { 
    return false;
  }
  char testcase_2 = 'a';
  bool output_2 = is_snake(testcase_2);
  if (!assert_true("output_2", output_2)) { 
    return false;
  }

  char testcase_3 = 's';
  bool output_3 = is_snake(testcase_3);
  if (!assert_true("output_3", output_3)) { 
    return false;
  }

  char testcase_4 = 'd';
  bool output_4 = is_snake(testcase_4);
  if (!assert_true("output_4", output_4)) { 
    return false;
  }
  char testcase_5 = 'W';
  bool output_5 = is_snake(testcase_5);
  if (!assert_true("output_5", output_5)) { 
    return false;
  }
  char testcase_14 = 'A';
  bool output_14 = is_snake(testcase_14);
  if (!assert_true("output_14", output_14)) { 
    return false;
  }

  char testcase_6 = 'S';
  bool output_6 = is_snake(testcase_6);
  if (!assert_true("output_6", output_6)) { 
    return false;
  }

  char testcase_7 = 'D';
  bool output_7 = is_snake(testcase_7);
  if (!assert_true("output_7", output_7)) { 
    return false;
  }
  
  char testcase_9 = '^';
  bool output_9 = is_snake(testcase_9);
  if (!assert_true("output_9", output_9)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase_10 = '<';
  bool output_10 = is_snake(testcase_10);
  if (!assert_true("output_10", output_10)) { 
    return false;
  }
  char testcase_11 = 'v';
  bool output_11 = is_snake(testcase_11);
  if (!assert_true("output_11", output_11)) { 
    return false;
  }

  char testcase_12 = '>';
  bool output_12 = is_snake(testcase_12);
  if (!assert_true("output_12", output_12)) { 
    return false;
  }

  char testcase_13 = 'z';
  bool output_13 = is_snake(testcase_13);
  if (!assert_false("output_13", output_13)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  return true;
}

bool test_body_to_tail() {
  // TODO: Implement this function.
  char testcase_1 = '^';
  bool output_1 = body_to_tail(testcase_1) == 'w' ;
  if (!assert_true("output_1", output_1)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }

  char testcase_2 = '<';
  bool output_2 = body_to_tail(testcase_2) == 'a' ;
  if (!assert_true("output_2", output_2)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }

  char testcase_3 = 'v';
  bool output_3 = body_to_tail(testcase_3) == 's' ;
  if (!assert_true("output_3", output_3)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  
  char testcase_4 = '>';
  bool output_4 = body_to_tail(testcase_4) == 'd' ;
  if (!assert_true("output_4", output_4)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  return true;
}

bool test_head_to_body() {
  // TODO: Implement this function.
  char testcase_1 = 'W';
  bool output_1 = head_to_body(testcase_1) == '^' ;
  if (!assert_true("output_1", output_1)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }

  char testcase_2 = 'A';
  bool output_2 = head_to_body(testcase_2) == '<' ;
  if (!assert_true("output_2", output_2)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }

  char testcase_3 = 'S';
  bool output_3 = head_to_body(testcase_3) == 'v' ;
  if (!assert_true("output_3", output_3)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  
  char testcase_4 = 'D';
  bool output_4 = head_to_body(testcase_4) == '>' ;
  if (!assert_true("output_4", output_4)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  return true;
}

bool test_get_next_row() {
  // TODO: Implement this function.
  char testcase1_char = 'v';
  char testcase1_row = '1';
  bool output_1 = get_next_row(testcase1_row, testcase1_char) ==  testcase1_row + 1;
  if (!assert_true("output_1", output_1)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase2_char = 's';
  char testcase2_row = '1';
  bool output_2 = get_next_row(testcase2_row, testcase2_char) ==  testcase2_row + 1;
  if (!assert_true("output_2", output_2)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase3_char = 'S';
  char testcase3_row = '1';
  bool output_3 = get_next_row(testcase3_row, testcase3_char) ==  testcase3_row + 1;
  if (!assert_true("output_3", output_3)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase4_char = '^';
  char testcase4_row = '1';
  bool output_4 = get_next_row(testcase4_row, testcase4_char) ==  testcase4_row - 1;
  if (!assert_true("output_4", output_4)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase5_char = 'w';
  char testcase5_row = '1';
  bool output_5 = get_next_row(testcase5_row, testcase5_char) ==  testcase5_row - 1;
  if (!assert_true("output_5", output_5)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase6_char = 'W';
  char testcase6_row = '1';
  bool output_6 = get_next_row(testcase6_row, testcase6_char) ==  testcase6_row - 1;
  if (!assert_true("output_6", output_6)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  return true;
}

bool test_get_next_col() {
  // TODO: Implement this function.
  char testcase1_char = '>';
  char testcase1_col = '1';
  bool output_1 = get_next_col(testcase1_col, testcase1_char) ==  testcase1_col + 1;
  if (!assert_true("output_1", output_1)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase2_char = 'd';
  char testcase2_col = '1';
  bool output_2 = get_next_col(testcase2_col, testcase2_char) ==  testcase2_col + 1;
  if (!assert_true("output_2", output_2)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase3_char = 'D';
  char testcase3_col = '1';
  bool output_3 = get_next_col(testcase3_col, testcase3_char) ==  testcase3_col + 1;
  if (!assert_true("output_3", output_3)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase4_char = '<';
  char testcase4_col = '1';
  bool output_4 = get_next_col(testcase4_col, testcase4_char) ==  testcase4_col - 1;
  if (!assert_true("output_4", output_4)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase5_char = 'a';
  char testcase5_col = '1';
  bool output_5 = get_next_col(testcase5_col, testcase5_char) ==  testcase5_col - 1;
  if (!assert_true("output_5", output_5)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  char testcase6_char = 'A';
  char testcase6_col = '1';
  bool output_6 = get_next_col(testcase6_col, testcase6_char) ==  testcase6_col - 1;
  if (!assert_true("output_6", output_6)) { // assertion succeeds if, and only if, bool(expr) evaluates to equal to false.
    return false;
  }
  return true;
}

bool test_customs() {
  if (!test_greater_than_forty_two()) {
    printf("%s\n", "test_greater_than_forty_two failed.");
    return false;
  }
  if (!test_is_vowel()) {
    printf("%s\n", "test_is_vowel failed.");
    return false;
  }
  if (!test_is_tail()) {
    printf("%s\n", "test_is_tail failed");
    return false;
  }
  if (!test_is_head()) {
    printf("%s\n", "test_is_head failed");
    return false;
  }
  if (!test_is_snake()) {
    printf("%s\n", "test_is_snake failed");
    return false;
  }
  if (!test_body_to_tail()) {
    printf("%s\n", "test_body_to_tail failed");
    return false;
  }
  if (!test_head_to_body()) {
    printf("%s\n", "test_head_to_body failed");
    return false;
  }
  if (!test_get_next_row()) {
    printf("%s\n", "test_get_next_row failed");
    return false;
  }
  if (!test_get_next_col()) {
    printf("%s\n", "test_get_next_col failed");
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  init_colors();

  if (!test_and_print("custom", test_customs)) {
    return 0;
  }

  return 0;
}
