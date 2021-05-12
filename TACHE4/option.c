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
                        "\t-epss\t\t--fichierEpsS\t\t\t cree un fichier eps avec comme parametre une ligne pour l'image en argument.\n"
                        " \t-epssp\t\t--fichierEpsSp\t\t\tcree un fichier eps avec comme parametre ligne + point pour l'image en argument.\n"
                        " \t-epsf\t\t--fichierEpsF\t\t\tcree un fichier eps avec comme parametre fill pour l'image en argument.\n"
                        "\n"
        );
}