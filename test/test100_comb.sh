#!/bin/bash

# Programa para probar: asumiendo que es 'push_swap' en el mismo directorio
PROGRAM="./push_swap"

for i in {5..100}; do
    # Generar una combinación aleatoria de números del 1 al 100
    NUMBERS=$(seq 1 100 | sort -R | head -n $i | tr '\n' ' ')

    # Mostrar la combinación
    echo "Testing with $i numbers: $NUMBERS"

    # Ejecutar el programa con la combinación generada
    $PROGRAM $NUMBERS

    # Agregar una pausa (opcional)
	read -p "Press [Enter] to test the next combination."
done

