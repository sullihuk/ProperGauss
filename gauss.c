#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 5	 // Number of unknowns

void checkerZero (double system[N][N+1]) // Метод избавляется от нулей на осевых элементах
{

		for (size_t i=0; i<N; i++) // Цикл пробегает по всем уравнениям системы
		{
			for(size_t j=0; j<N+1; j++) // Цикл пробегает по всем коэффициентам каждого уравнения
			{
				if (i==j && system[i][j]==0 && i!=N-1) // Если номер уравнения в системе равен номеру коэффициента, а коэффициент в свою очередь равен нулю, то к каждому коэффициенту прибавляется соотоветствующий коэффициент следующего в системе уравнения, умноженный на -1 (элементарные преобразования системы линейных уравнений)
				{
					for(j=0; j<N+1; j++)
					{
						system[i][j] += (system[i+1][j])*(-1);
					}
				}
					if (i==j && system[i][j]==0 && i==N-1) // Т.к. для последнего уравнения в системе нет следующего, что очевидно, к соответствующим коэффициентам последнего прибавляются коэффициенты предыдущего, также умноженные на -1, что не противоречит правилам элементарных преобразований 
					{
						for(j=0; j<N+1; j++)
						{
							system[i][j] += (system[i-1][j])*(-1);
						}
						
					}
			}
		}
} 
void forwardElim(double mat[N][N+1]);


// function to print matrix content at any stage
void print(double mat[N][N+1])
{
	for (int i=0; i<N; i++, printf("\n"))
		for (int j=0; j<=N; j++)
			printf("%.2f ", mat[i][j]);

	printf("\n");
}

// function to reduce matrix to r.e.f.
void forwardElim(double mat[N][N+1])
{
	for (int k=0; k<N; k++)
	{

		for (int i=k+1; i<N; i++)
		{
			/* factor f to set current row kth element to 0,
			* and subsequently remaining kth column to 0 */
			double f = mat[i][k]/mat[k][k];

			/* subtract fth multiple of corresponding kth
			row element*/
			for (int j=k+1; j<=N; j++)
				mat[i][j] -= mat[k][j]*f;

			/* filling lower triangular matrix with zeros*/
			mat[i][k] = 0;
		}

		print(mat);	 //for matrix state
	}
	print(mat);		 //for matrix state
	//return -1;
}


// Driver program
int main()
{
	/* input matrix */
	double rate[N][N+1] = {
		{0, 4, 6, 0, 5, 20},
		{-2, -2, 0, 4, 4, -10}, 
		{5, -1, -1, 5, 5, 34}, 
		{-3, -1, 1, 5, 2, -2}, 
		{2, 6, 5, -2, 0, 37}
	};
	/*double rate[N][N+1] = {
			{2, 6, 6, -4, 1, 30},
			{-2, -2, 0, 4, 4, -10}, 
			{5, -1, -1, 5, 5, 34}, 
			{-3, -1, 1, 5, 2, -2}, 
			{5, 7, 4, -7, -2, 39}
	};*/
	checkerZero(rate);
	forwardElim(rate);

	//return 0;
}

