#!/bin/bash


# (3p.) W pliku tekstowym adresy.txt istnieje wiele adresów email firm świadczących pewne usługi (np. instalacji okien PCV). W pliku tresc.txt wpisana została treść maila zawierającego zapytanie ofertowe do takiej firmy. W plikach spec*.pdf mamy szereg dokumentów zawierających dokładną specyfikację, rysunki, itp. dotyczące zamawianej usługi. Chcemy automatycznie rozesłać kompletne zapytanie ofertowe (treść+załączniki) do wszystkich firm.
# Znajdź program klienta poczty elektronicznej pozwalającego wysyłać maile z wiersza poleceń w trybie nieinterakcyjnym (np. mail/mailx, pine/alpine, mutt, itp). Przeczytaj jego opis i opracuj wyrażenie shella pozwalającego automatycznie rozesłać zapytanie ofertowe do wszystkich adresów w pliku.

# Ważne: emaile muszą być rozesłane indywidualnie do wszystkich adresatów. Niedopuszczalne jest wysłanie jednego emaila do listy zawierającej wszystkie adresy.

# Wskazówka: istotą tego zadania nie jest wysyłanie emaili, ale czytanie w pętli kolejnych wierszy z pliku. Najprościej to wykonać ustawiając dla polecenia pętli while skierowanie wejścia stdin z pliku, dzięki czemu w kolejnych przebiegach pętli czytanie z pliku/stdin będzie kontynuowane.


localisation=$(pwd)/Zad2_pliki

for mail in $(cat $localisation/adresy.txt)
do
    cat $localisation/tresc.txt | mutt -s "Okna PCV" $mail -a $my_file_path/spec*.pdf
done
