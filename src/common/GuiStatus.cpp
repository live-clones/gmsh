// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The one description of the status bar, walked by both interfaces. See
// GuiStatus.h for why it exists; this file is meant to read like the bar it
// describes.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "GuiStatus.h"
#include "GuiMenus.h"
#include "GuiActions.h"
#include "Gui.h"
#include "Context.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "Options.h"
#include "drawContext.h"

namespace StatusBar {

  namespace {

    // --- little builders, so that the description below is only description

    Button turns(const std::string &label, const std::string &what,
                 const std::string &tooltip, const std::string &glyph = "")
    {
      Button b;
      b.label = label;
      b.glyph = glyph;
      b.tooltip = tooltip;
      b.action = [what](bool reverse, bool sync) {
        Gui::orientViews(what, reverse, sync);
      };
      return b;
    }

    Button drops(const std::string &label, const std::string &tooltip,
                 const std::function<std::vector<Menu::Item>()> &what,
                 const std::string &glyph = "")
    {
      Button b;
      b.label = label;
      b.glyph = glyph;
      b.tooltip = tooltip;
      b.menu = what;
      return b;
    }

    Button does(const std::string &label, const std::string &glyph,
                const std::string &tooltip,
                const std::function<void()> &what)
    {
      Button b;
      b.label = label;
      b.glyph = glyph;
      b.tooltip = tooltip;
      b.action = [what](bool, bool) { what(); };
      return b;
    }

    // the four buttons of the animation, which mean nothing until there is
    // something to animate
    Button animates(Button b)
    {
      b.enabled = []() { return viewIsAnimatable(); };
      return b;
    }

  } // namespace

  std::vector<Button> bar()
  {
    std::vector<Button> buttons;

    buttons.push_back(drops("M", "Set the current (active) model",
                            Menu::models, "gmsh_models"));
    buttons.push_back(
      drops("O",
            "Open the quick access menu (also available by double-clicking in "
            "the graphic window)",
            Menu::quickAccess));

    buttons.push_back(
      turns("X", "x", "Set the +X or -X (Shift) view (Alt+x or Alt+Shift+x)"));
    buttons.push_back(
      turns("Y", "y", "Set the +Y or -Y (Shift) view (Alt+y or Alt+Shift+y)"));
    buttons.push_back(
      turns("Z", "z", "Set the +Z or -Z (Shift) view (Alt+z or Alt+Shift+z)"));
    buttons.push_back(
      turns("R", "r",
            "Rotate +90 or -90 (Shift) degrees, or sync rotations (Ctrl)",
            "gmsh_rotate"));
    {
      Button unit =
        turns("1:1", "1:1",
              "Set unit scale, sync scale between viewports (Ctrl), or reset "
              "bounding box around visible entities (Shift) (Alt+1, Alt+Ctrl+1, "
              "Alt+Shift+1)");
      // "1:1" is not a square
      unit.widthEm = 2.;
      buttons.push_back(unit);
    }

    {
      // It says so when picking is *off*, which is the state one does not
      // expect: the bar this reproduces paints it red then, and leaves it
      // plain the rest of the time.
      Button select = does("S", "", "Toggle mouse selection ON/OFF (Escape)",
                           []() {
                             Gui::setMouseSelection(
                               !CTX::instance()->mouseSelection);
                           });
      select.alert = []() { return !CTX::instance()->mouseSelection; };
      buttons.push_back(select);
    }

    {
      Button rewind = animates(does("|<", "gmsh_rewind", "Rewind animation",
                                    animationRewind));
      rewind.gapBefore = true;
      buttons.push_back(rewind);
    }
    buttons.push_back(animates(does("<", "gmsh_back",
                                    "Step backward (Left arrow)",
                                    []() { animationStepBy(false); })));
    {
      Button play = animates(does(">", "gmsh_play", "Play/pause animation",
                                  Gui::toggleAnimation));
      play.labelOn = "||";
      play.glyphOn = "gmsh_pause";
      play.on = []() { return Gui::animating(); };
      buttons.push_back(play);
    }
    buttons.push_back(animates(does(">|", "gmsh_forward",
                                    "Step forward (Right arrow)",
                                    []() { animationStepBy(true); })));

    return buttons;
  }

  // --- what takes the rest of the bar

  namespace {

    struct messageState {
      std::string text;
      int colour = 0;
      std::string progressText;
      double value = 0., least = 0., most = 0.;
    };

    messageState &_message()
    {
      static messageState state;
      return state;
    }

  } // namespace

  void setMessage(const std::string &text)
  {
    // Only the thread that draws may touch it. The mesher calls Msg::StatusBar
    // from its OpenMP threads, and neither toolkit is re-entrant.
    if(Msg::GetThreadNum() > 0) return;
    _message().text = text;
  }

  void setColour(int colour)
  {
    if(Msg::GetThreadNum() > 0) return;
    _message().colour = colour;
  }

  void setProgress(double value, double least, double most)
  {
    if(Msg::GetThreadNum() > 0) return;
    messageState &m = _message();
    m.value = value;
    m.least = least;
    m.most = most;
  }

  Message message()
  {
    const messageState &m = _message();
    Message out;
    out.text = " " + m.text;
    out.colour = m.colour;
    out.running = (m.most > m.least);
    out.fraction = out.running ? (m.value - m.least) / (m.most - m.least) : 0.;
    out.progressText = m.text;

    // What went wrong, said where one is looking. Only while the console is
    // hidden: with it open the errors are already there to read, and the bar
    // saying so as well would be saying it twice.
    if(Gui::panelVisible(Gui::PanelMessageConsole)) {
      out.colour = Gui::StatusColorDefault;
      return out;
    }
    int errors = Msg::GetErrorCount(), warnings = Msg::GetWarningCount();
    if(!errors && !warnings) return out;
    out.text += "  -  " + std::to_string(errors ? errors : warnings);
    out.text += (errors > 1)     ? " Errors" :
                errors           ? " Error" :
                (warnings > 1)   ? " Warnings" :
                                   " Warning";
    out.text += " : Click to show messages [ ... ";
    out.text += errors ? Msg::GetFirstError() : Msg::GetFirstWarning();
    out.text += " ... ]";
    return out;
  }

  void messagePressed()
  {
    Gui::showPanel(Gui::PanelMessageConsole,
                   !Gui::panelVisible(Gui::PanelMessageConsole));
  }

  std::string messageTooltip()
  {
    return "Show or hide the message console";
  }

} // namespace StatusBar

#endif
