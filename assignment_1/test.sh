#test script
make clean
make 
#pgmEcho read and write; Test 1:
echo "Test 1: Testing read and write"
./pgmEcho slice0a.pgm testOutRW.pgm

#pgmCompare; Test 2:
echo "Test 2: Testing compare -> IDENTICAL"
./pgmCompare slice0a.pgm testOutSame.pgm

echo "Test 3: Testing compare -> DIFFERENT"
./pgmCompare slice0a.pgm testOutDifferent.pgm

#pgmConverted - Ascii to Binary; Test 4:
echo "Test 4: Testing converted -> CONVERTED"
./pgma2b out.pgm outConvertedA2B.pgm

echo "Test 5 : Testing converted -> CONVERTED"
./pgmb2a out.pgm  outConvertedB2A.pgm

#pgmReduce Test: Reduces the file of a file
echo "Test 6: Testing pgmReduce -> REDUCED by a factor of 2"
./pgmReduce slice0a.pgm 2 pgmTestReduced.pgm

echo "Test 7: Testing pgmReduce -> REDUCED by a factor of 20"
./pgmReduce coins.ascii.pgm 20 pgmCoinsReducedBy20.pgm

# PGM Convert and Compare
echo "Test 8: Testing Convert and Compare"
./pgma2b slice0a.pgm a2b.pgm

echo "Test 8 Compare between ASCII and BINARY"
./pgmCompare a2b.pgm slice0a.pgm


