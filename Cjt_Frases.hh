/** @file Cjt_Frases.hh
    @brief Especificació de la clase Cjt_Frases
*/
#ifndef CJTFRASES_HH
#define CJTFRASES_HH

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>


/** @class Cjt_Frases
    @brief Conté un conjunt de frases.

    Todas las operaciones son de <b>coste constante</b>
*/
using namespace std;

class Cjt_Frases{

private:
	/** @brief Estructura de dades que conté el conjunt de frases.*/
	vector <list <string> > vfrases;
	
	/** @brief Conté el número de paraules que té el conjunt de frases.*/
    int nparaules;
 
	/** @brief Variable de dades que conté una paraula del conjunt de frases i els cops que apareix.*/
    struct freq{
        int repeticions;
        string paraula;
    };
   
  	/** @brief Variable de dades que conté les diferents paraules del conjunt de frases i els cops que apareixen. .*/
    vector <freq> taula;
    
	/** @brief Consultora de signes. 
		\pre <em>aux no és buit.</em>
		\post retorna cert si la paraula acaba amb ',', '.', '?', '!', ';', ':'.
	*/
    bool te_signe(string aux);
    
	/** @brief Eliminadora de signes. 
		\pre <em>aux ha de tenir signe</em>
		\post S'ha eliminat el signe.
	*/
    string treure_signes(string aux);
    
	/** @brief Guarda signe 
		\pre <em>aux té signe</em>
		\post Retorna el signe.
	*/
    char guardar_signe(string aux);
    
	/** @brief Conté paraules
		\pre <em>l i s no són buits</em>
		\post Retorna cert si l conté les paraules de s en ordre de i=0 fins i=s.size()-1.
	*/
    bool conte_paraules_plus(list<string>& l, vector<string>& s);
    
	/** @brief Afegeix taula
		\pre <em>Cert</em>
		\post Si s no existeix a la taula de freqüències aquesta es afegida, i si existeix se li suma 1 al contador en qüestió.
	*/
    void afegir(string& s);
   
	/** @brief Imprimeix una frase 
		\pre <em>Cert</em>
		\post Escriu pel canal estàndar de sortida la frase l.
	*/
    void imprimir_frase(const list<string>& l) const;
    
	/** @brief Crieri per ordenar la taula de freqüències, primer per freqüència, després creixenment per tamany, i després alfabèticament*/
    static bool ord(const freq& a,const freq& b);
    
	/** @brief Busca paraula en una frase
		\pre <em>Existeix vfrases[i]</em>
		\post Retorna cert si troba la paraula a la frase v[i].
	*/
    bool conte_paraula_expressio(string paraula, int i);
    
 	/** @brief Funció d'immersió d'expressió.
		\pre <em>exp és com a mínim una expressió binaria</em>
		\post Retorna cert si l'expressió es compleix per la frase vfrases[j].
	*/   
    bool expressio_i(vector<string>& exp, int j);
    

public:
	// Constructores
	/** @brief Creadora por defecte. 
		S'executa automàticament al declarar un cjt_frases
		\pre <em>Cert</em>
		\post El resultat és un conjunt de frases buit.
	*/ 
	Cjt_Frases();
	
	//Modificadores
	
	/** @brief Substitueix una paraula per una altre. 
		\pre <em>La paraula1 ha d'apareixer com a mínim un cop en el paràmetre implícit.</em>
		\post S'han substituït totes les paraules coincidents a paraula1 del paràmetre implícit per paraula2.
	*/ 
	void substituir_paraula(string paraula1, string paraula2);

	/** @brief Substitueix el conjunt de frases
		\pre <em>s no és buit</em>
		\post El paràmetre implícit queda substituit per l'string s.
	*/
	void substituir_cjtfrases(string s);
	
	/** @brief Consultora del contingut. 
		\pre <em> n <= m, n>0 i m<= numero de frases </em>
		\post Modifica el paràmetre implícit de forma que només contè les frases del rang n, m.
	*/ 	
	void consultar_frasesxy(int n, int m);
	
	//Destructora
	
//	~Cjt_Frases();
	//Consultores
	
	/** @brief Consultora del número de paraules. 
		\pre <em>Cert</em>
		\post El resultat es el número de paraules del paràmetre implícit.
	*/
	int numero_de_paraules() const;
	
	/** @brief Consultora del número de frases. 
		\pre <em>Cert</em>
		\post El resultat es el número de frases del paràmetre implícit
	*/       
	int numero_de_frases() const;
	
	/** @brief Consultora conté paraula. 
		\pre <em>El vector de paraules no és buit</em>
		\post El resultat indica si el paràmetre implícit conté o no la paraula
	*/  
	bool conte_paraula(string paraula);
	
	/** @brief Consultora paraules. 
		\pre <em>el vector paraules no és buit</em>
		\post el resultat ens indica si la frase conté la mateixa seqüència de paraules.
	*/  
	void conte_paraules(string paraules);
	
	
	//Lectura i escriptura
	
	/** @brief Imprimeix frases. 
		\pre <em>Entra una expressió binària i entre claus o parèntesis i claus dins.</em>
		\post Imprimeix pel canal estàndar de sortida les frases del contingut que compleixen l'expressió.
	*/
	void expressio(string& exp);

	/** @brief Imprimeix la taula de freqüènces. 
		\pre <em>cert</em>
		\post s'ha escrit la taula de frequencies del paràmetre implícit al canal estàndar de sortida
	*/
	void taula_frequencies();

	/** @brief Llegeix un Cjt_Frases. 
		\pre <em>Estan preparats al canal estandar d'entrada una seqüència de frases acabada en ****</em>
		\post El paràmetre implícit passa a tenir els atributs llegits pel canal estàndard d'entrada.
	*/
	void llegir();

	/** @brief Imprimeix una frase. 
		\pre <em>Existeix la frase número n</em>
		\post Escriu pel canal estàndar de sortida la frase número n.
	*/	
	void imprimir_nfrase(int n);
	
	/** @brief Imprimeix el rang de frases x y. 
		\pre <em>n <= m, n>0 i m<= numero de frases</em>
		\post Imprimeix pel canal estàndar de sortida el rang de frases x, y amb 
		el número de frase en la que apareixen respecte del text devant.
	*/ 	
	void frasesxy(int n, int m) const;
	
	/** @brief Imprimeix el contingut. 
		\pre <em> Cert </em>
		\post Imprimeix pel canal estàndar de sortida tot el conjunt de frases numerades respecte la posició en el text.
	*/ 	
	void escriure() const;
	
	
};
#endif
