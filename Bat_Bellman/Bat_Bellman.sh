#!/bin/bash

# Binary
bellman=./bellman.bin

input_dir="instances"
results_dir="res"

echo "Testando algoritmo de Bellman-Ford"
for i in "$input_dir"/*.mtx
do
    echo -e "\e[33mInstância $i\e[0m";
    
    $bellman -f "$i" > temp;
    
    filename=$(basename "$i")
    res_file="${filename/input/res}"
    j="$results_dir/$res_file"
    
    if [ -f "$j" ]; then
        diff -w temp "$j" > /dev/null;
        if [ $? -eq 0 ]; then
            echo -e "\e[32mOK\e[0m"
        else
            echo -e "\e[31mErro\e[0m";
            echo "Resultado esperado:"
            cat "$j"
            echo ""
            echo "Recebido:"
            cat temp
        fi
    else
        echo -e "\e[33mArquivo de resultados não encontrado para $res_file\e[0m"
        echo "Output:"
        cat temp
    fi
    
    rm temp;
done