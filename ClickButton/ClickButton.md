# Czym jest Qt?

Qt to znacznie więcej niż tylko wieloplatformowy pakiet SDK - to strategia technologiczna, która pozwala szybko i ekonomicznie projektować, rozwijać, wdrażać i utrzymywać oprogramowanie, zapewniając jednocześnie bezproblemową obsługę wszystkich urządzeń - tak piszą o Qt jego twórcy.

# Wybór Qt?

## Powód pierwszy: 

- Qt daje nieograniczone możliwości do budowy cross-platformowych aplikacji, interfejsów graficznych lub paneli operatorskich. 
- Raz napisaną aplikację mogę bez większych problemów zbudować na Windowsie, Linuksie, na urządzeniu z Androidem lub iOS.

Prawdziwe jest więc stwierdzenie ze strony Qt: Code less, create more, deploy everywhere.

## Powód drugi: 
Qt w wersji Open Source jest darmowe! Qt wydane jest na kilku licencjach w tym: LGPL3, GPL2 i GPLv3. Szczególnie interesująca jest ta pierwsza, ponieważ pozwala nam na zamknięcie źródła naszego oprogramowania, bez konieczności zakupu komercyjnej licencji. Czyli, możemy na tym zarabiać i jednocześnie chronić naszą pracę (oczywiście jeśli działamy zgodnie z warunkami licencji).

# Nowy projekt

1. Nowy plik lub projekt --> aplikacja Qt Widgets
2. Ścieżka projektu nie może zawierać spacji (Android)
3. Wybór zestawu narzędzi --> Platforma np. Desktop
4. Nazwanie domyślnej głównej klasy np. MainWindow. Będzie to główna klasa, która zajmuje się obsługą interfejsu graficznego aplikacji. Do niej można też dołączać nasze własne klasy lub klasy Qt.
5. Edytor graficzny --> drzewo projektu: 
  -  plik z rozszerzeniem .pro, jest to plik, który zawiera konfigurację projektu - są w nim informacje dla specjalnego preprocesora Qt (nie edytujemy tego pliku bez potrzeby, jedynie można dodawać specjalne moduły Qt). 
  -  pliki z popularnymi rozszerzeniami .h i .cpp (definicje i implementacje programu),
  -  pliki z rozszerzeniem .ui. - są to pliki, które korzystają z formatu XML i zawierają informacje o elementach (i ich właściwościach) interfejsu graficznego (nie edytuje się ręcznie, edytuje się go jedynie w trybie Design).

# Tworzenie interfejsu aplikacji w Qt

1. Tryb Design uruchamia się domyślnie, gdy klikniemy 2x na plik mainwindow.ui. Tworzenie interfejsu jest bardzo intuicyjne i proste, polega na przeciąganiu elementów interfejsu (widgetów) z listy po lewej i upuszczaniu ich na obszar głównego widgetu (centralWidget) aplikacji.
2. Hierarchię obiektów (elementy i ich zależności) interfejsu znajdziemy w miejscu zaznaczonym na żółto. Ostatnia część okna, zaznaczona na niebiesko, pozwala na sprawdzenie właściwości elementu, który jest aktualnie wybrany.
3. Edycję interfejsu zaczynamy od usunięcia menuBar, mainToolBar i statusBar (nie używane).
4. Dodanie do interfejsu przycisk – przeciągnięcie elementu Push Button. Dwukrotne kliknięcie w obszar nazwy przycisku spowoduje pojawienie się kursora edycji tekstu, zmieńmy nazwę przycisku z PushButton na Zamknij.
5. Wprowadzenie siatki - klikamy element centralWidget w Hierarchii obiektów (albo wybieramy go klikając w obszar naszej aplikacji). Następnie z menu wybieramy przycisk Rozmieść w siatce.
6. Siatka zapewni skalowanie okna aplikacji bez przemieszczania się elementów interfejsu. Jest to przydatne, gdy chcemy, aby interfejs wyglądał tak samo na różnych wyświetlaczach.
7. Spacery - odpowiadają one za wolne miejsce na naszym interfejsie. 
8. Dobrą praktyką jest nazywanie obiektów w usystematyzowany sposób, w ten sposób, że zostawiam człon pushButton (żeby podczas pisania kodu szybko znaleźć interesujący mnie element) i dodaje do jego nazwy, słowny opis jego funkcji (mój przycisk będzie zamykał aplikację) więc dodaję człon Close, uzyskując w ten sposób nazwę pushButtonClose - będzie to ID przycisku, którym będziemy się posługiwać w kodzie. Sposób nazwy obiektu został przedstawiony na powyższym zrzucie.
9. Zbudowanie aplikacji i jej uruchomienie: Ctrl + R lub wybierzemy odpowiedni przycisk.
10. Rozpocznie to etap kompilacji, a po jej zakończeniu uruchomi się aplikacja. 
11. Spróbuj teraz powiększyć okno aplikacji! Co się dzieje z pozycją przycisku Zamknij, czy jego pozycja względem prawego dolnego rogu aplikacji ulega zmianie? Następnie wyłącz rozmieszczanie w siatce (przycisk obok Rozmieszczania w siatce) i znowu uruchom aplikację, sprawdź czy wtedy aplikacja skaluje się poprawnie. Po testach, przywróć umieszczanie w siatce.

# Sygnały i sloty - podłączanie przycisków

Mechanizm sygnałów i slotów jest jedną z funkcjonalności Qt, która wyróżnia je na tle podobnych projektów. Mechanizm ten pozwala na komunikację między różnymi obiektami bibliotek Qt, przy tym jest intuicyjny i prosty w użyciu. Ogólna zasada działania tego mechanizmu polega na wysyłaniu sygnału (na jakieś zdarzenie), który powoduje wykonanie zdefiniowanych w slocie akcji.

## Pierwszy sposób wykorzystania mechanizmu sygnałów i slotów

Pierwszy sposób możemy zastosować dla sygnałów i slotów zdefiniowanych dla elementów interfejsu Qt.

1. W trybie Design należy kliknąć w przycisk Modyfikuj sygnały (włączenie nowego, interaktywnego trybu łączenia sygnałów ze slotami). Musimy najechać kursorem na przycisk Zamknij, nacisnąć lewy przycisk myszy i przeciągnąć kursor w stronę obszaru aplikacji.
2. Wybieramy sygnał clicked(), zaznaczamy checkbox "Pokaż sygnały i sloty klasy Qwidget", a następnie wybieramy slot close(). Klikamy OK (połączono sygnał kliknięcia przycisku ze slotem zamknięcia aplikacji).

## Drugi sposób wykorzystania mechanizmu sygnałów i slotów

Drugi sposób możemy zastosować dla sygnałów i slotów zdefiniowanych dla elementów interfejsu Qt, przy czym możemy zdefiniować własne akcje (w slocie). 

1. Stworzenie kolejnego przycisku, nazwanego OK, następnie kliknij na niego prawym przyciskiem myszy i wybierz opcję "Przejdź do slotu...".
2. Następnie spośród listy slotów wybierz clicked().
3. Czynność ta przeniesie nas do implementacji wybranego slotu – plik mainwindow.cpp. W tym miejscu musimy umieścić akcje, które mają się wykonać po wciśnięciu przycisku OK. Zatem do dzieła: pomiędzy klamrami wpisz następującą linijkę kodu:

qDebug() << "Wcisnąłeś przycisk OK";

2. Następnie (u góry pliku mainwindow.cpp) zaimportuj klasę QDebug:

#include <QDebug>

Kod mainwindow.cpp:

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButtonOK_clicked()
{
	qDebug() << "Wcisnąłeś przycisk OK";
}
  
Klasa QDebug zapewnia strumień wyjściowy do debugowania. W naszej implementacji wciśnięcie przycisku spowoduje wyświetlenie w zakładce Komunikaty Aplikacji tekstu: "Wcisnąłeś przycisk OK".

Uruchom aplikację (tak jak poprzednio) i naciśnij przycisk OK, analizując wyjście strumienia w zakładce Komunikaty aplikacji, wynik powinien być następujący:

Zwróć uwagę jak nazywa się metoda tego slotu:

void MainWindow::on_pushButtonOK_clicked()

Możemy to rozumieć w ten sposób: na sygnał clicked() z obiektu pushButtonOK wykonuj akcje z ciała tej metody. Zauważ, że nazwa zawiera nazwę obiektu emitującego sygnał i nazwę sygnału. Jak pewnie się domyślasz, zdefiniowane sygnały i sloty można używać ręcznie przez zdefiniowanie nowych metod w klasie MainWindow. Jedyne co musisz zrobić to sprawdzić jakie sygnały i sloty posiadają dane obiekty (np. w Qt Creatorze jak poprzednio przy wyborze sygnałów/slotów lub w dokumentacji klas Qt) i na tej podstawie stworzyć nową metodę klasy MainWindow.

Przykładowo w pliku mainwindow.h pod klasyfikatorem private slots można dodać:

void on_pushButtonOK_pressed();

A w pliku mainwindow.cpp stworzyć odpowiednią implementację:

void MainWindow::on_pushButtonOK_pressed() {
  qDebug() << "pressed";
  //...
}

## Trzeci sposób wykorzystania mechanizmu sygnałów i slotów

Trzeci sposób pozwala nam na wykorzystanie naszych sygnałów i slotów. Własne sygnały zdefiniujemy w późniejszych częściach tej serii, na tą chwilę zajmiemy się stworzeniem własnego slotu.

Dodaj kolejny przycisk i nazwij go Test, a nazwę tego obiektu zmień na pushButtonTest. Następnie w pliku mainwindow.h dodaj pod klasyfikatorem private slots linijkę:

void myCustomSlot();

Powinno to wyglądać mniej więcej w ten sposób:

Następnie stwórz implementację tego slotu w pliku mainwindow.cpp:

void MainWindow::myCustomSlot() {
  qDebug() << "Wcisnales przycisk Test i wykorzystałeś mechanizm sygnałów i slotów";
}

Pozostaje jeszcze jedna czynność, którą wcześniej robiło za nas środowisko, czyli faktycznie łączenie sygnałów ze slotami. W konstruktorze MainWindow należy użyć metody klasy QObject - connect(). Klasa QObject jest klasą bazową dla wszystkich klas Qt (na razie, ta informacja nam wystarczy). A zatem, w konstruktorze dodajemy linijkę:


connect(ui->pushButtonTest, SIGNAL(clicked()), this, SLOT(myCustomSlot()));

Metoda connect dokonuje fizycznego połączenia sygnału clicked() dodanego przycisku z naszym slotem myCustomSlot().

Składnia metody connect jest następująca:

connect(nadawca, sygnał, odbiorca, slot);

W naszym przypadku

- nadawcą jest: ui−>pushButtonTest, poprzez ui (który defacto jest wskaźnikiem na klasę, która zawiera implementację naszych elementów interfejsu) możemy odnosić się do elementów naszego interfejsu. ui−>pushButtonTest jest niczym innym jak wskaźnikiem na obiekt pushButtonTest. Co więcej, metoda connect oczekuje w miejscu argumentu nadawcy, właśnie wskaźnika na obiekt, który ma emitować sygnał,
- sygnałem jest: sygnał clicked() przycisku pushButtonTest i przekazujemy go w argumencie za pomocą makra SIGNAL,
- odbiorcą jest: nasza główna klasa MainWindow – to w niej zdefiniowaliśmy nasz slot, przesyłamy ją do metody connect za pomocą wskaźnika this,
- slotem jest: nasz zdefiniowany slot myCustomSlot, przekazujemy go za pomocą makra SLOT.

Ostatecznie implementacja mainwindow.cpp:

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->pushButtonTest, SIGNAL(clicked()), this, SLOT(myCustomSlot()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButtonOK_clicked()
{
	qDebug() << "Wcisnałes przycisk OK";
}

void MainWindow::myCustomSlot()
{
	qDebug() << "Wcisnales przycisk Test i wykorzystales mechanizm sygnalow i slotow";
}

Uruchom program i przetestuj go, wynik powinien być następujący:

Ostatnią ciekawą rzeczą jest wykorzystanie wartości zwracanej przez metodę connect. W tym celu zmień nieco poprzedni kod, zamień:

connect(ui->pushButtonTest, SIGNAL(clicked()), this, SLOT(myCustomSlot()));

na:

qDebug() << "Connect się powiódł?" << connect(ui->pushButtonTest, SIGNAL(clicked()), this, SLOT(myCustomSlot()));

Wynik tej zamiany powinien być następujący:

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	qDebug() << "Connect sie powiodl?" << connect(ui->pushButtonTest, SIGNAL(clicked()), this, SLOT(myCustomSlot()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButtonOK_clicked()
{
	qDebug() << "Wcisnałes przycisk OK";
}

void MainWindow::myCustomSlot()
{
	qDebug() << "Wcisnales przycisk Test i wykorzystales mechanizm sygnalow i slotow";
}

Jest to bardzo przydatny zabieg zwłaszcza wtedy, kiedy tworzymy swoje sygnały oraz sloty i zaczynamy łączyć je między różnymi klasami. Czasem nasza próba połączenia sygnału i slotu może się nie powieść. Wtedy ten zabieg oszczędzi nam bardzo dużo czasu podczas szukania błędów, które sprawiają, że nasz program nie działa tak jak chcemy, a także oszczędzi nam czasu na analizowaniu potencjalnych problemów (które, nie zawsze są powodem tego błędu).

# Materiały dodatkowe

Ddokumentacja

## Poradniki

Bardzo dobre poradniki robi Bryan Cairns, który publikuje swoje filmy na You Tube (zwłaszcza pierwsze 20 odcinków).

## Książki

- C++ i Qt. Wprowadzenie do wzorców projektowych, Alan Ezust, Paul Ezust (zawiera dużo informacji o podstawach C++ i wykorzystaniu go w połączeniu z Qt)
- Biblioteki Qt. Zaawansowane programowanie przy użyciu C++, Mark Summerfield (polecane dla bardziej zaawansowanych)
