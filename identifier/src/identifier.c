#include "identifier.h"

int valid_s(char ch);
int valid_f(char ch);

int identifier(char * ident)
{
  char achar;
  int  length, valid_id;
  length = 0;
  valid_id = valid_s(ident[0]);
  if(valid_id) {
    length = 1;
  }
  achar = ident[1];
  while(achar != '\0') {
    if(!(valid_f(achar))) {
      valid_id = 0;
    }
    length++;
    achar = ident[length];
  }
  if (valid_id && (length >= 1) && (length <= 6)) {
    return 0;
  }
  else {
    return 1;
  }
}

// int main(void)
// {
// 	char string[10] = {"Laaa"};
//     identifier(string);
// }

int valid_s(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}
