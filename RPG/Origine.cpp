//programmato da Emanuele Parinetti e Iuri Antico
//commentato da iuri antico
//programmato in Visual Studio 2019

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
//#include "tatti.cpp"

using namespace std;

//variabili globali :)
bool wall_chk_special = true, en_check1 = true, en_check2 = true, salvi_check = false, child_check = false;
int hp1 = 100, hp2 = 100, en1 = 100, en2 = 100, cl1 = 0, cl2 = 0, def1 = 0, def2 = 0, i = 1, i0 = 0, m = 0, wall_check;
float atk, cr;
char choice;
string scl1, scl2;

float atk_trump(int m)//decide quale attacco eseguire data la mossa dell'utente
{
	switch (m)
	{
	case 1://in caso la mossa [m] sia 1 ritorna come danno 15 (attacco normale standard)
		return 15;
		break;
	case 2://in caso la mossa [m] sia 2 ritorna come danno 56 (attacco speciale McNuke: brought to you by capitalism)
		return 56;
		break;
	default://in caso la mossa [m] sia 3 o altro ritorna come danno 0 (attacco speciale Muro) e cambia lo stato del muro come attivato. questa mossa è relativamente più complicata delle altre: può essere usata solo una volta per partita e i suoi effetti si manifestano anche al turno successivo
		return 0;
		wall_check=1;
		break;
	}
}
//////
float atk_soleimani(int m)//decide quale attacco eseguire data la mossa dell'utente
{
	switch (m)
	{
	case 1://in caso la mossa [m] sia 1 ritorna come danno 15 (attacco normale standard)
		return 15;
		break;
	case 2://in caso la mossa [m] sia 2 ritorna come danno 40 (attacco speciale Schiaffo Shiita)
		return 40;
		break;
	default://in caso la mossa [m] sia 3 o altro ritorna come danno 1 (attacco speciale Bambini!)
		return 1;
		break;
	}
}
//////
float atk_salvini(int m)//decide quale attacco eseguire data la mossa dell'utente
{
	switch (m)
	{
	case 1://in caso la mossa [m] sia 1 ritorna come danno 15 (attacco normale standard)
		return 15;
		break;
	case 2://in caso la mossa [m] sia 2 ritorna come danno 30 (attacco speciale RUSPA)
		return 30;
		break;
	default://in caso la mossa [m] sia 3 o altro ritorna come danno 10 (attacco speciale Legittima Difesa)
		return 10;
		break;
	}
}
//////
int en_trump(int m)//decide quanta energia toglie data la mossa dell'utente, le funzioni [en_*] sono semplici e simili tra loro quindi mi asterrò dal commentare tutto
{
	switch (m)
	{
	case 1://in caso la mossa [m] sia 1 ritorna come energia da togliere 40 (attacco normale)
		return 40;
		break;
	case 2:
		return 90;//in caso la mossa [m] sia 2 ritorna come energia da togliere 90 (attacco speciale McNuke: brought to you by capitalism)
		break;
	default:
		return 10;//in caso la mossa [m] sia 3 o altro ritorna come energia da togliere 10 (attacco speciale Muro)
		break;
	}
}
//////
float en_salvini(int m)//idem
{
	switch (m)
	{
	case 1:
		return 40;
		break;
	case 2:
		return 60;
		break;
	default:
		return 45;
		break;
	}
}
//////
float en_soleimani(int m)//idem
{
	switch (m)
	{
	case 1:
		return 40;
		break;
	case 2:
		return 60;
		break;
	default:
		return 60;
		break;
	}
}

/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/ /*cool transition*/

int main()
{
	srand(time(NULL));//its cool, i guess?

	cout << "-1-Donaldo Trombetta:\n\t\tAbilita':\tMcNuke\tMuro\n\n-2-Soleimani:\n\t\tAbilita':\tSchiaffo Shiita\tBambini!\n\n-3-Capitan Salvini:\n\t\tAbilita':\tRUSPA\tLegittima Difesa" << endl << endl;
	cout << "Giocatore 1, scegliere la classe!" << endl;//^^^stampa un menu primitivo che elenca i personaggi e le loro mosse
	cin >> cl1;
	switch (cl1)//in base alla scelta dell'utente1 assegna a delle stringhe il nome del corrispettivo personaggio [cl1] sta per classe1, [scl1] sta per stringa classe1, idem per utente2
	{
		int tatti;
	case 1:
		scl1 = "Donaldo Trombetta";
		break;
	case 2:
		scl1 = "Soleimani";
		break;
	case 3:
		scl1 = "Capitan Salvini";
		break;
	default:
		for (tatti = 0; tatti < 100; tatti++)
		{
			cout << "tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti \ntatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti \ntatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti \ntatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti tatti \n" << endl;
			system("color 1e");
			system("color c3");
			system("color 0f");
			system("color 1e");
			system("color c3");
			system("color 0f");
		}
		cl1 = 3;
		scl1 = "Capitan Salvini";
		break;
	}
	do//gli utenti non possono scegliere personaggi uguali perche avevo poco tempo quindi questo ciclo si assicura che utente2 scelga qualcosa di differente
	{
		cout << "Giocatore 2, scegliere la classe!" << endl;
		cin >> cl2;
	}while(cl2==cl1);
	switch (cl2)//in base alla scelta dell'utente2 assegna a delle stringhe il nome del corrispettivo personaggio
	{
	case 1:
		scl2 = "Donaldo Trombetta";
		break;
	case 2:
		scl2 = "Soleimani";
		break;
	default:
		scl2 = "Capitan Salvini";
		break;
	}
	do//ripete il codice dei turni fino a quando la vita di un utente raggiunge 0, per via di di alcune falle si puo "infierire sul nemico" nonostante la vita sia a zero, la considero una feature
	{
		i0 = i % 2;
		if (i0 == 1)//decide chi fa il turno con un "if a conteggio"
		{
			//start of turn
			cout << "Scegli la tua mossa, " << scl1 << endl;
			do
			{
				do
				{
					cout << "energia : " << en1 << "\nvita : " << hp1 << endl;//stampa all'utente le sue statistche
					switch (cl1)//sceglie che personaggio usare in base alla scelta dell'utente [cl1]
					{
					case 1:
						cout << "-1-Attacco Normale\n-2-McNuke\n-3-Muro\n";//stampa le mosse
						cin >> m;
						if (wall_check == 1 && m > 2)//se l'utente usa trump e sceglie il muro e ha gia usato il muro eseguira forzatamente un attacco normale
						{
							m == 1;
						}
						if (en_trump(m) < en1)//vede se l'utente ha abbastanza energia
						{
							hp2 = hp2 - atk_trump(m) + def2;//sottrae alla vita dell'avversario il valore ritornato dalla funzione di attacco [atk_*] e ci aggiunge il valore di difesa avversario
							system("color 1e");//cambia i colori per divertimento
							system("color c3");
							system("color 0f");
							system("color 1e");
							system("color c3");
							system("color 0f");
							en_check1 = true;//mette [en_check] come vera per dire che ha energia
							en1 = en1 - en_trump(m);//prende il valore ritornato dalla funzione dell'energia [en_*] e lo sottrae alla energia totale [en*]
						}
						else//queste righe fanno si che l'utente capisca che abbia finito il turno
						{
							cout << "Non hai abbastanza energia" << endl;
							en_check1 = false;
						}
						break;
					case 2://identico al case precedente ma con personaggio diverso per la maggior parte
						cout << "-1-Attacco Normale\n-2-Schiaffo Shiita\n-3-Bambini!\n";
						cin >> m;
						if (en_soleimani(m) < en1)
						{
							hp2 = hp2 - atk_soleimani(m) + def2;
							system("color 1e");
							system("color c3");
							system("color 0f");
							system("color 1e");
							system("color c3");
							system("color 0f");
							en_check1 = true;
							en1 = en1 - en_soleimani(m);
							if (m == 3 && child_check == false)//se la mossa è 3 e [child_check] è uguale a false la difesa aumenta di 8 e imposta [child_check] a true
							{
								def1 = def1 + 8;
								child_check = true;
							}
						}
						else if (wall_chk_special == true)//vede se trump ha attivato il muro e se è vero annulla l'attacco
						{
							cout << "il tuo attacco e' stato annullato dal muro di trump!";
						}
						else
						{
							cout << "Non hai abbastanza energia" << endl;
							en_check1 = false;
						}
						break;
					default:
						cout << "-1-Attacco Normale\n-2-RUSPA\n-3-Legittima Difesa\n";
						cin >> m;
						if (en_salvini(m) < en1 && wall_chk_special == false)
						{
							hp2 = hp2 - atk_salvini(m) + def2;
							system("color 1e");
							system("color c3");
							system("color 0f");
							system("color 1e");
							system("color c3");
							system("color 0f");
							en_check1 = true;
							en1 = en1 - en_salvini(m);
							if (m == 3 && salvi_check == false)//se la mossa scelta è uguale a 3 e [salvi_check] è false aumenta la difesa di 10 danneggia l'avversario di 5 punti vita e imposta [salvi_check] su true
							{
								def1 = def1 + 10;
								hp2 = hp2 - 5;
								salvi_check = true;
							}
						}
						else if (wall_chk_special == true)
						{
							cout << "il tuo attacco e' stato annullato dal muro di trump!";
						}
						else
						{
							cout << "Non hai abbastanza energia\n" << endl;
							en_check1 = false;
						}
						break;
					}
				} while (en_check1 == true);//vede se l'utente ha abbastanza energia, lo fa uscire se non ha energia
				if (en_check1 == false)//se l'utente non ha abbastanza energia ([en_check] è true) termina il turno
				{
					choice = 'n';
				}
			} while (choice == 's');//vede se l'utente può continuare il turno, con scelta tramite variabile char
			if (wall_chk_special == true)//vede se il muro è stato attivato in questo turno e se è true da un bonus all'energia data che normalmente è 50
			{
				en1 = en1 + 75;
			}
			else
			{
				en1 = en1 + 50;
			}
			wall_chk_special = false;
			//end of turn
		}
		else//è la stessa identica cosa di prima ma le variabili sono cambiate per il secondo giocatore
		{
			//start of turn
			cout << "Scegli la tua mossa, " << scl2 << endl;
			do
			{
				do
				{
					cout << "energia : " << en2 << "\nvita : " << hp2 << endl;
					switch (cl2)
					{
					case 1:
						cout << "-1-Attacco Normale\n-2-McNuke\n-3-Muro\n";
						cin >> m;
						if (wall_check == 1 && m > 2)
						{
							m == 1;
						}
						if (en_trump(m) < en2)
						{
							hp1 = hp1 - atk_trump(m)+def1;
							system("color 1e");
							system("color c3");
							system("color 0f");
							system("color 1e");
							system("color c3");
							system("color 0f");
							en_check2 = true;
							en2 = en2 - en_trump(m);
						}
						else
						{
							cout << "Non hai abbastanza energia" << endl;
							en_check2 = false;
						}
						break;
					case 2:
						cout << "-1-Attacco Normale\n-2-Schiaffo Shiita\n-3-Bambini!\n";
						cin >> m;
						if (en_soleimani(m) < en2)
						{
							hp1 = hp1 - atk_soleimani(m) + def1;
							system("color 1e");
							system("color c3");
							system("color 0f");
							system("color 1e");
							system("color c3");
							system("color 0f");
							en_check2 = true;
							en2 = en2 - en_soleimani(m);
							if (m == 3 && child_check == false)
							{
								def2 = def2 + 8;
								child_check = true;
							}
						}
						else if (wall_chk_special == true)
						{
							cout << "il tuo attacco e' stato annullato dal muro di trump!";
						}
						else
						{
							cout << "Non hai abbastanza energia" << endl;
							en_check2 = false;
						}
						break;
					default:
						cout << "-1-Attacco Normale\n-2-RUSPA\n-3-Legittima Difesa\n";
						cin >> m;
						if (en_salvini(m) < en2 && wall_chk_special == false)
						{
							hp1 = hp1 - atk_salvini(m) + def1;
							system("color 1e");
							system("color c3");
							system("color 0f");
							system("color 1e");
							system("color c3");
							system("color 0f");
							en_check2 = true;
							en2 = en2 - en_salvini(m);
							if (m == 3 && salvi_check == false)
							{
								def2 = def2 + 10;
								hp1 = hp1 - 5;
								salvi_check = true;
							}
						}
						else
						{
							cout << "Non hai abbastanza energia\n" << endl;
							en_check2 = false;
						}
						break;
					}
				} while (en_check2 == true);
				if (en_check1 == false)
				{
					choice = 'n';
				}
				else
				{
					cout << "Vuoi fare un'altra mossa? s/n?" << endl;
					cin >> choice;
				}
			} while (choice == 's');
			if (wall_chk_special == true)
			{
				en2 = en2 + 75;
			}
			else
			{
				en2 = en2 + 50;
			}
			wall_chk_special = false;
			//end of turn
		}
		i++;
	} while (hp1 > 0 && hp2 > 0);
	if (hp2 == 0)//enuncia il risultato con l'aiuto di stringhe [scl1], [scl2]
	{
		cout << scl2 <<" Gli hai fatto il culo!" << endl;
	}
	else
	{
		cout << scl1 << " Gli hai fatto il culo!" << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
//¯\_(ツ)_ /¯