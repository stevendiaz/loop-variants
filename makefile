CC=icc


hellomake: multiply.c no_papi_multiply.c
	$(CC) -L$(TACC_PAPI_LIB) -lpapi -I$(TACC_PAPI_INC) -Wall -Werror -O3 -fp-model precise multiply.c -o multiply.o
	$(CC) -Wall -Werror -O3 -fp-model precise no_papi_multiply.c -o no_papi.o -lrt 

clean:
	rm *.o
