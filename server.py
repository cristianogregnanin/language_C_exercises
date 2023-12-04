import socket
import sys

def rimuovi_carattere(stringa, carattere_da_rimuovere):
    return stringa.replace(carattere_da_rimuovere, '')

 def start_server(porta, carattere_da_rimuovere):
    host = '0.0.0.0'

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, porta))
    server_socket.listen(1)

    print(f"Server in ascolto sull' {host}: e sulla porta {porta}...")

    while True:
        client_socket, client_address = server_socket.accept()
        print(f"connessione avvenuta")

        data = client_socket.recv(1024).decode('utf-8')
        stringa = data.split(',')[0]

        result_string = rimuovi_carattere(stringa, carattere_da_rimuovere)

        client_socket.send(result_string.encode('utf-8'))

        client_socket.close()
        print("Connesione chiusa")

    if len(sys.argv) != 3:
        print("rispetta questo ordine <porta> <carattere_da_rimuovere>")
        sys.exit(1)

    porta = int(sys.argv[1])
    carattere_da_rimuovere = sys.argv[2]

    start_server(porta, carattere_da_rimuovere)