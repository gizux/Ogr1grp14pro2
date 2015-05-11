# Program: Makefile
# Tarih: 11.05.2015
# Grup elemanlari: Gizem ULUTAŞ <B101210033>, Mehmet Eray Alakese <G111210087>

TARGET		=	Odev


Odev		:	main.c	
	gcc	-o	Odev	main.c
	gcc	-o	Sampler1	Sampler.c
	chmod	777	Sampler1
	./Odev

clean		:
	rm	-rf	Odev
	rm	-rf	Sampler1
