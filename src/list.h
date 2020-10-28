#ifndef LIST_H
#define LIST_H

class List
{
    public:
    /*
        Escalonamento de tarefas utilizando o algoritmo List Scheduling online. Não se altera a ordem das tarefas, é o equivalente a processa-las na ordem de chegada.
        Entrada:
            - (unsigned int) número de máquinas à serem distribuídas
            - (std::queue<unsigned int>) lista de tarefas
        Saída:
            - (unsigned int) o makespan do escalonamento encontrado
    */
    static unsigned int Schedule(unsigned int no_machines, std::queue<unsigned int> job_list);

    private:
    /* Função interna que retorna índice da máquina com menor makespan */
    static unsigned int min(unsigned int no_machines, const unsigned int *loads);

    /* Função interna que retorna índice da máquina com maior makespan */
    static unsigned int max(unsigned int no_machines, const unsigned int *loads);

    /* Função interna que reordena máquinas quando uma é alterada */
    static void sort(unsigned int no_machines, unsigned int *loads, unsigned int index = 0);
};

#endif
