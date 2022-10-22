#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int compareTwoLocks(char* lock1, char* lock2);

int main()
{
    //Odczyt iloœci zamków
    unsigned int locksCount;
    scanf("%u", &locksCount);

    //Sprawdzanie czy liczba zamków jest poprawna z za³o¿eniami
    if(locksCount > 20){
        printf("Too much locks!");
        return;
    }

    //Pêtla sprawdzania ci¹gów
    for(int q=0;q<locksCount;q++){

        //Zbieranie dwóch ci¹gów zamków
        char a[60001];
        scanf("%60000s",a);
        char b[60001];
        scanf("%60000s",b);

        //Wypisywanie wyniku porówanania ci¹gów
        printf("%s\n", (compareTwoLocks(a,b))?"yes":"no");
    }

    return 0;
}

//Funkcja porównuj¹ca ci¹gi znakowe zamków
unsigned int compareTwoLocks(char* lock1, char* lock2){
    //Sprawdzanie równoœci d³ugoœci ci¹gów znaków
    unsigned int len = strlen(lock1);
    if(len != strlen(lock2))
        return 0;

    //Tworzenie tymczasowego ci¹gu który jest podówjna kopi¹ zamka 2
    char templock2[2*len];
    memcpy(templock2, lock2, len);
    memcpy(templock2+len, lock2, len);

    //Porównywanie zamka 1 z powojon¹ kopi¹ zamka 2 z przesuwaniem co jeden znak
    for(unsigned int q=0;q<len;q++){
        if(!strncmp(lock1, templock2+q,len)){
            return 1;
        }
    }
    return 0;
}
