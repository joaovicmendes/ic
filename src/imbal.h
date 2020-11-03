#ifndef IMBAL_H
#define IMBAL_H

class Imbal
{
    public:
    /*
        Escalonamento de tarefas utilizando o algoritmo online Imbal/MR. Não se altera a ordem das tarefas, é o equivalente a processa-las na ordem de chegada.
        Entrada:
            - (unsigned int) número de máquinas à serem distribuídas
            - (std::queue<unsigned int>) lista de tarefas
        Saída:
            - (unsigned int) o makespan do escalonamento encontrado
    */
    static unsigned int Schedule(unsigned int no_machines, std::queue<unsigned int> job_list, double c=1.92009433771);

    private:

    /* Função interna que reordena máquinas quando uma é alterada */
    static void sort(unsigned int no_machines, unsigned int *loads, unsigned int index = 0);
    
    /* Função interna que calcula a média das máquinas no intervalo i..j */
    static double get_average_load(unsigned int no_machines, unsigned int *loads, unsigned int i, unsigned int j);
};

#endif
