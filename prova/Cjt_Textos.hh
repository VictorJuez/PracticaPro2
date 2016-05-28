/** @file Cjt_Textos.hh
    @brief Especificació de la clase Cjt_Textos
*/

#ifndef CJTTEXTOS_HH
#define CJTTEXTOS_HH

#include "Text.hh"

/** @class Cjt_Textos
    @brief Conté un conjunt de textos.

    Todas las operaciones son de <b>coste constante</b>
*/
class Cjt_Textos{

private:
	list <Text> ctextos;
	list <Text>::iterator it_triat;
	bool triat;
	struct aut_tit{
		string autor;
		string titol;
	};
	struct s1{
		string aautor;
		int num_textos;
		int num_frases;
		int num_paraules;
	};
	static bool ordena(aut_tit a,aut_tit b);
	static bool o(string a, string b);
	static bool u(s1 a, s1 b);
	
	void imprimir_vector(vector<string>& v);
	bool apareix_contingut(string& s);
	void crear_vfrase(string s, vector<string>& frase);
	bool trobar_paraules(vector<string> v, Text& t);

public:
	// Constructores
	
	/** @brief Creadora por defecte. 
		S'executa automàticament al declarar un cjt_textos
		\pre <em>Cert</em>
		\post El resultat és un conjunt de textos buit.
	*/ 
	Cjt_Textos();
	
	
	//Modificadores
	/** @brief Modificadora afegir text. 
		afegeix un text al paràmetre implícit
		\pre <em>El text té un títol diferent a qualsevol text ja existent al paràmetre implícit</em>
		\post S'ha afegit el text al conjunt de textos.
	*/ 
	void afegir_text(const Text& text);
   
	/** @brief Modificadora eliminar text. 
		elimina un text al paràmetre implícit
		\pre <em>Tenim un text triat</em>
		\post S'ha eliminat el text i no tenim cap text triat.
	*/      
	void eliminar_text();
	
	/** @brief Modificadora triar text. 
		busca el text que conté les paraules.
		\pre <em>Existeix un únic text amb les paraules introduïdes</em>
		\post El text triat és el que conté les paraules.
	*/ 	
	void triar_text(string& s);
	
	//Destructora
	

	
	//Consultores
	
	/** @brief Consultora text triat. 
		Consulta si hi ha un text triat o no.
		\pre <em>Cert</em>
		\post Retorna cert si hi ha un text triat i fals si no.
	*/ 	
	bool text_triat();
	
	bool existent(string titol, string autor);
	
	/** @brief Retorna el text triat. 
		\pre <em>Hi ha un text triat</em>
		\post Retorna el text triat.
	*/ 		
	Text consultar_text_triat();
	
	//Lectura i escriptura
	
	/** @brief Imprimeix titol i autor. 
		\pre <em>Cert</em>
		\post Escriu pel canal estàndar de sortida el títol i l'autor de cada text ordenats per autor i després títol.
	*/ 		
	
	void imprimir();
	
	void imprimir_textos();
	
	/** @brief Imprimeix els títols de l'autor. 
		\pre <em>Existeix l'autor</em>
		\post Escriu pel canal estàndar de sortida els títols dels textos de l'autor.
	*/ 			
	void imprimir_textos_autor(string& autor) const;
	
	/** @brief Imprimeix tots els autors amb el nombre de textos, frases i paraules. 
		\pre <em>El conjunt de textos no és buit</em>
		\post Escriu pel canal estàndar de sortida els autors amb el nombre de textos, frases i paraules.
	*/ 		
	void imprimir_tots_autors() const;
};
#endif
