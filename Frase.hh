

Class Frase{

//Tipus de mòdul: dades
//Descripció del tipus: Conté un conjunt de paraules que formen la frase i aquestes poden estar separades per comes, punts i comes i dos punts. Tota frase //està acabada en interrogant de tancar, admiració de tancar o en punt. Conté la variable num_paraules , la cual ens indica quantes paraules conté la
//frase.

private:

public:
	// Constructores

	Frase();
	/* Pre: cert */
	/* Post: el resultat és una frase buida sense cap element i num_paraules = 0 */
	
	//Modificadores
	
	void substituir_paraula(string paraula1, string paraula2);
	/* Pre: la paraula1 ha d'apareixer com a mínim un cop en el paràmetre implícit*/
	/* Post: s'han substituït totes les paraules coincidents a paraula1 del paràmetre implícit i s'han substituït per paraula2*/ 

	//Destructora
	
	//Consultores

	int numero_de_paraules() const;
	/*Pre: cert*/
	/*Post: el resultat es la variable num_paraules del paràmetre implícit*/

	bool conte_paraula(string paraula) const;
	/* Pre: cert */
	/* Post: el resultat indica si el paràmetre implícit conté o no la paraula*/

	bool conte_paraules(vector<string> paraules) const;
	/* Pre:cert*/
	/* Post: el resultat ens indica si la frase conté la seqüència paraules en el mateix ordre*/
	
	//Lectura i escriptura
	
	void llegir();
	/* Pre: estan preparats al canal estandar d'entrada una seqüència de paraules i/o 	     signes de puntuació no buit , acabada en punt, signe d'interrocació de tancament 	     o signe d'exclamació de tancament*/
	/*Post: el paràmetre implícit passa a tenir els atrivuts llegits pel canal estàndard 	    d'entrada i la variable num_paraules conté el nombre de paraules introduides*/

	void escriure() const;
	/* Pre: cert*/
	/* Post: s'ha la seqüència de paraules del paràmetre implícit al canal estàndar de 	     sortida*/
}