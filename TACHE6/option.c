#include<stdio.h>
#include <string.h>


#include "option.h"

void usage(const char *prog_name){
     fprintf(stderr, "Usage:  %s [OPTION] <Image>\n", prog_name);
        fprintf(stderr,
                        "\n"
                        "Options:\n"
                        "\t-h\t\t--help\t\t\t\tAffiche ce message et s'arrete.\n"
                        "\t-ct\t\t--contourT\t\t\tstock le contour dans un tableau a taille variable et l'affiche.\n"
                        "\t-eps\t\t--fichierEps\t\t\tcree un fichier eps avec comme parametre une ligne pour l'image en argument.\n"
                        "\t-s\t\t--save\t\t\t\tsauvegarde le contour au format \".contour.txt\"\n"
                        "\t-sdp\t\t--simpDouglas \t\t\tcree un ficher eps contenant le contour de l'image en argument simplifier avec douglas\n"
                        "\n"
        );
}