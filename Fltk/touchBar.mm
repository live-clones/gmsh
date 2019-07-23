// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributors: Anthony Royer

#define GL_SILENCE_DEPRECATION

#include "touchBar.h"
#include "graphicWindow.h"
#include "drawContext.h"
#include "Options.h"
#include "PView.h"
#include <Foundation/Foundation.h>
#include <AppKit/AppKit.h>

static NSString *touchBarCustomizationId = @"com.something.customization_id";

static NSString *touchBarItemRunMesh = @"com.something.item_runmesh";

static NSString *touchBarItemGeoMenu = @"com.something.item_geoMenu";
static NSString *touchBarItemGeoButtons = @"com.something.item_geoButtons";
static NSString *touchBarItemGeoHoldButtons = @"com.something.item_geoHoldButtons";

static NSString *touchBarItemMeshMenu = @"com.something.item_meshMenu";
static NSString *touchBarItemMeshButtons = @"com.something.item_meshButtons";
static NSString *touchBarItemMeshHoldButtons = @"com.something.item_meshHoldButtons";

static NSString *touchBarItemViewMenu = @"com.something.item_viewMenu";
static NSString *touchBarItemViewButtons = @"com.something.item_viewButtons";
static NSString *touchBarItemViewSlider = @"com.something.item_viewSlider";

@interface TouchBarDelegate : NSObject <NSTouchBarDelegate>

@property(strong ) NSSegmentedControl *geoButtons;
@property(strong ) NSSegmentedControl *meshButtons;
@property(strong ) NSButton *viewMenuButton;
@property(strong ) NSSegmentedControl *viewButtons;
@property(strong ) NSSlider *viewSlider;

  - (NSTouchBar *)makeTouchBar;
  - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier;
  - (void)buttonRunMesh:(id)sender;
  - (void)buttonGeo:(id)sender;
  - (void)buttonHoldGeo:(id)sender;
  - (void)buttonMesh:(id)sender;
  - (void)buttonHoldMesh:(id)sender;
  - (void)buttonView:(id)sender;
  - (void)sliderView:(id)sender;
  - (void)updateGeo;
  - (void)updateMesh;
  - (void)updateViewMenu;
  - (void)updateViewButtons;
  - (void)updateViewSlider;
  - (void)update;
@end

@implementation TouchBarDelegate
    - (NSTouchBar *)makeTouchBar
    {
      NSTouchBar *touchBar = [[NSTouchBar alloc] init];
      touchBar.delegate = self;
      touchBar.customizationIdentifier = touchBarCustomizationId;

      touchBar.defaultItemIdentifiers = @[touchBarItemRunMesh, touchBarItemGeoMenu, touchBarItemMeshMenu, touchBarItemViewMenu];
      touchBar.customizationAllowedItemIdentifiers = @[touchBarItemRunMesh, touchBarItemGeoMenu, touchBarItemMeshMenu, touchBarItemViewMenu];

      return touchBar;
    }

    - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier
    {
      if ([identifier isEqualToString:touchBarItemRunMesh])
      {
        NSSegmentedControl *segmentedControl = [NSSegmentedControl segmentedControlWithLabels:@[@"1D", @"2D", @"3D"] trackingMode:NSSegmentSwitchTrackingMomentary target:self action:@selector(buttonRunMesh:)];

        NSCustomTouchBarItem *touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemRunMesh];
        touchBarItem.view = segmentedControl;
        touchBarItem.customizationLabel = @"Meshing commands";

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemGeoMenu])
      {
        NSPopoverTouchBarItem *popoverTouchBarItem = [[NSPopoverTouchBarItem alloc] initWithIdentifier:touchBarItemGeoMenu];
        popoverTouchBarItem.customizationLabel = @"Geometry";

        popoverTouchBarItem.showsCloseButton = YES;
        popoverTouchBarItem.collapsedRepresentationLabel = @"Geometry";

        NSTouchBar *secondTouchBar = [[NSTouchBar alloc] init];
        secondTouchBar.delegate = self;
        secondTouchBar.defaultItemIdentifiers = @[touchBarItemGeoButtons];

        NSTouchBar *thirdTouchBar = [[NSTouchBar alloc] init];
        thirdTouchBar.delegate = self;
        thirdTouchBar.defaultItemIdentifiers = @[touchBarItemGeoHoldButtons];

        popoverTouchBarItem.popoverTouchBar = secondTouchBar;
        popoverTouchBarItem.pressAndHoldTouchBar = thirdTouchBar;

        return popoverTouchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemGeoButtons])
      {
        NSSegmentedControl *segmentedControl = [NSSegmentedControl segmentedControlWithLabels:@[@"Points", @"Curves", @"Surfaces", @"Volumes"] trackingMode:NSSegmentSwitchTrackingSelectAny target:self action:@selector(buttonGeo:)];

        NSCustomTouchBarItem *touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemGeoButtons];
        touchBarItem.view = segmentedControl;

        _geoButtons = segmentedControl;
        [self updateGeo];

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemGeoHoldButtons])
      {
        NSSegmentedControl *segmentedControl = [NSSegmentedControl segmentedControlWithLabels:@[@"Show all", @"Hide all"] trackingMode:NSSegmentSwitchTrackingMomentary target:self action:@selector(buttonHoldGeo:)];

        NSCustomTouchBarItem *touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemGeoHoldButtons];
        touchBarItem.view = segmentedControl;

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemMeshMenu])
      {
        NSPopoverTouchBarItem *popoverTouchBarItem = [[NSPopoverTouchBarItem alloc] initWithIdentifier:touchBarItemMeshMenu];
        popoverTouchBarItem.customizationLabel = @"Mesh";

        popoverTouchBarItem.showsCloseButton = YES;
        popoverTouchBarItem.collapsedRepresentationLabel = @"Mesh";

        NSTouchBar *secondTouchBar = [[NSTouchBar alloc] init];
        secondTouchBar.delegate = self;
        secondTouchBar.defaultItemIdentifiers = @[touchBarItemMeshButtons];

        NSTouchBar *thirdTouchBar = [[NSTouchBar alloc] init];
        thirdTouchBar.delegate = self;
        thirdTouchBar.defaultItemIdentifiers = @[touchBarItemMeshHoldButtons];

        popoverTouchBarItem.popoverTouchBar = secondTouchBar;
        popoverTouchBarItem.pressAndHoldTouchBar = thirdTouchBar;

        return popoverTouchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemMeshButtons])
      {
        NSSegmentedControl *segmentedControl = [NSSegmentedControl segmentedControlWithLabels:@[@"Nodes", @"Lines", @"2D Edges", @"2D Faces", @"3D Edges", @"3D Faces"] trackingMode:NSSegmentSwitchTrackingSelectAny target:self action:@selector(buttonMesh:)];

        NSCustomTouchBarItem *touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemMeshButtons];
        touchBarItem.view = segmentedControl;

        _meshButtons = segmentedControl;
        [self updateMesh];

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemMeshHoldButtons])
      {
        NSSegmentedControl *segmentedControl = [NSSegmentedControl segmentedControlWithLabels:@[@"Show all", @"Hide all"] trackingMode:NSSegmentSwitchTrackingMomentary target:self action:@selector(buttonHoldMesh:)];

        NSCustomTouchBarItem *touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemMeshHoldButtons];
        touchBarItem.view = segmentedControl;

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemViewMenu])
      {
        NSPopoverTouchBarItem *popoverTouchBarItem = [[NSPopoverTouchBarItem alloc] initWithIdentifier:touchBarItemViewMenu];
        popoverTouchBarItem.customizationLabel = @"View";

        popoverTouchBarItem.showsCloseButton = YES;
        popoverTouchBarItem.collapsedRepresentationLabel = @"View";

        NSTouchBar *secondTouchBar = [[NSTouchBar alloc] init];
        secondTouchBar.delegate = self;

        _viewMenuButton = (NSButton*) popoverTouchBarItem.view;
        [self updateViewMenu];

        secondTouchBar.defaultItemIdentifiers = @[touchBarItemViewButtons, touchBarItemViewSlider];
        popoverTouchBarItem.popoverTouchBar = secondTouchBar;

        return popoverTouchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemViewButtons])
      {
        NSSegmentedControl *segmentedControl = [NSSegmentedControl segmentedControlWithLabels:@[@"Iso-values", @"Continuous map", @"Filled iso-values", @"Numeric values"] trackingMode:NSSegmentSwitchTrackingSelectOne target:self action:@selector(buttonView:)];

        NSCustomTouchBarItem *touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemViewButtons];
        touchBarItem.view = segmentedControl;

        _viewButtons = segmentedControl;
        [self updateViewButtons];

        return touchBarItem;
      }
      else if ([identifier isEqualToString:touchBarItemViewSlider])
      {
        NSSlider *slider = [NSSlider sliderWithValue:10 minValue:1 maxValue:50 target:self action:@selector(sliderView:)];

        NSCustomTouchBarItem *touchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemViewSlider];
        touchBarItem.view = slider;

        _viewSlider = slider;
        [self updateViewSlider];

        return touchBarItem;
      }


      return nil;
    }

    - (void)buttonRunMesh:(id)sender
    {
      NSInteger segment = ((NSSegmentedControl*) sender).selectedSegment;
      switch(segment) {
      case 0:
        mesh_1d_cb(0, 0);
        break;
      case 1:
        mesh_2d_cb(0, 0);
        break;
      case 2:
        mesh_3d_cb(0, 0);
        break;
      default:
        break;
      }
    }

    - (void)buttonGeo:(id)sender
    {
      NSInteger segment = ((NSSegmentedControl*) sender).selectedSegment;
      switch(segment) {
      case 0:
        quick_access_cb(0, (void *)"geometry_points");
        break;
      case 1:
        quick_access_cb(0, (void *)"geometry_curves");
        break;
      case 2:
        quick_access_cb(0, (void *)"geometry_surfaces");
        break;
      case 3:
        quick_access_cb(0, (void *)"geometry_volumes");
        break;
      default:
        break;
      }
      drawContext::global()->draw();
    }

    - (void)buttonHoldGeo:(id)sender
    {
      NSInteger segment = ((NSSegmentedControl*) sender).selectedSegment;
      switch(segment) {
      case 0: // show all
        if(!opt_geometry_points(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_points");
        }
        if(!opt_geometry_curves(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_curves");
        }
        if(!opt_geometry_surfaces(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_surfaces");
        }
        if(!opt_geometry_volumes(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_volumes");
        }
        break;
      case 1: // hide all
        if(opt_geometry_points(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_points");
        }
        if(opt_geometry_curves(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_curves");
        }
        if(opt_geometry_surfaces(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_surfaces");
        }
        if(opt_geometry_volumes(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"geometry_volumes");
        }
        break;
      default:
        break;
      }
      [self updateGeo];
      drawContext::global()->draw();
    }

    - (void)buttonMesh:(id)sender
    {
      NSInteger segment = ((NSSegmentedControl*) sender).selectedSegment;
      switch(segment) {
      case 0:
        quick_access_cb(0, (void *)"mesh_points");
        break;
      case 1:
        quick_access_cb(0, (void *)"mesh_lines");
        break;
      case 2:
        quick_access_cb(0, (void *)"mesh_surfaces_edges");
        break;
      case 3:
        quick_access_cb(0, (void *)"mesh_surfaces_faces");
        break;
      case 4:
        quick_access_cb(0, (void *)"mesh_volumes_edges");
        break;
      case 5:
        quick_access_cb(0, (void *)"mesh_volumes_faces");
        break;
      default:
        break;
      }
      drawContext::global()->draw();
    }

    - (void)buttonHoldMesh:(id)sender
    {
      NSInteger segment = ((NSSegmentedControl*) sender).selectedSegment;
      switch(segment) {
      case 0: // show all
        if(!opt_mesh_points(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_points");
        }
        if(!opt_mesh_lines(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_lines");
        }
        if(!opt_mesh_surfaces_edges(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_surfaces_edges");
        }
        if(!opt_mesh_surfaces_faces(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_surfaces_faces");
        }
        if(!opt_mesh_volumes_edges(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_volumes_edges");
        }
        if(!opt_mesh_volumes_faces(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_volumes_faces");
        }
        break;
      case 1: // hide all
        if(opt_mesh_points(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_points");
        }
        if(opt_mesh_lines(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_lines");
        }
        if(opt_mesh_surfaces_edges(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_surfaces_edges");
        }
        if(opt_mesh_surfaces_faces(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_surfaces_faces");
        }
        if(opt_mesh_volumes_edges(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_volumes_edges");
        }
        if(opt_mesh_volumes_faces(0, GMSH_GET, 0)) {
          quick_access_cb(0, (void *)"mesh_volumes_faces");
        }
        break;
      default:
        break;
      }
      [self updateMesh];
      drawContext::global()->draw();
    }

    - (void)buttonView:(id)sender
    {
      NSInteger segment = ((NSSegmentedControl*) sender).selectedSegment;
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        if(opt_view_visible(i, GMSH_GET, 0)) {
          opt_view_intervals_type(i, GMSH_SET|GMSH_GUI, segment+1);
        }
      }
      if(segment+1 == 1 || segment+1 == 3) { // For iso-values and filled iso-values
        _viewSlider.hidden = NO;
      }
      else {
        _viewSlider.hidden = YES;
      }
      drawContext::global()->draw();
    }

    - (void)sliderView:(id)sender
    {
      NSSlider *slider = ((NSSlider*) sender);
      if(!slider.hidden) {
        double value = slider.doubleValue;
        for(std::size_t i = 0; i < PView::list.size(); i++) {
          if(opt_view_visible(i, GMSH_GET, 0)) {
            opt_view_nb_iso(i, GMSH_SET|GMSH_GUI, value);
          }
        }
        drawContext::global()->draw();
      }
    }

    - (void)updateGeo
    {
      if(opt_geometry_points(0, GMSH_GET, 0)) {
        [_geoButtons setSelected:YES forSegment:0];
      }
      else {
        [_geoButtons setSelected:NO forSegment:0];
      }

      if(opt_geometry_curves(0, GMSH_GET, 0)) {
        [_geoButtons setSelected:YES forSegment:1];
      }
      else {
        [_geoButtons setSelected:NO forSegment:1];
      }

      if(opt_geometry_surfaces(0, GMSH_GET, 0)) {
        [_geoButtons setSelected:YES forSegment:2];
      }
      else {
        [_geoButtons setSelected:NO forSegment:2];
      }

      if(opt_geometry_volumes(0, GMSH_GET, 0)) {
        [_geoButtons setSelected:YES forSegment:3];
      }
      else {
        [_geoButtons setSelected:NO forSegment:3];
      }
    }

    - (void)updateMesh
    {
      if(opt_mesh_points(0, GMSH_GET, 0)) {
        [_meshButtons setSelected:YES forSegment:0];
      }
      else {
        [_meshButtons setSelected:NO forSegment:0];
      }

      if(opt_mesh_lines(0, GMSH_GET, 0)) {
        [_meshButtons setSelected:YES forSegment:1];
      }
      else {
        [_meshButtons setSelected:NO forSegment:1];
      }

      if(opt_mesh_surfaces_edges(0, GMSH_GET, 0)) {
        [_meshButtons setSelected:YES forSegment:2];
      }
      else {
        [_meshButtons setSelected:NO forSegment:2];
      }

      if(opt_mesh_surfaces_faces(0, GMSH_GET, 0)) {
        [_meshButtons setSelected:YES forSegment:3];
      }
      else {
        [_meshButtons setSelected:NO forSegment:3];
      }

      if(opt_mesh_volumes_edges(0, GMSH_GET, 0)) {
        [_meshButtons setSelected:YES forSegment:4];
      }
      else {
        [_meshButtons setSelected:NO forSegment:4];
      }

      if(opt_mesh_volumes_faces(0, GMSH_GET, 0)) {
        [_meshButtons setSelected:YES forSegment:5];
      }
      else {
        [_meshButtons setSelected:NO forSegment:5];
      }
    }

    - (void)updateViewMenu
    {
      if(PView::list.empty()) {
        _viewMenuButton.hidden = YES;
      }
      else {
        _viewMenuButton.hidden = NO;
      }
    }

    - (void)updateViewButtons
    {
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        if(opt_view_visible(i, GMSH_GET, 0)) {
          NSInteger opt = opt_view_intervals_type(i, GMSH_GET, 0);
          [_viewButtons setSelected:YES forSegment:opt-1];
        }
      }
    }

    - (void)updateViewSlider
    {
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        if(opt_view_visible(i, GMSH_GET, 0)) {
          NSInteger opt = opt_view_intervals_type(i, GMSH_GET, 0);
          if(opt-1 == 1 || opt-1 == 3) { // For iso-values and filled iso-values
            _viewSlider.hidden = YES;
          }
          else {
            _viewSlider.hidden = NO;
          }
        }
      }
    }

    - (void)update
    {
      [self updateGeo];
      [self updateMesh];
      [self updateViewMenu];
      [self updateViewButtons];
      [self updateViewSlider];
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

void updateTouchBar()
{
  [touchBarDelegate update];
}
