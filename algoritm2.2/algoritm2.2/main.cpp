
#define _CRT_SECURE_NO_WARNINGS // ��� ���������� ������ scanf()
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#pragma comment(linker, "/STACK:1468006400") 
void qs(int �[], int left, int right)
{
	
  int pivot; // ����������� �������
  int l_hold = left; //����� �������
  int r_hold = right; // ������ �������
  pivot = �[left];

  while (left < right) // ���� ������� �� ���������
  {
    while ((�[right] >= pivot) && (left < right))
      right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
    if (left != right) // ���� ������� �� ����������
    {
      �[left] = �[right]; // ���������� ������� [right] �� ����� ������������
      left++; // �������� ����� ������� ������
    }
    while ((�[left] <= pivot) && (left < right))
      left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
    if (left != right) // ���� ������� �� ����������
    {
      �[right] = �[left]; // ���������� ������� [left] �� ����� [right]
      right--; // �������� ������ ������� �����
    }
  }
  �[left] = pivot; // ������ ����������� ������� �� �����
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
    qs(�, left, pivot - 1);
  if (right > pivot)
    qs(�, pivot + 1, right);
  
 
}
  
// ������� ���������� �����
void ShellSort(int n, int �[])
{
    int i, j, step;
    int tmp;
	
    for (step = n / 2; step > 0; step /= 2) //���� ��� ������ ���� ����� ����������� ��� ����
        for (i = step; i < n; i++) //������� �������� ���� ������������ � i, ���� i< �������� ������� ����� ����������� ��� ����
        {
            tmp = �[i]; //� tmp ������������ ������ �������� �������
			//���������� ��������, ��������� �� j
            for (j = i; j >= step; j=j-step) // ������� �������� i ������������ � j, ���� j ������ ��� ����� step ����������� ��� ���� 
            {
                if (tmp < �[j - step]) //���� ������ ������� ������� ������, ��� ���������, �� ����������� ��� ����
                    �[j] = �[j - step];//��������� � ���������� ���������� ��������
                else
                    break;
            }
            �[j] = tmp;//���� �������� ����������� �������
        }
	
}

int compare (const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int main()
{
	srand(time(NULL)); //������� ��� ��������� ��������� �����
	setlocale(LC_ALL, "Rus");//������� ����������� 
	FILE *F = fopen ( "prikol.txt", "wt" );
	int numb, i, j, n, b, k, d, numb1, numb2;
	//���� ���������� �������� �������
	printf("������� numb: ");
    scanf_s("%d", &numb);
	printf("\n");
	numb1 = numb/2;
	numb2 = numb/2;
	//�������� �������
	int* A;
    A = (int *)malloc(numb1 * sizeof(int));//��������� ������ ��� ������
	int* B;
    B = (int *)malloc(numb2 * sizeof(int));//��������� ������ ��� ������
	int* C;
    C = (int *)malloc(numb * sizeof(int));//��������� ������ ��� ������
	int* D;
	D = (int *)malloc(numb * sizeof(int));//��������� ������ ��� ������
	int* G;
	G = (int *)malloc(numb * sizeof(int));//��������� ������ ��� ������
	int* H;
	H = (int *)malloc(numb * sizeof(int));//��������� ������ ��� ������
	//fprintf(F, "\n"); 
	//fprintf(F, "����������� � ������������� � ���������� ���������� ������:\n");//������ ����� � ����
	//���������� ������� ������������� � ���������� ����������
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
	//fprintf(F, "����������� � ���������� ���������� ������:\n");//������ ����� � ����
	for(i = numb; i != -1; i--) {
			G[i] = i - 1;
			//fprintf(F, "%d\t", G[i]);
	
	}
	fprintf(F, "\n\n"); 
	//fprintf(F, "\n ����������� � ������������� ���������� ������:\n");//������ ����� � ����
	for(i = 0; i != numb; i++) {
			H[i] = i + 1;
			//fprintf(F, "%d\t", H[i]);
	}

	fprintf(F, "\n\n"); 
	//fprintf(F, "����������� � ���������� ���������� ������:\n");//������ ����� � ����
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		//fprintf(F, "%d\t", D[i]);
    }
	//fprintf(F, "\n\n"); 
	//fprintf(F, "\n��������������� ������ ������� �������� � ������������� � ���������� ���������� :\n");//������ ����� � ����

	double time_potr = 0.0; // ��� �������� ������� ���������� ����
    clock_t nach = clock();
	qs(C, 0, numb-1);
	clock_t konec = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", C[i]);
	//}
	time_potr += (double)(konec - nach) / CLOCKS_PER_SEC;
	//printf("���������� ����� � �������� �� quick sort %f ", time_potr);
    printf("\n");
	//���������� ������� ����� ��� ������������� � ����������
	//fprintf(F, "\n\n");  
	//fprintf(F, "\n��������������� ������ �������� ����� � ������������� � ���������� ���������� :\n");//������ ����� � ����
    
	double time_p = 0.0; // ��� �������� ������� ���������� ����
	clock_t na = clock();
	qs(D, 0, numb-1);
	clock_t ko = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", D[i]);
	//}
	time_p += (double)(ko- na) / CLOCKS_PER_SEC;
	//printf("���������� ����� � �������� �� quick sort %f ", time_p);
	
	double time_pot = 0.0; // ��� �������� ������� ���������� ����
	clock_t nac = clock();
	qs(H, 0, numb-1);
	clock_t kon = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", H[i]);
	//}
	time_pot += (double)(kon- nac) / CLOCKS_PER_SEC;
	
	double time_pota = 0.0; // ��� �������� ������� ���������� ����
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
	//fprintf(F, "����������� � ���������� ���������� ������:\n");//������ ����� � ����
	for(i = numb; i != -1; i--) {
			G[i] = i - 1;
			//fprintf(F, "%d\t", G[i]);
	
	}
	fprintf(F, "\n\n"); 
	//fprintf(F, "\n ����������� � ������������� ���������� ������:\n");//������ ����� � ����
	for(i = 0; i != numb; i++) {
			H[i] = i + 1;
			//fprintf(F, "%d\t", H[i]);
	}

	fprintf(F, "\n\n"); 
	//fprintf(F, "����������� � ���������� ���������� ������:\n");//������ ����� � ����
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		//fprintf(F, "%d\t", D[i]);
    }

	double time_spent = 0.0; // ��� �������� ������� ���������� ����
    clock_t begin = clock();
    ShellSort(numb-1, C);//����� ������� ������ �����
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;// ���������� ��������� �����, ����� ������� (end - begin) � ������� ������� �� CLOCKS_PER_SEC ��� �������� � �������
	//printf("���������� ����� � �������� �� Shell's sort %f ", time_spent);
    //����� ���������������� ������� �� �����
    //for (int i = 0; i < numb; i++){
    //    fprintf(F, "%d\t ", C[i]);
	//}

	double time_s = 0.0; // ��� �������� ������� ���������� ����
    clock_t be = clock();
    ShellSort(numb-1, D);//����� ������� ������ �����
	clock_t en = clock();
	time_s += (double)(en - be) / CLOCKS_PER_SEC;// ���������� ��������� �����, ����� ������� (end - begin) � ������� ������� �� CLOCKS_PER_SEC ��� �������� � �������
	
	double time_st = 0.0; // ��� �������� ������� ���������� ����
    clock_t beg = clock();
    ShellSort(numb-1, H);//����� ������� ������ �����
	clock_t eni = clock();
	time_st += (double)(eni - beg) / CLOCKS_PER_SEC;// ���������� ��������� �����, ����� ������� (end - begin) � ������� ������� �� CLOCKS_PER_SEC ��� �������� � �������
   // for (int i = 0; i < numb; i++){
      //  fprintf(F, "%d\t ", H[i]);
	//}
	
	double time_sta = 0.0; // ��� �������� ������� ���������� ����
    clock_t begi = clock();
    ShellSort(numb-1, G);//����� ������� ������ �����
	clock_t enid = clock();
	time_sta += (double)(enid - begi) / CLOCKS_PER_SEC;// ���������� ��������� �����, ����� ������� (end - begin) � ������� ������� �� CLOCKS_PER_SEC ��� �������� � �������
	//printf("���������� ����� � �������� �� Shell's sort %f ", time_s);
	//fprintf(F, "\n\n"); 
    //����� ���������������� ������� � ������������ � ��������� �������������������� �� �����
    //for (int i = 0; i < numb; i++){
    //    fprintf(F, "%d\t ", D[i]);
	//}
	//fprintf(F, "\n\n"); 
	//fprintf(F, "��������������� � ���� ���������� ������� �������� ������:\n");//������ ����� � ����
	//fprintf(F, "\n\n"); 
	//fprintf(F, "��������������� � ���������� ���������� ������� �������� ������:\n");//������ ����� � ����
	
   
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
	//fprintf(F, "����������� � ���������� ���������� ������:\n");//������ ����� � ����
	for(i = numb; i != -1; i--) {
			G[i] = i - 1;
			//fprintf(F, "%d\t", G[i]);
	
	}
	fprintf(F, "\n\n"); 
	//fprintf(F, "\n ����������� � ������������� ���������� ������:\n");//������ ����� � ����
	for(i = 0; i != numb; i++) {
			H[i] = i + 1;
			//fprintf(F, "%d\t", H[i]);
	}

	fprintf(F, "\n\n"); 
	//fprintf(F, "����������� � ���������� ���������� ������:\n");//������ ����� � ����
	srand(time(NULL));
    for (i = 0; i < numb; i++){
        D[i] = rand() % 100;
		//fprintf(F, "%d\t", D[i]);
    }
	
	//���������� ������� ����� ��� ���������� �������
	//fprintf(F, "\n\n"); 
	//fprintf(F, "��������������� � ���������� ���������� �������� ����� ������:\n");//������ ����� � ����
	
    
	//printf("���������� ����� � �������� �� quick sort %f ", time_p);
    //fprintf(F, "\n\n"); 
	//fprintf(F, "��������������� � ���� ���������� �������� ����� ������:\n");//������ ����� � ����
	

	//fprintf(F, "\n\n"); 
	//fprintf(F, "��������������� � ���� ���������� ������� �������� ������:\n");//������ ����� � ����
   
   // fprintf(F, "\n\n"); 
	//fprintf(F, "��������������� � ���� ���������� �������� ����� ������:\n");//������ ����� � ����
	
	
    //for (int i = 0; i < numb; i++){
    //    fprintf(F, "%d\t ", G[i]);
	
//}

	double time_potan = 0.0; // ��� �������� ������� ���������� ����
	clock_t nacan = clock();
	qsort(C, numb, sizeof(int), compare);
	clock_t koncn = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", C[i]);
	//}
	time_potan += (double)(koncn- nacan) / CLOCKS_PER_SEC;

	double time_potani = 0.0; // ��� �������� ������� ���������� ����
	clock_t nacani = clock();
	qsort(D, numb, sizeof(int),compare);
	clock_t koncni = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", D[i]);
	//}
	time_potani += (double)(koncni- nacani) / CLOCKS_PER_SEC;

	double time_potanic = 0.0; // ��� �������� ������� ���������� ����
	clock_t nacanic = clock();
	qsort(G, numb, sizeof(int),compare);
	clock_t koncnic = clock();
	//for (int i = 0; i < numb; i++){
     //   fprintf(F, "%d\t ", H[i]);
	//}
	time_potanic += (double)(koncnic- nacanic) / CLOCKS_PER_SEC;

	double time_potanica = 0.0; // ��� �������� ������� ���������� ����
	clock_t nacanica = clock();
	qsort(H, numb, sizeof(int),compare);
	clock_t koncnica = clock();
	//for (int i = 0; i < numb; i++){
      //  fprintf(F, "%d\t ", G[i]);
	//}
	time_potanica += (double)(koncnica- nacanica) / CLOCKS_PER_SEC;

	printf("������ ��������� ����� ���������� � ��������� ����� 'prikol.txt'");
	fprintf(F,"\n\n*----------------------------------------------------------*");
	fprintf(F,"\n\n");
	fprintf(F,"* ������������������ *  QuickSort  *  Shellsort  *  qsort  *");
	fprintf(F,"\n");
	fprintf(F,"* ������             *  %f",time_p);
	fprintf(F,"   *%f", time_s);
	fprintf(F,"     *%f", time_potani);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"* ���� � ����        *  %f",time_potr);
	fprintf(F,"   *%f", time_spent);
	fprintf(F,"     *%f", time_potan);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"* ����               *  %f",time_pot);
	fprintf(F,"   *%f", time_st);
	fprintf(F,"     *%f", time_potanic);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"* ����               *  %f",time_pota);
	fprintf(F,"   *%f", time_sta);
	fprintf(F,"     *%f", time_potanica);
	fprintf(F," *");

	fprintf(F,"\n");
	fprintf(F,"*----------------------------------------------------------*");

getchar();
getchar();
}
