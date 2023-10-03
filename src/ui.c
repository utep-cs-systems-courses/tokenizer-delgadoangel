#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  puts("Welcome!");

  while (1) {

    fputs("$ ", stdout);
    
    int i = 0;
    int c;
    char strIn[20];
    
    while ((c = getchar()) == '\n');
    
    while ((c = getchar()) != '\n') {
      strIn[i] = c;
      i += 1;
    }

    fflush(stdout);

    if (c == EOF) {
      goto done;
    }
    
  }

  done: // exit
    return 0;

}


    
