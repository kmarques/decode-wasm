
extern "C" void (*dispatcher[])();

extern "C" void analyser_score(int score) {
  if (score > 100) {
    dispatcher[0]();
  } else if (score < 0) {
    dispatcher[1]();
  } else {
    dispatcher[2]();
  }
}