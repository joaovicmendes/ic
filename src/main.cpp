#include <iostream>
#include <cstdio>
#include <queue>
#include <ctime>
#include "./list.h"
#include "./imbal.h"

int main(int argc, char **argv)
{
    FILE *fp;
    unsigned int m, result;
    std::queue<unsigned int> jobs;

    if (argc < 2)
    {
        printf("Argumentos insuficientes. Informe o algoritmo a ser utilizado (utilize --help para listar os disponíveis). Ex:\n");
        printf("    ./main LIST <my_file>\n");
        exit(1);
    }
    else if (strcmp("--help", argv[1]) == 0)
    {
        printf("Lista de algoritmos disponíveis:\n");
        printf("    LIST\n");
        printf("    IMBAL\n");
        printf("    IMBAL1.725\n");
        printf("    IMBAL1.75\n");
        exit(0);
    }

    if (argc < 3)
    {
        printf("Argumentos insuficientes. Informe o nome do arquivo de entrada. Ex:\n");
        printf("    ./main <algorithm> <my_file>\n");
        exit(1);
    }

    fp = fopen(argv[2], "r");
    if (fp == NULL)
    {
        printf("Arquivo '%s' inválido.\n", argv[2]);
        exit(1);
    }

    // Leitura da entrada
    fscanf(fp, "%d ", &m);
    while (!feof(fp))
    {
        unsigned int job;
        fscanf(fp, "%d ", &job);

        jobs.push(job);
    }

    clock_t begin = clock();

    // Escolhendo algoritmo adequado
    if (strcmp(argv[1], "LIST") == 0)
        result = List::Schedule(m, jobs);
    if (strcmp(argv[1], "IMBAL") == 0)
        result = Imbal::Schedule(m, jobs);
    if (strcmp(argv[1], "IMBAL1.725") == 0)
        result = Imbal::Schedule(m, jobs, 1.725);
    if (strcmp(argv[1], "IMBAL1.75") == 0)
        result = Imbal::Schedule(m, jobs, 1.75);

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    printf("%d\n", result);
    printf("%lf\n", elapsed_secs);

    return 0;
}
