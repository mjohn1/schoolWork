#include "my.h"
/*
 * Pre Conditions takes an int
 * Post Conditions prints the int
 */
void my_int(int i){
  int boolb=0;
  unsigned int ii=i;
  int maxpow10=1;
  unsigned int max_pos=1<<(8*sizeof(int)-1);
  while((max_pos/(maxpow10*10))>1){
    maxpow10*=10;
  }

  if(i==0){
    my_char('0');
    return;
  }

  if(i<0){
    my_char('-');
    ii=i*-1;
  }

  while (maxpow10!=0){
    if(boolb==1){
      my_char((ii/maxpow10)+48);
      ii-=(ii/maxpow10)*maxpow10;
    }
    else{
      if(ii/maxpow10>0){
	my_char((ii/maxpow10)+48);
	ii-=(ii/maxpow10)*maxpow10;
	boolb=1;
      }
    }
    maxpow10/=10;
  }
}
