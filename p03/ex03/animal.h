#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
using namespace std;

class Veterinario {
		string nome;
		string especialidade;
	public:
		Veterinario(string, string);
		Veterinario();
		string getNome() const;
		void setNome(string);
		string getEspecialidade() const;
		void setEspecialidade(string);
};

class Animal {
		const string especie;
		const bool sexo;
		const string nome;
		int idade;
		Veterinario veterinario;
	public:
		// alinea b)
		Animal(string, bool, string, int);
		Animal(string, bool, string, int, Veterinario);
		// alinea d)
		Animal(Animal &);
		// alinea c)
		string getEspecie() const;
		bool getSexo() const;
		string getNome() const;
		void setIdade(int);
		int getIdade(void) const;
		void setVeterinario(Veterinario);
		Veterinario getVeterinario() const;
};

#endif
