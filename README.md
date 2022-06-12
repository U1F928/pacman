# Pacman
Implementujte klasickou hru Pacman proti počítači.

## Ovládání 
* Pohyb pomocí kláves h, j, k, l. Hra se ukončí klávesou Esc.

## Funkcionality
*  Dodržování základních pravidel, sbírání bonusů, míncí, třešniček, teleporty, atp.
*  Je implementováno několik druhů AI duchů. Hra musí umět zároveň zobrazovat různé duchy s různými AI. 
*  Zobrazování duchů s různou AI se pro přehlednost může lišit např. barvou nebo znakem.
*  Lze načítat mapy ze souboru 
*  Konfigurovatelná obtížnost hry ze souboru     
*  Škálovatelná obtížnost duchů 

## Využití polymorfismu
* Abstraktní třída GameEntity pokrývající všechny herní entity
* Abstraktní třída Interaction pokrývající všechny interakce mezi herními entitami

