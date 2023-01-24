# ExamenATM2019_Propunere

Pe orice hartă, indiferent de scară, pot fi măsurate anumite elemente definitorii ale spațiului, cum ar fi distanțele în linie dreaptă. După efectuarea unor măsurători direct pe hartă, un angajat a înregistrat datele măsurate în fișiere, în următorul format:
<numarator(km)>:<numitor(cm)>
<nr_masuratori>
<Oras1>-<Oras2>:<distanta(cm)>
	         . . .
<OrasX>-<OrasY>:<distanta(cm)>

1.	Fie fișierul masuratori1.txt (vezi exemplele de mai jos). Nicio linie din fișier nu conține spații între informațiile înregistrate.  Să se citească informațiile din fișier astfel încât să se poată calcula distanțele între orașe în km și să se afișeze pe ecran aceste informații sub forma <OrasX> - <OrasY> : <distanta(km)> . Distanța în kilometri se va calcula conform formulei D=d*n, unde d=distanța măsurată pe harta în cm, D=distanța pe teren în cm, n=numitorul scării hărții, iar distanța pe teren D este convertită apoi din cm în km. 
2.	Scrieți într-un fișier perechile de orașe și distanțele în km calculate la punctul anterior. Numele fișierului este transmis prin argumentele programului.  
3.	În fișierul masuratori2.txt (vezi exemplul de mai jos) ar trebui să fie înregistrate măsurătorile realizate pe altă hartă, cu o scară diferită, regăsită pe prima linie a fișierului. Pentru a putea fi comparate cele două hărți este necesar ca mai întâi să se verifice dacă punctele de măsurare (<OrasX> - <OrasY>) din primul fișier (masuratori1.txt) apar și în cel de-al doilea, chiar dacă nu sunt în aceeași ordine (liniile nu corespund) sau orașele sunt inversate. Realizați o funcție care să verifice această condiție și să afișeze la consolă un mesaj corespunzător.  Cele două fișiere date ca exemplu respectă condiția descrisă în acest subpunct.
4.	Dacă înregistrările din cele două fișiere permit compararea hărților (se respectă condiția verificată prin funcția de la subpunctul 2), apelați  o funcție de comparare a celor două hărți. Compararea se realizează ținând cont de distanța măsurată între aceleași orașe. Dacă pentru aceleași orașe raportul dintre  distanța înregistrată în primul fișier și  distanța înregistrată în cel de-al doilea fișier este egal cu inversul raportului dintre numitorul scării din primul fișier și numitorul scării din cel de-al doilea fișier, atunci măsurătorile corespund. Dacă toate măsurătorile corespund, se afișează mesajul „Cele două harți corespund”. În caz contrar, se afișează orașele și distanțele unde sunt neconcordanțe, alături de distanțele înregistrate, sub forma: <OrasX> - <OrasY>: <distanta_fisier1> <->  <distanta_fisier2>
5.	Implementați funcția void concat(char **filelist, int nof, char* outputfile) care să concateneze toate măsurătorile dintr-un șir de fișiere (filelist) de dimenisune nof, generând un fișier nou (outputfile), în care să se regăsească pe prima linie scara cea mai mică dintre toate scările citite la nivelul fiecărui fișier, pe cea de-a doua linie numărul total al măsurătorilor înregistrate în noul fișier, urmate de toate măsuratorile din toate fișierele, eliminând duplicatele și având distanțele calculate la scara stabilită pentru acest nou fișier. 
6.	???Implementați o funcție care să genereze o semnătură a unui fișier binar (hash) a cărei dimensiune în octeți să poată fi transmisă ca parametru al funcției, după următorul algoritm:
-	Împarte întreg conținutul fișierului în blocuri de câte L div (k-1) octeți, unde L reprezintă numărul total de octeți din fișier și k reprezintă dimensiunea valorii hash, primită ca parametru în funcție.Ultimul bloc este completat cu biți de 1 până la dimensiunea L div (k-1)
-	Pentru fiecare bloc obținut generează câte un octet al hash-ului, astfel: numărul de biți de 1 din bloc este shiftat la stânga cu i poziții, unde i reprezintă indexul blocului de octeți din cadrul fișierului. 

Exemple de fișiere:
 
masuratori1.txt
1:100000
4
Brasov-Sacele:3
Brasov-Rasnov:3.5
Codlea-Brasov:5
Cristian-Rasnov:1.5

masuratori2.txt
1:1000000
4
Rasnov-Brasov:0.35
Brasov-Sacele:3
Rasnov-Cristian:0.15
Codlea-Brasov:0.5
