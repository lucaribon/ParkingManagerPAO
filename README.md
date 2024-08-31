# Parking Manager PAO
## Model
- [x] creare classe astratta sensore
- [x] creare classi concrete sensori
- [x] creare classe astratta sensoreAria
- [x] creare classi concrete sensoriQualita-Gas
- [x] implementare metodi specifici per sensori
  - [ ] generazione dati per simulazione statica nei sensori concreti
  - [x] getAirStatus per sensoreAria
- [x] sensore posto auto occupato ~~con tre stati: libero, in attesa, occupato~~
- [x] gestire correlazione: sensore presenza -> posto auto
  - [ ] ~~aggiunta dei sensori di parcheggio a zone (tot di posti ogni zona) -> aggiungere a destra nella~~
  - [x] possibilità di aggiungere, rimuovere zone (attributo area negli oggetti)

## Controller
- [ ] vettore di sensori
- [ ] passaggio dati view<->model (gestione dei sensori)
- [ ] gestione json (salvataggio, apertura, creazione)
- [ ] ricerca (chiamata a funzione di ricerca nel model)
- [ ] autosave json (non necessario)

## View
### Creazione sensori
- [ ] pannello con form per inserimento e modifica dei sensori
- [ ] quando si clicka in un area vengono visualizzati solo i sensori per quell'area (forse anche con multiselezione delle aree)
### Report
- [ ] tabella log, tipo lista (dati json)
### Grafici
- [ ] grafico giornaliero presenze
- [ ] qualità aria
- [ ] temperatura
### Dashboard
- [ ] dati su presenza, temperatura ecc..
- [ ] parcheggio si popola in base ai sensori di presenza
  - [ ] ~~oppure layout preimpostati?~~
  - [ ] creiamo noi dei json di esempio da poter caricare
- [ ] ricerca case insensitive
 
### Extra
- [ ] (model) variare qualità, temperatura in base al numero di macchine
