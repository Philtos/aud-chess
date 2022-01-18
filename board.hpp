class Board {

//   vector < Tile * > tiles;
//   Tile * tile = nullptr;

  public:

    void draw() {
      for (int f = 'A'; f < 'I'; f++) {
        for (int r = 1; r < 9; r++) {
          string pos = ((char) f) + std::to_string(r);
          char color;
          if (f % 2 == 0 ^ r % 2 != 0) {
            color = 'b';
          } else {
            color = 'w';
          }
          tile = new Tile(pos, color);
          tiles.push_back(tile);
        }
      }
    }

  void showLabels() {
    for (Tile * tile: tiles) {
      tile -> showLabel();
    }
  }

  void hideLabels() {
    for (Tile * tile: tiles) {
      tile -> hideLabel();
    }
  }
  
  void unmark() {for (Tile * tile: tiles) {tile -> unmark();}}
  
  void initPieces() {
    for (int i = 0; i < 8; i++) {
      zeiger = new Pawn(fr2str('A' + i, 2),'b');
      figuren.push_back(zeiger);
      
    }

    for (int i = 0; i < 8; i++) {
      zeiger = new Pawn(fr2str('A' + i, 7),'w');
      figuren.push_back(zeiger);
    }

    for (int i = 0; i < 8; i = i + 7) {
      zeiger = new Rook(fr2str('A' + i, 8),'w');
      figuren.push_back(zeiger);
    }

    for (int i = 0; i < 8; i = i + 7) {
      zeiger = new Rook(fr2str('A' + i, 1),'b');
      figuren.push_back(zeiger);
    }

    for (int i = 1; i < 8; i = i + 5) {
      zeiger = new Knight(fr2str('A' + i, 8),'w');
      figuren.push_back(zeiger);
    }

    for (int i = 1; i < 8; i = i + 5) {
      zeiger = new Knight(fr2str('A' + i, 1),'b');
      figuren.push_back(zeiger);
    }

    for (int i = 2; i < 8; i = i + 3) {
      zeiger = new Bishop(fr2str('A' + i, 8),'w');
      figuren.push_back(zeiger);
    }

    for (int i = 2; i < 8; i = i + 3) {
      zeiger = new Bishop(fr2str('A' + i, 1),'b');
      figuren.push_back(zeiger);
    }

    zeiger = new King("D1",'b');
    figuren.push_back(zeiger);
    zeiger = new King("E8",'w');
    figuren.push_back(zeiger);
    zeiger = new Queen("E1",'b');
    figuren.push_back(zeiger);
    zeiger = new Queen("D8",'w');
    figuren.push_back(zeiger);
  }
  
  void setOccupied() {
    for (Tile * tile: tiles) {
      tile -> setOccupied(false);
      for (Piece * figur: figuren) {
        if (tile -> getRank() == figur -> getRank() && tile -> getFile() == figur -> getFile()) {
          tile -> setOccupied(true);
        }
      }
    }
  }  
    
  void reset() {
    if (figuren.empty()) {
      this -> initPieces();
    } else {
    for (Piece * figur: figuren) {
      figur -> clear();
    }
      figuren.clear();
      this -> initPieces();
    }
  }

  Board() {
    this -> draw();
  }
};