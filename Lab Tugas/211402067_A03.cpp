/*
        Nama File       : 211402067_A03.cpp
        Nama            : Ivandohan Samuel Siregar
        NIM             : 211402067

        === Operasi Perkalian dan Penjumlahan Matriks dengan Konsep Overloading ===
*/

#include <iostream>
#include <iomanip>
using namespace std;
class Matrix
{
	public:
        int a[10][10], m, n;
        bool res;
        Matrix(){
            res = true;
        }
		void inputmatrices();
		void outputmatrices();
		Matrix operator*(Matrix x);
		Matrix operator+(Matrix x);

};


void Matrix::inputmatrices()
{
	int i,j;
	cout<<"Ukuran Matriks   : ";
	cin>>m>>n;
	cout<<"Elemen Matriks   : ";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
}
void Matrix::outputmatrices()
{ 
	int i,j;
    if(res == false){
        cout << "Operasi matriks tidak dapat dilakukan\n";
    } else {
        for(i=0;i<m;i++)
        { 
            for(j=0;j<n;j++)
            {
                cout << setw(5) << a[i][j];
                if(j == n-1)
                    cout << "\n";
            }
        }
    }
}

Matrix Matrix::operator*(Matrix x)
{ 
	Matrix c;
	int i,j,k;
	if(n==x.m)
	{ 
		c.m=m;
		c.n=x.n;
		for(i=0;i<m;i++)
		{
			for(j=0;j<x.n;j++)
			{ 
				c.a[i][j]=0;

                for(k=0; k<n;k++)
                {
                    c.a[i][j] += a[i][k]*x.a[k][j];
                }
			}
		}
		return c; 
	}
	else
        c.res = false;
        return c;
}

Matrix Matrix::operator+(Matrix x)
{ 
	Matrix c;
	int i,j,k;
	if( n == x.n && m == x.m)
	{ 
		c.m=m;
		c.n=x.n;
		for(i=0;i<m;i++)
		{
			for(j=0;j<x.n;j++)
			{
                c.a[i][j] = a[i][j] + x.a[i][j];
			}
		}
		return c;
	}
	else
        c.res = false;
        return c;
}   

int main()
{ 
    Matrix A,B,C;
    cout<<"Matriks A : "<< endl;
    A.inputmatrices();
    cout<<"Matriks B : "<< endl;
    B.inputmatrices();

    C=A*B;
    cout<<"{A x B} = "<< endl;
    C.outputmatrices();

    C=A+B;
    cout<<"{A + B} = "<< endl;
    C.outputmatrices();

    return 0;
}