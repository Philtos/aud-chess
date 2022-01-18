Tile * getTile(string pos) {
  for (Tile * tile: tiles) {
    if (tile -> getRank() == str2rank(pos) && tile -> getFile() == str2file(pos)) {
      return tile;
    }
  }
  return NULL;
}

Piece * getPiece(string pos) {
  for (Piece * figur: figuren) {
    if (figur -> getRank() == str2rank(pos) && figur -> getFile() == str2file(pos)) {
      return figur;
    }
  }
  return NULL;
}