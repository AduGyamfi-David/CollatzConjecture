#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef enum {false, true} bool; //Creating Boolean Data Types

int main(int argc, int *argv[]){

  printf("%d \n", argc);

  // int i = 0
  // for (i = 0; i < argc; i ++){
  //
  //   printf("%s \n", argv[i]);
  //
  // }
  int inNum = atoi(argv[1]);
  printf("%d \n", inNum);
  int outNum = inNum;
  int tempNum = 0;
  int flag = false;

  int counter = 0;
  while (outNum != 1){
    tempNum = outNum;
    counter += 1;
    if (outNum < 0){
      printf("Error occured.\n Last number = %d.\n Current number = %d.\n Number of iterations = %d", tempNum, outNum, counter);
      outNum = 1;
    }
    else{
      operation(outNum, tempNum, flag);
    }
    // if (outNum % 2 == 0){
    //   outNum = outNum / 2;
    //   printf("Dividing by 2. \n \nResult is %d \n", outNum);
    // }
    // else{
    //   outNum = (3 * outNum) + 1;
    //   printf("Multiplying by 3 and adding 1.\n \nResult is %d \n", outNum);
    // }
  }
  if (outNum == 1){
    printf("Expexcted outcome.\n Number of iterations = %d", counter);
  }
  int value = 0;
}

int operation(int* num, int* pNum, int* flag){
  if (num < 0){
    flag = true;
  }
  else{
    pNum = num;
    if (num % 2 == 0){
      num = num / 2;
      printf("Dividing by 2. \n \nResult is %d \n", num);
    }
    else{
      num = (3 * num) + 1;
      printf("Multiplying by 3 and adding 1.\n \nResult is %d \n", num);
    }
  }
}
