import os
import sys

# Obtendo todos os casos de teste
raw_tests = os.listdir("./../test/")
tests = []
for test in raw_tests:
    if not test.endswith(".metadata"):
        tests.append(test)

# Obtendo os algoritmos disponíveis
os.system('./../src/main --help > algoritmos')

file = open("algoritmos", "r")
algorithms = file.read()
file.close()

algorithms = algorithms.split()[4:]

# Selecionando apenas o algoritmo desejado
if len(sys.argv) > 1 and sys.argv[1].upper() != "ALL":
    if sys.argv[1].upper() not in algorithms:
        print("Opção '%s' não existente. Tente:" % sys.argv[1])
        for algorithm in algorithms:
            print(algorithm)
        print("ALL")
        exit()
    else:
        algorithms = [sys.argv[1].upper()]

# Execução dos testes
for algorithm in algorithms:
    for test in tests:
        sol_path = "./../sols/" + algorithm + "/" + test + ".sol"
        test_path = "./../test/" + test
        # Execução de um caso de teste
        print(f"Executando {algorithm} {test}")
        os.system("./../src/main " + algorithm + " " + test_path + " > " + sol_path)
