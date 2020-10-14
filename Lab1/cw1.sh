#!/bin/bash

# (2p.) Wykorzystaj 'date' do wyswietlania różnych komunikatów powitalnych w zależności czy aktualnie jest dzień roboczy czy świąteczny (dla uproszczenia: dzień tygodnia czy weekend).
# Uwaga: Porównywanie napisów wyświetlanych przez program 'date' (i inne programy) jest zależne od języka i lokalizacji. Sprawdź możliwość ustawienia zmiennych lokalizacji LC_* (np. LC_ALL=C) i ich wpływ na postać komunikatu. Która/które z nich sterują postacią wyświetlanej daty? Ustawiając tę zmienną w skrypcie na wartość C (lub POSIX), wymuszamy lokalizację kanoniczną, co ułatwia sprawdzanie wartśoci daty, i uniezależnia działanie skryptu od lokalizacji (będzie on poprawnie sprawdzał warunek również np. w Japonii).

[ "$(date +%u)" -gt 5 ] && echo "WEEKEND" || echo "NIE WEEKEND :("
