#include <cmath>
#include <queue>
#include "./imbal.h"

unsigned int Imbal::Schedule(unsigned int no_machines, std::queue<unsigned int> job_list, double c)
{
    unsigned int k, i, makespan;
    double alpha, total_avg = 0, smaller_avg = 0;
    unsigned int *loads = new unsigned int[no_machines];

    for (unsigned int i = 0; i < no_machines; i++)
        loads[i] = 0;

    // Por padrão, c = 1 + sqrt((1 + log(2))/2) ~= 1.92009433771 
    i = ceil((5*c - 2*pow(c, 2) - 1)*no_machines/c) - 1;
    k = 2*i - no_machines;
    alpha = (2*c-2)/(2*c-3);

    while (!job_list.empty())
    {
        // Recebendo a próxima tarefa
        unsigned int job = job_list.front();
        job_list.pop();

        // Atualiza média total e média das menos carregadas
        total_avg += (double)job/no_machines;

        // Decisão gulosa: se o escalonamento for plano E a carga i não passar em c vezes a média total, escalona
        // em i, caso contrário, escalona na última máquina (no_machines-1)
        if (loads[k] < alpha*smaller_avg && loads[i]+job <= c*total_avg)
        {
            loads[i] += job;
            Imbal::update(no_machines, loads, i, i, job, &smaller_avg);
        }
        else
        {
            loads[no_machines-1] += job;
            Imbal::update(no_machines, loads, no_machines-1, i, job, &smaller_avg);

        }
    }

    makespan = loads[0];
    delete [] loads;

    return makespan;
}

void Imbal::update(unsigned int no_machines, unsigned int *loads, unsigned int index, unsigned int avg_delim, unsigned int job, double *avg)
{
    unsigned int aux;
    unsigned int load_wout_job = loads[index]-job;

    aux = loads[index];
    while (index > 0 && aux > loads[index-1])
    {
        // Otimização no cáculo da média da máquina menos carregada
        if (index-1 == avg_delim)
        {
            *avg -= (double)load_wout_job/(no_machines-avg_delim-1);
            *avg += (double)loads[index-1]/(no_machines-avg_delim-1);
        }

        loads[index] = loads[index-1];
        index--;
    }
    loads[index] = aux;

    if (index > avg_delim)
        *avg += (double)job/(no_machines-avg_delim-1);
}

void Imbal::sort(unsigned int no_machines, unsigned int *loads, unsigned int index)
{
    bool swapped = true;

    while (swapped && index > 0)
    {
        if (loads[index] > loads[index-1])
        {
            unsigned int aux = loads[index-1];
            loads[index-1] = loads[index];
            loads[index] = aux;

            swapped = true;
            index--;
        }
        else
            swapped = false;
    }
}

double Imbal::get_average_load(unsigned int no_machines, unsigned int *loads, unsigned int lower, unsigned int upper)
{
    double avg = 0;

    for (unsigned int i = lower; i < upper; i++)
        avg += loads[i];

    return (double)avg/(upper-lower);
}
