int pos2x(string pos) {
  return (((pos[0] - '@') * 2) - 2) * 64;
}

int pos2y(string pos) {
  return (((9 - (pos[1] - '0')) * 2) - 2) * 64;
}

int str2rank(string pos) {
  return pos[1] - '0';
}

char str2file(string pos) {
  return pos[0];
}

string fr2str(char file, int rank) {
  return file + std::to_string(rank);
}
