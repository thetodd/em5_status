# Status Plugin f�r Emergency 5

Dieses Plugin erweitert Fahrzeuge um eine Statuskomponente und ein neues GUI
um die Fahrzeugstatus zu setzen. Das GUI wird automatisch aufgerufen, wenn ein
Fahrzeug mit Statuskomponente ausgew�hlt wird.

## Installieren

Zuerst muss das Repository auf den eigenen Rechner geklont werden.

```
git clone https://github.com/thetodd/em5_status.git
```

Nun muss noch die Datei **sdk_directories.props** angepasst werden. Dazu einfach im
Ordner **build/visual_studio_property_sheets** die Datei **sdk_directories.props.example**
umbenennen und das *.example* aus dem Dateinamen entfernen.

Danach die Datei mit einem Texteditor �ffnen und die Pfade an die eigene
Entwicklungsumgebung anpassen.

Danach kann das Projekt in Visual Studio ge�ffnet und erstellt werden.

�ber den World Builder kann Fahrzeugen die neue Komponente "flo11::StatusComponent"
hinzugef�gt werden.

Der initiale Status kann dann unter den Object Properties ge�ndert werden.

## Elemente
|Name|Typ|Beschreibung|
|---|---|---|
|flo11::StatusComponent|Komponente|Beinhaltet Logik und Speicherung des aktuelen Status eines Fahrzeugs. Sollte den Fahrzeugen als neue Komponente hinzugef�gt werden.|
|flo11::MoveWithStatusCommand|Command|MoveCommand mit Logik, dass Fahrzeuge sich nur in bestimmten Status bewegen k�nnen. Der Command ist deaktiv in Status 4 und 6.|

## Mitwirken

Solltest Du Fehler beseitigt oder Verbesserungen am Code vorgenommen haben, bitten
wir dich diese �nderungen auch dem Rest der Community bereitzustellen. Mach dazu
doch ein Pull-Request auf den development-branch.