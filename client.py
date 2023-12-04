import socket
import sys

def start_client(server_ip, porta, stringa, carattere):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((server_ip, porta))

    data = f"{stringa},{carattere}"

    client_socket.send(data.encode('utf-8'))

    result_string = client_socket.recv(1024).decode('utf-8')

    print(f"risultato della stringa è : {result_string}")

    client_socket.close()
    
    if len(sys.argv) != 5:
        print("rispetta questo ordine <server_ip> <porta> <stringa> <carattere>")
        sys.exit(1)

    server_ip = sys.argv[1]
    porta = int(sys.argv[2])
    stringa = sys.argv[3]
    carattere = sys.argv[4]

    start_client(server_ip, stringa, carattere)