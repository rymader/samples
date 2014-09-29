Hw5 test cases


client(Number).txt.decrypted should have the decryption file.  

 
Test case 1: Basic communication and decryption (single client, single line)
Points: 15
Server Command: ./decryption_server 6500 1
Client Command: ./decryption_client localhost 6500 client1.txt
Files decrypted on client side: client1.txt
Thread 1 is handling client (127.0.0.1,PORT)
Thread 1 finished handling client (127.0.0.1,PORT)

Test case 2: Multiple lines one client (single client, multiple lines)
Points: 15
Server Command: ./decryption_server 6500 1
Client Command: ./decryption_client localhost 6500 client6.txt
Files decrypted on client side: client6.txt
Thread 1 is handling client (127.0.0.1,PORT)
Thread 1 finished handling client (127.0.0.1,PORT)

Test case 3: Multiple clients, one thread
Points: 10
Server Command: ./decryption_server 6500 1
Client 1 Command: ./decryption_client localhost 6500 client2.txt
Client 2 Command: ./decryption_client localhost 6500 client4.txt
Files decrypted on client 1 side: client1.txt
Files decrypted on client 2 side: client7.txt
Expected stdout on server side:
Thread 1 is handling client (127.0.0.1,X)
Thread 1 finished handling client (127.0.0.1,X)
Thread 1 is handling client (127.0.0.1,Y)
Thread 1 finished handling client (127.0.0.1,Y)


Test case 4: Multiple clients, Multiple lines (same number of clients and threads)
Points: 10
Server Command: ./decryption_server 6500 3
Client 1 Command: ./decryption_client localhost 6500 client2.txt
Client 2 Command: ./decryption_client localhost 6500 client3.txt
Client 3 Command: ./decryption_client localhost 6500 client4.txt
Files decrypted on client 1 side: client2.txt
Files decrypted on client 2 side: client3.txt
Files decrypted on client 3 side: client4.txt
Expected stdout on server side:
Thread X is handling client (127.0.0.1,X)
Thread X finished handling client (127.0.0.1,X)
Thread X is handling client (127.0.0.1,Y)
Thread X finished handling client (127.0.0.1,Y)
Thread X is handling client (127.0.0.1,Z)
Thread X finished handling client (127.0.0.1,Z)

Test case 5: More clients than threads
Points: 20
Server Command: ./decryption_server 6500 3
Client 1 Command: ./decryption_client localhost 6500 client2.txt
Client 2 Command: ./decryption_client localhost 6500 client3.txt
Client 3 Command: ./decryption_client localhost 6500 client4.txt
Client 4 Command: ./decryption_client localhost 6500 client5.txt
Client 5 Command: ./decryption_client localhost 6500 client6.txt
Client 6 Command: ./decryption_client localhost 6500 client7.txt
Files decrypted on client 1 side: client2.txt
Files decrypted on client 2 side: client3.txt
Files decrypted on client 3 side: client4.txt
Files decrypted on client 4 side: client5.txt
Files decrypted on client 5 side: client6.txt
Files decrypted on client 6 side: client6.txt
Expected stdout on server side:
Thread X is handling client (127.0.0.1,X)
Thread X finished handling client (127.0.0.1,X)
Thread X is handling client (127.0.0.1,Y)
Thread X finished handling client (127.0.0.1,Y)
Thread X is handling client (127.0.0.1,Z)
Thread X finished handling client (127.0.0.1,Z)
Thread X is handling client (127.0.0.1,R)
Thread X finished handling client (127.0.0.1,R)
Thread X is handling client (127.0.0.1,T)
Thread X finished handling client (127.0.0.1,T)
Thread X is handling client (127.0.0.1,B)
Thread X finished handling client (127.0.0.1,BS)


Test case 6: Bigger client file
Points: 10
Server Command: ./decryption_server 6500 1
Client Command: ./decryption_client localhost 6500 huge.txt
Files decrypted on client side: huge.txt
Expected stdout on server side:
Thread 1 is handling client (127.0.0.1,X)
Thread 1 finished handling client (127.0.0.1,X)

Extra credit test case: Multiple files per client
Points: 10
Server Command: ./decryption_server 5000 1
Client Command: ./decryption_client localhost 5000 client1.txt client3.txt client6.txt
Files translated on client side: client1.txt client3.txt client6.txt
Expected stdout on server side: (can be in a different order, accept any integer for X)
Thread 1 is handling client (127.0.0.1,X)
Thread 1 finished handling client (127.0.0.1,X)












