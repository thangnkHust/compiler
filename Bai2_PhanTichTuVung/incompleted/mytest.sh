#! /bin/bash
echo "Test 1"
./scanner ../test/example1.kpl | diff ../test/result1.txt -
echo "Test 2"
./scanner ../test/example2.kpl | diff ../test/result2.txt -
echo "Test 3"
./scanner ../test/example3.kpl | diff ../test/result3.txt -
echo "Test 4"
./scanner ../test/example4.kpl | diff ../test/result4.txt -
echo "Test 5"
./scanner ../test/example5.kpl | diff ../test/result5.txt -
echo "Test 6"
./scanner ../test/example6.kpl | diff ../test/result6.txt -
