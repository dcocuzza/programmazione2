/* 
Corso di Programmazione II (A-L), Prof. Dario Catalano 

Esercizi sulla ricorsione

Esercizio 4: Torri di Hanoi
(esempio di ricorsione)
*/

#include<iostream>
using namespace std;

void Hanoi(char iniziale, char centrale, char finale, int n) 
{
 	if (n==1)  
 		cout << "Muovo il disco 1 dal piatto " << iniziale 
 			 << " al piatto " << finale << endl; 			 
 	else 
 	{	Hanoi(iniziale, finale, centrale,n-1);
 		cout << "Muovo il disco " << n 
 			 << " dal piatto " << iniziale 
 			 << " al piatto " << finale << endl; 
 		Hanoi(centrale,iniziale, finale, n-1);
 	}  
 		
} 


int main() 
{	int n;
	
	cout << "Inserire un intero positivo: ";
	cin >> n;  
	if (n<=0) cout << "Errore: numero non positivo \n"; 
	else {
		cout << "Con " << n 
			 << " dischi la sequenza di operazioni è \n"; 
		Hanoi('A','B','C',n);
		} 
}
