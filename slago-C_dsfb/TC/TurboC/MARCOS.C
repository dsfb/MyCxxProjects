#include<stdlib.h>
#include<stdio.h>
main()
{int vetor[10],pos;
for(pos=0;pos<10;pos++)
{
printf ("entre com numero");
scanf("%d",&vetor[pos]);
}
system("pause");

for(pos=9;pos>=0;(pos=pos-1))
{
printf("%d",vetor[pos]);
}

system("pause");
}