#include <stdio.h>
#include <stdlib.h>
#include <err.h>

void print_matrix(float marks[][10], size_t rows)
{
	for(size_t i = 0; i<rows; i++)
	{
		for(size_t j = 0; j<10; j++)
		{
			printf("marks[%zu][%zu]= %f\n",i,j,marks[i][j]);
		}
		printf("\n");
	}
}

void static_string_copy(char dst[], char src[])
{
	size_t i = 0;
	while (src[i]!=0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

size_t len_st(char a[])
{
	size_t i = 0;
	while (a[i] != 0)
	{
		i++;
	}
	return i;
}

void zeros_array(char a[], size_t len)
{
	while (len>0)
	{
		a[len-1] = 0;
		len--;
	}
}



float negative_power_of_ten(int expo)
{
	float res = 1;
	int i = 0;
	while (i<expo)
	{
		res /= 10;
		i++;
	} 
	return res;
}

unsigned long power_of_ten(int expo)
{
	unsigned long res = 1;
	int i = 0;
	while (i<expo)
	{
		res *= 10;
		i++;
	}
	return res;
}

float string_to_float(char str[])
{
	//first we calculate len(partieEntière) et len(partieFractionaire)
	if (str[0] == 0)
	{
		return -1;
	}
	else
	{
		size_t e = 0, f = 0, i = 0, j=0;
		while (str[i] != 0 && str[i] != ',')
		{
			e++;
			i++;
		}
		if ( str[i] == ',' )
		{
			i++;
		}
		while ( str[i] != 0 )
		{
			f++;
			i++;
		}
		float res = 0;
		//printf("e: %zu, f: %zu\n",e,f);
		i = 0;
		while (str[i] != 0 && str[i] != ',')
		{
			res += (str[i]-48) * (power_of_ten(e-i-1));
			i++;
		}
		if ( str[i] == ',' )
		{
			i++;
		}
		while (str[i] != 0)
		{
			res += (str[i]-48) * (negative_power_of_ten(j+1));
			i++;
			j++;
		}
		return res;
	}
}

float partie_frac(float x)
{
	float partie_frac;
	int num = x;
	partie_frac = x - num;
	return partie_frac;
}

int partie_ent(float x)
{
	int num = x;
	return num;
}

/*
void float_to_string(char str[6], float x)
{
	int num = x;
	float frac = x - num;
	size_t e = 0;
	if (num!=0)
	{
		while(num != 0)
		{
			e++;
			num /= 10;
		}
	}
	else
	{
		e = 1;
	}
	size_t f = 0;
	while (frac != 0)
	{
		f++;
		frac *= 10;
		frac = partie_frac(frac);
	}
	str[e+f+1] = 0;
	printf("%s",str);
	num = x;
	frac = partie_frac(x);
	size_t i = e;
	int llevo = 0;
	while (i>0)
	{
		int num2 = (num - llevo)/power_of_ten(i-1);
		str[e-i] = num2 + 48;
		llevo += (str[e-i] - 48) * power_of_ten(i-1);
		i--;
	}
	str[e-i] = ',';
	size_t i2 = e+1;
	size_t j = f;
	
	while(j>0)
	{
		int ent = frac * 10;
		str[i2] = ent + 48;
		j--;
		i2++;
		frac = partie_frac(frac * 10);
	}
	str[i2] = 0;
	
}
*/

void float_to_string(char str[], float x)
{
	int Ex = partie_ent(x);
	size_t i = 0;
	if(Ex == x)
	{
		if ( Ex == 20 )
		{
			str[0] = 2 + 48;
			str[1] = 0 + 48;
			str[2] = 0;
		}
		else if (Ex>9)
		{
			str[0] = 1 + 48;
			str[1] = Ex%10 + 48;
			str[2] = 0;
		}
		else
		{
			str[0] = Ex%10 + 48;
			str[1] = 0;
		}
	}
	
	else
	{
		if ( Ex == 20 )
		{
			str[0] = 2 + 48;
			str[1] = 0 + 48;
			str[2] = ',';
			i = 2;
		}
		else if (Ex>9)
		{
			str[0] = 1 + 48;
			str[1] = Ex%10 + 48;
			str[2] = ',';
			i = 2;
		}
		else
		{
			str[0] = Ex%10 + 48;
			str[1] = ',';
			i = 1;
		}
		float fx = partie_frac(x);
		fx *= 10;
		str[i+1] = partie_ent(fx) + 48;
		fx = partie_frac(fx);
		fx *= 10;
		int Efx = partie_ent(fx);
		if (Efx!=0)
		{
			str[i+2] = Efx + 48;
			str[i+3] = 0;
		}
		else
		{
			str[i+2] = 0;
		}
	}
	
}

void minus_one(float a[][10], size_t rows)
{
	for (size_t f = 0; f<rows; f++)
	{
		for (size_t c = 0; c<10; c++)
		{
			a[f][c] = -1;
		}
	}
}

char *static_to_dynamic(char str[], size_t len)
{
	char *res = malloc(len * sizeof(char) + 1);
	size_t i = 0;
	while ( i < len )
	{
		*(res + i) = str[i];
		i++;
	}
	*(res + i) = 0;
	return res;
}

void concat(char str[], char str2[])
{
	//str2 is added to str, we suppose str is large enough
	size_t i = 0;
	while( str[i] != 0 )
	{
		i++;
	}
	size_t j = 0;
	while( str2[j] != 0)
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	str[i] = 0;
}
char equal_static_strings(char str1[], char str2[])
{
	size_t i = 0;
	while ( str1[i] != 0 && str2[i] != 0 && str1[i] == str2[i])
	{
		i++;
	}
	if(str1[i] == 0 && str2[i] == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char equal_strings(char *str1, char *str2)
{
	size_t i = 0;
	while (*(str1 + i) != 0 && *(str2 + i) != 0
			&& *(str1 + i) == *(str2 + i))
	{
		i++;
	}
	if ( *(str1 + i) == 0 && *(str2 + i) == 0 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


