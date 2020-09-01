#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

//PROTOTIPOS
void dividir(int a[], int inicial, int final);
void fusionar(int a[], int pinicial, int pfinal, int medio);

    char r;
//FUNCION PRINCIPAL
int main()
{
    ofstream archivo;
    string datos;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin,datos);
    archivo.open(datos.c_str(),ios::app);
    do{
    int numeros[10];

    srand(time(NULL));
    for (int i=0; i<6;i++)
    {
        numeros[i]=1+rand()%(50-1);
    }
    archivo << "Elementos originales: ";
    for (int i=0; i<6;i++)
    {
        cout<<"|"<<numeros[i]<<"|";
        archivo <<"|"<<numeros[i]<<"|";
    }
    dividir(numeros,0,6);
    cout<<endl;
    archivo << endl;
    archivo << "Elementos ordenados: ";
    for (int i=0; i<6;i++)
    {
        cout<<"|"<<numeros[i]<<"|";
        archivo <<"|"<<numeros[i]<<"|";
    }
    archivo << endl;
    cout<<"\nDESEA AGREGAR OTRO DATO s/n: ";
  cin>>r;
  cin.ignore();
  }while(r=='s');
  archivo.close();
}


void dividir(int a[], int inicial, int final)
{

    int mitad;

    if (inicial<final)
    {
        mitad=(inicial+final)/2;

        dividir(a,inicial,mitad);

        dividir(a,mitad+1,final);

        fusionar(a,inicial,final,mitad);
    }

}

void fusionar(int a[], int pinicial, int pfinal, int medio)
{
    int i, j, k, temp[pfinal-pinicial+1];
	i = pinicial;
	k = 0;
	j = medio + 1;

	while (i <= medio && j <= pfinal)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= medio)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <=pfinal)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = pinicial; i <= pfinal; i++)
	{
		a[i] = temp[i-pinicial];
	}
}