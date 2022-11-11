#ifndef UTILS_H
#define UTILS_H

void print_matrix(float marks[][10], size_t rows);
void static_string_copy(char dst[], char src[]);
size_t len_st(char a[]);
void zeros_array(char a[], size_t len);
float negative_power_of_ten(int expo);
unsigned long power_of_ten(int expo);
float partie_frac(float x);
int partie_ent(float x);
float string_to_float(char str[]);
void float_to_string(char str[6], float x);
void minus_one(float a[][10], size_t rows);
char *static_to_dynamic(char str[], size_t len);
void concat(char str[], char str2[]);
char equal_static_strings(char str1[], char str2[]);
char equal_strings(char *str1, char *str2);

#endif
