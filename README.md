# Szyfrowanie_XOR
## Opis projektu

Projekt przedstawia prosty program do szyfrowania i odszyfrowywania wiadomości za pomocą algorytmu XOR.

Aplikacja działa w przeglądarce internetowej. Logika szyfrowania została napisana w języku C++, a następnie skompilowana do WebAssembly za pomocą Emscripten.

## Technologie

- **C++** – implementacja algorytmu XOR oraz kodowanie Base64.
- **HTML** – struktura strony internetowej.
- **CSS** – wygląd i styl aplikacji.
- **JavaScript** – obsługa interfejsu i komunikacja z modułem WebAssembly.
- **WebAssembly (WASM)** – uruchamianie kodu C++ w przeglądarce.
- **Emscripten** – kompilacja C++ do WebAssembly.

## Funkcje

- Szyfrowanie wiadomości algorytmem XOR.
- Odszyfrowywanie wcześniej zaszyfrowanych wiadomości.
- Automatycznie ustawiony klucz szyfrujący.
- Kodowanie wyniku do formatu Base64.
- Kopiowanie wyniku do schowka.
- Czyszczenie pól tekstowych.

## Jak uruchomić projekt?

1. Pobierz lub sklonuj repozytorium.
2. Otwórz folder projektu.
3. Uruchom terminal w folderze projektu.
4. Wpisz polecenie:

```bash
python -m http.server 8000
```

5. Otwórz przeglądarkę i przejdź pod adres:

```text
http://localhost:8000
```

## Struktura projektu

```text
Szyfrowanie_XOR/
│
├── main.cpp
├── index.html
├── style.css
├── app.js
├── xor_module.js
├── xor_module.wasm
└── README.md
```

## Zasada działania

Algorytm XOR wykonuje operację logiczną XOR na kolejnych bajtach wiadomości i klucza szyfrującego.

Do odszyfrowania wiadomości wykorzystywany jest ten sam klucz, ponieważ operacja XOR jest odwracalna.

Wynik szyfrowania jest dodatkowo kodowany w Base64, aby można go było wygodnie wyświetlić i skopiować.

## Informacja

Projekt ma charakter edukacyjny i służy do demonstracji działania algorytmu XOR oraz technologii WebAssembly. Nie należy używać go do ochrony poufnych danych.

---

**Autor:** Wiktor

**Projekt:** Szyfrowanie XOR
