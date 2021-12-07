#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
  Pessoalmente, eu não gosto de aritimética de ponteiros, e faria este exercício usando regex.
  Mas eu não sei o que vocês tem ai em termos de ambiente para compilar, e é possível que falhe dependencia. Então, no intuito de utilizar apenas as bibliotecas padrão, fiz desta forma, que não considero a melhor
*/

char** stringSplit (const char *text, char separator, int *length) {
  
  int strl = strlen(text);
  char *p1, *p2;
  char **ret;
  int i, j;

  *length = 0;

  for (i=0; i<strl; i++){
    if (text[i] == separator) 
      (*length)++;
  }

  *length -=1;
  if (*length < 1) {
    *length = 0;
    return NULL;
  }

  ret = malloc((*length) * sizeof(char *));

  p1 = (char *)text;
  j =0;
  for (i=0; i< *length; i++){

    while(*p1 != separator)
      p1++;


    p2 = p1 + 1;
    
    while(*p2 != separator){
      p2++;
    }

    *p2 = 0;
    ret[j] = malloc(strlen(p1));
    p1++;
    strncpy(ret[j], p1, strlen(p1));
    p1 = p2;
    *p2 = separator;
    j++;

  }
  return ret;

}

int main(void) {
  char test[] = "/fla/flu/bota/";
  int len, i;
  char ** split;

  split = stringSplit(test, '/', &len);
  for(i = 0; i<len; i++){
    printf("%s\n", split[i]);
  }

  return 0;
}