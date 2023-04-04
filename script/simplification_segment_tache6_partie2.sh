cd ../src
make
cd ../IMAGES_TEST


while read ligne
do
    nom_sortie=$(basename $ligne .pbm)
    nom_sortie1="${nom_sortie}_simplifier_segment_d1"
    nom_sortie2="${nom_sortie}_simplifier_segment_d2"
    nom_sortie_eps1="${nom_sortie1}.eps"
    nom_sortie_eps2="${nom_sortie2}.eps"
    echo - $ligne -- $nom_sortie -- $nom_sortie1 -- $nom_sortie2
    ../src/simplifier_segment $ligne 1 $nom_sortie1
    mv $nom_sortie_eps1 ../RESULTATS/
    ../src/simplifier_segment $ligne 2 $nom_sortie2
    mv $nom_sortie_eps2 ../RESULTATS/

done < "../script/a_simplifier.txt"