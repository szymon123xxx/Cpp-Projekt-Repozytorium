# C++-Projekt-Repozytorium

Gra zręcznościowa w której będziemy sterować obiektem za pomocą WASD.
Widok gry będzie w formacie 2D. 
Gra będzie polegała na zebraniu jak największej ilości celów. 
Podczas rozgrywki będą losowo rozmieszczane obiekty takie jak "przeciwnik" które będa się poruszały oraz "punkty" które gracz bedzie miał za zadanie zebrać.
Będzie wprowadzona interakcja gracza z krawędziami planszy, gracz-przeszkoda oraz gracz-punkty.
Wraz z odpowiednią ilością punktów zbieranie celów będzie utrudniane.
Gracz będzie posiadał określoną liczbe żyć.
Na dodatek wraz z zwiększeniem ilości punktów będzie zmniejszany czas na zebranie celu oraz zostanie wprowadzona możliwość podglądu ilości zebranych punktów z ostatnich prób.
Technologia użyta do tego projektu to C++ wraz z biblioteką sfml

Do zrobienia:

-okno gry JEST

-model postaci ( tekstury , poruszanie się postacią ) JEST

-model celów  ( tekstury , randomowe rozmieszczanie ) JEST

-model przeszkód ( tekstury, randomowe rozmieszczanie, poruszanie sie po wyznaczonej trajektori(nie ma) )  JEST

-interakcja gracz-przeszkoda JEST

-interakcja gracz-cel JEST

-interakcja gracz krawędzie JEST

-ilość żyć JEST

-stworzenie menu JEST

-statystyki ostatnich gier 

-możliwość wyboru muzyki  JEST

-czas na zebranie celu JEST

 # Raport I
 Do tej pory utworzyłem okno gry oraz dodałem postać wraz z teksturami i możliwością poruszania się. Do następnego raportu planuję zrobić model celów oraz iterakcje gracz-przeszkoda, gracz-cel, gracz-krawędzie.
![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/poczatek.png)

 # Raport II
 Do tej pory utowrzyłem model celów, przeszkód oraz dodałem background planszy. Między postać-cel, a zarówno przeszkody-cel zostały dodane interakcje po których cel zmienia swoje położenie oraz interakcje postci z krawędziami planszy. 
 Do następnego raportu planuje zrobić menu w którym będą znajdowały się 3 poziomy trudności , licznik zdobytych punktów oraz wstępnie odtwarzanie melodi podczas gry. 
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport_2.png)
 
 # Raport III
 Do tej pory utowrzyłem menu w którym mamy możliwość wyboru poziomów. Każdy poziom różni się ilością wygenerowanych przeszkód. Współrzędne generowane są za każdym razme losowo z zadanego przedziału. Wprowadziłem także licznik punktów. Niestety muzyki nie wprowadziłem bo wyżej wymienione rzeczy okazały się bardzo czasochłonne. Do następnego raportu mam zamiar zrobic metode obsługującą zderzenia postaci z przeszkodami oraz odtwarzanie muzyki w tle. Na dodatek mam zamiar dodać licznik czasu na zebranie celu, ilość żyć oraz utrudnienie poziomów poprzez zwiększenie prędkości na poszczególnych levelach.
 
 Menu
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport3menu1.png)
 Menu z poziomami
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport3menu2.png)
 Poziom easy
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport3easy.png)
  Poziom medium
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport3medium.png)
  Poziom hard
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport3hard.png)
 
 # Raport IV
 Do tej pory utworzyłem menu z melodiami. Dodałem także zderzenia postaci z przeszkodami , licznik czasu na zebranie celu oraz ilość żyć postaci wraz z utrudnieniem poziomów poprzez zwiększenie prędkości postaci na poszczególnych levelach.
 
 
 Muzyka
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport4.png)
 Czas 
 ![image](https://github.com/szymon123xxx/Cpp-Projekt-Repozytorium/blob/main/zdj%C4%99cia/raport4_2.png)
