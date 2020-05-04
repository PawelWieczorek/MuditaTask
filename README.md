# MuditaTask

Program 1 and Program 2 for Mudita

All rights reserved


The content of the task:
"Zadanie 1

Zadanie polega na napisaniu 2 programów, w dalszej treści nazywanych odpowiednio program 1 i program 2. Program 1 jest źródłem komend opisujących obraz, program 2 jest odpowiedzialny za przetwarzanie otrzymanych od programu 1 komend i przygotowanie na ich bazie obrazu. Obraz ten ten ma być następnie zapisany do pliku.

Programy powinny być przygotowane wg poniższych wymagań:
Język programowania - C/C++
Programy muszą kompilować się na Linuksie a wszelkie niestandardowe biblioteki powinny być załączone z rozwiązaniem.
Program 1 uruchamia program 2,
Program 1 umożliwia wprowadzanie poleceń:
z klawiatury, zatwierdzanych naciśnięciem ENTER,
z pliku jako parametru podanego przy uruchamianiu programu 1
Program 1 przesyła polecenia do programu 2 w dowolny sposób z wyłączeniem gniazd (socketów),
Program 2 odbiera i analizuje polecenia. Jeżeli polecenie zostanie rozpoznane poprawnie program 2 je realizuje, w przeciwnym wypadku odsyła do programu 1 komunikat o błędzie.
Program 1 zapisuje do pliku log.txt niepoprawne komendy otrzymane od programu 2. 
Programy realizują następujący minimalny zestaw komend:
SET_WIDTH W - komenda określa szerokość ekranu w pikselach, W jest liczbą całkowitą określającą ilość pikseli.
SET_HEIGHT H - komenda określa wysokość ekranu w pikselach, H jest liczbą całkowitą określającą ilość pikseli.
DRAW_RECTANGLE X,Y,W,H - komenda służy do rysowania prostokąta, którego lewy górny róg ma współrzędne X,Y a W i H oznaczają odpowiednio szerokość i wysokość prostokąta.
DRAW_TRIANGLE X1,Y1,X2,Y2,X3,Y3 - komenda służy do rysowania trójkąta którego rogi mają współrzędne poziome i pionowe odpowiednio w punktach (X1,Y1), (X2,Y2) oraz (X3,Y3).
RENDER NAME - przygotowuje obraz oraz zapisuje go do pliku w wybranym formacie graficznym (BMP, PNG, JPEG) pod nazwą określoną parametrem “NAME”.

Wymagane artefakty:
źródła obu programów,
plik testowy z komendami,
skrypt budujący make lub cmake,"
