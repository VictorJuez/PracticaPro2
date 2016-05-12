/** @file Frase.hh
    @brief Especificación de la clase Frase
*/

#ifndef FRASE_HH
#define FRASE_HH

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/** @class Frase
    @brief Conté un conjunt de paraules que formen la frase i aquestes poden estar separades per comes, punts i comes i dos punts. Acabada en '.', '?' o '!'.

    Todas las operaciones son de <b>coste constante</b>
*/
class Frase{

private:
        int numero_de_paraules;
        vector<string> frase;

public:
	// Constructores
	
	/** @brief Creadora per defecte. 
		S'executa automàticament al declarar una frase.
		\pre <em>Cert</em>
		\post El resultat és una frase buida.
	*/ 
	Frase();
	
	//Modificadores
	
	/** @brief Modificadora de frase.

		\pre <em>La paraula1 ha d'apareixer com a mínim un cop en el paràmetre implícit</em>
		\post S'han substituït totes les paraules coincidents a paraula1 del paràmetre implícit per paraula2
	*/ 
	void substituir_paraula(string& paraula1, string& paraula2);

	//Destructora
	/** @brief Destructora per defecte.
		\pre <em>Cert</em>
		\post El resultat és la frase eliminada.
	*/ 	
//	~Frase();
	
	//Consultores
	/** @brief Consultora de numero de paraules. 

		\pre <em>Cert</em>
		\post El resultat es el número de paraules del paràmetre implícit.
	*/ 

	int num_de_paraules() const;

	/** @brief Consultora conté paraula. 

		\pre <em>Cert</em>
		\post El resultat indica si el paràmetre implícit conté o no la paraula.
	*/
	bool conte_paraula(string& paraula) const;
	
	/** @brief Consultora de numero de paraules. 

		\pre <em>Cert</em>
		\post El resultat indica si el paràmetre implícit conté o no la seqüència de paraules.
	*/
//	bool conte_paraules(vector<string>& paraules) const;
	
	//Lectura i escriptura
	
	/** @brief Lectura de paraules. 

		\pre <em>Estan preparats al canal estandar d'entrada una seqüència de paraules i/o signes de puntuació no buit, acabada en punt, signe d'interrocació de tancament o signe d'exclamació de tancament</em>
		\post El paràmetre implícit passa a tenir els atributs llegits pel canal estàndard d'entrada.
	*/	
	void llegir();
	
	/** @brief Lectura de paraules. 

		\pre <em>Cert</em>
		\post S'ha escrit la seqüència de paraules del paràmetre implícit al canal estàndar de sortida.
	*/	
	void escriure() const;
}; 
#endif
