
#include <exception>

#include "IteratorLP.h"
#include "Lista.h"

#include <iostream>

//complexitate O(capacitate)
Lista::Lista() {
	/* de adaugat */
	size = 0;
	primul = -1;
	for (int i = 0; i < capacitate; i++)
	{
		urmator[i] = i + 1;
		urmator[capacitate - 1] = -1;
	}
	primLiber = 0;
}

//complexitate teta(1)
int Lista::alocare() {
	int i = primLiber;
	primLiber = urmator[primLiber];
	return i;
}

//complexitate teta(1)
void Lista::dealocare(int i) {
	urmator[i] = -1;
	elemente[i] = 0;
	primLiber = i;
}

//complexitate O(capacitate)
void Lista::redimensionare()
{
	capacitate = capacitate * 2;
	TElem* elemente_noi = new TElem[capacitate];
	TElem* urmator_nou = new TElem[capacitate];
	for (int i = 0; i < size; i++)
	{
		elemente_noi[i] = elemente[i];
		urmator_nou[i] = urmator[i];
	}
	for (int i = size; i < capacitate; i++)
	{
		urmator_nou[i] = i + 1;
	}
	urmator_nou[capacitate - 1] = -1;
	delete[] elemente;
	delete[] urmator;
	elemente = elemente_noi;
	urmator = urmator_nou;
	primLiber = size;
}

//complexitate teta(1)
int Lista::creare_nod(TElem e) {
	int i = alocare();
	if (i != -1)
	{
		this->elemente[i] = e;
		urmator[i] = -1;
	}
	return i;
}

//complexitate teta(1)
int Lista::dim() const {
	/* de adaugat */
	return size;
}

//complexitate teta(1)
bool Lista::vida() const {
	/* de adaugat */
	if (dim()==0)
		return true;
	else
		return false;
}

//complexitate teta(1)
IteratorLP Lista::prim() const {
	/* de adaugat */
    return IteratorLP(*this);
}


//complexitate teta(1)
TElem Lista::element(IteratorLP poz) const {
	/* de adaugat */
	return poz.element();
}

//complexitate teta(1)
TElem Lista::sterge(IteratorLP& poz) {
	/* de adaugat */

	TElem de_retunrat = poz.element();
	if (poz.valid() == false)
		throw std::exception();

	int pozitie = poz.curent;
	int anterior = -1;
	int current = primul;

	while (current != pozitie) {
		anterior = current;
		current = urmator[current];
	}

	if (anterior == -1) {
		primul = urmator[current];
	}
	else {
		urmator[anterior] = urmator[current];
	}

	dealocare(current);
	size--;

	return de_retunrat;
}

//complexitate O(capacitate)
IteratorLP Lista::cauta(TElem e) const{
	/* de adaugat */
	IteratorLP it = this->prim();
	while (it.valid())
	{
		if (it.element() == e)
			return it;
		it.urmator();
	}
	return it;
}

//complexitate teta(1)
TElem Lista::modifica(IteratorLP poz, TElem e) {
	/* de adaugat */
	TElem vechi = poz.element();
	this->elemente[poz.curent] = e;
	return vechi;
}

//complexitate teta(1)
void Lista::adauga(IteratorLP& poz, TElem e) {
	/* de adaugat */
	if (poz.valid() == false)
		throw std::exception();
	int i = creare_nod(e);
	if (i != -1)
	{
		urmator[i] = urmator[poz.curent];
		urmator[poz.curent] = i;
		poz.urmator();
	}
	else
	{
		redimensionare();
		int i = creare_nod(e);
		urmator[i] = urmator[poz.curent];
		urmator[poz.curent] = i;
		poz.urmator();
	}
}

//complexitate teta(1)
void Lista::adaugaInceput(TElem e) {
	/* de adaugat */
	int i = creare_nod(e);
	if (i != -1)
	{
		urmator[i] = primul;
		primul = i;
	}
	else
	{
		redimensionare();
		int i = creare_nod(e);
		urmator[i] = primul;
		primul = i;
	}
	size++;
}

//complexitate O(N) amortizat
void Lista::adaugaSfarsit(TElem e) {
	/* de adaugat */
	int i = creare_nod(e);
	if (i != -1) {
		if (primul == -1) {
			primul = i;
		}
		else {
			int current = primul;
			while (urmator[current] != -1) {
				current = urmator[current];
			}
			urmator[current] = i;
		}
		urmator[i] = -1;
	}
	else
	{
		redimensionare();
		int i = creare_nod(e);
		if (primul == -1) {
			primul = i;
		}
		else {
			int current = primul;
			while (urmator[current] != -1) {
				current = urmator[current];
			}
			urmator[current] = i;
		}
		urmator[i] = -1;
	}
	size++;
}

//complexitate O(N) amortizat
int Lista::eliminaToate(Lista& l)
{
	int contor = 0;
	IteratorLP it = l.prim();
	while (it.valid())
	{
		if (this->cauta(it.element()).valid())
		{
			IteratorLP de_sters = this->cauta(it.element());
			this->sterge(de_sters);
			contor++;
		}
		it.urmator();
	}
	return contor;
}


Lista::~Lista() {
	/* de adaugat */
	delete[] elemente;
	delete[] urmator;

}
