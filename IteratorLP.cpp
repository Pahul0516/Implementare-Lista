#include "IteratorLP.h"
#include "Lista.h"
#include <exception>


//complexitate teta(1)
IteratorLP::IteratorLP(const Lista& l):lista(l) {
	/* de adaugat */
	curent = l.primul;
}

//complexitate teta(1)

void IteratorLP::prim(){
	/* de adaugat */
	curent = lista.primul;
}

//complexitate teta(1)

void IteratorLP::urmator(){
	/* de adaugat */
	if (curent == -1)
		throw std::exception();
	else
		curent = lista.urmator[curent];
}

//complexitate teta(1)
bool IteratorLP::valid() const{
	/* de adaugat */
	return curent != -1;
}

//complexitate teta(1)
TElem IteratorLP::element() const{
	/* de adaugat */
	if (valid()==true)
		return lista.elemente[curent];
	else 
		throw std::exception();
}


