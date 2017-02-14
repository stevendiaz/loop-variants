CC=icc


multiply: multiply.c no_papi_multiply.c
	$(CC) -L$(TACC_PAPI_LIB) -lpapi -I$(TACC_PAPI_INC) -Wall -Werror -O3 -fp-model precise multiply.c -o multiply.o

no_papi:
	$(CC) -Wall -Werror -O3 -fp-model precise no_papi_multiply.c -o no_papi.o -lrt 

run:
	./multiply.o

run_np:
	./no_papi.o

clean:
	rm *.o
