cd ../src
make


echo "######### segment #########"
while read ligne
do
    nom=$(basename $ligne .pbm)
    echo -------- $nom --------
    ../src/test_performance $nom 0 s
    ../src/test_performance $nom 0.5 s
    ../src/test_performance $nom 1 s
    ../src/test_performance $nom 2 s
    ../src/test_performance $nom 4 s
    ../src/test_performance $nom 8 s
    ../src/test_performance $nom 16 s

done < "../script/fichiers_performance.txt"



echo "######### bezier2 #########"
while read ligne
do
    nom=$(basename $ligne .pbm)
    echo -------- $nom --------
    ../src/test_performance $nom 0 b
    ../src/test_performance $nom 0.5 b
    ../src/test_performance $nom 1 b
    ../src/test_performance $nom 2 b
    ../src/test_performance $nom 4 b
    ../src/test_performance $nom 8 b
    ../src/test_performance $nom 16 b

done < "../script/fichiers_performance.txt"