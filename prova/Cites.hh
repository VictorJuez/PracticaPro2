/** @file Cites.hh
    @brief Especificació de la clase Cites
*/

/** @class Cites
    @brief Conté operacions de cites.

    Todas las operaciones son de <b>coste constante</b>
*/
	
	#include <map>
	#include "Text.hh"

class Cites{

private:
	
	struct cita{
		int inici;
		Text tcita;
		};
		
	map <string, cita> mcites;
	
	struct sref{
		string ref;
		int contador;
		};
	vector<sref> vref;
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
	void afegir_cita(int x, int y, Text& text);
 	
 	/** @brief Modificadora eliminar cita. 
		\pre <em>Existeix una cita amb la mateixa referencia</em>
		\post S'ha eliminat la cita que tenia la mateixa referència.
	*/ 	       
	void eliminar_cita(string& referencia);

	//Destructora
	
	//Consultores
	
	//Lectura i escriptura
	
 	/** @brief Imprimir cita. 
		\pre <em>Existeix una cita amb la mateixa referència</em>
		\post S'escriu pel canal estandar de sortida la cita amb aquesta referència.
	*/         
        void escriure_cita(string& referencia);
        
 	/** @brief Imprimir cites d'autor. 
		\pre <em>Existeix l'autor dins de les cites</em>
		\post S'han escrit pel canal estàndar de sortida les cites de l'autor autor.
	*/       
        void escriure_cites_autor(string& autor);

 	/** @brief Imprimir cita triat. 
		\pre <em>Ha d'haver un text triat</em>
		\post S'han escrit pel canal estàndar de sortida totes les cites del text triat.
	*/         
        void escriure_cita_triat();
        
 	/** @brief Imprimir cites. 
		\pre <em>Cert</em>
		\post S'han escrit pel canal estàndar de sortida totes les cites.
	*/        
        void escriure_cites();
}
