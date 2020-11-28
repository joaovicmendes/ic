import os
import sys
import random

if len(sys.argv) < 3:
    print("Erro nos argumentos. Execução:")
    print("> python generate_test.py <número_maquinas> <número_tarefas> <tamanho_max_tarefa> <tamanho_min_tarefa>")
    print("Os dois últimos parâmetros são opcionais.")
    exit()

# Recortando parâmetros
instance_name = "sched_" + sys.argv[1] + "_" + sys.argv[2]
number_of_machines = int(sys.argv[1])
number_of_jobs = int(sys.argv[2])
max_job_size = int(sys.argv[3]) if len(sys.argv) == 4 else 1000
min_job_size = int(sys.argv[4]) if len(sys.argv) == 5 else 1

# Criando arquivo caso de teste
file_path = "./../test/" + instance_name
file = open(file_path, "w")

content = str(number_of_machines) + "\n"
# Gerando valores aleatórios para tarefas
for _ in range(number_of_jobs):
    job = random.randint(min_job_size, max_job_size)
    content += str(job) + " "

file.write(content)
file.close()

print("Caso gerado em '%s'." % file_path)
