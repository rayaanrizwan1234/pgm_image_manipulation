#test script
make pgmEcho 
make pgmCompare
make pgma2b 
#pgmEcho read and write; Test 1:
echo "Test 1: Testing read and write"
./pgmEcho slice0a.pgm testOutRW.pgm

#pgmCompare; Test 2:
echo "Test 2: Testing compare -> IDENTICAL"
./pgmCompare slice0a.pgm testOutSame.pgm

#pgmCompare; Test 3:
echo "Test 3: Testing compare -> DIFFERENT"
./pgmCompare slice0a.pgm testOutDifferent.pgm

#pgmConverted - Ascii to Binary; Test 4:
echo "Test 4: Testing converted -> CONVERTED"
./pgma2b out.pgm outConvertedA2B.pgm

#pgmConverted - Binary to Ascii; Test 5:
#echo "Test 5 : Testing converted -> CONVERTED"
#./pgmb2a out.pgm  outConvertedB2A.pgm




