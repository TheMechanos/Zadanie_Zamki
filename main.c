#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int compareTwoLocks(char* lock1, char* lock2);

int main()
{
    //Odczyt ilo�ci zamk�w
    unsigned int locksCount;
    scanf("%u", &locksCount);

    //Sprawdzanie czy liczba zamk�w jest poprawna z za�o�eniami
    if(locksCount > 20){
        printf("Too much locks!");
        return;
    }

    //P�tla sprawdzania ci�g�w
    for(int q=0;q<locksCount;q++){

        //Zbieranie dw�ch ci�g�w zamk�w
        char a[60001];
        scanf("%60000s",a);
        char b[60001];
        scanf("%60000s",b);

        //Wypisywanie wyniku por�wanania ci�g�w
        printf("%s\n", (compareTwoLocks(a,b))?"yes":"no");
    }

    return 0;
}

//Funkcja por�wnuj�ca ci�gi znakowe zamk�w
unsigned int compareTwoLocks(char* lock1, char* lock2){
    //Sprawdzanie r�wno�ci d�ugo�ci ci�g�w znak�w
    unsigned int len = strlen(lock1);
    if(len != strlen(lock2))
        return 0;

    //Tworzenie tymczasowego ci�gu kt�ry jest pod�wjna kopi� zamka 2
    char templock2[2*len];
    memcpy(templock2, lock2, len);
    memcpy(templock2+len, lock2, len);

    //Por�wnywanie zamka 1 z powojon� kopi� zamka 2 z przesuwaniem co jeden znak
    for(unsigned int q=0;q<len;q++){
        if(!strncmp(lock1, templock2+q,len)){
            return 1;
        }
    }
    return 0;
}
