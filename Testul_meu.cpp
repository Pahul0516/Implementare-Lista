#include <assert.h>
#include <exception>

#include "TestExtins.h"
#include "IteratorLP.h"
#include "Lista.h"

void testul_meu()
{
	Lista lista = Lista();
	lista.adaugaSfarsit(1);
	lista.adaugaSfarsit(2);
	lista.adaugaSfarsit(3);
	lista.adaugaSfarsit(4);
	lista.adaugaSfarsit(5);

	Lista l = Lista();
	l.adaugaSfarsit(1);
	l.adaugaSfarsit(2);
	l.adaugaSfarsit(3);

	assert(lista.eliminaToate(l) == 3);
	assert(lista.dim() == 2);


	Lista lista2 = Lista();
	lista2.adaugaSfarsit(1);
	lista2.adaugaSfarsit(2);
	lista2.adaugaSfarsit(3);
	lista2.adaugaSfarsit(4);
	lista2.adaugaSfarsit(5);

	Lista l2 = Lista();
	l2.adaugaSfarsit(1);
	l2.adaugaSfarsit(2);
	l2.adaugaSfarsit(19);
	assert(lista2.eliminaToate(l2) == 2);
	assert(lista2.dim() == 3);


	Lista lista3 = Lista();
	lista3.adaugaSfarsit(1);
	lista3.adaugaSfarsit(2);
	lista3.adaugaSfarsit(3);
	lista3.adaugaSfarsit(4);
	lista3.adaugaSfarsit(5);

	Lista l3 = Lista();
	l3.adaugaSfarsit(1);
	l3.adaugaSfarsit(2);
	l3.adaugaSfarsit(3);
	l3.adaugaSfarsit(4);
	l3.adaugaSfarsit(5);
	assert(lista3.eliminaToate(l3) == 5);
	assert(lista3.dim() == 0);

	Lista lista4 = Lista();
	lista4.adaugaSfarsit(1);
	lista4.adaugaSfarsit(2);
	lista4.adaugaSfarsit(3);
	lista4.adaugaSfarsit(4);
	lista4.adaugaSfarsit(5);

	Lista l4 = Lista();
	assert(lista4.eliminaToate(l4) == 0);
	assert(lista4.dim() == 5);


	Lista lista5 = Lista();
	lista5.adaugaSfarsit(1);
	lista5.adaugaSfarsit(3);
	lista5.adaugaSfarsit(5);
	lista5.adaugaSfarsit(4);
	lista5.adaugaSfarsit(2);


	Lista l5 = Lista();
	l5.adaugaSfarsit(2);
	l5.adaugaSfarsit(1);
	l5.adaugaSfarsit(412);
	l5.adaugaSfarsit(5);
	l5.adaugaSfarsit(41342);
	l5.adaugaSfarsit(4);
	l5.adaugaSfarsit(41212);
	l5.adaugaSfarsit(4);
	assert(lista5.eliminaToate(l5) == 4);
	assert(lista5.dim() == 1);
}