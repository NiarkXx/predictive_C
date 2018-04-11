smspred: main.o bibli_doc.o bibli_pred.o
	gcc -o smspred main.o bibli_doc.o bibli_pred.o 

main.o: main.c bibli_doc.h bibli_pred.h
	gcc -g -c main.c 

bibli_doc.o: bibli_doc.c bibli_doc.h
	gcc -g -c bibli_doc.c 

bibli_pred.o: bibli_pred.c bibli_pred.h
	gcc -g -c bibli_pred.c 