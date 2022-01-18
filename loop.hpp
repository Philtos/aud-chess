void moveTo(string op, string np) {
  string oldpos = op;
  string newpos = np;
  
  Piece * oldP = getPiece(oldpos);
  Piece * newP = getPiece(newpos);
    
  if (getTile(newpos) -> getOccupied() == false) {
    int file = str2file(newpos);
    char rank = str2rank(newpos);

    oldP -> sprite -> moveTo(((file - '@') * 2 - 1) * 64, (((9 - rank) * 2 - 1) * 64 - 15) - 20);

    oldP -> str2pos(newpos);
    brett.setOccupied();
  } else {
    if (oldP -> getColor() == newP -> getColor()) {
      AlgoViz::sendText("Hier steht schon eine deiner Figuren!");
      brett.setOccupied();
    } else {
      delete newP;

      int file = str2file(newpos);
      char rank = str2rank(newpos);

      oldP -> sprite -> moveTo(((file - '@') * 2 - 1) * 64, (((9 - rank) * 2 - 1) * 64 - 15) - 20);

      oldP -> str2pos(newpos);
      brett.setOccupied();
    }
  }
}

void raisePiece() {
  while (maus.left() == false) { // this needs a way to check if a tile is empty or not
    maus = view.lastClick();
    char file = 'A' + maus.x() / 128;
    int rank = 8 - maus.y() / 128;
    if (maus.left()) {
      for (Piece * figur: figuren) {
        if (figur -> getRank() == rank && figur -> getFile() == file && maus.isLegal()) {
          //                     figur->printPos();
          figur -> raise();
        }
      }
    }
  }
  maus = view.lastClick();
}

void movePiece() {
  while (maus.left() == false) {
    maus = view.lastClick();
    char file = 'A' + maus.x() / 128;
    int rank = 8 - maus.y() / 128;
    if (maus.left()) {
      string pos = file + std::to_string(rank);
      for (Piece * figur: figuren) {
        if (figur -> getRaised()) {
          moveTo(figur -> pos2str(),pos);
          figur -> lower();
        }
      }
    }
  }
  maus = view.lastClick();
}

void gameLoop(string end) {
  taste = "";
  do {
    raisePiece(); // make sure only one piece can be raised
    movePiece();
    taste = view.lastKey();
  } while (taste != end);
  //   brett.reset();
}