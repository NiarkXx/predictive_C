smspred: main.o bibli_doc.o bibli_pred.o
	gcc -o smspred main.o bibli_doc.o bibli_pred.o

main.o: main.c bibli_doc.h bibli_pred.h
	gcc -o main.o -c main.c 

bibli_doc.o: bibli_doc.c bibli_doc.h
	gcc -o bibli_doc.o -c bibli_doc.c

bibli_pred.o: bibli_pred.c bibli_pred.h
	gcc -o bibli_pred.o -c bibli_pred.c