#include <queue>
#include "./list.h"

unsigned int List::Schedule(unsigned int no_machines, std::queue<unsigned int> job_list)
{
    unsigned int makespan;
    unsigned int *loads = new unsigned int[no_machines];

    for (unsigned int i = 0; i < no_machines; i++)
        loads[i] = 0;

    while (!job_list.empty())
    {
        // Recebendo a próxima tarefa
        unsigned int job = job_list.front();
        job_list.pop();

        // Decisão gulosa: escalonar a tarefa atual na maquina menos carregada
        loads[0] += job;
        List::sort(no_machines, loads);
    }

    // Definindo makespan (máquina mais carregada)
    makespan = loads[no_machines-1];

    delete [] loads;
    return makespan;
}

unsigned int List::min(unsigned int no_machines, const unsigned int *loads)
{
    unsigned int min_load = UINT_MAX, min_index = 0;

    for (unsigned int i = 0; i < no_machines; i++)
    {
        if (loads[i] < min_load)
        {
            min_index = i;
            min_load = loads[i];
        }
    }

    return min_index;
}

unsigned int List::max(unsigned int no_machines, const unsigned int *loads)
{
    unsigned int max_load = 0, max_index = 0;

    for (unsigned int i = 0; i < no_machines; i++)
    {
        if (loads[i] > max_load)
        {
            max_index = i;
            max_load = loads[i];
        }
    }

    return max_index;
}

void List::sort(unsigned int no_machines, unsigned int *loads, unsigned int index)
{
    bool swapped = true;

    while (swapped && index < no_machines-1)
    {
        if (loads[index] > loads[index+1])
        {
            unsigned int aux = loads[index+1];
            loads[index+1] = loads[index];
            loads[index] = aux;

            swapped = true;
            index++;
        }
        else
            swapped = false;
        
    }
}

