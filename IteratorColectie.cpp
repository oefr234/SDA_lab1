#include "IteratorColectie.h"
#include "Colectie.h"
#include <stdio.h>
#include <exception>


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
    pozitie = 0;
    frecventa1 = 1;
    index = 0;
}

void IteratorColectie::prim() {
    pozitie = 0;
    index = 0;
}


void IteratorColectie::urmator() {
    if (!valid())
        throw std::exception();
    if (frecventa1 < col.frecventa[pozitie]) {
        frecventa1++;
    }
    else {
        pozitie++;
        frecventa1 = 1;
    }
    index++;
}


bool IteratorColectie::valid() const {
    /* de adaugat */
    return index < col.dim();
}



TElem IteratorColectie::element() const {
    if (!valid())
        throw std::exception();
    int x = 0;
    while (col.frecventa[x] < 1)
        x += 1;
    return x;
}
