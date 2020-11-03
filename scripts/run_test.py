import os

# Obtendo todos os casos de teste
test_cases = os.listdir("./../test/")

# Obtendo os algoritmos a serem executados
os.system('./../src/main --help > algoritmos')

file = open("algoritmos", "r")
raw_algorithms = file.read()
file.close()

algorithms = raw_algorithms.split()[4:]

for algorithm in algorithms:
    for test in test_cases:
        sol_path = "./../sols/" + algorithm + "/" + test + ".sol"
        test_path = "./../test/" + test
        # Execução de um caso de teste
        os.system("./../src/main " + algorithm + " " + test_path + " > " + sol_path)
