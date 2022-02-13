CC=g++
FLAGS = -g -o
LNSL = -lnsl
all :
	$(CC) $(FLAGS) calcul_client calcul_xdr.o calcul_client.o calcul_clnt.o $(LNSL)
	$(CC) $(FLAGS) calcul_server calcul_svc.o calcul_xdr.o calcul_server.o
	@mv calcul_server ../server
	@mv calcul_client ../client