"""
1. (8p.) Napisz program, który:
* wykona mapowanie obszaru pamięci do pliku na dysku (funkcja mmap), w taki sposób, aby zapisy do pamięci były widoczne w pliku,
* będzie wykonywał w pętli nieskończonej następujące operacje na plikach tekstowych:
    - odpyta użytkownika o nazwę pliku,
    - obliczy długość pliku i zmieni odpowiednio wielkość obszaru pamięci wspólnej i zmapowanego pliku (funkcje stat, mmap, ftruncate),
    - wczyta podany plik do zmapowanego obszaru pamięci.
"""

import mmap as memory_senpai
import os

while True:
    file_nameu = input()
    with open(file_nameu, "r+b") as f:
        # memory-map the file, size 0 means whole file
        memory_chan = memory_senpai.mmap(f.fileno(), 0)
        print(memory_chan.read())  # prints the file
        b = input()
        memory_chan.seek(0)
        print(memory_chan.read())
        # close the map
