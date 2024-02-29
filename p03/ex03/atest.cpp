#include "animal.h"
#include <iostream>
using namespace std;

int main()
{
	Animal a1("cao", 1, "kurika", 10);			// especie, sexo, nome, idade
	Veterinario v1("rui silva", "geral");		// nome, especialidade
	Animal a2("morcego", 0, "bobo", 2, v1); // especie, sexo, nome, idade, veterinario
	Animal a3("urso", 1, "banny", 5);				// especie, sexo, nome, idade

	a3.setIdade(6);
	a3.setVeterinario(Veterinario("carlos macedo", "mamíferos"));

	cout << "Informação acerca de " << a1.getNome() << endl;
	cout << "Animal: " << a1.getEspecie() << ", " << a1.getSexo() << ", " << a1.getNome() << ", " << a1.getIdade() << "; Responsavel: " << (a1.getVeterinario()).getNome() << endl;
	cout << "Informação acerca de " << a2.getNome() << endl;
	cout << "Animal: " << a2.getEspecie() << ", " << a2.getSexo() << ", " << a2.getNome() << ", " << a2.getIdade() << "; Responsavel: " << (a2.getVeterinario()).getNome() << endl;
	cout << "Informação acerca de " << a3.getNome() << endl;
	cout << "Animal: " << a3.getEspecie() << ", " << a3.getSexo() << ", " << a3.getNome() << ", " << a3.getIdade() << "; Responsavel: " << (a3.getVeterinario()).getNome() << endl;

	Animal a4(a1);
	Animal *pa5 = new Animal(a2);

	cout << "Informação acerca de " << pa5->getNome() << endl;
	cout << "Animal: " << pa5->getEspecie() << ", " << pa5->getSexo() << ", " << pa5->getNome() << ", " << pa5->getIdade() << "; Responsavel: " << (pa5->getVeterinario()).getNome() << endl;

	return 0;
}