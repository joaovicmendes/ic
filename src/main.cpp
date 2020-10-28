#include <iostream>
#include <cstdio>
#include <queue>
#include "./list.h"

int main(int argc, char **argv)
{
    FILE *fp;
    unsigned int m, result;
    std::queue<unsigned int> jobs;

    if (argc < 2)
    {
        printf("Argumentos insuficientes. Informe o nome do arquivo de entrada. Ex:\n");
        printf("    ./main <my_file>\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Arquivo '%s' inválido.\n", argv[1]);
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

    result = List::Schedule(m, jobs);
    printf("%d\n", result);

    return 0;
}
