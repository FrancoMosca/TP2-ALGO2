#include <iostream>
#include "BatallaDigital.h"
#include "string"

using namespace std;

int main() {
    BatallaDigital * batallaDigital = new BatallaDigital();
    batallaDigital->iniciarJuego();
    batallaDigital->jugarJuego();

    delete batallaDigital;
    return 0;
}
