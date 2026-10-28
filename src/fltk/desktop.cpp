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

void desktopTitleBar(void *, bool) {} // the title bars follow by themselves

void watchWindowMoves(void *, void (*)(void *)) {} // a move is a resize

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

#include <cwchar>
#include <map>
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

static void (*_changed)() = nullptr;

// the window procedure of a hidden window of our own: the message of a switch
// is broadcast to every top-level window, hidden ones included, and goes
// straight to their procedures (the system handlers of FLTK never see it)
static LRESULT CALLBACK settingsProc(HWND hwnd, UINT msg, WPARAM w, LPARAM l)
{
  if(msg == WM_SETTINGCHANGE && l &&
     !wcscmp((const wchar_t *)l, L"ImmersiveColorSet") && _changed)
    _changed();
  return DefWindowProcW(hwnd, msg, w, l);
}

void watchDesktopAppearance(void (*changed)())
{
  _changed = changed;
  WNDCLASSW wc = {};
  wc.lpfnWndProc = settingsProc;
  wc.hInstance = GetModuleHandleW(nullptr);
  wc.lpszClassName = L"GmshDesktopWatch";
  RegisterClassW(&wc);
  CreateWindowW(wc.lpszClassName, L"", 0, 0, 0, 0, 0, nullptr, nullptr,
                wc.hInstance, nullptr);
}

void desktopTitleBar(void *window, bool dark)
{
  // asked from the window manager, which draws the title bars light unless
  // told (DWMWA_USE_IMMERSIVE_DARK_MODE, 20 since Windows 10 20H1); the
  // function looked up at run time, so that nothing new is linked
  typedef HRESULT(WINAPI * setAttribute)(HWND, DWORD, LPCVOID, DWORD);
  static setAttribute set = nullptr;
  static bool looked = false;
  if(!looked) {
    looked = true;
    if(HMODULE dwm = LoadLibraryW(L"dwmapi.dll"))
      set = reinterpret_cast<setAttribute>(
        reinterpret_cast<void *>(GetProcAddress(dwm, "DwmSetWindowAttribute")));
  }
  if(!set || !window) return;
  BOOL on = dark ? TRUE : FALSE;
  set((HWND)window, 20, &on, sizeof(on));
}

// the window procedures of FLTK that are watched, by window, and ours in
// front of them: a move, during the drag and at its end, is reported once
// FLTK has taken it
static std::map<HWND, WNDPROC> _watched;
static void (*_moved)(void *) = nullptr;

static LRESULT CALLBACK moveProc(HWND hwnd, UINT msg, WPARAM w, LPARAM l)
{
  WNDPROC proc = _watched[hwnd];
  LRESULT r = CallWindowProcW(proc, hwnd, msg, w, l);
  if((msg == WM_MOVE || msg == WM_EXITSIZEMOVE) && _moved) _moved(hwnd);
  if(msg == WM_NCDESTROY) _watched.erase(hwnd);
  return r;
}

void watchWindowMoves(void *window, void (*moved)(void *))
{
  HWND hwnd = (HWND)window;
  _moved = moved;
  if(!hwnd || _watched.count(hwnd)) return;
  _watched[hwnd] =
    (WNDPROC)SetWindowLongPtrW(hwnd, GWLP_WNDPROC, (LONG_PTR)moveProc);
}

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

void desktopTitleBar(void *, bool) {} // the title bars are the desktop's

void watchWindowMoves(void *, void (*)(void *)) {} // a move is a resize

#endif
