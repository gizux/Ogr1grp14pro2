# Program: Makefile Derleme Dosyası.
# Tarih: 29.12.13
# Grup elemanları: Volkan DEMİR, Gizem ULUTAŞ, Oğuzcan DUMAN, Kübra ALİ, Ahmet BOZANLAR

TARGET		=	Odev


Odev		:	main.c	
	gcc	-o	Odev	main.c
	gcc	-o	Sampler1	Sampler.c
	./Odev

clean		:
	rm	-rf	Odev
	rm	-rf	Sampler
