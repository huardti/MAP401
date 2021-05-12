echo "lancement du shell"
echo "nombre de contour de :" > resultat.txt
f=img/Asterix3.pbm

    echo 1 | ./simplification_6 -sdp "$f" >> resultat.txt
    mv out.eps EPS_Asterix/segment_d_1.eps

    echo 2 | ./simplification_6 -sdp "$f" >> resultat.txt
    mv out.eps EPS_Asterix/segment_d_2.eps

    echo 4 | ./simplification_6 -sdp "$f" >> resultat.txt
    mv out.eps EPS_Asterix/segment_d_4.eps

    echo 8 | ./simplification_6 -sdp "$f" >> resultat.txt
    mv out.eps EPS_Asterix/segment_d_8.eps

    echo 1 | ./simplification_7-1 -b2 "$f" >> resultat.txt
    mv out.eps EPS_Asterix/bezier_2_d_1.eps

    echo 2 | ./simplification_7-1 -b2 "$f" >> resultat.txt
    mv out.eps EPS_Asterix/bezier_2_d_2.eps

    echo 4 | ./simplification_7-1 -b2 "$f" >> resultat.txt
    mv out.eps EPS_Asterix/bezier_2_d_4.eps

    echo 8 | ./simplification_7-1 -b2 "$f" >> resultat.txt
    mv out.eps EPS_Asterix/bezier_2_d_8.eps