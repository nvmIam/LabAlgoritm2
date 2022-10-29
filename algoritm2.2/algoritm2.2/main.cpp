
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#pragma comment(linker, "/STACK:1468006400") 
void qs(int С[], int left, int right)
{
	
  int pivot; // разрешающий элемент
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pivot = С[left];

  while (left < right) // пока границы не сомкнутся
  {
    while ((С[right] >= pivot) && (left < right))
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      С[left] = С[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо
    }
    while ((С[left] <= pivot) && (left < right))
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    if (left != right) // если границы не сомкнулись
    {
      С[right] = С[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу влево
    }
  }
  С[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    qs(С, left, pivot - 1);
  if (right > pivot)
    qs(С, pivot + 1, right);
  
 
}
  
// Функция сортировки Шелла
void ShellSort(int n, int С[])
{
    int i, j, step;
    int tmp;
	
    for (step = n / 2; step > 0; step /= 2) //пока шаг больше нуля будет выполняться код ниже
        for (i = step; i < n; i++) //текущее значение шага записывается в i, пока i< значений массива будет выполняться код ниже
        {
            tmp = С[i]; //в tmp записывается первое значение массива
			//перебираем элементы, отстоящие от j
            for (j = i; j >= step; j=j-step) // текущее значение i записывается в j, пока j больше или равно step выполняется код ниже 
            {
                if (tmp < С[j - step]) //Если первый элемент массива меньше, чем отстоящий, то выполняется код ниже
                    С[j] = С[j - step];//переходим к следующему отстающему элементу
                else
                    break;
            }
            С[j] = tmp;//сюда помещаем сохраненный элемент
        }
	
}

int compare (const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int main()
{
	srand(time(NULL)); //функция для генерации рандомных чисел
	setlocale(LC_ALL, "Rus");//русская локализация 
	FILE *F = fopen ( "prikol.txt", "wt" );
	int numb, i, j, n, b, k, d, numb1, numb2;
	//ввод количества значений массива
	printf("Введите numb: ");
    scanf_s("%d", &numb);
	printf("\n");
	numb1 = numb/2;
	numb2 = numb/2;
	//создание массива
	int* A;
    A = (int *)malloc(numb1 * sizeof(int));//выделение памяти под массив
	int* B;
    B = (int *)malloc(numb2 * sizeof(int));//выделение памяти под массив
	int* C;
    C = (int *)malloc(numb * sizeof(int));//выделение памяти под массив
	int* D;
	D = (int *)malloc(numb * sizeof(int));//выделение памяти под массив
	int* G;
	G = (int *)malloc(numb * sizeof(int));//выделение памяти под массив
	int* H;
	H = (int *)malloc(numb * sizeof(int));//выделение памяти под массив
	//fprintf(F, "\n"); 
	//fprintf(F, "Первородный с возрастающими и убывающими значениями массив:\n");//запись фразы в файл
	//заполнение массива возрастающими и убывающими значениями
	for (int i = 0; i <= numb1; i++) {	
		for(i = numb1; i != 0; i--) {
			A[i] = i - 1;
			//fprintf(F, "%d\t", A[i]);
		}
		for(i = 0; i != numb2; i++) {
			B[i] = i + 1;
			//fprintf(F, "%d\t", B[i]);
		}	
	}
	k = -1; i = 0; j = 0; 
	for(int i = 0; i <= numb1; i++) {
		C[k++] = A[i];
	}
	for(int i = 0; i <= numb2 ; i++) {
		C[k++] = B[i];
		
	}
	/*for(int i = 0; i <= numb1+numb2-1; i++) {

		fprintf(F, "%d\t", C[i]);
	}*/
	
	fprintf(F, "\n\n"); 
	//fprintf(F, "Первородный с убывающими значениями массив:\n");//запись фразы в файл
	for(i = numb; i != -1; i--) {
			G[i] = i - 1;
			//fprintf(F, "%d\t", G[i]);
	
	}
	fprintf(F, "\n\n"); 
	//fprintf(F, "\n Первородный с возрастающими значениями массив:\n");//запись фразы в файл
	for(i = 0; i != numb; i++) {
			H[i] = i + 1;
			//fprintf(F, "%d\t", H[i]);
	}

	fprintf(F, "\n\n"); 
	//fprintf(F, "Первородный с рандомными значениями массив:\n");//запись фразы в файл
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		//fprintf(F, "%d\t", D[i]);
    }
	//fprintf(F, "\n\n"); 
	//fprintf(F, "\nОтсортированный массив быстрым способом с возрастающими и убывающими значениями :\n");//запись фразы в файл

	double time_potr = 0.0; // для хранения времени выполнения кода
    clock_t nach = clock();
	qs(C, 0, numb-1);
	clock_t konec = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", C[i]);
	//}
	time_potr += (double)(konec - nach) / CLOCKS_PER_SEC;
	//printf("Затраченно время в секундах на quick sort %f ", time_potr);
    printf("\n");
	//сортировка методом Шелла для возрастающего и убывающего
	//fprintf(F, "\n\n");  
	//fprintf(F, "\nОтсортированный массив способом Шелла с возрастающими и убывающими значениями :\n");//запись фразы в файл
    
	double time_p = 0.0; // для хранения времени выполнения кода
	clock_t na = clock();
	qs(D, 0, numb-1);
	clock_t ko = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", D[i]);
	//}
	time_p += (double)(ko- na) / CLOCKS_PER_SEC;
	//printf("Затраченно время в секундах на quick sort %f ", time_p);
	
	double time_pot = 0.0; // для хранения времени выполнения кода
	clock_t nac = clock();
	qs(H, 0, numb-1);
	clock_t kon = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", H[i]);
	//}
	time_pot += (double)(kon- nac) / CLOCKS_PER_SEC;
	
	double time_pota = 0.0; // для хранения времени выполнения кода
	clock_t naca = clock();
	qs(G, 0, numb-1);
	clock_t konc = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", G[i]);
	//}
	time_pota += (double)(konc- naca) / CLOCKS_PER_SEC;


		for (int i = 0; i <= numb1; i++) {	
		for(i = numb1; i != 0; i--) {
			A[i] = i - 1;
			//fprintf(F, "%d\t", A[i]);
		}
		for(i = 0; i != numb2; i++) {
			B[i] = i + 1;
			//fprintf(F, "%d\t", B[i]);
		}	
	}
	k = -1; i = 0; j = 0; 
	for(int i = 0; i <= numb1; i++) {
		C[k++] = A[i];
	}
	for(int i = 0; i <= numb2 ; i++) {
		C[k++] = B[i];
		
	}
	/*for(int i = 0; i <= numb1+numb2-1; i++) {

		fprintf(F, "%d\t", C[i]);
	}*/
	
	fprintf(F, "\n\n"); 
	//fprintf(F, "Первородный с убывающими значениями массив:\n");//запись фразы в файл
	for(i = numb; i != -1; i--) {
			G[i] = i - 1;
			//fprintf(F, "%d\t", G[i]);
	
	}
	fprintf(F, "\n\n"); 
	//fprintf(F, "\n Первородный с возрастающими значениями массив:\n");//запись фразы в файл
	for(i = 0; i != numb; i++) {
			H[i] = i + 1;
			//fprintf(F, "%d\t", H[i]);
	}

	fprintf(F, "\n\n"); 
	//fprintf(F, "Первородный с рандомными значениями массив:\n");//запись фразы в файл
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		//fprintf(F, "%d\t", D[i]);
    }

	double time_spent = 0.0; // для хранения времени выполнения кода
    clock_t begin = clock();
    ShellSort(numb-1, C);//вызов функции метода шелла
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;// рассчитать прошедшее время, найдя разницу (end - begin) и деление разницы на CLOCKS_PER_SEC для перевода в секунды
	//printf("Затраченно время в секундах на Shell's sort %f ", time_spent);
    //вывод отсортированного массива на экран
    //for (int i = 0; i < numb; i++){
    //    fprintf(F, "%d\t ", C[i]);
	//}

	double time_s = 0.0; // для хранения времени выполнения кода
    clock_t be = clock();
    ShellSort(numb-1, D);//вызов функции метода шелла
	clock_t en = clock();
	time_s += (double)(en - be) / CLOCKS_PER_SEC;// рассчитать прошедшее время, найдя разницу (end - begin) и деление разницы на CLOCKS_PER_SEC для перевода в секунды
	
	double time_st = 0.0; // для хранения времени выполнения кода
    clock_t beg = clock();
    ShellSort(numb-1, H);//вызов функции метода шелла
	clock_t eni = clock();
	time_st += (double)(eni - beg) / CLOCKS_PER_SEC;// рассчитать прошедшее время, найдя разницу (end - begin) и деление разницы на CLOCKS_PER_SEC для перевода в секунды
   // for (int i = 0; i < numb; i++){
      //  fprintf(F, "%d\t ", H[i]);
	//}
	
	double time_sta = 0.0; // для хранения времени выполнения кода
    clock_t begi = clock();
    ShellSort(numb-1, G);//вызов функции метода шелла
	clock_t enid = clock();
	time_sta += (double)(enid - begi) / CLOCKS_PER_SEC;// рассчитать прошедшее время, найдя разницу (end - begin) и деление разницы на CLOCKS_PER_SEC для перевода в секунды
	//printf("Затраченно время в секундах на Shell's sort %f ", time_s);
	//fprintf(F, "\n\n"); 
    //вывод отсортированного массива с возрастающей и убывающей последовательностями на экран
    //for (int i = 0; i < numb; i++){
    //    fprintf(F, "%d\t ", D[i]);
	//}
	//fprintf(F, "\n\n"); 
	//fprintf(F, "Отсортированный с возр значениями быстрым способом массив:\n");//запись фразы в файл
	//fprintf(F, "\n\n"); 
	//fprintf(F, "Отсортированный с рандомными значениями быстрым способом массив:\n");//запись фразы в файл
	
   
		for (int i = 0; i <= numb1; i++) {	
		for(i = numb1; i != 0; i--) {
			A[i] = i - 1;
			//fprintf(F, "%d\t", A[i]);
		}
		for(i = 0; i != numb2; i++) {
			B[i] = i + 1;
			//fprintf(F, "%d\t", B[i]);
		}	
	}
	k = -1; i = 0; j = 0; 
	for(int i = 0; i <= numb1; i++) {
		C[k++] = A[i];
	}
	for(int i = 0; i <= numb2 ; i++) {
		C[k++] = B[i];
		
	}
	/*for(int i = 0; i <= numb1+numb2-1; i++) {

		fprintf(F, "%d\t", C[i]);
	}*/
	
	fprintf(F, "\n\n"); 
	//fprintf(F, "Первородный с убывающими значениями массив:\n");//запись фразы в файл
	for(i = numb; i != -1; i--) {
			G[i] = i - 1;
			//fprintf(F, "%d\t", G[i]);
	
	}
	fprintf(F, "\n\n"); 
	//fprintf(F, "\n Первородный с возрастающими значениями массив:\n");//запись фразы в файл
	for(i = 0; i != numb; i++) {
			H[i] = i + 1;
			//fprintf(F, "%d\t", H[i]);
	}

	fprintf(F, "\n\n"); 
	//fprintf(F, "Первородный с рандомными значениями массив:\n");//запись фразы в файл
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		//fprintf(F, "%d\t", D[i]);
    }
	
	//сортировка методом Шелла для рандомного массива
	//fprintf(F, "\n\n"); 
	//fprintf(F, "Отсортированный с рандомными значениями способом Шелла массив:\n");//запись фразы в файл
	
    
	//printf("Затраченно время в секундах на quick sort %f ", time_p);
    //fprintf(F, "\n\n"); 
	//fprintf(F, "Отсортированный с возр значениями способом Шелла массив:\n");//запись фразы в файл
	

	//fprintf(F, "\n\n"); 
	//fprintf(F, "Отсортированный с убыв значениями быстрым способом массив:\n");//запись фразы в файл
   
   // fprintf(F, "\n\n"); 
	//fprintf(F, "Отсортированный с убыв значениями способом Шелла массив:\n");//запись фразы в файл
	
	
    //for (int i = 0; i < numb; i++){
    //    fprintf(F, "%d\t ", G[i]);
	
//}

	double time_potan = 0.0; // для хранения времени выполнения кода
	clock_t nacan = clock();
	qsort(C, numb, sizeof(int), compare);
	clock_t koncn = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", C[i]);
	//}
	time_potan += (double)(koncn- nacan) / CLOCKS_PER_SEC;

	double time_potani = 0.0; // для хранения времени выполнения кода
	clock_t nacani = clock();
	qsort(D, numb, sizeof(int),compare);
	clock_t koncni = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", D[i]);
	//}
	time_potani += (double)(koncni- nacani) / CLOCKS_PER_SEC;

	double time_potanic = 0.0; // для хранения времени выполнения кода
	clock_t nacanic = clock();
	qsort(G, numb, sizeof(int),compare);
	clock_t koncnic = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", H[i]);
	//}
	time_potanic += (double)(koncnic- nacanic) / CLOCKS_PER_SEC;

	double time_potanica = 0.0; // для хранения времени выполнения кода
	clock_t nacanica = clock();
	qsort(H, numb, sizeof(int),compare);
	clock_t koncnica = clock();
	//for (int i = 0; i < numb; i++){
      //  fprintf(F, "%d\t ", G[i]);
	//}
	time_potanica += (double)(koncnica- nacanica) / CLOCKS_PER_SEC;

	printf("Работу программы можно посмотреть в текстовом файле 'prikol.txt'");
	fprintf(F,"\n\n*----------------------------------------------------------*");
	fprintf(F,"\n\n");
	fprintf(F,"* Последовательность *  QuickSort  *  Shellsort  *  qsort  *");
	fprintf(F,"\n");
	fprintf(F,"* Рандом             *  %f",time_p);
	fprintf(F,"   *%f", time_s);
	fprintf(F,"     *%f", time_potani);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"* Возр и убыв        *  %f",time_potr);
	fprintf(F,"   *%f", time_spent);
	fprintf(F,"     *%f", time_potan);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"* Возр               *  %f",time_pot);
	fprintf(F,"   *%f", time_st);
	fprintf(F,"     *%f", time_potanic);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"* Убыв               *  %f",time_pota);
	fprintf(F,"   *%f", time_sta);
	fprintf(F,"     *%f", time_potanica);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"*----------------------------------------------------------*");

getchar();
getchar();
}
