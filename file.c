#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "utils.h"

/*
	This is a personal project, the goal of which is to be able
	to control my marks at "university" without needing to write 
	them again and again. Once I enter a mark, it is saved inside
	the text files.
	
	This program calculates a weighted arithmetic mean (a kind of
	average), but you can't choose the weights, this is because
	this program is only meant to work when calculating the average
	mark of a subject in my "university". Indeed, the purpose
	of this program is not to be useful for other people on the 
	internet, it is just a personal project to help me to be aware
	of my marks.
	
	Also, some identifiers are in english, others are in french and
	some others are in spanish.
	
	By Francisco Lara Rico, November 11 2022
*/



float moyenne(float marks[][10], char subject[])
{
	//Calculates the weighted arithmetic mean with the marks
	//in marks[][], where each row is a different section
	//(tests, exams, midterm exam, final exam, practical works, ...)
	float res = 0;
	float suma_coef = 0;
	if (equal_static_strings(subject, "maths.txt") == 1
		|| equal_static_strings(subject, "algo.txt") == 1)
	{
		//qcm
		size_t f = 0, c = 0;
		float suma_qcm = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_qcm += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 2;
			res += suma_qcm/c * 2;
		}
		//ci
		f++;
		c = 0;
		float suma_ci = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_ci += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 2;
			res += suma_ci/c * 2;
		}
		//mid
		f++;
		c = 0;
		float suma_mid = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_mid += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 3;
			res += suma_mid/c * 3;
		}
		//final
		f++;
		c = 0;
		float suma_final = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_final += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 5;
			res += suma_final/c * 5;
		}
		res /= suma_coef;
	}
	else if (equal_static_strings(subject, "prog.txt") == 1)
	{
		//tp
		size_t f = 0, c = 0;
		float suma_tp = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_tp += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 1;
			res += suma_tp/c;
		}
		//mid
		f++;
		c = 0;
		float suma_mid = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_mid += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 2;
			res += suma_mid/c * 2;
		}
		//final
		f++;
		c = 0;
		float suma_final = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_final += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 3;
			res += suma_final/c * 3;
		}
		res /= suma_coef;
	}
	else if (equal_static_strings(subject, "phy.txt") == 1
		|| equal_static_strings(subject, "elec.txt") == 1
		|| equal_static_strings(subject, "archi.txt") == 1)
	{
		//qcm
		size_t f = 0, c = 0;
		float suma_qcm = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_qcm += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 1;
			res += suma_qcm/c;
		}
		//mid
		f++;
		c = 0;
		float suma_mid = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_mid += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 1;
			res += suma_mid/c;
		}
		//final
		f++;
		c = 0;
		float suma_final = 0;
		while (c<10 && marks[f][c] != -1)
		{
			suma_final += marks[f][c];
			c++;
		}
		if (c != 0)
		{
			suma_coef += 2;
			res += suma_final/c * 2;
		}
		res /= suma_coef;
	}
	return res;
}


size_t index_matr(char filename[], char category[])
{
	//returns the index of the row of the marks matrix 
	//where a new mark for the "category" category should be added
	//for the subject "filename"
	size_t res = 0;
	if ( equal_static_strings(filename,"maths.txt") == 1 )
	{
		//maths categories: "qcm", "ci", "mid", "final"
		switch (category[0])
		{
			case 'q':
				res = 0;
				break;
			case 'c':
				res = 1;
				break;
			case 'm':
				res = 2;
				break;
			case 'f':
				res = 3;
				break;
		}
	}
	else if ( equal_static_strings(filename,"algo.txt") == 1 )
	{
		switch (category[0])
		{
			case 'q':
				res = 0;
				break;
			case 'd':
				res = 1;
				break;
			case 'm':
				res = 2;
				break;
			case 'f':
				res = 3;
				break;
		}
	}
	else if ( equal_static_strings(filename,"prog.txt") == 1 )
	{
		switch (category[0])
		{
			case 't':
				res = 0;
				break;
			case 'm':
				res = 1;
				break;
			case 'f':
				res = 2;
				break;
		}
	}
	else if ( equal_static_strings(filename,"archi.txt") == 1 
		|| equal_static_strings(filename,"phy.txt") == 1
		|| equal_static_strings(filename,"elec.txt") == 1)
	{
		switch (category[0])
		{
			case 'q':
				res = 0;
				break;
			case 'm':
				res = 1;
				break;
			case 'f':
				res = 2;
				break;
		}
	}
	else
	{
		errx(1, "Not valid subject name");
	}
	return res;
}



void add_mark(float marks[][10], size_t index, float new_mark)
{
	//adds the mark new_mark in the marks[][] matrix at 
	//the index row, in other words, in the index section
	size_t i = 0;
	while (marks[index][i] != -1)
	{
		i++;
	}
	marks[index][i] = new_mark;
}

char is_string_valid(char *filename)
{
	//returns 1 if filename is a valid subject name with ".txt"
	//at the end (this function is barely used)
	if ( equal_strings(filename,static_to_dynamic("maths.txt",9)) == 1
	  || equal_strings(filename,static_to_dynamic("algo.txt",8)) == 1
	  || equal_strings(filename,static_to_dynamic("prog.txt",8)) == 1
	  || equal_strings(filename,static_to_dynamic("archi.txt",9)) == 1
	  || equal_strings(filename,static_to_dynamic("phy.txt",7)) == 1
	  || equal_strings(filename,static_to_dynamic("elec.txt",8)) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void create_file(char *filename)
{
	//creates a file named filename, and fills it with with 
	//dashes to separate each section of marks
	if ( is_string_valid(filename) )
	{
		FILE *fle;
		fle = fopen(filename,"w");
		//"15 16 17 20 9 - 14 16 - 17 - 14"
		size_t n = 0;
		switch (*filename)
		{
			case 'm':
				n = 4;
			break;
			case 'a':
				if(*(filename+1) == 'r')
				{
					n = 3;
				}
				else
				{
					n = 4;
				}
			break;
			case 'p':
			case 'e':
				n = 3;
			break;
			default:
				n = 0;
		}
		for (size_t i = 0; i<n-1; i++)
		{
			fprintf(fle," - ");
		}
		fprintf(fle, "\n");
		fclose(fle);
	}
	else
	{
		errx(1, "Filename is not a subject name");
	}
}

void create_file_marks(char *filename, float marks[][10], size_t rows)
{
	// creates the file filename and fills it with the marks
	// in the marks[][] matrix, which has "rows" rows
	char str[6];
	FILE *fle = fopen(filename, "w");
	for(size_t f = 0; f<rows-1; f++)
	{
		if(marks[f][0] != -1)
		{
			float_to_string(str,marks[f][0]);
			fprintf(fle,str);
		}
		for(size_t c = 1; c<10; c++)
		{
			if ( marks[f][c] != -1 )
			{
				fprintf(fle," ");
				float_to_string(str,marks[f][c]);
				fprintf(fle,str);
			}
		}
		fprintf(fle," - ");
	}
	if (marks[rows-1][0] != -1)
	{
		float_to_string(str,marks[rows-1][0]);
		fprintf(fle,str);
	}
	for(size_t c = 1; c<10; c++)
	{
		if ( marks[rows-1][c] != -1 )
		{
			fprintf(fle," ");
			float_to_string(str,marks[rows-1][c]);
			fprintf(fle,str);
		}
	}
	fprintf(fle,"\n");
	fclose(fle);
}

void get_arrays(char *filename, float marks[][10], size_t rows)
{
	// this function takes the file filename, gets the marks saved in
	//it and copies them into the marks[][] matrix (with "rows" rows)
	FILE *fle = fopen(filename, "r");
	char letra = fgetc(fle);
	size_t nota = 0;
	for (size_t h = 0; h<rows-1; h++)
	{
		while (letra != '-')
		{
			char num[5];
			size_t i = 0;
			while (letra != ' ' && letra != '\n')
			{
				num[i] = letra;
				i++;
				letra = fgetc(fle);
			}
			num[i] = 0;
			marks[h][nota] = string_to_float(num);
			nota++;
			zeros_array(num,5);
			letra = fgetc(fle);
		}
		nota = 0;
		letra = fgetc(fle);
		letra = fgetc(fle);
	}
	while(letra!=EOF)
	{
		char num[5];
		size_t i = 0;
		while (letra != ' ' && letra != '\n')
		{
			num[i] = letra;
			i++;
			letra = fgetc(fle);
		}
		num[i] = 0;
		marks[rows-1][nota] = string_to_float(num);
		nota++;
		zeros_array(num,5);
		letra = fgetc(fle);
	}
}

int main(int argc, char **argv)
{
	// if there are no parameters (appart from the ./file
	// command), the program can do nothing, so an error occurs
	if (argc<2)
	{
		errx(1,"Not enough parameters, try:\n\t--create\n\t--add\n\t--moy\n");
	}
	else if (argc<3)
	{
		errx(1,"Not enough parameters, specify subject\n");
	}
	//the first parameters might not be a valid subject name,
	//but that case will be treated ahead
	char subject[12];
	static_string_copy(subject,argv[2]);
	
	if(equal_static_strings(argv[1],"--create"))
	{
		//--create command, creates a new file filled with dashes
		if (argc<3)
		{
			errx(1,"Not enough parameters, specify subject\n");
		}
		concat(subject,".txt");
		create_file(static_to_dynamic(subject,12));
	}
	else if (equal_static_strings(argv[1],"--add"))
	{
		if (argc<5)
		{
			errx(1,"Not enough parameters, specify subject, mark and section\n");
		}
		// ./file --add maths 18 qcm
		//    0     1     2    3   4
		concat(subject,".txt");
		size_t rows = -1;
		if ( equal_static_strings(subject, "maths.txt") == 1 
			|| equal_static_strings(subject, "algo.txt") == 1)
		{
			rows = 4;		
		}
		else if ( equal_static_strings(subject, "archi.txt") == 1 
			|| equal_static_strings(subject, "phy.txt") == 1
			|| equal_static_strings(subject, "elec.txt") == 1 
			|| equal_static_strings(subject, "prog.txt") == 1 )
		{
			rows = 3;
		}
		else
		{
			errx(1,"Not a valid subject name");
		}
		float marks[rows][10];
		minus_one(marks,rows);
		get_arrays(static_to_dynamic(subject,len_st(subject)),marks,rows);
		size_t index = index_matr(subject,argv[4]);
		add_mark(marks,index,string_to_float(argv[3]));
		create_file_marks(static_to_dynamic(subject,12),marks,rows);
		printf("The average mark is: %f\n",moyenne(marks,subject));
		
	}
	else if (equal_static_strings(argv[1],"--moy"))
	{
		if (argc<3)
		{
			errx(1,"Not enough parameters, specify subject\n");
		}
		concat(subject,".txt");
		size_t rows = -1;
		if ( equal_static_strings(subject, "maths.txt") == 1 
			|| equal_static_strings(subject, "algo.txt") == 1)
		{
			//MATES
			rows = 4;		
		}
		else if ( equal_static_strings(subject, "archi.txt") == 1 
			|| equal_static_strings(subject, "phy.txt") == 1
			|| equal_static_strings(subject, "elec.txt") == 1 
			|| equal_static_strings(subject, "prog.txt") == 1 )
		{
			rows = 3;
		}
		else
		{
			errx(1,"Not a valid subject name");
		}
		float marks[rows][10];
		minus_one(marks,rows);
		get_arrays(static_to_dynamic(subject,len_st(subject)),marks,rows);
		float moy = moyenne(marks,subject);
		printf("The average %s mark is %f\n",subject,moy);
		
	}
	else
	{
		errx(1,"Not a valid command");
	}
	
	return 0;
}
