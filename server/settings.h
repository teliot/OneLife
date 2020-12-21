#ifndef _ONELIFE_SETTINGS_H
#define _ONELIFE_SETTINGS_H

#include <string>
#include <unordered_map>
#include <confini.h>

#define INI_CONF "server.conf"

using namespace std;

class Settings {

  public:
    Settings();
    ~Settings();

    std::unordered_map<std::string, std::string> settingsUM;

    string getValue (const string key);

  private:
    static int _dispHandler (IniDispatch *, void *);

};

#endif
