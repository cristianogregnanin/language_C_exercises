import socket
import sys
HOST = ""    
PORT = int(sys.argv[1])             
socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.connect((HOST, PORT))
f=open('rubrica.txt','r')
socket.send(f.encode)
f2 = socket.recv(1024).decode()
file=open('rubrica_ordinata.txt', 'w') 
for contact in f2:
    file.write(f"Nome: {contact['nome']}, Cognome: {contact['cognome']}, Telefono: {contact['telefono']}\n")
socket.close()
