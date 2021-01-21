# 42_Get_Next_Line
GNL lit un fichier fd, ligne par ligne, ce programme utilise de nombreux "malloc" sans leak et une variable statique

Correction avec <a href="https://github.com/Mazoise/42TESTERS-GNL.git">GNLKiller</a> ou <a href="https://github.com/charMstr/GNL_lover">GNLLover</a>.   

## TESTER LES LEAKS : 

Faire une boucle infini dans le main 

While(1){} 

gcc main + tous les fichiers .c .h puis ./a.out + le text

A cote taper :  

Ou dans main : system(“leaks a.out”) 

Ou utiliser VALGRIND 

-> valgrind ./a.out nomdefichier (--leak-check=full --leak-kinds=all)
