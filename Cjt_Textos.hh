/** @file Cjt_Textos.hh
    @brief Especificació de la clase Cjt_Textos
*/

#ifndef CJTTEXTOS_HH
#define CJTTEXTOS_HH

#include "Text.hh"

/** @class Cjt_Textos
    @brief Conté un conjunt de textos.
*/
class Cjt_Textos{

private:
	/** @brief Estructura de dades on s'emmagatzema el conjunt de textos.*/
	list <Text> ctextos;
	
	/** @brief Iterador que apunta al text triat quan triat és cert.*/
	list <Text>::iterator it_triat;
	
	/** @brief Variable que conté un autor amb un títol d'un text seu.*/
	bool triat;
	
	/** @brief Variable que conté un autor amb un títol d'un text seu.*/
	struct aut_tit{
		string autor;
		string titol;
	};
	
	/** @brief Variable que conté un autor amb els respectius numero de texos que té, frases i paraules totals.*/
	struct s1{
		string aautor;
		int num_textos;
		int num_frases;
		int num_paraules;
	};
	
	/** @brief Funció per establir el criteri d'ordenació, primer per autor i després per títol*/	
	static bool ordena(aut_tit a,aut_tit b);
	
	/** @brief Funció per establir el criteri d'ordenació el qual és alfabèticament*/	
	static bool o(string a, string b);

	/** @brief Funció per establir el criteri d'ordenació el qual ordena alfabèticament per autor (aautor)*/	
	static bool u(s1 a, s1 b);

	/** @brief Busca les paraules. 
		\pre <em>v i text no són buits </em>
		\post retorna cert si totes les paraules apareixen o en el títol o en l'autor o en el contingut del text.
	*/ 
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
	
	/** @brief Consultora. 
		\pre <em>Cert</em>
		\post retorna cert si existeix un text amb el titol "titol" i l'autor "autor" i fals si no.
	*/ 
	bool existent(string titol, string autor);
	
	/** @brief Retorna el text triat. 
		\pre <em>Hi ha un text triat</em>
		\post Retorna el text triat.
	*/ 		
	Text consultar_text_triat();
	
	//Lectura i escriptura
	
	/** @brief Imprimeix tots els textos. 
		\pre <em>Cert</em>
		\post Escriu pel canal estàndar de sortida tots els textos ordenats primer per autor i despres per títol.
	*/ 
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
