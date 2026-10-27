// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cctype>
#include <cstdio>
#include "desktop.h"

#if defined(__APPLE__)

#include <CoreFoundation/CoreFoundation.h>

std::string desktopFont() { return ""; }

int desktopDark()
{
  // the global preference, set to "Dark" in dark mode and absent in light
  // mode, read from the user's domain after a synchronize: the application
  // value is cached and lags the notification of a switch
  CFPreferencesSynchronize(kCFPreferencesAnyApplication,
                           kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
  CFPropertyListRef v = CFPreferencesCopyValue(
    CFSTR("AppleInterfaceStyle"), kCFPreferencesAnyApplication,
    kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
  bool dark = v && CFGetTypeID(v) == CFStringGetTypeID() &&
              CFStringCompare((CFStringRef)v, CFSTR("Dark"),
                              kCFCompareCaseInsensitive) == kCFCompareEqualTo;
  if(v) CFRelease(v);
  return dark ? 1 : 0;
}

static void (*_changed)() = nullptr;

static void themeChanged(CFNotificationCenterRef, void *, CFNotificationName,
                         const void *, CFDictionaryRef)
{
  if(_changed) _changed();
}

void watchDesktopAppearance(void (*changed)())
{
  // the notification the system sends to every application on a switch
  _changed = changed;
  CFNotificationCenterAddObserver(
    CFNotificationCenterGetDistributedCenter(), nullptr, themeChanged,
    CFSTR("AppleInterfaceThemeChangedNotification"), nullptr,
    CFNotificationSuspensionBehaviorDeliverImmediately);
}

#elif defined(WIN32)

#include <windows.h>

std::string desktopFont() { return ""; }

int desktopDark()
{
  // the setting of the Colors page of the personalization settings
  DWORD light = 1, size = sizeof(light);
  if(RegGetValueW(HKEY_CURRENT_USER,
                  L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\"
                  L"Personalize",
                  L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &light,
                  &size) != ERROR_SUCCESS)
    return -1;
  return light ? 0 : 1;
}

// the switch comes as a window message, which FlGui watches
void watchDesktopAppearance(void (*)()) {}

#else

// the output of a command, empty when it is not there or fails
static std::string run(const std::string &cmd)
{
  std::string out;
  FILE *f = popen((cmd + " 2>/dev/null").c_str(), "r");
  if(!f) return out;
  char buf[256];
  while(fgets(buf, sizeof(buf), f)) out += buf;
  pclose(f);
  return out;
}

// a setting read through the settings portal of xdg-desktop-portal, which
// GNOME, KDE and the others serve on X11 and Wayland alike
static std::string portal(const std::string &ns, const std::string &key)
{
  return run("gdbus call --session --dest org.freedesktop.portal.Desktop "
             "--object-path /org/freedesktop/portal/desktop "
             "--method org.freedesktop.portal.Settings.Read " +
             ns + " " + key);
}

// the text between the first pair of single quotes
static std::string quoted(const std::string &s)
{
  std::string::size_type a = s.find('\'');
  if(a == std::string::npos) return "";
  std::string::size_type b = s.find('\'', a + 1);
  if(b == std::string::npos) return "";
  return s.substr(a + 1, b - a - 1);
}

std::string desktopFont()
{
  // "Cantarell 11", through the portal or straight from the GNOME settings
  std::string name = quoted(portal("org.gnome.desktop.interface", "font-name"));
  if(name.empty())
    name = quoted(run("gsettings get org.gnome.desktop.interface font-name"));
  // the family without the size
  while(!name.empty() && (isdigit(name.back()) || name.back() == '.'))
    name.pop_back();
  while(!name.empty() && name.back() == ' ') name.pop_back();
  return name;
}

int desktopDark()
{
  // "(<<uint32 1>>,)": 1 dark, 2 light, 0 no preference
  std::string s = portal("org.freedesktop.appearance", "color-scheme");
  std::string::size_type p = s.find("uint32 ");
  if(p != std::string::npos) return s[p + 7] == '1' ? 1 : 0;
  // "'prefer-dark'" or "'default'" from the GNOME settings
  s = run("gsettings get org.gnome.desktop.interface color-scheme");
  if(s.find("prefer-dark") != std::string::npos) return 1;
  return s.empty() ? -1 : 0;
}

// no notification without a D-Bus listener: the switch is seen when a window
// gets the focus
void watchDesktopAppearance(void (*)()) {}

#endif
