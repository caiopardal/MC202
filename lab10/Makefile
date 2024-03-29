###############################################################################################
######################### Compilação com suporte a múltiplos arquivos #########################
###############################################################################################

.PHONY: build clean

LAB = 10
MAX_TST = 16

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
GFLAGS  = -std=c99 -Wall -Werror

build: $(OBJECTS)
	gcc $(GFLAGS) *.o -o lab$(LAB) -lm

%.o: %.c
	gcc $(GFLAGS) -g -c $< -o $@

clean:
	rm -f *.o


###############################################################################################
####################### Suporte para testar o programa usando os testes #######################
###############################################################################################

.PHONY: testar_programa

testar_programa:
	@set -e ; \
	if [ ! -d testes ] ; then \
		echo "\033[1;31mDiretório 'testes' não encontrado!\033[0m" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes/*.in ; do \
		echo "\033[1;34mTestando \033[4;34m$$entrada\033[0m" ; \
		saida=$$(echo "$$entrada" | sed -re 's/\.in$$/.out/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\.in$$/.res/' ) ; \
		./lab$(LAB) < "$$entrada" > "$$saida" ; \
		if diff "$$resposta" "$$saida" ;  then \
			echo "\033[1;32mResultado correto!\033[0m" ; \
		else \
			echo "\033[1;31mFalhou!\033[0m" ; \
			exit 1; \
		fi ; \
		echo ; \
	done

###############################################################################################
###################### Suporte para checar o programa usando o valgrind #######################
###############################################################################################

.PHONY: checar_testes

checar_testes:
	@set -e ; \
	if [ ! -d testes ] ; then \
		echo "\033[1;31mDiretório 'testes' não encontrado!\033[0m" ; \
		exit 1 ; \
	fi ; \
	for entrada in testes/*.in ; do \
		echo "\033[1;34mTestando \033[4;34m$$entrada\033[0m" ; \
		saida=$$(echo "$$entrada" | sed -re 's/\.in$$/.out/' ) ; \
		resposta=$$(echo "$$entrada" | sed -re 's/\.in$$/.res/' ) ; \
		if valgrind -q --leak-check=full ./lab$(LAB) < "$$entrada" > "$$saida" ;  then \
			echo "\033[1;32mResultado correto!\033[0m" ; \
		else \
			echo "\033[1;31mFalhou!\033[0m" ; \
			exit 1; \
		fi ; \
		echo ; \
	done


###############################################################################################
################################ Suporte para baixar os testes ################################
###############################################################################################

.PHONY: baixar_testes baixar_pdf

baixar_testes:
	@mkdir -p testes ; \

	for i in $(shell seq -f "%02g" 1 $(MAX_TST)) ; do \
		echo "\033[1;34mBaixando arquivos de teste #$$i\033[0m" ; \
		for ext in .in .res ; do \
			url=https://susy.ic.unicamp.br:9999/mc202defg/$(LAB)/dados/arq$$i$$ext ; \
			echo "$(LAB)/dados/arq$$i$$ext" ; \
			curl -sk "$$url" > testes/arq$$i$$ext ; \
		done ; \
		echo "\033[1;32mConcluído!\033[0m" ; \
		echo ; \
	done

#### make baixar_pdf PDF=1
baixar_pdf:
	curl "https://raw.githubusercontent.com/iagoac/mc202/master/exercicios_laboratorio/Lab_$(PDF)_202.pdf" --output Lab_$(LAB).pdf ; \