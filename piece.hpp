class Piece {
  char color;
  bool isRaised = false;
  int rank;
  char file;

  public:

    Image * sprite = nullptr;

  // Getters and Setters

  void setColor(char color) {
    this -> color = color;
  }

  char getColor() {
    return color;
  }

  void setRaised(bool isRaised) {
    this -> isRaised = isRaised;
  }

  bool getRaised() {
    return isRaised;
  }

  void setRank(int rank) {
    this -> rank = rank;
  }

  char getRank() {
    return rank;
  }

  void setFile(char file) {
    this -> file = file;
  }

  char getFile() {
    return file;
  }

  void str2pos(string pos) {
    this -> setFile(str2file(pos));
    this -> setRank(str2rank(pos));
  }

  // Printing

  string pos2str() {
    return this -> file + std::to_string(this -> rank);
  }

  void printPos() {
    std::cout << this -> pos2str() << std::endl;
  }

  void raise() {
    for (int i = 0; i < 20; i++) {
      this -> setRaised(true);
      this -> sprite -> moveBy(0, -1);
      AlgoViz::sleep(20);
    }
  }

  void lower() {
    for (int i = 0; i < 20; i++) {
      this -> setRaised(false);
      this -> sprite -> moveBy(0, 1);
      AlgoViz::sleep(20);
    }
  }

  virtual void clear() {
    delete sprite;
  }

  virtual void possibleMoves() {}

  virtual void draw(string pos) {}

    ~Piece() {
      delete sprite;
    }
};

class Pawn: public Piece {

  public:

    void draw(string pos) {

      char f = str2file(pos);
      int r = str2rank(pos);

      if (this -> getColor() == 'W' || this -> getColor() == 'w') {
        sprite = new Image("/user-redirect/algoviz/img/chess/pawn_white.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      } else if (this -> getColor() == 'B' || this -> getColor() == 'b') {
        sprite = new Image("/user-redirect/algoviz/img/chess/pawn_black.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      }
    }

  Pawn(string pos, char color) {
    setColor(color);
    str2pos(pos);
    draw(pos);
  }
};

class Rook: public Piece {

  public:

    void draw(string pos) {

      char f = str2file(pos);
      int r = str2rank(pos);

      if (this -> getColor() == 'W' || this -> getColor() == 'w') {
        sprite = new Image("/user-redirect/algoviz/img/chess/rook_white.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      } else if (this -> getColor() == 'B' || this -> getColor() == 'b') {
        sprite = new Image("/user-redirect/algoviz/img/chess/rook_black.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      }
    }

  void possibleMoves() {
    for (Tile * tile: tiles) {
      if (tile -> getRank() == this -> getRank() || tile -> getFile() == this -> getFile()) {
        tile -> mark();
      }
    }
  }

  Rook(string pos, char color) {
    setColor(color);
    str2pos(pos);
    draw(pos);
  }
};

class Bishop: public Piece {

  public:

    void draw(string pos) {

      char f = str2file(pos);
      int r = str2rank(pos);

      if (this -> getColor() == 'W' || this -> getColor() == 'w') {
        sprite = new Image("/user-redirect/algoviz/img/chess/bishop_white.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      } else if (this -> getColor() == 'B' || this -> getColor() == 'b') {
        sprite = new Image("/user-redirect/algoviz/img/chess/bishop_black.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      }
    }

  void possibleMoves() {
    char file = this -> getFile();
    int rank = this -> getRank();
    for (Tile * tile: tiles) {
      for (int i = -8; i < 9; i++) {
        if ((tile -> getFile() == file - i &&
          tile -> getRank() == rank + i) && tile -> getOccupied() == false) {
          tile -> mark();
        }

        if ((tile -> getFile() == file + i &&
          tile -> getRank() == rank + i) && tile -> getOccupied() == false) {
          tile -> mark();
        }
      }
    }
  }

  Bishop(string pos, char color) {
    setColor(color);
    str2pos(pos);
    draw(pos);
  }
};

class Knight: public Piece {

  public:

    void draw(string pos) {

      char f = str2file(pos);
      int r = str2rank(pos);

      if (this -> getColor() == 'W' || this -> getColor() == 'w') {
        sprite = new Image("/user-redirect/algoviz/img/chess/knight_white.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      } else if (this -> getColor() == 'B' || this -> getColor() == 'b') {
        sprite = new Image("/user-redirect/algoviz/img/chess/knight_black.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      }
    }

  void possibleMoves() {
    char file = this -> getFile();
    int rank = this -> getRank();
    for (Tile * tile: tiles) {
      if (((rank + 2 == tile -> getRank() || rank - 2 == tile -> getRank()) &&
          (file + 1 == tile -> getFile() || file - 1 == tile -> getFile())) ||
        ((rank + 1 == tile -> getRank() || rank - 1 == tile -> getRank()) &&
          (file + 2 == tile -> getFile() || file - 2 == tile -> getFile()))) {
          if ( tile -> getOccupied() == false) {
              tile -> mark();
          }
      }
    }
  }

  Knight(string pos, char color) {
    setColor(color);
    str2pos(pos);
    draw(pos);
  }
};

class King: public Piece {

  public:

    void draw(string pos) {

      char f = str2file(pos);
      int r = str2rank(pos);

      if (this -> getColor() == 'W' || this -> getColor() == 'w') {
        sprite = new Image("/user-redirect/algoviz/img/chess/king_white.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      } else if (this -> getColor() == 'B' || this -> getColor() == 'b') {
        sprite = new Image("/user-redirect/algoviz/img/chess/king_black.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      }
    }

  King(string pos, char color) {
    setColor(color);
    str2pos(pos);
    draw(pos);
  }
};

class Queen: public Piece {

  public:

    void draw(string pos) {

      char f = str2file(pos);
      int r = str2rank(pos);

      if (this -> getColor() == 'W' || this -> getColor() == 'w') {
        sprite = new Image("/user-redirect/algoviz/img/chess/queen_white.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      } else if (this -> getColor() == 'B' || this -> getColor() == 'b') {
        sprite = new Image("/user-redirect/algoviz/img/chess/queen_black.png", ((f - '@') * 2 - 1) * 64, ((9 - r) * 2 - 1) * 64 - 15, 128, 128, & view);
      }
    }

  Queen(string pos, char color) {
    setColor(color);
    str2pos(pos);
    draw(pos);
  }
};

vector < Piece * > figuren;
Piece * zeiger = nullptr;

Piece * getPiece(string pos) {
  for (Piece * figur: figuren) {
    if (figur -> getRank() == str2rank(pos) && figur -> getFile() == str2file(pos)) {
      return figur;
    }
  }
  return NULL;
}