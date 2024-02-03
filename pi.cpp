#include <cmath>
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <fstream>

// Programma per trovare un'approssimazione di pigreco partendo dal lancio di un dado

using namespace std;

// Funzione che genera numeri con cifre da 1 a 6  mettendo in sequenza una serie di lanci

int lanci(int i)
{
  int c;
  int dado = rand() % 6 + 1; // lancio del dado
  c = dado * pow(10, (i));   // moltiplicazione del dado per 10^i per ottenere numeri con cui fare la sequenza
  // cout << c << endl;
  return c;
}

int main()
{
  ofstream file;
  file.open("pigreco.csv");          // Apre il file .csv nel quale inserire i dati
  file << "Pi Value, Lanci" << endl; // Nome delle colonne del file .csv (Excel)
  srand((unsigned)time(0));
  cout.precision(12);
  ;
  double pi; // pigreco
  int i = 0;
  int n = 0; // n=numero di punti
  double x = 0;
  double y = 0;
  int g = 0; // numero di lanci
  int a = 0; // numero punti interni alla circonferenza x^2+y^2=1
  long xseme = 0;
  long yseme = 0;
  // iter per trovare le coordinate x e y dei punti compresi nell'intervallo [0,1]
  for (int k = 0; k <= 50; k++)
  { // numero di pigreco da estrarre = k (es. 10 valori)
    g = 0;
    a = 0;
    pi = 0;
    for (n = 0; n <= 1000000; n++)
    { // Numero di punti da estrarre
      do
      {
        int c = lanci(i); // richiama la funzione lanci
        xseme += c;       // crea il seme per generare numeri casuali
        i++;              // aumento deell'esponente i nella funzione lanci
        g++;              // aumento di 1 il numero di lanci effettuati
        // cout << "numero lanci: " << g << endl;
      } while (i <= 6); // faccio quanto descritto sopra fino a raggiungere un numero con 6 cifre (*10^6)

      // cout << "seme di x:" << xseme <<endl;
      srand(xseme);                  // imposto il seme trovato in precedenza
      x = rand() / double(RAND_MAX); // genero il numero casuale partendo dal numero trovato coi dadi
      // cout << "x: " << x <<endl;
      i = 0; // reimposto le variabili i e imposto il seme di nuovo totalmente casuale
      srand((unsigned)time(0));
      // eseguo quanto descritto per x ancher per y
      do
      {
        int c = lanci(i);
        yseme += c;
        i++;
        g++;
        // cout << "numero lanci: " << g << endl;
      } while (i <= 6);
      // cout << "seme di  y: " << y <<endl;
      srand(yseme);
      y = rand() / double(RAND_MAX);
      // cout << "y: " << y <<endl;
      // Trovo il numero di punti appartenenti al cerchio
      if ((x * x) + (y * y) <= 1)
      {
        a++;
      }
    }
    // cout << "numero lanci totali: " << g <<endl;
    // cout << "conteggio punti interni:" << a << endl;
    pi = ((double)a / n) * 4.0;
    // cout << "pigreco: " << pi << endl;
    // cout << "numero di lanci: " << g <<endl;
    file << pi << "," << g << endl; // inserisco i dati nel file .csv
  }
  file.close();
  cout << "Valori salvati nel file pigreco.csv!" << endl;
}
