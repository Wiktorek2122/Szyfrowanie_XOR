
let modul;

const klucz = "XOR123";

createXorModule().then(function(m) {
    modul = m;
    document.getElementById("status").innerText;
}).catch(function(error) {
    document.getElementById("status").innerText ;
    console.error(error);
});

function szyfruj() {
    if (!modul) return;

    let tekst = document.getElementById("tekst").value;

    try {
        let wynik = modul.encryptText(tekst, klucz);
        document.getElementById("wynik").value = wynik;
        document.getElementById("status").innerText ;
    } catch (e) {
        alert(e);
    }
}

function odszyfruj() {
    if (!modul) return;

    let tekst = document.getElementById("tekst").value;

    try {
        let wynik = modul.decryptText(tekst, klucz);
        document.getElementById("wynik").value = wynik;
        document.getElementById("status").innerText;
    } catch (e) {
        alert(e);
    }
}

function wyczysc() {
    document.getElementById("tekst").value = "";
    document.getElementById("wynik").value = "";
    document.getElementById("status").innerText ;
}

function kopiuj() {
    let wynik = document.getElementById("wynik").value;

    navigator.clipboard.writeText(wynik);
}
