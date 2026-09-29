// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <cctype>

#include "cocoaCommon.h"

// The menus are NSMenus made from the description, in the menu bar at the
// top of the screen. A shortcut with Command is given to its entry, which is
// how macOS shows it and runs it; the others are read by the windows, off
// Sources::keys, as in the other interfaces. What is on and what is greyed is
// asked again as each menu opens, through validateMenuItem:.

// what a menu entry runs, and what it says of itself; kept alive by the entry
// that holds it as its represented object
@interface GmshMenuTarget : NSObject {
@public
  std::function<void()> action;
  std::function<bool()> enabled, checked;
}
- (void)run:(id)sender;
@end

@implementation GmshMenuTarget
- (void)run:(id)sender
{
  std::function<void()> what = action;
  cocoaLater([what]() {
    if(what) what();
    cocoaRefreshBar();
  });
}
- (BOOL)validateMenuItem:(NSMenuItem *)item
{
  if(checked)
    [item setState:checked() ? NSControlStateValueOn : NSControlStateValueOff];
  return enabled ? enabled() : YES;
}
@end

// the entries of the Edit menu, which the text of the fields needs: Command-C
// is also the scene's, which it stays whenever no text has the focus
@interface GmshEditTarget : NSObject
- (void)edit:(id)sender;
@end

@implementation GmshEditTarget
- (void)edit:(id)sender
{
  NSMenuItem *item = (NSMenuItem *)sender;
  SEL what = NSSelectorFromString([item representedObject]);
  NSResponder *first = [[NSApp keyWindow] firstResponder];
  if([first isKindOfClass:[NSText class]] ||
     ![first isKindOfClass:[NSView class]] || [first respondsToSelector:what]) {
    if([NSApp sendAction:what to:nil from:sender]) return;
  }
  NSEvent *e = [NSApp currentEvent];
  if([e type] == NSEventTypeKeyDown) cocoaMainKey(e);
}
- (BOOL)validateMenuItem:(NSMenuItem *)item
{
  return YES;
}
@end

// --- running later

void cocoaWake()
{
  NSEvent *e = [NSEvent otherEventWithType:NSEventTypeApplicationDefined
                                  location:NSZeroPoint
                             modifierFlags:0
                                 timestamp:0
                              windowNumber:0
                                   context:nil
                                   subtype:0
                                     data1:0
                                     data2:0];
  [NSApp postEvent:e atStart:NO];
}

void cocoaLater(const std::function<void()> &what)
{
  std::function<void()> kept = what;
  // a timer rather than the main queue: the queue runs one block at a time,
  // and a block that turns the loop -- the mesher calling check() -- would hold
  // every other up, the button that stops it among them. A timer fires in the
  // loop turned inside another's, in any of its modes: a menu that is open or
  // a window being resized do not hold it up either
  NSTimer *t = [NSTimer timerWithTimeInterval:0.
                                      repeats:NO
                                        block:^(NSTimer *) {
                                          @autoreleasepool {
                                            if(kept) kept();
                                          }
                                          cocoaWake();
                                        }];
  [[NSRunLoop mainRunLoop] addTimer:t forMode:NSRunLoopCommonModes];
}

// --- keys

bool cocoaUiKey(NSEvent *e, int &key, unsigned &mods)
{
  NSEventModifierFlags m = [e modifierFlags];
  mods = 0;
  // Control is Command, as in the other interfaces on macOS
  if(m & (NSEventModifierFlagCommand | NSEventModifierFlagControl))
    mods |= Ui::ModCommand;
  if(m & NSEventModifierFlagShift) mods |= Ui::ModShift;
  if(m & NSEventModifierFlagOption) mods |= Ui::ModAlt;
  key = 0;
  NSString *plain = [e charactersIgnoringModifiers];
  unichar c = [plain length] ? [plain characterAtIndex:0] : 0;
  if(c >= NSF1FunctionKey && c <= NSF12FunctionKey)
    key = Ui::KeyF1 + (c - NSF1FunctionKey);
  else {
    switch(c) {
    case NSLeftArrowFunctionKey: key = Ui::KeyLeft; break;
    case NSRightArrowFunctionKey: key = Ui::KeyRight; break;
    case NSUpArrowFunctionKey: key = Ui::KeyUp; break;
    case NSDownArrowFunctionKey: key = Ui::KeyDown; break;
    case 27: key = Ui::KeyEscape; break;
    case NSHomeFunctionKey: key = Ui::KeyHome; break;
    case NSPageUpFunctionKey: key = Ui::KeyPageUp; break;
    case NSPageDownFunctionKey: key = Ui::KeyPageDown; break;
    case NSDeleteFunctionKey:
    case NSDeleteCharacter:
    case NSBackspaceCharacter: key = Ui::KeyDelete; break;
    default: break;
    }
  }
  if(key) return true;
  if(c < 128 && std::isalpha((int)c)) {
    key = std::toupper((int)c);
    return true;
  }
  // a digit or a mark is the one typed, whatever key gives it on this
  // keyboard (Shift, on a French one); Option makes another letter of it
  NSString *typed =
    (mods & (Ui::ModCommand | Ui::ModAlt)) ? plain : [e characters];
  unichar t = [typed length] == 1 ? [typed characterAtIndex:0] : 0;
  if(t > ' ' && t < 127) {
    key = t;
    mods &= ~Ui::ModShift;
    return true;
  }
  if(c > ' ' && c < 127) {
    key = c;
    mods &= ~Ui::ModShift;
    return true;
  }
  return false;
}

// --- menus

namespace {

  // the key macOS shows, and runs, for a shortcut with Command; none for the
  // others, which an entry would take from the text being typed
  bool _equivalent(const Ui::Shortcut &s, NSString *__strong &key,
                   NSEventModifierFlags &mask)
  {
    if(s.empty() || !(s.mods & Ui::ModCommand) || (s.mods & Ui::ModAny))
      return false;
    unichar c = 0;
    if(s.key >= Ui::KeyF1 && s.key < Ui::KeyF1 + 12)
      c = NSF1FunctionKey + (s.key - Ui::KeyF1);
    else if(s.key == Ui::KeyLeft)
      c = NSLeftArrowFunctionKey;
    else if(s.key == Ui::KeyRight)
      c = NSRightArrowFunctionKey;
    else if(s.key == Ui::KeyUp)
      c = NSUpArrowFunctionKey;
    else if(s.key == Ui::KeyDown)
      c = NSDownArrowFunctionKey;
    else if(s.key > ' ' && s.key < 127)
      c = (unichar)std::tolower(s.key);
    else
      return false;
    key = [NSString stringWithCharacters:&c length:1];
    mask = NSEventModifierFlagCommand;
    if(s.mods & Ui::ModShift) mask |= NSEventModifierFlagShift;
    if(s.mods & Ui::ModAlt) mask |= NSEventModifierFlagOption;
    return true;
  }

  // the keys the Edit menu has, which no entry of the description takes
  bool _editKey(const Ui::Shortcut &s)
  {
    if(s.mods != Ui::ModCommand && s.mods != (Ui::ModCommand | Ui::ModShift))
      return false;
    if(s.mods == (Ui::ModCommand | Ui::ModShift)) return s.key == 'Z';
    return s.key == 'Z' || s.key == 'X' || s.key == 'C' || s.key == 'V' ||
           s.key == 'A';
  }

  NSMenu *_menu(const std::vector<Ui::MenuItem> &items, NSString *title,
                bool bar);

  // bar: the entries of the menu bar, which hides what macOS has elsewhere and
  // shows the keys; a menu of its own shows none
  void _fill(NSMenu *menu, const std::vector<Ui::MenuItem> &items, bool bar)
  {
    for(const auto &it : items) {
      if(bar && it.hideInSystemBar) {
        if(it.dividerAfter && [menu numberOfItems] &&
           ![[menu itemAtIndex:[menu numberOfItems] - 1] isSeparatorItem])
          [menu addItem:[NSMenuItem separatorItem]];
        continue;
      }
      NSMenuItem *entry =
        [[NSMenuItem alloc] initWithTitle:cocoaString(it.label)
                                   action:nil
                            keyEquivalent:@""];
      if(it.kind == Ui::MenuItem::Submenu) {
        NSMenu *sub = _menu(it.children, cocoaString(it.label), bar);
        [entry setSubmenu:sub];
        if(it.enabled) {
          GmshMenuTarget *t = [[GmshMenuTarget alloc] init];
          t->enabled = it.enabled;
          [entry setRepresentedObject:t];
          [entry setEnabled:it.enabled() ? YES : NO];
        }
      }
      else {
        GmshMenuTarget *t = [[GmshMenuTarget alloc] init];
        t->action = it.action;
        t->enabled = it.enabled;
        if(it.kind == Ui::MenuItem::Toggle) {
          t->checked = it.checked;
          if(it.checked)
            [entry setState:it.checked() ? NSControlStateValueOn :
                                           NSControlStateValueOff];
        }
        [entry setTarget:t];
        [entry setAction:@selector(run:)];
        // the entry holds it: a target is not kept by the entry it serves
        [entry setRepresentedObject:t];
        NSString *key = nil;
        NSEventModifierFlags mask = 0;
        if(bar && !_editKey(it.shortcut) &&
           _equivalent(it.shortcut, key, mask)) {
          [entry setKeyEquivalent:key];
          [entry setKeyEquivalentModifierMask:mask];
        }
      }
      [menu addItem:entry];
      if(it.dividerAfter) [menu addItem:[NSMenuItem separatorItem]];
    }
    // no separator at the end
    while([menu numberOfItems] &&
          [[menu itemAtIndex:[menu numberOfItems] - 1] isSeparatorItem])
      [menu removeItemAtIndex:[menu numberOfItems] - 1];
  }

  NSMenu *_menu(const std::vector<Ui::MenuItem> &items, NSString *title,
                bool bar)
  {
    NSMenu *menu = [[NSMenu alloc] initWithTitle:title ? title : @""];
    _fill(menu, items, bar);
    return menu;
  }

  GmshEditTarget *_editTarget = nil;

  NSMenu *_applicationMenu()
  {
    NSMenu *menu = [[NSMenu alloc] initWithTitle:@"Gmsh"];
    // About and Quit belong here on macOS: the description's are hidden from
    // the system bar, and these run what they run
    std::function<void()> about, quit;
    std::vector<Ui::MenuItem> all = cocoaSources().menuBar ?
                                      cocoaSources().menuBar() :
                                      std::vector<Ui::MenuItem>();
    std::vector<const Ui::MenuItem *> todo;
    for(const auto &m : all) todo.push_back(&m);
    // the keys of macOS give way to the description's
    bool hide = true, others = true;
    while(!todo.empty()) {
      const Ui::MenuItem *m = todo.back();
      todo.pop_back();
      for(const auto &k : m->children) todo.push_back(&k);
      if(m->shortcut.key == 'H' && m->shortcut.mods == Ui::ModCommand)
        hide = false;
      if(m->shortcut.key == 'H' &&
         m->shortcut.mods == (Ui::ModCommand | Ui::ModAlt))
        others = false;
      if(!m->hideInSystemBar) continue;
      if(m->shortcut.key == 'Q' && m->shortcut.mods == Ui::ModCommand)
        quit = m->action;
      else if(!about)
        about = m->action;
    }
    if(about) {
      GmshMenuTarget *t = [[GmshMenuTarget alloc] init];
      t->action = about;
      NSMenuItem *entry = [menu addItemWithTitle:@"About Gmsh"
                                          action:@selector(run:)
                                   keyEquivalent:@""];
      [entry setTarget:t];
      [entry setRepresentedObject:t];
      [menu addItem:[NSMenuItem separatorItem]];
    }
    NSMenuItem *services = [menu addItemWithTitle:@"Services"
                                           action:nil
                                    keyEquivalent:@""];
    NSMenu *servicesMenu = [[NSMenu alloc] initWithTitle:@"Services"];
    [services setSubmenu:servicesMenu];
    [NSApp setServicesMenu:servicesMenu];
    [menu addItem:[NSMenuItem separatorItem]];
    [menu addItemWithTitle:@"Hide Gmsh"
                    action:@selector(hide:)
             keyEquivalent:hide ? @"h" : @""];
    NSMenuItem *rest = [menu addItemWithTitle:@"Hide Others"
                                       action:@selector(hideOtherApplications:)
                                keyEquivalent:others ? @"h" : @""];
    [rest setKeyEquivalentModifierMask:NSEventModifierFlagCommand |
                                       NSEventModifierFlagOption];
    [menu addItemWithTitle:@"Show All"
                    action:@selector(unhideAllApplications:)
             keyEquivalent:@""];
    [menu addItem:[NSMenuItem separatorItem]];
    GmshMenuTarget *t = [[GmshMenuTarget alloc] init];
    t->action = quit ? quit : []() {
      if(cocoaHost().quitting) cocoaHost().quitting();
    };
    NSMenuItem *entry = [menu addItemWithTitle:@"Quit Gmsh"
                                        action:@selector(run:)
                                 keyEquivalent:@"q"];
    [entry setTarget:t];
    [entry setRepresentedObject:t];
    return menu;
  }

  NSMenu *_editMenu()
  {
    if(!_editTarget) _editTarget = [[GmshEditTarget alloc] init];
    NSMenu *menu = [[NSMenu alloc] initWithTitle:@"Edit"];
    struct {
      NSString *title, *key, *selector;
      bool shift;
    } entries[] = {{@"Undo", @"z", @"undo:", false},
                   {@"Redo", @"z", @"redo:", true},
                   {nil, nil, nil, false},
                   {@"Cut", @"x", @"cut:", false},
                   {@"Copy", @"c", @"copy:", false},
                   {@"Paste", @"v", @"paste:", false},
                   {@"Select All", @"a", @"selectAll:", false}};
    for(auto &e : entries) {
      if(!e.title) {
        [menu addItem:[NSMenuItem separatorItem]];
        continue;
      }
      NSMenuItem *entry = [menu addItemWithTitle:e.title
                                          action:@selector(edit:)
                                   keyEquivalent:e.key];
      if(e.shift)
        [entry setKeyEquivalentModifierMask:NSEventModifierFlagCommand |
                                            NSEventModifierFlagShift];
      [entry setTarget:_editTarget];
      [entry setRepresentedObject:e.selector];
    }
    return menu;
  }

} // namespace

NSMenu *cocoaMenu(const std::vector<Ui::MenuItem> &items, NSString *title)
{ return _menu(items, title, true); }

void cocoaRefreshMenuBar()
{
  static unsigned built = 0;
  static bool ever = false;
  if(!NSApp || !cocoaSources().menuBar) return;
  unsigned generation =
    cocoaSources().menuGeneration ? cocoaSources().menuGeneration() : 0;
  if(ever && generation == built) return;
  ever = true;
  built = generation;
  NSMenu *bar = [[NSMenu alloc] initWithTitle:@""];
  NSMenuItem *app = [bar addItemWithTitle:@"Gmsh" action:nil keyEquivalent:@""];
  [app setSubmenu:_applicationMenu()];
  bool edit = false;
  NSMenu *window = nil, *help = nil;
  for(const auto &it : cocoaSources().menuBar()) {
    if(it.kind != Ui::MenuItem::Submenu) continue;
    NSMenuItem *entry = [bar addItemWithTitle:cocoaString(it.label)
                                       action:nil
                                keyEquivalent:@""];
    NSMenu *menu = cocoaMenu(it.children, cocoaString(it.label));
    [entry setSubmenu:menu];
    if(it.label == "Window") window = menu;
    if(it.label == "Help") help = menu;
    // after the first, as macOS has it
    if(!edit) {
      NSMenuItem *e = [bar addItemWithTitle:@"Edit"
                                     action:nil
                              keyEquivalent:@""];
      [e setSubmenu:_editMenu()];
      edit = true;
    }
  }
  if(!edit) {
    NSMenuItem *e = [bar addItemWithTitle:@"Edit" action:nil keyEquivalent:@""];
    [e setSubmenu:_editMenu()];
  }
  [NSApp setMainMenu:bar];
  // macOS lists the windows under Window, and searches under Help
  if(window) [NSApp setWindowsMenu:window];
  if(help) [NSApp setHelpMenu:help];
}

void cocoaPopupMenu(const std::vector<Ui::MenuItem> &items)
{
  if(items.empty()) return;
  NSMenu *menu = _menu(items, @"", false);
  [menu popUpMenuPositioningItem:nil
                      atLocation:[NSEvent mouseLocation]
                          inView:nil];
}
