# shell 01 Exercise 05

- Создайте файл "\?$*'KwaMe'*$?\" , содержащий только «42» и НИЧЕГО больше.

- Его имя будет:
```
"\?$*'MaRViN'*$?\"
```

- Пример:
```
$>ls -lRa *MaRV* | cat -e
-rw---xr-- 1 75355 32015 2 Oct 2 12:21 "\?$*'MaRViN'*$?\"$
$>
```
_________________________________________________________________________________
_________________________________________________________________________________
_________________________________________________________________________________



Создаем файл через программу `еcho` c помощью перенаправления потока вывода в файл вот так:
```
echo -e "42" | tr -d "\n" > '"\?$*'KwaMe'*$?\"'
```


или так:
```
echo -e "42" > '"\?$*'KwaMe'*$?\"'
```

_________________________________________________________________________________
_________________________________________________________________________________
_________________________________________________________________________________

Документация.

Google.com :)
