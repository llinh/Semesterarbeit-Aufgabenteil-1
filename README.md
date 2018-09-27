# Semesterarbeit-Aufgabenteil-1
Aufgabenteil 1: BeschreibungTeil 1 ist von Ihnen nur dann zu bearbeiten, wenn Sie die Semesterarbeit für C++ 1 zuvor nicht erfolgreich bearbeitet haben.

Ziel des Aufgabenteils ist die Programmierung eines Command Line Interfaces (CLI). Das Programm soll Informationen aus zwei unterschiedlichen Datenquellen (1) auslesen,  (2) zwischenspeichern, (3) durchsuchen und anschließend (3) in ein neues Format überführen können. Eine der Datenquellen muss eine XML-Datei (mit zugehöriger DTD) sein. Das neue Format muss ebenfalls vom Typ XML sein und die Daten der Ursprungsdateien sinnvoll zusammenführen.

Inhaltlich können Sie sich frei bewegen: Es bleibt Ihnen / Ihrer Gruppe überlassen, ob Sie Personendaten und Geburtstage, Produktinformationen und Lagerbestände oder beliebige andere Informationen verarbeiten wollen. Die Semesterarbeit kann in 4 Stufen erfüllt werden. Sie können die in den Vorlesungsfolien beschriebenen Token– und Attributklassen anwenden, wenn Sie möchten. (Vgl.: http://hki.uni-koeln.de/cpp-ws1718-task/)

Hinweis: Grundsätzlich soll nach Möglichkeit ein objektorientiertes Programm umgesetzt werden. Es empfiehlt sich, dass Sie das Projekt vor seiner Implementierung planen.

Stufe I – Basisaufgabe1. Entwerfen und beschreiben Sie einen konkreten Anwendungsfall für Ihr Programm. Die Ergebnisse sollten aus dem README.md file in GitHub ersichtlich und nachvollziehbar sein.

2. Legen Sie zwei unterschiedliche Datenquellen an. Eine Datenquelle muss eine XML-Instanz mit Dokumenttypdefinition (DTD) sein, die andere ein CSV-Format (Legen Sie die Datenquellen mit Blick auf Stufe IV an! ).

3. Die Komplexität Ihrer Datensätze darf die der Beispiele des vergangenen Jahres nicht unterschreiten: http://hki.uni-koeln.de/cpp-ws1718-task/

Hinweis: Wenn Sie auf Schwierigkeiten mit Ihren XML-Instanzen stoßen, kann sich ein Blick in Ihre BSI-Unterlagen aus dem 1. Semester lohnen.

4. Lesen Sie die Daten mit Hilfe eines Parsers ein und ermöglichen Sie folgende Operationen:

4.1 Menüführung: Ein Menü startet verschiedene Abläufe im Programm und kehrt danach ins Menü zurück.

4.2 Konvertieren: Das Programm fragt nach Name und Pfad der Ausgabe und exportiert die Informationen aus beiden Datensätzen in einer neuen, vereinten XML Instanz, welche Sie inkl. DTD definieren.

Stufe IIDie Basisaufgabe wird erfüllt. Zusätzlich ermöglicht das Programm:

1. Alle (vereinten) Datensätze auszugeben (d.h. darzustellen). Alle Datensätze haben dabei eine Nr. / ID.

2. Neue Datensätze anzulegen. Die ID wird durch das Programm vergeben und darf nicht doppelt vorkommen.

3. Datensätze zu löschen. Die geschieht per Angabe der Nr. / ID.

Stufe IIIStufe II wird erfüllt. Zusätzlich bietet das Programm die Möglichkeit, alle (vereinten) Datensätze sinnvoll anhand von 2 Kriterien zu durchsuchen. Dies könnte z.B. ein Name oder ein numerischer Wert sein, der als Eigenschaft des Datensatzes vorliegt. Die Suche gibt eine Liste aller Treffer aus. Erläutern Sie die Funktionalität der Suche bei der Einreichung kurz.

Stufe IVStufe III wird erfüllt. Außerdem wird das Programm um folgende Operationen ergänzt:

1. Erweitern Sie die Software um eine Berechnung über mehrere Datensätze hinweg (z.B. Anzahl oder Werte addieren).

2. Ermöglichen Sie einen Export der berechneten Daten.

3. Erweitern Sie Ihr CLI um eine Prüfung der gegebenen XML-Instanz anhand Ihrer DTD.
