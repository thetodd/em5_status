## Status Plugin für Emergency 5

Dieses Plugin erweitert Fahrzeuge um eine Statuskomponente und ein neues GUI
um die Fahrzeugstatus zu setzen. Das GUI wird automatisch aufgerufen, wenn ein
Fahrzeug mit Statuskomponente ausgewählt wird.

## Installieren

Zuerst muss das Repository auf den eigenen Rechner geklont werden.

```
git clone https://github.com/thetodd/em5_status.git
```

Nun muss noch die datei sdk_directories.props angepasst werden. Dazu einfach im
Ordner **build/visual_studio_property_sheets** die Datei **sdk_directories.props.example**
umbenennen und das *.example* aus dem Dateinamen entfernen.

Danach die Datei mit einem Texteditor öffnen und die Pfade an die eigene
Entwicklungsumgebung anpassen.

Danach kann das Projekt in Visual Studio geöffnet und erstellt werden.

Über den World Editor kann Fahrzeugen die neue Komponente "flo11::StatusComponent"
hinzugefügt werden.

Der initiale Status kann dann unter den Object Properties geändert werden.

## Mitwirken

Solltest Du Fehler beseitigt oder Verbesserungen am Code vorgenommen haben, bitten
wir dich diese Änderungen auch dem Rest der Community bereitzustellen. Mach dazu
doch ein Pull-Request auf den development-branch.