class Text{

private:

public:
	// Constructores

	Text();
	/* Pre: cert */
	/* Post: el resultat és un Text sense autor, ni títol, ni contingut, ni cites*/
	
	//Modificadores
	
	void substituir_paraula(string paraula1, string paraula2);
	/* Pre: la paraula1 ha d'apareixer com a mínim un cop en el contingut del paràmetre implícit*/
	/* Post: s'han substituït totes les paraules coincidents a paraula1 del contingut del paràmetre implícit i s'han substituït per paraula2*/ 
	
	//Destructora
	
	~Text();
	
	//Consultores
	
        string consultar_autor();
        /*Pre: el text té autor*/
        /*Post: el resultat és l'autor del text en qüestió*/
        
        string consultar_titol();
        /*Pre: el text té títol*/
        /*Post: el resultat és el títol del text en qüestió*/
        
        Cjt_Frases consultar_contingut();
        /*Pre: el text té contingut*/
        /*Post: el resultat és el contingut del text en qüestió*/
	
	//Lectura i escriptura
	
	
	void llegir();
	/* Pre: estan preparats al canal estandar d'entrada un títol, un autor i un contingut */
	/*Post: el paràmetre implícit passa a tenir els atributs llegits pel canal estàndard d'entrada*/

	void escriure() const;
	/* Pre: cert*/
	/* Post: s'ha escrit el títol, l'autor i el contingut pel canal estandar de sortida.*/
}