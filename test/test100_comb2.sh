#!/bin/bash

# Programa para probar: asumiendo que es 'push_swap' en el mismo directorio
PROGRAM="./push_swap"

for i in {5..100}; do
    # Generar una combinación aleatoria de números en el rango de int
    NUMBERS=$(for j in $(seq 1 $i); do
                echo $(( $RANDOM * ($RANDOM % 2 == 0 ? 1 : -1) ))
              done | tr '\n' ' ')

    # Mostrar la combinación
    echo "Testing with $i numbers: $NUMBERS"

    # Ejecutar el programa con la combinación generada
    $PROGRAM $NUMBERS

    # Solicitar al usuario presionar "Intro" para continuar
    read -p "Press [Enter] to test the next combination."
done

