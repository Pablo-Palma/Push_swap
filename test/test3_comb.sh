#!/bin/bash

combinations=("1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1")
count=1

for combo in "${combinations[@]}"; do
    echo -e "\033[31mCASO $count:\033[0m" # CASO X en rojo
    ./push_swap $combo | perl -pe 's/(Pila A antes de ordenar:.*)/\033[33m$1\033[0m/; s/(Pila A ordenada:.*)/\033[32m$1\033[0m/'
    echo # Agregar una línea vacía después de cada iteración
    ((count++))
done

