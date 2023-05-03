cd ../src
make


echo "######### segment #########"
while read ligne
do
    echo -------- $ligne --------
    ../src/test_performance $ligne 0 s
    ../src/test_performance $ligne 0.5 s
    ../src/test_performance $ligne 1 s
    ../src/test_performance $ligne 2 s
    ../src/test_performance $ligne 4 s
    ../src/test_performance $ligne 8 s
    ../src/test_performance $ligne 16 s

done < "../script/fichiers_performance.txt"



echo "######### bezier2 #########"
while read ligne
do
    echo -------- $ligne --------
    ../src/test_performance $ligne 0 b
    ../src/test_performance $ligne 0.5 b
    ../src/test_performance $ligne 1 b
    ../src/test_performance $ligne 2 b
    ../src/test_performance $ligne 4 b
    ../src/test_performance $ligne 8 b
    ../src/test_performance $ligne 16 b

done < "../script/fichiers_performance.txt"