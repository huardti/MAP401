#include<stdio.h>
#include <string.h>


#include "option.h"

void usage(const char *prog_name){
     fprintf(stderr, "Usage:  %s [OPTION] <Image>\n", prog_name);
        fprintf(stderr,
                        "\n"
                        "Options:\n"
                        "\t-h, --help\t\t\tAffiche ce message et s'arrete.\n"
                        "\t-c, --contour\t\t\tAffiche sur la sortie standard la liste des points qui compose le contour de l'image.\n"
                        "\t-p, --printImg\t\t\tAffiche l'image <Image> avec des 0 pour representer le blanc et 1 pour le noir.\n"
                        "\n"
        );
}