class Cjt_Textos{

private:

public:
	// Constructores

	Cjt_Textos();
	/* Pre: cert */
	/* Post: el resultgit at és un Text sense autor, ni títol, ni contingut, ni cites*/
	
	//Modificadores
	
	void afegir_text(const Text& text);
        /*Pre: El text té un títol diferent a qualsevol text ja existent al paràmetre implícit*/
        /*Post: S'ha afegit el text al conjunt de textos*/
        
        void eliminar_text();
        /*Pre: Tenim un text triat*/
        /*Post: S'ha eliminat el text i no tenim cap text triat*/
	
	//Destructora
	
	~Cjt_Textos();
	
	void eliminar_text();
        /* Pre: hi ha un text seleccionat*/
        /* Post: s'ha elminat el text seleccionat i no hi ha cap text seleccionat*/
	
	//Consultores
	
	//Lectura i escriptura
        
        void escriure();
        /*Pre: cert*/
        /*Post: s'ha escrit pel canal estandar de sortida el títoli l'autor de cada text del conjunt*/
}