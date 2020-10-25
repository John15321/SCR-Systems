#!/bin/bash

# (3p.) Ćwiczenia z programem find: napisz skrypt znajdujący programem find wszystkie pliki o zadanym rozszerzeniu lub masce, które były modyfikowane w ciągu ostatnich N dni i tworzący z nich archiwum tar o zadanej nazwie. Mamy tu trzy parametry: maskę nazwy pliku, liczbę N i nazwę archiwum. Parametry są zadawane przez argumenty, to znaczy skrypt zawsze będzie wywołany z trzema parametrami.

mkdir "$3"
for found_file in $(find . -name "*$1" -print);
do
    # Gets the number of days since the last modification of the file
    mod=$(date -r $found_file +%s)
    now=$(date +%s)
    days=$(expr \( $now - $mod \) / 86400)
    # Check if the file modification date is in range
    [ "$days" -le "$2" ] && cp $found_file "./$3"
done
tar -czvf "$3.tar.gz" "./$3"
rm -rf "$3"
