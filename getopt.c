#include <unistd.h>

int main(int argc, char *argv[]){
    int opt;

    while ((opt = getopt(argc, argv, "af:tx")) != -1){
        switch (opt){
            case 'a':
                // for option -a
                break;
            case 'f':
                // for option -f
                break;
            case '?':
                // for invalid option
                break;
        }
    }
    // contents
}
