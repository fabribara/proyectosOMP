// pruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <omp.h>

#define N 1000000
#define chunk 100000
#define mostrar 10000
void imprimeArreglo(float*);
int main()
{
     "Sumando Arreglos en Parealelo!\n";
    float *a= new float[N], *b= new float[N], *c = new float[N];
    int i=0;
    for (i = 0; i < N; i++)
    {
        a[i] = (float)i * 100.0;
        b[i] = ((float)i + 3.0) * 3.7;
    }
    int pedazos = chunk;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    #pragma omp parallel for \
    shared(a,b,c,pedazos) private(i)\
    schedule(static,pedazos)
    for (i = 0; i < N; i++)
    {
        if (i==0)
             begin = std::chrono::steady_clock::now();
        c[i] = a[i] + b[i];

    }
    std::cout << "Imprimiendo los primeros (" << mostrar << ") valores del arreglo a: \n";
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros (" << mostrar << ") valores del arreglo b: \n";
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros (" << mostrar << ") valores del arreglo c: \n";
    imprimeArreglo(c);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << " Utilizando N =(" << N << ") con Chunk =(" << chunk << ")\n el tiempo de ejecución fue de :" <<
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " millisegundos ...";
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " - ";

    }
    std::cout << std::endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
