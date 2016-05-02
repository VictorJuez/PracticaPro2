/** @file Cjt_Frases.hh
    @brief Especificació de la clase Cjt_Frases
*/

/** @class Cjt_Frases
    @brief Conté un conjunt de frases.

    Todas las operaciones son de <b>coste constante</b>
*/
class Cjt_Frases{

private:

public:
	// Constructores
	/** @brief Creadora por defecte. 
		S'executa automàticament al declarar un cjt_frases
		\pre <em>Cert</em>
		\post El resultat és un conjunt de frases buit.
	*/ 
	Cjt_Frases();
	
	//Modificadores
	
	/** @brief Substitueix una paraula per una altre. 
		\pre <em>La paraula1 ha d'apareixer com a mínim un cop en el paràmetre implícit.</em>
		\post S'han substituït totes les paraules coincidents a paraula1 del paràmetre implícit per paraula2.
	*/ 
	void substituir_paraula(string paraula1, string paraula2);

	//Destructora
	
	~Cjt_Frases();
	//Consultores
	
	/** @brief Consultora del número de paraules. 
		\pre <em>Cert</em>
		\post El resultat es el número de paraules del paràmetre implícit.
	*/
	int numero_de_paraules() const;
	
	/** @brief Consultora del número de frases. 
		\pre <em>Cert</em>
		\post El resultat es el número de frases del paràmetre implícit
	*/       
	int numero_de_frases() const;
	
	/** @brief Consultora conté paraula. 
		\pre <em>El vector de paraules no és buit</em>
		\post El resultat indica si el paràmetre implícit conté o no la paraula
	*/  
	bool conte_paraula(string paraula) const;
	
	/** @brief Consultora paraules. 
		\pre <em>el vector paraules no és buit</em>
		\post el resultat ens indica si la frase conté la mateixa seqüència de paraules.
	*/  
	bool conte_paraules(vector<string> paraules) const;
	
	//Lectura i escriptura

	/** @brief Imprimeix la taula de freqüènces. 
		\pre <em>cert</em>
		\post s'ha escrit la taula de frequencies del paràmetre implícit al canal estàndar de sortida
	*/
	void taula_frequencies() const;

	/** @brief Llegeix un Cjt_Frases. 
		\pre <em>Estan preparats al canal estandar d'entrada una seqüència de frases acabada en ****</em>
		\post El paràmetre implícit passa a tenir els atributs llegits pel canal estàndard d'entrada.
	*/
	void llegir();

	/** @brief Llegeix un Cjt_Frases. 
		\pre <em>cert</em>
		\post S'ha escrit la seqüència de frases del paràmetre implícit al canal estàndar de sortida.
	*/	
	void escriure() const;
}
