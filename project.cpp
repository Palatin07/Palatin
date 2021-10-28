#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
long int a; // Количество элементов в массиве
long int max, min; // Максимальные и максимальные числа диапазона
int result; // Результат работы программы
double sum = 0;
double* mas;
int* fraction;
srand(time(NULL));
setlocale(0, "rus");

printf("Укажите, сколько чисел должно быть в сгенерированном списке:\n");
scanf("%ld", &a);

printf("Задайте минимальное число диапазона:\n");
scanf("%ld", &min);

printf("Задайте максимальное число диапазона:\n");
scanf("%ld", &max);

mas = malloc(a * sizeof(double));
fraction = malloc(a * sizeof(int));
for (int i = 0; i < a; i++)
{
	float f = (min + (max - min) * (float)rand() / RAND_MAX);
	mas[i] = f;
	fraction[i] = ((mas[i] - (int)mas[i]) * 10000);
}

printf("Результат работы алгоритма:\n");
for (int i = 0; i < a; i++)

{
	for (int k = 0; k < a; k++)
	{
		if (i == fraction[k])
		{
			sum = sum - mas[i];
			fraction[k] = 0.0;
		}
	}
}

for (int i = 0; i < a; i++)
{
	sum += mas[i];
}

printf("%f", sum);
free(mas);
free(fraction);
return 0;
}
