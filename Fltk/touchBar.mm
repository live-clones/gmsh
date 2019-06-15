// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#define GL_SILENCE_DEPRECATION

#include "touchBar.h"
#include "graphicWindow.h"
#include "drawContext.h"
#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>

static NSString *touchBarCustomizationId = @"com.something.customization_id";
static NSString *touchBarItem1D = @"com.something.item_1D";
static NSString *touchBarItem2D = @"com.something.item_2D";
static NSString *touchBarItem3D = @"com.something.item_3D";
static NSString *touchBarItemMeshDisplay = @"com.something.item_meshDisplay";

@interface TouchBarDelegate : NSObject <NSTouchBarDelegate>
  - (NSTouchBar *)makeTouchBar;
  - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier;
  - (void)button1D:(id)sender;
  - (void)button2D:(id)sender;
  - (void)button3D:(id)sender;
  - (void)meshDisplay:(id)sender;
@end

@implementation TouchBarDelegate
    - (NSTouchBar *)makeTouchBar
    {
      NSTouchBar *touchBar = [[NSTouchBar alloc] init];
      touchBar.delegate = self;
      touchBar.customizationIdentifier = touchBarCustomizationId;

      touchBar.defaultItemIdentifiers = @[touchBarItem1D, touchBarItem2D, touchBarItem3D, touchBarItemMeshDisplay];
      touchBar.customizationAllowedItemIdentifiers = @[touchBarItem1D, touchBarItem2D, touchBarItem3D, touchBarItemMeshDisplay];

      return touchBar;
    }

    - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier
    {
      if ([identifier isEqualToString:touchBarItem1D])
      {
        NSButton *button = [NSButton buttonWithTitle:NSLocalizedString(@"1D", @"") target:self action:@selector(button1D:)];

        NSCustomTouchBarItem* touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItem1D];
        touchBarItem.view = button;
        touchBarItem.customizationLabel = NSLocalizedString(@"Truth Button", @"");

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItem2D])
      {
        NSButton *button = [NSButton buttonWithTitle:NSLocalizedString(@"2D", @"") target:self action:@selector(button2D:)];

        NSCustomTouchBarItem* touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItem2D];
        touchBarItem.view = button;
        touchBarItem.customizationLabel = NSLocalizedString(@"Truth Button", @"");

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItem3D])
      {
        NSButton *button = [NSButton buttonWithTitle:NSLocalizedString(@"3D", @"") target:self action:@selector(button3D:)];

        NSCustomTouchBarItem* touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItem3D];
        touchBarItem.view = button;
        touchBarItem.customizationLabel = NSLocalizedString(@"Truth Button", @"");

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemMeshDisplay])
      {
        NSButton *button = [NSButton buttonWithTitle:NSLocalizedString(@"Mesh display", @"") target:self action:@selector(meshDisplay:)];

        NSCustomTouchBarItem* touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemMeshDisplay];
        touchBarItem.view = button;
        touchBarItem.customizationLabel = NSLocalizedString(@"Truth Button", @"");

        return touchBarItem;
      }

      return nil;
    }

    - (void)button1D:(id)sender
    {
      mesh_1d_cb(0, 0);
    }

    - (void)button2D:(id)sender
    {
      mesh_2d_cb(0, 0);
    }

    - (void)button3D:(id)sender
    {
      mesh_3d_cb(0, 0);
    }

    - (void)meshDisplay:(id)sender
    {
      quick_access_cb(0, (void *)"mesh_toggle");
      drawContext::global()->draw();
    }
@end

TouchBarDelegate* touchBarDelegate = NULL;
void showTouchBar()
{
  if (!touchBarDelegate) {
    touchBarDelegate = [[TouchBarDelegate alloc] init];
    [NSApplication sharedApplication].automaticCustomizeTouchBarMenuItemEnabled = YES;
  }

  NSTouchBar* touchBar = [touchBarDelegate makeTouchBar];

  NSArray<NSWindow*>* windows = [NSApplication sharedApplication].windows;
  for (int i = 0; i < windows.count; ++i) {
    NSWindow* wnd = windows[i];
    wnd.touchBar = touchBar;
  }
}
