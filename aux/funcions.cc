AFEGIR, ELIMINAR I MODIFICAR TEXTOS:

afegir text "<títol>"
autor "<autor>"
<contingut>
****

triar text {<paraula1> <paraula2>... <paraulaN>}

eliminar text

substitueix "<paraula1>" per "<paraula2>"


CONSULTORES:

textos autor "<autor>" ?

tots textos ?

tots autors?

info ? //autor, títol, nombre de frases, nombre de paraules i cites associades

autor ? //mostra l'autor de l'últim text triat

contingut ? //mostra contingut de l'últim text triat amb les frases numerades

frases x y ? // mostra les frases des de x fins a y

nombre de frases ? // mostra el nombre de frases

nombre de paraules ? 

taula de frequencies ? // mostra totes les paraules del contingut del text ordenades decreixentment, si empaten per freq
						//frequencia les paraules s'ordenen creixement, primer per allargada i despres alfabeticament
						
frases <expressió> ? //dificil

frases "<paraula1> <paraula2> ... <paraulaN> " ?


CITES:

afegir cita x y

info cita "<referència>" ?

cites autor "<autor>" ?

cites ? // ultim text triat, mostra la referència, el contingut de les frases, autor i títol del text d'on provenen. 

totes cites ? 

eliminar cita "<referència>"

						


