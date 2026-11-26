#ifndef PACIENT_HH
#define PACIENT_HH

#include <string>

struct Pacient {
    std::string id;
    int prioritat;
    int timestamp;
};

// El Heap és un max-heap, per tant cal invertir:
// - prioritat menor = més prioritari (volem que surti primer)
// - timestamp menor = va arribar abans (volem que surti primer)
// Invertim el sentit perquè el heap treu el màxim.
bool operator>(const Pacient& a, const Pacient& b) {
    if (a.prioritat != b.prioritat) return a.prioritat < b.prioritat;
    return a.timestamp < b.timestamp;
}

#endif
