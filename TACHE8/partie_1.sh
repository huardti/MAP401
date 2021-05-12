echo "lancement du shell"
echo "time pour segment :" > resultat.txt
for f in img/*.pbm
do
    echo "$f" >> resultat.txt
    echo 0 | (time ./simplification_6 -sdp "$f") 2>> resultat.txt
    echo "" >> resultat.txt
    echo "" >> resultat.txt
done

echo "time pour bezier2 :" >> resultat.txt
for f in *.pbm
do
    echo "$f" >> resultat.txt
    echo 0 | (time ./simplification_7-1 -b2 "$f") 2>> resultat.txt
    echo "" >> resultat.txt
    echo "" >> resultat.txt
done
