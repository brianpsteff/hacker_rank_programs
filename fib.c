#include<stdio.h>
#include<stdbool.h>


bool isFib(int n);

int main(void){
    
    int testCases, i;
    scanf("%d", &testCases);
    
    for(i = 0; i<testCases; i++)
    {
        long num;
        scanf("%ld", &num);
        if(isFib(num)){
            printf("IsFibo\n");
        } else {
            printf("IsNotFibo\n");
        }
    }
    
}

bool isFib(int n)
{
    //compute without having to us an arry, via the "Brade Method".
    int a = 0;
    int b = 1;
    int c = a + b;
    if(a == n || b==n || c==n){
        return true;
    }
    while(c<=n){
        a = b;
  
        b = c;
    
        c = a+b;
        
        
        if(a == n || b==n || c==n){
            return true;
        }
    }
    return false;
    
    
    
}