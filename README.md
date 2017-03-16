# Senso-qt-1
Qt  und Visual Studio
Diese Applikation demonstriert wie mit VS2105 und qt eine Windows Desktop Applikation aufgebaut wird. 
Um die gegeben Source zu compilieren muss installiert sein
1.) Visual Studio 2015 mit VCc++ installieren

2.) qt 5.6.0 (qt-opensource-windows-x86-msvc2015-5.6.0.exe) im Download Qt  5.6 for Windows VS 2015 836MB)

3.) Visual Studio Tools-->extension an updates --> online --> Qt5 Package (=Plugun für VS2105 um Prokekte mit Qt zu erzeugen)

3.1.) Plugin ezeugt den Menüeileisteineintrag qt5 
      qt5--> qt5 options --> im Menüfenster Button Add --> 
      
3.2.)      Version name: qt 5.6 und Pfad  ...z.B. ... qt560\qt56MSVC2015_x86 (Durch Browsing den Installationspfad von qt56 eintragen)

4.) neues Project unterstützt nun auch die qt Laufzeitumgebung für Windows

