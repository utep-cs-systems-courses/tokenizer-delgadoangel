#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h" // project-related declarations


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  if (c == ' ' || c == '\t') {
    return 1;
  }

  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  if (c != ' ' &&  c != '\t' && c != '\0') {
    return 1;
  }
  
  return 0;
}
    
/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str) {
  char *temp = str;

 start:
  if (*temp == '\0') { // Checks null pointer
    return 0;
  }
  
  if (space_char(*temp)) {
    temp += sizeof(char);
    goto start;
  }

  return temp;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token) {
  char *temp = token;

  while (non_space_char(*temp)) {
    temp += sizeof(char);
  }

  return temp;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str) {
  int tokens = 0;
  char * temp = str;
  
 start:
  
  temp = token_start(temp);
  if (temp == 0) {
    goto done;
  }
  
  temp = token_terminator(temp);
  tokens += 1;
  goto start;

 done:
  return tokens;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len) {
  char* ptr = (char*) malloc(len * sizeof(char));

  for (int i = 0; i < len; i += 1) {
    ptr[i] = inStr[i];
  }
  char* end = ptr + len;
  end = 0;

  return ptr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {
  int tokens = count_tokens(str);
  char** strVect = (char**) calloc(tokens, sizeof(char)); // Allocate space for pointers of Strings
  char* token_begin = str;
  char* token_end;
  
  for (int i = 0; i < tokens; i += 1) { // Iterate through str make copies and save their adresses in the new Vector
    token_begin = token_start(token_begin);
    token_end = token_terminator(token_begin);
    
    strVect[i] = copy_str(token_begin,(token_end - token_begin) / sizeof(char));
    token_begin = token_end;
  }

  strVect[tokens] = 0;
	 
  return strVect;
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
  
  for (int i = 0; tokens[i] != 0; i += 1) {
    printf("tokens[%d] : %s\n", i, tokens[i]);
  }

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {
  int i = 0;

  while (tokens[i] != 0) {
    free(tokens[i]);
    i += 1;
  }

  free(tokens[i]);
  free(tokens);

}
