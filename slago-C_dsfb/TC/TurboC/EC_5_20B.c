#include <stdio.h>
#ifdef TURBOC
#include <conio.h>
#else
#include <stdlib.h>
#endif

void strcpy(char s[], char t[])
{
    unsigned int i = 0;

    while(t[i] != '\0')
    {
        s[i] = t[i];
        i++;
    }

    s[i] = '\0';
}

unsigned int strlen(char s[])
{
	unsigned int i = 0;

	while(s[i] != '\0') i++;

    return  i; 
}

int char2Int(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - 48;
	}

	return -1;
}

int absOfInt(int i)
{
	if (i < 0) i = -i;

	return i;
}

int strContains(char s[], char c)
{
    unsigned int i = 0;

    while(s[i] != '\0')
    {
        if (s[i] == c) return 1;
        i++;
    }

    return 0;
}

int strContainsOnly(char s[], char pattern[])
{
    unsigned int i = 0;

    while(s[i] != '\0')
    {
        if (!strContains(pattern, s[i])) return 0;
        i++;
    }

    i = 0;

    while(pattern[i] != '\0')
    {
        if (!strContains(s, pattern[i])) return 0;
        i++;
    }

    return 1;
}

char* getSubstr(char s[], unsigned int base, unsigned int desloc)
{
	static char response[128];
	unsigned int i = base;

	while(s[i] != '\0')
	{
		response[i - base] = s[i];
		i++;

		if (i > desloc) break;
	}

	response[i - base] = '\0';

	return response;
}

int verificaSeEhSegmentoLinear(char c1, char c2)
{
	return absOfInt(char2Int(c1) - char2Int(c2)) % 4 == 0;
}

int verificaSeEhLinha(char s[])
{
    int result = 1;
    unsigned int i;

    if (strlen(s) == 1) return 1;

    for (i = 0; s[i + 1] != '\0'; i++)
    {
    	if (!verificaSeEhSegmentoLinear(s[i], s[i + 1]))
    	{
    		result = 0;
    		break;
    	}
    }

    return result;
}

int verificaSeehRetangulo(char s[])
{
	unsigned short int numLines = 1;
	unsigned int base = 0, desloc = 1;

	if (strlen(s) < 4) return 0;

	while (s[base + desloc] != '\0')
	{
		if (verificaSeEhLinha(getSubstr(s, base, desloc))) desloc++;
		else
		{
			base = desloc;
			desloc++;
			numLines++;
			if (numLines > 4) return 0;
		}
	}

	return 1;
}

int ehRetangulo(char s[])
{
    if(strContainsOnly(s, "2064"))
	{
		return verificaSeehRetangulo(s);
	}

    if(strContainsOnly(s, "1357"))
	{
		return verificaSeehRetangulo(s);
	}	

	return 0;
}

int inclinouCom2(char c1, char c2)
{
    switch(c1)
    {
        case '0':
            switch(c2)
            {
                case '1':
                case '7':
                    return 1;
            }
            break;
        case '1':
            switch(c2)
            {
                case '2':
                case '0':
                    return 1;
            }
            break;
        case '2':
            switch(c2)
            {
                case '1':
                case '3':
                    return 1;
            }
            break;
        case '3':
            switch(c2)
            {
                case '2':
                case '4':
                    return 1;
            }
            break;
        case '4':
            switch(c2)
            {
                case '3':
                case '5':
                    return 1;
            }
            break;
        case '5':
            switch(c2)
            {
                case '4':
                case '6':
                    return 1;
            }
            break;
        case '6':
            switch(c2)
            {
                case '5':
                case '7':
                    return 1;
            }
            break;
        case '7':
            switch(c2)
            {
                case '6':
                case '0':
                    return 1;
            }
    }

    return 0;
}

int mudouDirecaoCom2(char c1, char c2)
{
    switch(c1)
    {
    	case '0':
    		switch(c2)
    		{
                case '2':                    
    			case '3':    				
    			case '5':
                case '6':
    				return 1;
    		}    		
    		break;
        case '1':
            switch(c2)
            {
                case '3':
                case '4':
                case '6':
                case '7':
                    return 1;
            }
            break;
    	case '2':
    		switch(c2)
    		{
                case '0':
                case '4':
    			case '5':    				
    			case '7':
    				return 1;
    		}
    		break;
        case '3':
            switch(c2)
            {
                case '0':
                case '1':
                case '5':
                case '6':
                    return 1;
            }
            break;
    	case '4':
    		switch(c2)
    		{
    			case '1':
                case '2':
                case '6':    				
    			case '7':
    				return 1;
    		}
    		break;
        case '5':
            switch(c2)
            {
                case '0':
                case '2':
                case '3':
                case '7':
                    return 1;
            }
            break;
    	case '6':
    		switch(c2)
    		{
                case '0':
    			case '1':
    			case '3':
                case '4':
    				return 1;
    		}
    		break;
        case '7':
            switch(c2)
            {
                case '1':
                case '2':
                case '4':
                case '5':
                    return 1;
            }
            break;
    }

    return 0;
}

char simplificaCom2(char c1, char c2)
{
	switch(c1)
    {
    	case '0':
    		switch(c2)
    		{
                case '2':
                    return '1';
    			case '3':
    				return '2';
    			case '5':
    				return '6';
                case '6':
                    return '7';
    		}    		
    		break;
        case '1':
            switch(c2)
            {
                case '3':
                case '4':
                    return '2';
                case '6':
                case '7':
                    return '0';
            }
            break;
    	case '2':
    		switch(c2)
    		{
                case '0':
                    return '1';
                case '4':
                    return '3';
    			case '5':
    				return '4';
    			case '7':
    				return '0';
    		}
    		break;
        case '3':
            switch(c2)
            {
                case '0':
                case '1':
                    return '2';
                case '5':
                case '6':
                    return '4';
            }
            break;
    	case '4':
    		switch(c2)
    		{
    			case '1':
    				return '2';
                case '2':
                    return '3';
                case '6':
                    return '5';
    			case '7':
    				return '6';
    		}
    		break;
        case '5':
            switch(c2)
            {
                case '0':
                case '7':
                    return '6';
                case '2':
                case '3':
                    return '4';
            }
            break;
    	case '6':
    		switch(c2)
    		{
                case '0':
                    return '7';
    			case '1':
    				return '0';
    			case '3':
    				return '4';
                case '4':
                    return '5';
    		}
    		break;
        case '7':
            switch(c2)
            {
                case '1':
                case '2':
                    return '0';
                case '4':
                case '5':
                    return '6';
            }
            break;
    }

    return 0;
}

char *simplificaCom2Inclinado(char c1, char c2)
{
    static char resultado[3] = "";

    switch(c1)
    {
        case '0':
            resultado[0] = '0';
            resultado[1] = '0';
            switch(c2)
            {
                case '1':
                    resultado[2] = '2';
                    break;
                case '7':
                    resultado[2] = '6';
                    break;
            }           
            break;
        case '1':
            switch(c2)
            {
                case '2':
                    resultado[0] = '0';
                    resultado[1] = '2';
                    resultado[2] = '2';
                    break;
                case '0':
                    resultado[0] = '2';
                    resultado[1] = '0';
                    resultado[2] = '0';
                    break;
            }
            break;
        case '2':
            resultado[0] = '2';
            resultado[1] = '2';
            switch(c2)
            {
                case '1':
                    resultado[2] = '0';
                    break;
                case '3':
                    resultado[2] = '4';
                    break;
            }
            break;
        case '3':
            switch(c2)
            {
                case '2':
                    resultado[0] = '4';
                    resultado[1] = '2';
                    resultado[2] = '2';
                    break;
                case '4':
                    resultado[0] = '2';
                    resultado[1] = '4';
                    resultado[2] = '4';
                    break;
            }
            break;
        case '4':
            resultado[0] = '4';
            resultado[1] = '4';
            switch(c2)
            {
                case '3':
                    resultado[2] = '2';
                    break;
                case '5':
                    resultado[2] = '6';
                    break;
            }
            break;
        case '5':
            switch(c2)
            {
                case '4':
                    resultado[0] = '6';
                    resultado[1] = '4';
                    resultado[2] = '4';
                    break;
                case '6':
                    resultado[0] = '4';
                    resultado[1] = '6';
                    resultado[2] = '6';
                    break;
            }
            break;
        case '6':
            resultado[0] = '6';
            resultado[1] = '6';
            switch(c2)
            {
                case '5':
                    resultado[2] = '4';
                    break;
                case '7':
                    resultado[2] = '0';
                    break;
            }
            break;
        case '7':
            switch(c2)
            {
                case '0':
                    resultado[0] = '6';
                    resultado[1] = '0';
                    resultado[2] = '0';
                    break;
                case '6':
                    resultado[0] = '0';
                    resultado[1] = '6';
                    resultado[2] = '6';
                    break;
            }
            break;
    }

    return resultado;
}

int mudouDirecaoCom3(char c1, char c2, char c3)
{
    return mudouDirecaoCom2(c1, c2) || 
        mudouDirecaoCom2(c2, c3);
}

int ehRetanguloAreaZero(char cF[])
{
    if(strContainsOnly(cF, "26") ||
        strContainsOnly(cF, "15") ||
        strContainsOnly(cF, "04") ||
        strContainsOnly(cF, "73"))
    {
        return 1;
    }

    return 0;
}

int ehPoligonoAreaZero(char cF[])
{
    char *cF1, *cF2;
    unsigned int length = strlen(cF);

    if (length % 2 == 0)
    {
        unsigned int length1, length2;

        cF1 = getSubstr(cF, 0, ((length/2) - 1));
        cF2 = getSubstr(cF, length/2, length - 1);

        if (ehRetanguloAreaZero(cF1) &&
            ehRetanguloAreaZero(cF2))
        {
            return 1;
        }

        length1 = strlen(cF1);
        length2 = strlen(cF2);

        if ((length1 > 2) ||
            (length2 > 2))
        {
            return ehPoligonoAreaZero(cF1) ||
                ehPoligonoAreaZero(cF2);
        }
    }
    
    return 0;
}

int insereDupla(char c1, char c2)
{
    switch(c1)
    {
        case '1':
            switch(c2)
            {
                case '3':
                    return 1;
                case '7':
                    return 1;
            }
            break;
        case '3':
            switch(c2)
            {
                case '1':
                    return 1;
                case '5':
                    return 1;
            }
            break;
        case '5':
            switch(c2)
            {
                case '3':
                    return 1;
                case '7':
                    return 1;
            }
            break;
        case '7':
            switch(c2)
            {
                case '1':
                    return 1;
                case '5':
                    return 1;
            }
            break;
    }

    return 0;
}

int inclinacoesCancelantes(char c1, char c2)
{
    switch(c1)
    {
        case '1':
            switch(c2)
            {
                case '3':
                case '7':
                    return 1;
            }
            break;
        case '3':
            switch(c2)
            {
                case '1':
                case '5':
                    return 1;
            }
            break;
        case '5':
            switch(c2)
            {
                case '3':
                case '7':
                    return 1;
            }
            break;
        case '7':
            switch(c2)
            {
                case '1':
                case '5':
                    return 1;
            }
            break;
    }   

    return 0;
}

int temInclinacoesCancelantes(char cF[], int inclinacoes[][2])
{
    int i, j, k;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                if (inclinacoesCancelantes(
                    cF[inclinacoes[i][0]],
                    cF[inclinacoes[j][k]]))
                {
                    return 1;
                }    
            }
        }
    }
}

float calculaAreaComInclinacoes(char cF[], int inclinacoes[][2])
{
    printf("Chamando calculaAreaComInclinacoes(%s)...\n", 
        cF);
    printf("[%d][%d],[%d][%d]...\n", inclinacoes[0][0], 
        inclinacoes[0][1], inclinacoes[1][0],
        inclinacoes[1][1]);
}

float calculaArea(char cF[])
{
    float result = 0;

    int i, j, indiceInclinacoes = -1;

    int inclinacoes[2][2];

	i = 0;
	j = 1;

    printf("Chamando calculaArea(%s)...\n", 
        cF);

    if (ehRetanguloAreaZero(cF))
    {
        return result;
    }

    if (ehPoligonoAreaZero(cF))
    {
        return result;
    }    

	while (cF[j] != '\0')
	{
		if (mudouDirecaoCom2(cF[i], cF[j]))
		{
			char newCF[128];
			unsigned int counter = 0;
            unsigned short int iD = 
                insereDupla(cF[i], cF[j]);

			while (cF[counter] != '\0')
			{
				if (counter < i)
				{
					newCF[counter] = cF[counter];
				}
				else if (counter == i)
				{
					newCF[counter] = simplificaCom2(cF[i], cF[j]);
                    if (iD)
                    {

                        newCF[counter + 1] = newCF[counter];
                    }
				}
				else if (counter > i)
				{
                    if (iD)
                    {
                        newCF[counter + 1] = cF[counter + 1];
                    }
                    else
                    {
                        newCF[counter] = cF[counter + 1];    
                    }
				}

                counter++;
			}

            if (iD)
            {
                return 1 + calculaArea(newCF);                
            }

			return 0.5 + calculaArea(newCF);
		}
        else if (inclinouCom2(cF[i], cF[j]))
        {
            switch (indiceInclinacoes)
            {
                case -1:
                    indiceInclinacoes = 0;
                    inclinacoes[indiceInclinacoes][0]
                     = i;
                    inclinacoes[indiceInclinacoes][1]
                     = j;
                    break;
                case 0:
                    indiceInclinacoes = 1;

                    inclinacoes[indiceInclinacoes][0]
                     = i;
                    inclinacoes[indiceInclinacoes][1]
                     = j;

                    if (temInclinacoesCancelantes(cF, inclinacoes))
                    {
                        return calculaAreaComInclinacoes(cF, 
                            inclinacoes);
                    }
                    else
                    {
                        indiceInclinacoes = 0;
                    }

                    break;                
            }
            /*
            char newCF[128];
            unsigned int counter = 0;
            unsigned short int iD = 
                insereDupla(cF[i], cF[j]);

            while (cF[counter] != '\0')
            {
                if (counter < i)
                {
                    newCF[counter] = cF[counter];
                }
                else if (counter == i)
                {
                    newCF[counter] = simplificaCom2(cF[i], cF[j]);
                    if (iD)
                    {

                        newCF[counter + 1] = newCF[counter];
                    }
                }
                else if (counter > i)
                {
                    if (iD)
                    {
                        newCF[counter + 1] = cF[counter + 1];
                    }
                    else
                    {
                        newCF[counter] = cF[counter + 1];    
                    }
                }

                counter++;
            }

            if (iD)
            {
                return 1 + calculaArea(newCF);                
            }

            return 0.5 + calculaArea(newCF);   
            */

            printf("inclinouCom2(%c, %c)[%d, %d]...\n", 
                cF[i], cF[j], i, j);
        }

		i++;
		j++;
	}

	return result;
}

void main(void)
{
	char cF[128];

	int testing = 1;

    #ifdef TURBOC
    clrscr();
    #endif

    if (testing)
    {
    	int segLin[8];
    	char str4Substr[] = "Hello, Daniel Bruno!";
    	char str4Retangulo[128];

    	segLin[0] = verificaSeEhSegmentoLinear('1', '1');
    	segLin[1] = verificaSeEhSegmentoLinear('1', '0');
    	segLin[2] = verificaSeEhSegmentoLinear('1', '7');
    	segLin[3] = verificaSeEhSegmentoLinear('1', '6');
    	segLin[4] = verificaSeEhSegmentoLinear('1', '5');
    	segLin[5] = verificaSeEhSegmentoLinear('1', '4');
    	segLin[6] = verificaSeEhSegmentoLinear('1', '3');
    	segLin[7] = verificaSeEhSegmentoLinear('1', '2');

    	printf("Testando verificaSeEhSegmentoLinear...\n");
    	printf("%d = 1\n", segLin[0]);
    	printf("%d = 0\n", segLin[1]);
    	printf("%d = 0\n", segLin[2]);
    	printf("%d = 0\n", segLin[3]);
    	printf("%d = 1\n", segLin[4]);
    	printf("%d = 0\n", segLin[5]);
    	printf("%d = 0\n", segLin[6]);
    	printf("%d = 0\n", segLin[7]);

    	/* char str4Substr[] = "Hello, Daniel Bruno!"; */
    	printf("Testando getSubstr...\n");
    	printf("'%s' = 'Hello'\n", getSubstr(str4Substr, 0, 4));
    	printf("'%s' = 'Hello,'\n", getSubstr(str4Substr, 0, 5));
    	printf("'%s' = 'Hello, '\n", getSubstr(str4Substr, 0, 6));
    	printf("'%s' = 'Daniel '\n", getSubstr(str4Substr, 7, 13));
    	printf("'%s' = 'Bruno!'\n", getSubstr(str4Substr, 14, 19));

    	printf("Testando ehRetangulo...\n");
    	strcpy(str4Retangulo, "2064");
    	printf("'%d' = '1'\n", ehRetangulo(str4Retangulo));
    	strcpy(str4Retangulo, "205");
    	printf("'%d' = '0'\n", ehRetangulo(str4Retangulo));
        strcpy(str4Retangulo, "2060");
        printf("'%d' = '0'\n", ehRetangulo(str4Retangulo));
        strcpy(str4Retangulo, "00646422");
        printf("'%d' = '0'\n", ehRetangulo(str4Retangulo));
        strcpy(str4Retangulo, "0065422");
        printf("'%d' = '0'\n", ehRetangulo(str4Retangulo));

        printf("Testando calculaArea...\n");
        printf("'%.1f' = '0.5'\n", calculaArea("250"));
        printf("'%.1f' = '1.0'\n", calculaArea("6316"));
        printf("'%.1f' = '1.0'\n", calculaArea("416614"));
        printf("'%.1f' = '1.0'\n", calculaArea("2064"));
        printf("'%.1f' = '2.0'\n", calculaArea("200644"));
        printf("'%.1f' = '2.0'\n", calculaArea("1753"));
        /*
        printf("'%.1f' = '...'\n", calculaArea("11000060666464444332"));
        */
        /*
        printf("'%.1f' = '9.0'\n", calculaArea("200066644422"));
        
        printf("'%.1f' = '6.0'\n", calculaArea("0006644422"));
        printf("'%.1f' = '7.0'\n", calculaArea("10765432"));
        */
    	printf("Pressione algo para sair!");	
		getch();
		exit(1);
    }

	printf("Digite a cadeia de Freeman: ");
	scanf("%s", &cF);

	printf("A area da cadeia de Freeman '%s' eh: %.2f.\n", 
		cF, calculaArea(cF));

	printf("Pressione algo para sair!");	
	getch();
}