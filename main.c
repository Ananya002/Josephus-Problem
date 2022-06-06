//Josephus-Problem using array in C
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int main()                                            
{                                                     
    //Local variables
    int n, k, c, i=-1, j=1, cq[SIZE];
    
    printf("Enter the no. of soldiers: ");
    scanf("%d", &n);
    
    printf("Enter a soldier number who you want to let free: ");
    scanf("%d", &k);
    
    c=n;
    
    for(;;)
    {
        j=1;
        for(j=1; j<=k; j++)
        {
            // As soldiers are standing in circular manner, for
            // the soldier at last place has right neighbour as 
            // the first soldier who survived the previous round.
            // So we are taking modulo to make it circular
            i=(i+1)%n;
        
            if(cq[i]==2)
            {
                while(cq[i]==2)
                    i=(i+1)%n;
            }
            
            if(j==k)
            {
                // mark the soldier no. who gets killed with some value (ex. 2)
                // and decrement the no. of soldiers left
                cq[i]=2;
                c--;
                
                // if only one soldier is remaining, then find the soldier no.
                // by incrementing the counter till you get the soldier no.
                // that is not previously marked with 2.
                if(c==1)
                {
                    while(cq[i]==2)
                            i=(i+1)%n;
                    
                    //print the soldier no. who survived
                    printf("The soldier's number who'll be let free : %d\n", i);
                    exit(0);
                }
            }
        }
    }
    return 0; 
}





