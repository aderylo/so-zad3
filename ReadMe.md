## Patch 

patch znajduje się w pliku ad432952.patch




## Usage 

Skrypt sync.sh kopiuje zmienione pliki na MINIX-a.

Na MINIX-ie należy zainstalować rsync:
  pkgin in rsync

Skrypt zakłada, że na MINIX-a można ssh-ować się poleceniem:
  ssh minix
W innym przypadku należy odpowiednio zmodyfikować polecenia w skrypcie.


Załączone źródła MINIX-a są kopią plików z naszego obrazu (ścieżka /usr/...).
