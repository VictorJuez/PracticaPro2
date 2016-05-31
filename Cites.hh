/** @file Cites.hh
    @brief Especificació de la clase Cites
*/
#include <list>
#ifndef CITES_HH
#define CITES_HH


#include "Text.hh"
#include <string>

using namespace std;

/** @class Cites
    @brief Conté operacions de cites.
*/
class Cites{

private:
	/** @brief Variable que defineix cita*/	
	struct cita{
		string referencia;
		int inici;
		Text tcita;
		};
		
	/** @brief Variable que conté una referència sense nombre i el valor més gran que se li ha assignat mai */	
	struct sref{
		string ref;
		int contador;
		};
	
	/** @brief shortcurt*/
	typedef list<cita>::iterator iterador;
	
	/** @brief Estructura on s'emmagatzen totes les cites*/	
	list <cita> lcites;

	/** @brief Iterador utilitzat per accedir als diferents elements del conjunt de cites*/
	iterador itc;
	
	/** @brief Espai de memòria on s'emmagatzemen les referències sense nombre i el valor més gran que se li ha assignat mai*/
	vector<sref> vref;
	
	/** @brief Escriure cita. 
		\pre <em>Cert</em>
		\post Retorna un iterador que apunta a la cita que conté la referència s i si no la conté que apunta al end().
	*/ 
	iterador buscar_referencia(string s);
	
	/** @brief Escriure cita. 
		\pre <em>Cert</em>
		\post Retorna un string que es la composició de s i n
	*/ 
	string crear_ref(string s, int n);
	
	/** @brief Funció per establir el criteri d'ordenació vref*/
	static bool comp(const cita& a, const cita& b);
	
 	/** @brief Escriure cita. 
		\pre <em>Existeix una cita amb referencia: "referencia"</em>
		\post Imprimeix pel canal estàndar de sortida la cita separada per frases.
	*/ 
	void escriure_cita(string& referencia);
public:
	// Constructores
	
	/** @brief Creadora per defecte. 
		S'executa automàticament al declarar una cita
		\pre <em>Cert</em>
		\post el resultat és un conjunt de cites buit.
	*/ 
	Cites();
	
	//Modificadores
	/** @brief Modificadora afegir cita. 
		S'executa automàticament al declarar una cita
		\pre <em>Text no és buit i es compleix 1 <= x <= y <= n on n es el nombre de frases de text</em>
		\post S'ha afegit una nova cita amb la seva referencia corresponent.
	*/ 	
	void afegir_cita(int x, int y, Text text);
	
	/** @brief Modificadora eliminar cita. 
		\pre <em>Existeix una cita amb la mateixa referencia</em>
		\post S'ha eliminat la cita que tenia la mateixa referència.
	*/ 	
	void eliminar_cita(string& referencia);
	//Destructora

	
	//Consultores
	
 	/** @brief Imprimir cita. 
		\pre <em>Existeix una cita amb la referencia r</em>
		\post retorna el contingut de la cita.
	*/ 
	Cjt_Frases consultar_contingut(string r);
 	
 	/** @brief Imprimir cita. 
		\pre <em>Cert</em>
		\post retorna cert si existeix una cita amb el rang marcat per x i y, el titol i l'autor del text citat.
	*/ 
	bool existeix_cita(int x, int y, string titol, string autor);
	
 	/** @brief Imprimir cita. 
		\pre <em>Cert</em>
		\post retorna cert si existeix la referencia en el conjunt de cites i fals si no.
	*/    	
	bool existeix_cita_ref(string referencia);
	
	//Lectura i escriptura
	
 	/** @brief Imprimir cita. 
		\pre <em>Existeix una cita amb la mateixa referència</em>
		\post S'escriu pel canal estandar de sortida la cita amb aquesta referència.
	*/         
        void escriure_cita_ref(string& referencia);
        
 	/** @brief Imprimir cites d'autor. 
		\pre <em>Existeix l'autor dins de les cites</em>
		\post S'han escrit pel canal estàndar de sortida les cites de l'autor autor.
	*/       
        void escriure_cites_autor(string& autor);

 	/** @brief Imprimir cita triat. 
		\pre <em>Ha d'haver un text triat</em>
		\post S'han escrit pel canal estàndar de sortida totes les cites del text triat.
	*/         
        void escriure_cita_triat(string titol, string autor);
        
 	/** @brief Imprimir cita info. 
		\pre <em>Ha d'existir una cita amb el titol "titol" i l'autor "autor" que passem</em>
		\post S'han escrit pel canal estàndar de sortida la referència i les cites del text referenciat.
	*/         
        void escriure_cita_info(string titol, string autor);
        
 	/** @brief Imprimir cites. 
		\pre <em>Cert</em>
		\post S'han escrit pel canal estàndar de sortida totes les cites.
	*/        
        void escriure_cites();
        
};
#endif

