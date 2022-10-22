#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int compareTwoLocks(char* lock1, char* lock2);

int main()
{
    unsigned int locksCount;

    scanf("%u", &locksCount);

    if(locksCount > 20){
        printf("Too much locks!");
        return;
    }


    for(int q=0;q<locksCount;q++){
        char a[60001];
        scanf("%60000s",a);
        char b[60001];
        scanf("%60000s",b);

        printf("%s\n", (compareTwoLocks(a,b))?"yes":"no");
    }

    return 0;
}

unsigned int compareTwoLocks(char* lock1, char* lock2){
    unsigned int len = strlen(lock1);
    if(len != strlen(lock2))
        return 0;


    char templock2[2*len];
    memcpy(templock2, lock2, len);
    memcpy(templock2+len, lock2, len);

    for(unsigned int q=0;q<len;q++){
        if(!strncmp(lock1, templock2+q,len)){
            return 1;
        }
    }
    return 0;
}
