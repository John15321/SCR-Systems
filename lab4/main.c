#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER 64

// 1. (8p.) Napisz program, który:
// utworzy potok (funkcją pipe),
// uruchomi podproces, z którym proces nadrzędny będzie komunikował się przez ten potok (funkcja fork),
// proces nadrzędny otworzy plik tekstowy podany w argumencie wywołania programu, a następnie wyśle procesowi potomnemu zawartość tego pliku przez potok,
// proces potomny odczyta dane z potoku, a następnie wyświetli je na standardowym wyjściu dodając znak '#' na początku i końcu każdej odebranej paczki danych. Wielkość paczek jest dowolna.



int main(int argc, char *argv[])

{
    int pid_num;
    int file_descriptor_num[2];

    pipe(file_descriptor_num);

    if (pid_num = fork())
    {
        char buf[MAX_BUFFER];
        while (read(file_descriptor_num[0], buf, MAX_BUFFER))
        {
            if (buf[MAX_BUFFER - 1] == 0)
            {
                break;
            }
            buf[MAX_BUFFER - 1] = '\0';
            printf("#%s#\n", buf);
        }
    }
    else
    {
        FILE *f = fopen(argv[1], "r");

        char buf[MAX_BUFFER];

        while (fgets(buf, MAX_BUFFER - 1, f))
        {
            buf[MAX_BUFFER - 1] = 1;
            write(file_descriptor_num[1], buf, MAX_BUFFER);
        }

        buf[MAX_BUFFER - 1] = 0;
        write(file_descriptor_num[1], buf, MAX_BUFFER);

        fclose(f);
    };



}



/*
Przykladowy output dla "./a.out text_file.txt":

john@DESKTOP-TPH31OD:/mnt/e/Uczelnia/Semestr5/SCR-Systems/lab4$ gcc main.c 
john@DESKTOP-TPH31OD:/mnt/e/Uczelnia/Semestr5/SCR-Systems/lab4$ ./a.out text_file.txt
#Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut la#
#cinia interdum vestibulum. Proin id lorem ultricies magna grav#
#ida pharetra eget at neque. Nunc fringilla sem dapibus,
#
# rhoncus tellus non, varius ipsum. Curabitur vulputate, ipsum #
#vel varius ultrices, arcu ligula bibendum orci, tincidunt accu#
#msan enim nibh id felis. Pellentesque pellentesque 
#
#accumsan eleifend. Donec sit amet sollicitudin neque, imperdie#
#t dapibus ipsum. Maecenas fermentum, justo sit amet lacinia pl#
#acerat, purus turpis ullamcorper ipsum, quis cursus 
#
#metus tellus non lectus. Pellentesque habitant morbi tristique#
# senectus et netus et malesuada fames ac turpis egestas. Donec#
# ut lectus at ipsum lobortis vehicula in eget enim.
#
#
#
#Sed posuere eros id venenatis tempus. Curabitur vehicula turpi#
#s orci, ut placerat enim elementum et. Proin vel faucibus sem,#
# id elementum erat. Nam tincidunt quis justo nec 
#
#lobortis. Cras ex velit, dapibus in nunc finibus, sodales inte#
#rdum augue. Mauris placerat ut mi nec rutrum. Quisque bibendum#
# nisi quam, ut porta elit ultrices eget. Nam laoreet
#
# feugiat mauris, vitae pharetra est pharetra non. Class aptent#
# taciti sociosqu ad litora torquent per conubia nostra, per in#
#ceptos himenaeos.
#
#
#
#Sed volutpat eget velit id eleifend. Pellentesque eu dignissim#
# lectus, id suscipit urna. Sed velit lacus, fermentum sed ligu#
#la sit amet, laoreet luctus erat. Aenean vestibulum 
#
#molestie molestie. Maecenas sit amet lorem scelerisque, condim#
#entum mauris non, mollis magna. In hac habitasse platea dictum#
#st. Donec cursus neque vel arcu ultrices vestibulum.
#
#
#
#Proin ex enim, porttitor eu leo non, vestibulum sollicitudin d#
#ui. Aenean at mauris porta, rhoncus justo at, venenatis urna. #
#Quisque vitae nunc cursus, tincidunt arcu at, varius 
#
#purus. Vivamus hendrerit malesuada felis eu pretium. Sed sempe#
#r ligula et nunc pulvinar feugiat tristique eget felis. Proin #
#consectetur dolor nec lorem gravida dictum. Duis vitae 
#
#quam lacus. Proin eu aliquam libero. Nullam sagittis in turpis#
# in interdum. Quisque ac euismod ligula, in euismod sem. Nunc #
#a facilisis nulla.
#
#
#
#Nunc dictum, nisi a porta facilisis, lorem risus cursus ex, a #
#iaculis diam nibh at justo. Phasellus ullamcorper volutpat pur#
#us. Sed tellus nisl, interdum vitae leo quis, 
#
#consectetur commodo odio. Sed non sapien a leo consequat luctu#
#s. Cras urna augue, imperdiet nec lectus sit amet, volutpat fe#
#rmentum ligula. Donec in sem maximus, consectetur enim 
#
#ut, sagittis mauris. Phasellus nec risus at lorem mattis eleme#
#ntum hendrerit nec nibh. Duis dictum est et lectus suscipit, a#
# aliquam sapien porttitor. Donec ornare euismod 
#
#ultricies.#
*/
// Przeklejenie z terminala troche zniszczylo miejscami szyk nie wiem czemu
