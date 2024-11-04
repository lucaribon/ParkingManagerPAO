# Parking Manager PAO
Progetto del corso di Programmazione ad Oggetti (PAO), UniPD 2023/24.

# TODO

## Model
- [x] creare classe astratta sensore
- [x] creare classi concrete sensori
- [x] creare classe astratta sensoreAria
- [x] creare classi concrete sensoriQualita-Gas
- [x] implementare metodi specifici per sensori
  - [x] generazione dati per simulazione statica nei sensori concreti
  - [x] getAirStatus per sensoreAria
- [x] sensore posto auto occupato ~~con tre stati: libero, in attesa, occupato~~
- [x] gestire correlazione: sensore presenza -> posto auto
  - [x] ~~aggiunta dei sensori di parcheggio a zone (tot di posti ogni zona) -> aggiungere a destra nella~~
  - [x] possibilità di aggiungere, rimuovere zone (attributo area negli oggetti)

## Controller
- [x] vettore di sensori
- [x] passaggio dati view<->model (gestione dei sensori)
- [x] gestione json (salvataggio, apertura, creazione)
- [x] ricerca (chiamata a funzione di ricerca nel model)
- [ ] autosave json (non necessario)

## View
### Creazione sensori
- [x] pannello con form per inserimento e modifica dei sensori
- [x] quando si clicka in un area vengono visualizzati solo i sensori per quell'area (forse anche con multiselezione delle aree)
### Report
- [ ] tabella log, tipo lista (dati json)
### Grafici
- [ ] grafico giornaliero presenze
- [x] qualità aria
- [x] temperatura
### Dashboard
- [x] dati su presenza, temperatura ecc..
- [ ] parcheggio si popola in base ai sensori di presenza
  - [ ] ~~oppure layout preimpostati?~~
  - [ ] creiamo noi dei json di esempio da poter caricare
- [ ] ricerca case insensitive
 
### Extra
- [ ] (model) variare qualità, temperatura in base al numero di macchine
