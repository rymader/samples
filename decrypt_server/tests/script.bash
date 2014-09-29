#!/bin/bash

#to test each section just uncomment the lines

#the output created files should be equal to output folder

#remember at each test to remove the .decrypted files

PORT=5000


#test 1
aux=10

PP=$[$PORT+$aux]

decryption_server $PP 1 &

#decryption_client localhost $PP client1.txt 

#test 2 
#aux=30
#PP=$[$PORT+$aux]
#./decryption_server $PP 1 &

#./decryption_client localhost $PP client6.txt 

#test 3 
#aux=54
#PP=$[$PORT+$aux]
#./decryption_server $PP 1 &

#./decryption_client localhost $PP client2.txt &

#./decryption_client localhost $PP client4.txt &

#test 4 

#aux=69
#PP=$[$PORT+$aux]
#./decryption_server $PP 3 &

#./decryption_client localhost $PP client2.txt &

#./decryption_client localhost $PP client3.txt &

#./decryption_client localhost $PP client4.txt &

#test 5 

#aux=100
#PP=$[$PORT+$aux]
#./decryption_server $PP  3 &

# ./decryption_client localhost $PP client2.txt &
# ./decryption_client localhost $PP client3.txt &
# ./decryption_client localhost $PP client4.txt &
# ./decryption_client localhost $PP client5.txt &
# ./decryption_client localhost $PP client6.txt &

 
#test 6 
#have to wait for the files be done some codes took some time
#aux=200
#PP=$[$PORT+$aux]
#./decryption_server $PP 1 &

# ./decryption_client localhost $PP huge.txt &
 
#test extra credit 
#aux=300
#PP=$[$PORT+$aux]
#./decryption_server $PP  1 &

#./decryption_client localhost $PP client1.txt client3.txt client6.txt &








