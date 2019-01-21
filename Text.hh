/** @file Text.hh
    @brief Especificació de la clase Text
*/

#ifndef TEXT_HH
#define TEXT_HH

#include "Cjt_Frases.hh"

#ifndef NO_DIAGRAM
#include <sstream>
#include <string>
#endif
/** @class Text
    @brief Conté un conjunt de frases.
*/
class Text{

private:
	/** @brief Autor del text. */
	string autor;
	
	/** @brief Títol del text. */
	string titol;
	
	/** @brief Contingut del text. */
	Cjt_Frases cjtfrase;

public:
	// Constructores

	/** @brief Creadora por defecte. 
		S'executa automàticament al declarar un cjt_textos
		\pre <em>Cert</em>
		\post El resultat és un Text sense autor, ni títol, ni contingut, ni cites.
	*/ 
	Text();
	
	//Modificadores
	
	/** @brief Creadora por defecte. 
		S'executa automàticament al declarar un cjt_textos
		\pre <em>La paraula1 ha d'apareixer com a mínim un cop en el contingut del paràmetre implícit</em>
		\post S'han substituït totes les paraules coincidents a paraula1 del contingut del paràmetre implícit i s'han substituït per paraula2.
	*/ 	
	void substituir_paraula(string paraula1, string paraula2);
	
	//Destructora
	
//	~Text();
	
	//Consultores
	
	/** @brief Consultora d'autor. 
		\pre <em>El text té autor</em>
		\post el resultat és l'autor del text en qüestió.
	*/ 		
	string consultar_autor();
	
	/** @brief Consultora de títol. 
		\pre <em>El text té títol</em>
		\post el resultat és el títol del text en qüestió.
	*/        
	string consultar_titol();
	
	/** @brief Consultora del contingut. 
		\pre <em>El text té contingut</em>
		\post el resultat és el contingut del text en qüestió.
	*/ 	    
	Cjt_Frases consultar_contingut();
	
	/** @brief Consultora del contingut. 
		\pre <em> x <= y, x>0 i y<= numero de frases </em>
		\post Modifica el paràmetre implícit de forma que només contè les frases del rang x, y.
	*/ 	
	void consultar_frasesxy(int x, int y);
	
	//Lectura i escriptura
	
	/** @brief Lectura d'un text. 
		\pre <em>Estan preparats al canal estandar d'entrada un títol, un autor i un contingut</em>
		\post El paràmetre implícit passa a tenir els atributs llegits pel canal estàndard d'entrada
	*/ 		
	void llegir(string linia);
};
#endif
