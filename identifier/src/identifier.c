#include "identifier.h"

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
  while(achar != '\n') {
    if(!(valid_f(achar))) {
      valid_id = 0;
    }
    length++;
    achar = ident[length];
  }
  if (valid_id && (length >= 1) && (length < 6)) {
    return 0;
  }
  else {
    return 1;
  }
}