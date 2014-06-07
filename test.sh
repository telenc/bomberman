make
rm -rf sortieTrade/*;
mkdir sortieTrade;
echo "Amazon : " > sortieTrade/amazon;
./trade_moulinette.php -p trade -f file/AMAZON1.TXT -m 100000 >> sortieTrade/amazon;

echo "Bac : " > sortieTrade/bac;
./trade_moulinette.php -p trade -f file/BAC1.TXT -m 100000 >> sortieTrade/bac;
echo "Boeing : " > sortieTrade/boeing5;

./trade_moulinette.php -p trade -f file/boeing5.txt -m 100000 >> sortieTrade/boeing5;
echo "Cison : " > sortieTrade/cison;

./trade_moulinette.php -p trade -f file/CISCO1.TXT -m 100000 >> sortieTrade/cison;
echo "Ibm : " > sortieTrade/ibm5;

./trade_moulinette.php -p trade -f file/ibm5.txt -m 100000 >> sortieTrade/ibm5 ;

echo "Nike : " > sortieTrade/nike;

./trade_moulinette.php -p trade -f file/nike5.txt -m 100000 > sortieTrade/nike;
cat sortieTrade/*
