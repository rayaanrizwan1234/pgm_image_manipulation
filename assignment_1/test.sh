#test script
make clean
make 
#pgmEcho Tests
echo "Test 1: Testing read and write -> ECHOED"
./pgmEcho pgmImages/slice0a.pgm pgmImages/sliceCopy.pgm

echo "Test 2: Testing Echo Binary -> ECHOED"
./pgmEcho pgmImages/sbinary.pgm pgmImages/sbinaryCopy.pgm

echo "Test 3: Testing Bad Dimensions -> Bad Data"
./pgmEcho pgmImages/badDimensions.pgm pgmImages/wrong.pgm

echo "Test 4: Testing Bad Max Gray -> Bad Max Gray Value"
./pgmEcho pgmImages/badMaxGray.pgm pgmImages/wrong.pgm

echo "Test 5 : Testing Bad Magic Number -> Bad Magic Number"
./pgmEcho pgmImages/badMagicNumber.pgm pgmImages/wrong.pgm

echo "Test 6: Testing Bad File name -> Bad File Name"
./pgmEcho pgmImages/a pgmImages/wrong.pgm

#pgmComp Tests
echo "Test 7: Testing Identical Images ASCII -> IDENTICAL"
./pgmComp pgmImages/slice0a.pgm pgmImages/sliceCopy.pgm

echo "Test 8: Testing Identical Images Binary -> IDENTICAL"
./pgmComp pgmImages/sbinary.pgm pgmImages/sbinaryCopy.pgm

echo "Test 9: Testing Identical Binary and ASCII Imges -> IDENTICAL"
./pgmComp pgmImages/slice0a.pgm pgmImages/sbinary.pgm 

echo "Test 10: Testing Different Images -> DIFFERENT"
./pgmComp pgmImages/slice0a.pgm pgmImages/compDifferent.pgm

#pgma2b Tests
echo "Test 11: Testing ASCII To Binary -> CONVERTED"
./pgma2b pgmImages/slice0a.pgm pgmImages/sbinary.pgm

echo "Test 12: Testing Binary Input -> Bad Magic Number"
./pgma2b pgmImages/sbinary.pgm pgmImages/wrong.pgm

#pgmb2a Tests
echo "Test 13: Testing Binary To ASCII -> CONVERTED"
./pgma2b pgmImages/sbinary.pgm pgmImages/slice0a.pgm

echo "Test 14: Testing ASCII Input -> Bad Magic Number"
./pgma2b pgmImages/slice0a.pgm pgmImages/wrong.pgm

#pgmReduce Tests
echo "Test 15: Testing Reduce ASCII -> REDUCED"
./pgmReduce pgmImages/coinsAscii.pgm 20 pgmImages/coinsReduce.pgm

echo "Test 16 Testing Reduce Binary -> REDUCED"
./pgmReduce pgmImages/sbinary.pgm 2 pgmImages/sbinaryReduced.pgm

#pgmTile Tests
echo "Test 17 Testing Tiling ASCII Image -> TILED"
./pgmTile pgmImages/compDifferent.pgm 2 pgmImages/"testTile_<row>_<column>.pgm"

echo "Test 18 Testing Tiling Binary Image -> TILED"
./pgmTile pgmImages/sbinary.pgm 2 pgmImages/"binaryTiled_<row>_<column>.pgm"

#pgmAssemble Tests
echo "Test 19 Testing Assemble -> ASSEMBLED"
./pgmAssemble pgmImages/assembeled.pgm 6 6 0 0 pgmImages/tiled_0_0.pgm 0 3 pgmImages/tiled_0_1.pgm 3 0 pgmImages/tiled_1_0.pgm 3 3 pgmImages/tiled_1_1.pgm   


