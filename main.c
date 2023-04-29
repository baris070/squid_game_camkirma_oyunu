#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Oyuncu { //tan�mlamalar
	int can;
	int bulundungustun;
	int bulundungusatir;
	int bulundungoncekiustun;
	int bulundunguoncekisatir;
	char harf;
}A, B, C, temp, Oyuncular[3];
int main()
{
	/*
	Oyuncular ayarland�
	*/
	A.harf = 'A'; // a oyuncusuna a harfini tan�mlad�k
	A.bulundungusatir = 0;//a oyuncusunun bulundu�u sat�r� 0 yapt�k
	A.bulundungustun = 0;//a oyuncusunun bulundu�u s�tunu 0 yapt�k
	A.can = 3;//a oyuncusunun can� 3 oldu
	B.harf = 'B';
	B.bulundungusatir = 0;
	B.bulundungustun = 0;
	B.can = 3;
	C.harf = 'C';
	C.bulundungusatir = 0;
	C.bulundungustun = 0;
	C.can = 3;

	//--Oyuncular�n oyuna ba�lama s�ras�
	Oyuncular[0] = A;//birinci s�rada a ba�layacak
	Oyuncular[1] = B;
	Oyuncular[2] = C;
	//------

	/*
		Camlarin kirilir kirilmaz oldugu belirlendi.
	*/
	char camlar[4][10];
	srand(time(NULL));
	int n;

	for (int i = 0; i < 10; i++) {
		camlar[0][i] = 'O';//hepsi kirilmaz cam
		camlar[1][i] = 'O';
		camlar[2][i] = 'O';
		camlar[3][i] = 'O';
		n = rand() % (4);
		camlar[n][i] = 'K';// Camlardan birisini kirilir yaptik

	}
	//Ekrana camlar�n bas�lmas�
	//---------------------------- Yazma i�lemi

	for (int i = 0; i < 10; i++) {
		printf("%d\t", i + 1);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("-\t");
	}
	printf("\n");
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 10; i++) {
			printf("%c\t", camlar[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	//---------------------------------



	int hamle;// ilk oyuncunun hareketi.
	int adim = 0;//ilk s�radaki elaman�n konumu
	int oyuncusayisi = 3;
	while ((oyuncusayisi > 0) && (adim < 10)) {//herhangi birinin cani varsa veya ilk adam bitirmemi�se devam et
		hamle = rand() % (4);
		if (camlar[hamle][adim] == 'K') {//At�lan ad�m k�r�lan cama basm��sa
			camlar[hamle][adim] = 'X';// Cam k�r�ld�.
			Oyuncular[0].can--;//Oyuncunun canini bir azaltacak.

			if (Oyuncular[0].can == 0) {//elenen oyuncu varm�, cani kalmayan oyuncuya bakiyoruz
				if (oyuncusayisi == 3) {// ilk oyuncu elenmi�tir
					Oyuncular[0] = Oyuncular[1];
					Oyuncular[1] = Oyuncular[2];
					oyuncusayisi--;
				}
				else if (oyuncusayisi == 2) {// iki oyuncu varsa
					Oyuncular[0] = Oyuncular[1];
					oyuncusayisi--;
				}
				else {
					oyuncusayisi--;
					break;// oyun biter cunku son oyuncuda elenmistir***********
				}

			}
			else {//ilk oyuncunu cani varsa
				  //Oyuncu de�i�tirme
				if (oyuncusayisi == 3) {// 3 oyuncu varsa
					temp = Oyuncular[0];
					Oyuncular[0] = Oyuncular[1];
					Oyuncular[1] = Oyuncular[2];
					Oyuncular[2] = temp;
				}
				else if (oyuncusayisi == 2) {//2 oyuncu varsa
					temp = Oyuncular[0];
					Oyuncular[0] = Oyuncular[1];
					Oyuncular[1] = temp;
				}
				else {//1 oyuncu varsa
				   //Hi� bir �ey yapma
				}
			}//ilk oyuncunu cani varsa
		}
		else if (camlar[hamle][adim] == 'X') {// ba�kas� taraf�ndan bas�lm�� ve k�r�lm�� bir camsa
		   //Burada baska cam secilecek
		}
		else if (camlar[hamle][adim] == 'O') {// kirilmaz camsa
			if (oyuncusayisi == 3) {//3 ki�i ise
				 //Oyuncular hareket ettirildi.
				Oyuncular[2].bulundungusatir = Oyuncular[1].bulundungusatir;
				Oyuncular[2].bulundungustun = Oyuncular[1].bulundungustun;
				Oyuncular[1].bulundungusatir = Oyuncular[0].bulundungusatir;
				Oyuncular[1].bulundungustun = Oyuncular[0].bulundungustun;
				Oyuncular[0].bulundungusatir = hamle;//ilk  oyuncunun bulundu�u sat�r hamle oldu
				Oyuncular[0].bulundungustun = adim;//ilk  oyuncunun bulundu�u s�tun adim oldu
				// birinci oyuncu bir ilerledikten sonra arkas�ndaki oyuncuyu onun yerine ald�
				if (adim == 0) {

				}
				else {
					if (adim == 1) {

					}
					else {
						camlar[Oyuncular[2].bulundungusatir][Oyuncular[2].bulundungustun] = Oyuncular[2].harf;
					}
				}
				if (adim != 0) {
					camlar[Oyuncular[1].bulundungusatir][Oyuncular[1].bulundungustun] = Oyuncular[1].harf;
				}
				camlar[Oyuncular[0].bulundungusatir][Oyuncular[0].bulundungustun] = Oyuncular[0].harf;

			}
			else if (oyuncusayisi == 2) {//2 ki�i ise
			   //Oyuncular hareket ettirildi

				Oyuncular[1].bulundungusatir = Oyuncular[0].bulundungusatir;
				Oyuncular[1].bulundungustun = Oyuncular[0].bulundungustun;
				Oyuncular[0].bulundungusatir = hamle;
				Oyuncular[0].bulundungustun = adim;
				//
				camlar[Oyuncular[1].bulundungusatir][Oyuncular[1].bulundungustun] = Oyuncular[1].harf;
				camlar[Oyuncular[0].bulundungusatir][Oyuncular[0].bulundungustun] = Oyuncular[0].harf;
			}
			else {

				Oyuncular[0].bulundungusatir = hamle;
				Oyuncular[0].bulundungustun = adim;
				camlar[Oyuncular[1].bulundungusatir][Oyuncular[1].bulundungustun] = Oyuncular[1].harf;
				camlar[Oyuncular[0].bulundungusatir][Oyuncular[0].bulundungustun] = Oyuncular[0].harf;
			}

			adim++;//bir adim attik
		}
		//---------------------------- Yazma i�lemi

		for (int i = 0; i < 10; i++) {
			printf("%d\t", i + 1);
		}
		printf("\n");
		for (int i = 0; i < 10; i++) {
			printf("-\t");
		}
		printf("\n");
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 10; i++) {
				printf("%c\t", camlar[j][i]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
		//---------------------------------

	}

 	 printf("Oyunu ilk bitiren oyuncu: %c\n",Oyuncular[0].harf);
 	 printf("\n");
 	 printf("\n");

	if (oyuncusayisi == 3) {
		printf("%c' nin %d cani kaldi\n", Oyuncular[0].harf, Oyuncular[0].can);
		printf("%c' nin %d cani kaldi\n", Oyuncular[1].harf, Oyuncular[1].can);
		printf("%c' nin %d cani kaldi\n", Oyuncular[2].harf, Oyuncular[2].can);
	}
	else if (oyuncusayisi == 2) {
		printf("%c' nin %d cani kaldi\n", Oyuncular[0].harf, Oyuncular[0].can);
		printf("%c' nin %d cani kaldi\n", Oyuncular[1].harf, Oyuncular[1].can);

	}
	else if (oyuncusayisi == 1) {
		printf("%c' nin %d cani kaldi\n", Oyuncular[0].harf, Oyuncular[0].can);


	}
	else {
		printf("Oyuncu kalmad�");
	}


	return 0;
}
