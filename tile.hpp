
// Implementierung der Klasse Tile und Variablen

class Tile {
    
  Rect *kachel = nullptr;
  Text *label = nullptr;
  char color;
  bool isOccupied = false;
  int rank;
  char file;

 // Farbe der Kacheln wird festgelegt
    
  public:
    
  void setColor(char color) {
    this->color = color;
  }
  
  char getColor() {
    return color;
  }
 
     // Feld bzw. Kacheln werden  eingefärbt  
  void mark() {
    kachel->setFill("#FEE3D7");    
  }
    
        
  void unmark() {
  if (this->getColor() == 'w' || this->getColor() == 'W') {
      kachel -> setFill("#A5A994");
    } else if (this->getColor() == 'b' || this->getColor() == 'B') {
      kachel -> setFill("#838767");
    }
  }
    
  
    //Ausgewähltes Feld wird hervorgehoben
    
    void highlight(int wait) {
    mark();
    AlgoViz::sleep(wait);
    unmark();  
  }
    
    // Set vund Get für belegte Felder
    
  void setOccupied(bool isOccupied) {
    this->isOccupied = isOccupied;
  }
    
  bool getOccupied() {
    return isOccupied;
  }
    
  void setRank(int rank) {
    this->rank = rank;
  }
  
  char getRank() {
    return rank;
  }
    
  void setFile(char file) {
    this->file = file;
  }
  
  char getFile() {
    return file;
  }
    
 //Ein-Ausblenden der Labels   
    
  void hideLabel() {
    this->label->hide();
  }
    
  void showLabel() {
     this->label->show();
  }
   
   //Felbezeichnungen werden gesetzt
    
  void str2pos (string pos) {
    this->setFile(str2file(pos));
    this->setRank(str2rank(pos));
  }
    
    //Komplettes Spielfeld wird erstellt
    
  Tile(string pos, char color) {
    this->setFile(str2file(pos));
    this->setRank(str2rank(pos));
    this->setColor(color);
    kachel = new Rect(pos2x(pos), pos2y(pos), 128, 128, &view);
    kachel->setColor("transparent");
    if (color == 'w' || color == 'W') {
      kachel -> setFill("#A5A994");
    } else if (color == 'b' || color == 'B') {
      kachel -> setFill("#838767");
    }
    label = new Text(pos, pos2x(pos) + 1, pos2y(pos) + 11, & view);
    label -> setFill("white");
    this->hideLabel();
  };

};

vector < Tile * > tiles;
Tile * tile = nullptr;

Tile * getTile(string pos) {
  for (Tile * tile: tiles) {
    if (tile -> getRank() == str2rank(pos) && tile -> getFile() == str2file(pos)) {
      return tile;
    }
  }
  return NULL;
}
