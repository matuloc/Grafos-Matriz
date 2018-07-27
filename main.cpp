#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int matriz,grafo[100][100],grafo2[100][100],cero[100][100],grafo_conexo[100][100],conexo=0,coeficiente;
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
            grafo_conexo[i][j]=grafo[i][j];
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
    cin>>coeficiente;
    if(coeficiente==0)
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
    else
    {
        //LLenar Matriz elevada a n
        for(int contador=0;contador<coeficiente;contador++)
        {
            if(contador==0)
                {
                    for(int i=0;i<matriz;i++)
                    {
                        for(int j=0;j<matriz;j++)
                        {
                            grafo2[i][j]=grafo[i][j];
                        }
                    }
                    for(int i=0;i<matriz;i++)
                    {
                        for(int j=0;j<matriz;j++)
                        {
                            grafo_conexo[i][j]= grafo2[i][j]+cero[i][j];
                        }
                    }
                }
                else if(contador==1)
                {
                    for(int i=0;i<matriz;i++)
                    {
                        for(int j=0;j<matriz;j++)
                        {
                            for (int k=0;k<matriz;k++)
                            {
                            grafo2[i][j]+= grafo[i][k]*grafo[k][j];
                            }
                        }
                    }
                    for(int i=0;i<matriz;i++)
                    {
                        for(int j=0;j<matriz;j++)
                        {
                            grafo_conexo[i][j]= grafo2[i][j]+grafo_conexo[i][j];
                        }
                    }
                }
                else if(contador>=2)
                {
                    for(int i=0;i<matriz;i++)
                    {
                        for(int j=0;j<matriz;j++)
                        {
                            for (int k=0;k<matriz;k++)
                            {
                                grafo2[i][j]+= grafo[i][k]*grafo2[k][j];
                            }
                        }
                    }
                    for(int i=0;i<matriz;i++)
                    {
                        for(int j=0;j<matriz;j++)
                        {
                            grafo_conexo[i][j]= grafo2[i][j]+grafo_conexo[i][j];
                        }
                    }
                }
        }
        //mostrar matriz elevada a n
        cout<<"Matriz elevada a "<<coeficiente<<endl;
        for(int i=0;i<matriz;i++)
        {
            for(int j=0;j<matriz;j++)
            {
                cout<<grafo2[i][j];
            }
            cout<<endl;
        }
        //LLenar Matriz para saber si es conexa
        cout<<"Matriz Conexa"<<endl;
        //Mostrar Matriz
        for(int i=0;i<matriz;i++)
        {
            for(int j=0;j<matriz;j++)
            {
                cout<<grafo_conexo[i][j];
                if(grafo_conexo[i][j]==0)
                {
                    conexo++;
                }
            }
            cout<<endl;
        }
        if(conexo==0)
        {
            cout<<"La matriz es conexo"<<endl;
        }
        else
        {
            cout<<"La Matriz no es conexo"<<endl;
        }
    }
}
