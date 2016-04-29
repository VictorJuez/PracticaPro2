class Text{

private:

public:
	// Constructores

	Text();
	/* Pre: cert */
	/* Post: el resultat és un text*/
	
	//Modificadores
	
	void substituir_paraula(string paraula1, string paraula2);
	/* Pre: la paraula1 ha d'apareixer com a mínim un cop en el paràmetre implícit*/
	/* Post: s'han substituït totes les paraules coincidents a paraula1 del paràmetre implícit i s'han substituït per paraula2*/ 

	//Destructora
	
	//Consultores

	int numero_de_paraules() const;
	/*Pre: cert*/
	/*Post: el resultat es el numero de paraules del paràmetre implícit*/
        
        int numero_de_frases() const;
	/*Pre: cert*/
	/*Post: el resultat es el numero de frases del paràmetre implícit*/

	bool conte_paraula(string paraula) const;
	/* Pre: cert */
	/* Post: el resultat indica si el paràmetre implícit conté o no la paraula*/

	bool conte_paraules(vector<string> paraules) const;
	/* Pre: el vector paraules no és buit*/
	/* Post: el resultat ens indica si la frase conté la seqüència paraules en el mateix ordre*/
	
	//Lectura i escriptura
	
	void taula_frequencies() const;
        /*Pre: cert*/
        /*Post: s'ha escrit la taula de frequencies del paràmetre implícit al canal estàndar de sortida*/
	
	void llegir();
	/* Pre: estan preparats al canal estandar d'entrada una seqüència de frases acabada en **** */
	/*Post: el paràmetre implícit passa a tenir els atributs llegits pel canal estàndard d'entrada*/

	void escriure() const;
	/* Pre: cert*/
	/* Post: s'ha escrit la seqüència de frases del paràmetre implícit al canal estàndar de sortida*/
}