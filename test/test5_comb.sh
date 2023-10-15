#!/bin/bash

combinations=(
    "1 2 3 4 5" "1 2 3 5 4" "1 2 4 3 5" "1 2 4 5 3" "1 2 5 3 4" "1 2 5 4 3"
    "1 3 2 4 5" "1 3 2 5 4" "1 3 4 2 5" "1 3 4 5 2" "1 3 5 2 4" "1 3 5 4 2"
    "1 4 2 3 5" "1 4 2 5 3" "1 4 3 2 5" "1 4 3 5 2" "1 4 5 2 3" "1 4 5 3 2"
    "1 5 2 3 4" "1 5 2 4 3" "1 5 3 2 4" "1 5 3 4 2" "1 5 4 2 3" "1 5 4 3 2"
    #... y así sucesivamente para los números 2, 3, 4 y 5 como primer número.
)
count=1

for combo in "${combinations[@]}"; do
    echo -e "\033[31mCASO $count:\033[0m" # CASO X en rojo
    ./push_swap $combo | awk '/El stack inicializa en:/ { for(i=1; i<=NF; i++) if($i ~ /^[0-9]+$/) $i="\033[33m"$i"\033[0m" }1' | awk '/El stack ordenado:/ { for(i=1; i<=NF; i++) if($i ~ /^[0-9]+$/) $i="\033[32m"$i"\033[0m" }1'
    echo # Agregar una línea vacía después de cada iteración
    ((count++))
done

