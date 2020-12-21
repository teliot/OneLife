#include "settings.h"

using namespace std;

Settings::Settings() {
  settingsUM.clear();
  load_ini_path(INI_CONF, INI_DEFAULT_FORMAT, NULL, _dispHandler, &settingsUM);
}

Settings::~Settings() {
}

int Settings::_dispHandler (IniDispatch * dispatch, void * const superMap) {

  if (dispatch->type != INI_KEY)  // Only pay attention to keys. Sections can be safely ignored if we keep them unique.
    return 0;

  reinterpret_cast<unordered_map<string, string>*>(superMap)->insert(pair<string, string>(dispatch->data, dispatch->value));
  return 0;
}

string Settings::getValue (const string key) {
  if(settingsUM.count(key))
    return settingsUM.at(key);
  return NULL;
}
