/*
Machine Exercise 11
Crypt Kicker
from Programming Challenges

RESOURCES :
http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110204&format=html
http://stackoverflow.com/questions/2175356/crypt-kicker-problem-programming-challeneges
*/

#include <stdio.h>

int main() {
   int dictItems = 0, i = 0, j = 0, k = 0;
   int count = 0, count2 = 0;
   int row = 0, col = 0;
   char word[1000][16];
   char encryptWord[80];
   char KeyArray[10];

   printf("Input number of items in dictionary :\n\t> ");
   scanf("%d", &dictItems);

   if(dictItems < 0 || dictItems >= 1000) {
      printf("Invalid. Dictionary items should be less than 1000 words.\n");
      return 0;
   }

   printf("\nEnter dictionary items :\n");
   for(count = 0; count < dictItems; count++) {
      printf("\t> ");
      scanf("%s", &word[i]);
      i++;
   }
   getchar();

   printf("Enter encrypted string :\n\t> ");
   fflush(stdout);
   fgets(encryptWord, 80, stdin);

   int size = i;
   i = 0;

   for(row = 0; row <= size; row++) {
      for(col = 0; word[i][col] != '\0'; col++) {
         printf("%c", word[i][col]);
      }
      printf("\n");
      i++;
   }

   printf("%s", encryptWord);

   count = 0;
   for(j = 0; encryptWord[j] != ' '; j++) {
      KeyArray[j] = encryptWord[j];
      count++;
   }

   printf("%d\n", count);

   for(i = 0; encryptWord[i] != '\n'; i++) {
      for(j = count + 1; encryptWord[j] != ' '; j++) {
         count2++;
      }
      if(count2 > count) {
         for(j = count + 1; encryptWord[j] != ' '; j++) {
            KeyArray[k] = encryptWord[j];
            k++;
         }
      }
   }

   printf("%s", KeyArray);

   return 0;
}
