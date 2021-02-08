/*primeiro programa 28-08*/

#include <stdlib.h>
#include <stdio.h>

main()
	{
	int x,y;
	system ("cls");
	printf("digite x=");
	scanf("%d",&x);
	printf("digite y=");
	scanf("%d",&y);
	if (x==y)
	   {
	    printf("os numeros sao iguais,\n\n");
	   }
	 else

	      if (x>y)
	      {
		printf("x maior que y \n\n");
	      }
	      else
	      {
	      printf("y maior que x \n\n");
	      }
	system ("pause");

	}
