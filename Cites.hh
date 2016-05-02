class Cites{

private:

public:
	// Constructores

	Cites();
	/* Pre: cert */
	/* Post: el resultat és un conjunt de cites buit*/
	
	//Modificadores
	
        void afegir_cita(int x, int y, Text& text);
        /*Pre: Text no és buit i es compleix 1 <= x <= y <= n on n es el nombre de frases de text*/
	/*Post: S'ha afegit una nova cita amb la seva referencia corresponent*/
        
        void eliminar_cita(string& referencia);
        /*Pre: Existeix una cita amb la mateixa referencia*/
	/*Post: S'ha eliminat la cita que tenia la mateixa referencia*/

	//Destructora
	
	//Consultores
	
	//Lectura i escriptura
        
        void escriure_cite(string& referencia);
        /*Pre: Exiseix una cita amb la mateixa referencia*/
        /*Post: S'escriu pel canal estandar de sortida la cite amb aquesta referencia*/
        
        void escriure_cites_autor(string& autor);
        /*Pre: Existeix l'autor dins de les cites*/
        /*Post: S'han escrit pel canal estandar de sortida les cites de l'autor*/
        
        void escriure_cite_triat();
        /*Pre: Hi ha d'haver un text triat*/
        /*Post: S'han escrit pel canal estandar de sortida totes els cites d'un text triat*/
        
        void escriure_cites();
        /*Pre: Cert*/
        /*Post: S'han escrit pel canal estandar de sortida totes les cites*/
}