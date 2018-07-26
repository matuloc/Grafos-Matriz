#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int matriz,grafo[100][100],grafo2[100][100],cero[100][100],elevada[100][100],conexo[100][100],a,contador=0;
    cout<<"Ingrese tamaño de la matriz: "<<endl;
    cin>>matriz;
    //LLenar Matriz
    for(int i=0;i<matriz;i++)
    {
        for(int j=0;j<matriz;j++)
        {
            cout<<"Ingrese Numero ["<<i<<"]["<<j<<"] :";
            cin>>grafo[i][j];
            grafo2[i][j]=grafo[i][j];
        }
    }
    //Mostrar Matriz
    for(int i=0;i<matriz;i++)
    {
        for(int j=0;j<matriz;j++)
        {
            cout<<grafo[i][j];
        }
        cout<<endl;
    }
    //Matriz elevada a cero
    for(int i=0;i<matriz;i++)
    {
        for(int j=0;j<matriz;j++)
        {
            if(i==j)
            {
                cero[i][j]=1;
            }
            else
            {
                cero[i][j]=0;
            }
        }
    }
    //Mostrar Matriz elevada a 0
    cout<<"Matriz elevada a 0"<<endl;
    for(int i=0;i<matriz;i++)
    {
        for(int j=0;j<matriz;j++)
        {
            cout<<cero[i][j];
        }
        cout<<endl;
    }
    //Matriz elevada
    cout<<"Indique el coeficiente para elevar la matriz:";
    cin>>a;
    if(a==0)
    {
        //Mostrar Matriz elevada a 0
        cout<<"Matriz elevada a 0"<<endl;
        for(int i=0;i<matriz;i++)
        {
            for(int j=0;j<matriz;j++)
            {
                cout<<cero[i][j];
            }
            cout<<endl;
        }
    }
    if(a==1)
    {
        //mostrar matriz normal
        cout<<"Matriz formada"<<endl;
        for(int i=0;i<matriz;i++)
        {
            for(int j=0;j<matriz;j++)
            {
                cout<<grafo[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        //LLenar Matriz elevada a n
        for(int rep=0;rep<a;rep++)
        {
            for(int i=0;i<matriz;i++)
            {
                for(int j=0;j<matriz;j++)
                {
                    for(int k=0;k<matriz;k++)
                    {
                        elevada[i][j]+=grafo2[i][k]*grafo[k][j];
                    }
                }
            }
        }
        //mostrar matriz elevada a n
        cout<<"Matriz elevada"<<endl;
        for(int i=0;i<matriz;i++)
        {
            for(int j=0;j<matriz;j++)
            {
                cout<<elevada[i][j];
            }
            cout<<endl;
        }
    }
    //LLenar Matriz para saber si es conexa
    cout<<"Matriz Conexa"<<endl;
    for(int i=0;i<matriz;i++)
    {
        for(int j=0;j<matriz;j++)
        {
            conexo[i][j]=elevada[i][j]+cero[i][j]+grafo[i][j];
            if(conexo[i][j]==0)
            {
                contador++;
            }
        }
    }
    //Mostrar Matriz
    for(int i=0;i<matriz;i++)
    {
        for(int j=0;j<matriz;j++)
        {
            cout<<conexo[i][j];
        }
        cout<<endl;
    }
    if(contador==0)
    {
        cout<<"Es Conexo"<<endl;
    }
    else
    {
        cout<<"No es conexo ya que no todos sus coeficientes son distintos de 0"<<endl;
    }
}
