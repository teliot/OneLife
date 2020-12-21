#include "settings.h"
#include <iostream>

using namespace std;

int main() {
  Settings settings;
  cout << settings.getValue("youGivingPhrases") << endl;
}
