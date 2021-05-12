echo "lancement du shell"
echo "nombre de contour de :" > resultat.txt
for f in img/Asterix3.pbm img/lettre-L-cursive.pbm img/Picasso-ColombesDeLaPaix.pbm
do
    echo 0 | ./simplification_7-2 -b2 "$f" >> resultat.txt
    echo "d = 0" >> resultat.txt
    echo "" >> resultat.txt

    echo 0.5 | ./simplification_7-2 -b2 "$f" >> resultat.txt
    echo "d = 0.5" >> resultat.txt
    echo "" >> resultat.txt

    echo 1 | ./simplification_7-2 -b2 "$f" >> resultat.txt
    echo "d = 1" >> resultat.txt
    echo "" >> resultat.txt

    echo 2 | ./simplification_7-2 -b2 "$f" >> resultat.txt
    echo " d = 2" >> resultat.txt
    echo "" >> resultat.txt

    echo 4 | ./simplification_7-2 -b2 "$f" >> resultat.txt
    echo "d = 4" >> resultat.txt
    echo "" >> resultat.txt

    echo 8 | ./simplification_7-2 -b2 "$f" >> resultat.txt
    echo "d = 8" >> resultat.txt
    echo "" >> resultat.txt

    echo 16 | ./simplification_7-2 -b2 "$f" >> resultat.txt
    echo "d = 16" >> resultat.txt
    echo "" >> resultat.txt
done