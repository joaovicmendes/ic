import os
import csv

def get_metadata(test):
    suffixes = ['_crescente', '_decrescente', '_embaralhado1', '_embaralhado2', '_embaralhado3']
    for suffix in suffixes:
        if test.endswith(suffix):
            test = test.removesuffix(suffix)

    path = './../test/'+test+'.metadata'
    ret = []
    with open(path, 'r') as test_file:
        line = test_file.readline()
        while line:
            data = line.split(": ")[1]
            ret.append(float(data))
            line = test_file.readline()
    return ret

# Obtendo todos os casos de teste
raw_tests = os.listdir("./../test/")
tests = []
for test in raw_tests:
    if not test.endswith(".metadata"):
        tests.append(test)
tests = sorted(tests)

# Obtendo todos os algoritmos
algorithms = sorted(os.listdir("./../sols/"))

header = ["Teste", "Número de máquinas", "Número de tarefas", "Menor tarefa", "Maior tarefa", "Média do tamanho das tarefas", "Carga média por máquina"]
for algorithm in algorithms:
    header += [algorithm, "Tempo"]

with open('./../output.csv', 'w') as csvfile:
    writer = csv.writer(csvfile, dialect='unix')

    writer.writerow(header)
    for test in tests:
        row = [test]
        row += get_metadata(test)
        for algorithm in algorithms:
            with open('./../sols/'+algorithm+'/'+test+'.sol', 'r') as solfile:
                makespan = int(solfile.readline())
                time = float(solfile.readline())
            row += [makespan, time]
        writer.writerow(row)
