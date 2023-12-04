import sys
import socket
HOST = ""               
PORT = int(sys.argv[1])       
socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket.bind((HOST, PORT))
socket.listen(6)
while 1:
    conn, addr = socket.accept()
    f = conn.recv(1024).decode()
    f = [line.strip().split(',') for line in file]
    f = [{'nome': contact[0], 'cognome': contact[1], 'telefono': contact[2]} for contact in contacts]
    sorted(contacts, key=lambda x: x['nome'])
    conn.send(f.encode())