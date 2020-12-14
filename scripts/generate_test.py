import os
import sys
import random

def write_test_to_file(path, number_of_machines, jobs):
    '''
        Escreve um número de tarefas e uma lista de jobs no arquivo especificado.
    '''
    content = str(number_of_machines) + "\n"
    for job in jobs:
        content += str(job) + " "

    file = open(path, "w")
    file.write(content)
    file.close()
    print("Caso gerado em '%s'." % path)

def write_test_metadata(path, number_of_machines, jobs):
    '''
        Escreve o tamanho mínimo, máximo e média das tarefas.
    '''
    content = "Número de máquinas: " + str(number_of_machines) + "\n"
    content += "Número de tarefas: " + str(len(jobs)) + "\n"
    content += "Menor tarefa: " + str(min(jobs)) + "\n"
    content += "Maior tarefa: " + str(max(jobs)) + "\n"
    content += "Média do tamanho das tarefas: " + str(sum(jobs)/len(jobs)) + "\n"
    content += "Carga média por máquina: " + str(sum(jobs)/number_of_machines) + "\n"

    file = open(path, "w")
    file.write(content)
    file.close()
    print("Metadados gerados em '%s'." % path)


def knuth_shuffle(jobs):
    '''
        Embaralha um vetor usando o algoritmo knuth-shuffle.
    '''
    shuffled = jobs.copy()
    
    for i in range(len(jobs)-1, -1, -1):
        j = random.randint(0, i)
        shuffled[i], shuffled[j] = shuffled[j], shuffled[i]

    return shuffled


# Verificando número de argumentos
if len(sys.argv) < 3:
    print("Erro nos argumentos. Execução:")
    print("    python generate_test.py <número_maquinas> <número_tarefas> [tamanho_max_tarefa] [tamanho_min_tarefa]")
    exit()

# Recortando parâmetros
instance_name = "sched_" + sys.argv[1] + "_" + sys.argv[2]
number_of_machines = int(sys.argv[1])
number_of_jobs = int(sys.argv[2])
max_job_size = int(sys.argv[3]) if len(sys.argv) == 4 else 1000
min_job_size = int(sys.argv[4]) if len(sys.argv) == 5 else 1

# Gerando valores aleatórios para tarefas
jobs = []
for _ in range(number_of_jobs):
    jobs.append( random.randint(min_job_size, max_job_size) )

# Criando arquivos do caso de teste
file_path = "./../test/" + instance_name

write_test_to_file(file_path+"_crescente", number_of_machines, sorted(jobs))

write_test_to_file(file_path+"_decrescente", number_of_machines, sorted(jobs, reverse=True))

write_test_to_file(file_path+"_embaralhado1", number_of_machines, knuth_shuffle(jobs))

write_test_to_file(file_path+"_embaralhado2", number_of_machines, knuth_shuffle(jobs))

write_test_to_file(file_path+"_embaralhado3", number_of_machines, knuth_shuffle(jobs))

write_test_metadata(file_path+".metadata", number_of_machines, jobs)
