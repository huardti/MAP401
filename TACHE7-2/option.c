#include<stdio.h>
#include <string.h>


#include "option.h"

void usage(const char *prog_name){
     fprintf(stderr, "Usage:  %s [OPTION] <Image>\n", prog_name);
        fprintf(stderr,
                        "\n"
                        "Options:\n"
                        "\t-h\t\t--help\t\t\t\tAffiche ce message et s'arrete.\n"
                        "\t-b2\t\t--simpBezier2\t\t\tsymplification par courbe de bezier_2\n"
                        "\t-b3\t\t--simpBezier3\t\t\tsymplification par courbe de bezier_3\n"
                        "\n"
        );
}