//
// Created by Mikołaj on 11.06.2021.
//

#include "introducing.hpp"

namespace introducing {

    auto introduce_program() -> void {
        std::cout << "PJAText2 - s22472\n";
        std::cout
                << "Program ten sluzy do roznych operacji na zawartosciach plikow tekstowych zapisanych w formacie ANSI.\n";
        std::cout << "Bazujac na przekazanych flagach (argumentach wywolania) aplikacja produkuje odpowiedni tekst.\n";
        std::cout
                << "Flaga to tekst rozpoczynajacy sie od myslnika i skrotu operacji, lub dwoch myslnikow i pelnej nazwy"
                   " tej operacji\n";
        std::cout << "Lista dostepnych flag:\n";
        std::cout << "-f / --file: oczekuje, ze nastepnym argumentem bedzie sciezka do pliku zrodlowego\n";
        std::cout << "-n / --newlines: wyswietla liczbe linii z pliku zrodlowego\n";
        std::cout << "-d / --digits: wyswietla liczbe cyfr z pliku zrodlowego\n";
        std::cout << "-dd / --numbers: wyswietla liczbe liczb z pliku zrodlowego\n";
        std::cout << "-c / --chars: wyswietla liczbe znakow z pliku zrodlowego\n";
        std::cout << "-w / --words: wyswietla liczbe slow z pliku zrodlowego\n";
        std::cout << "-s / --sorted: wyswietla wszystkie slowa z pliku zrodlowego w kolejnosci alfabetycznej\n";
        std::cout << "-rs / --reverse-sorted: wyswietla wszystkie slowa z pliku zrodlowego w kolejnosci odwrotnej do"
                     " alfabetycznej\n";
        std::cout << "-l / --by-length: modyfikuje dzialanie nastepujacej po niej flagi -s/-rs tak, ze flaga ta bierze"
                     " teraz pod uwage dlugosc slow, a nie ich alfabetyczna kolejnosc\n";
        std::cout << "-a / --anagrams: winno byc ostatnia sprecyzowana flaga."
                     " Wyswietla wszyskie slowa z pliku zrodlowego, ktore sa anagramami slow zapisanych po fladze -a\n";
        std::cout << "-p / --palindromes: winno byc ostatnia sprecyzowana flaga."
                     " Wyswietla wszystkie podane po sobie slowa, ktore sa palindromami i wystepuja w pliku zrodlowym\n";
        std::cout << "-o / --output: oczekuje, ze nastepnym argumentem bedzie sciezka do pliku."
                     " Przekierowuje caly output do tego pliku.\n";
        std::cout << "-i / --input: oczekuje, ze nastepnym argumentem bedzie sciezka do pliku wejsciowego."
                     " Winna byc jedyna sprecyzowana flaga, poniewaz to dzieki niej z pliku beda pobierane flagi i dane ich"
                     " dotyczace.\n";
    }
}
