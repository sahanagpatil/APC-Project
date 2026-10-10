SRCS = main.c dll.c compare.c check_sign.c addition.c subtraction.c multiplication.c division.c

OBJ = $(SRCS:.c=.o)

a.out: $(OBJ)
	gcc -o $@ $^

clean:
	rm -f *.o a.out