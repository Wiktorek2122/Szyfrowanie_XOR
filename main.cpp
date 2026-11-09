#include <string>
#include <stdexcept>
#include <emscripten/bind.h>

using namespace std;

// Szyfrowanie XOR
string xorSzyfruj(string tekst, string klucz) {

    if (klucz.empty()) {
        throw runtime_error("Podaj klucz szyfrujacy!");
    }

    string wynik = tekst;

    for (int i = 0; i < tekst.length(); i++) {
        wynik[i] = tekst[i] ^ klucz[i % klucz.length()];
    }

    return wynik;
}

// Alfabet Base64
const string alfabet =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Kodowanie Base64
string base64Encode(string tekst) {

    string wynik;
    int val = 0, valb = -6;

    for (unsigned char c : tekst) {
        val = (val << 8) + c;
        valb += 8;

        while (valb >= 0) {
            wynik.push_back(alfabet[(val >> valb) & 63]);
            valb -= 6;
        }
    }

    if (valb > -6)
        wynik.push_back(alfabet[((val << 8) >> (valb + 8)) & 63]);

    while (wynik.size() % 4)
        wynik.push_back('=');

    return wynik;
}

// Dekodowanie Base64
string base64Decode(string tekst) {

    string wynik;
    int val = 0, valb = -8;

    for (unsigned char c : tekst) {

        if (c == '=') break;

        size_t pos = alfabet.find(c);

        if (pos == string::npos)
            throw runtime_error("Niepoprawny szyfrogram!");

        val = (val << 6) + pos;
        valb += 6;

        if (valb >= 0) {
            wynik.push_back(char((val >> valb) & 255));
            valb -= 8;
        }
    }

    return wynik;
}

// Szyfrowanie
string encryptText(string tekst, string klucz) {
    return base64Encode(xorSzyfruj(tekst, klucz));
}

// Odszyfrowanie
string decryptText(string tekst, string klucz) {
    return xorSzyfruj(base64Decode(tekst), klucz);
}

// Udostepnienie funkcji dla JavaScript/WASM
EMSCRIPTEN_BINDINGS(moj_modul) {
    emscripten::function("encryptText", &encryptText);
    emscripten::function("decryptText", &decryptText);
}