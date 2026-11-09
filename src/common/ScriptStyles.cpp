// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cctype>
#include <map>
#include <set>
#include "GmshConfig.h"
#include "ScriptStyles.h"
#include "ScriptWords.h"
#include "Options.h"
#include "StringUtils.h"

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#endif

#if defined(HAVE_MESH)
#include "GModel.h"
#include "Field.h"
#endif

// the words of a language, and the names of the options of Gmsh by category
struct language {
  std::set<std::string> words;
  std::map<std::string, std::set<std::string>> options;
};

// the language of a file, by its extension, or none; the .geo language with
// the names Gmsh knows as it runs: its options, plugins and fields
static const language *languageOf(const std::string &fileName)
{
  static language geo, pro;
  if(geo.words.empty()) {
    geo.words.insert(std::begin(geoWords), std::end(geoWords));
#if defined(HAVE_PLUGINS)
    for(auto it = PluginManager::instance()->begin();
        it != PluginManager::instance()->end(); ++it)
      geo.words.insert(it->first);
#endif
#if defined(HAVE_MESH)
    for(auto &f : GModel::current()->getFields()->mapTypeName)
      geo.words.insert(f.first);
#endif
    for(const char *c : {"General", "Geometry", "Mesh", "Solver",
                         "PostProcessing", "View", "Print"}) {
      std::vector<std::string> names = GetOptionNames(c);
      geo.options[c].insert(names.begin(), names.end());
    }
    pro.words.insert(std::begin(proWords), std::end(proWords));
  }
  std::string ext = SplitFileName(fileName)[2];
  for(char &c : ext) c = (char)tolower(c);
  if(ext == ".geo" || ext == ".opt") return &geo;
  if(ext == ".pro") return &pro;
  return nullptr;
}

static bool isWordStart(char c)
{ return isalpha((unsigned char)c) || c == '_'; }
static bool isWordPart(char c) { return isalnum((unsigned char)c) || c == '_'; }

// the end of the word starting at i
static int wordEnd(const std::string &t, int i)
{
  int n = (int)t.size();
  while(i < n && isWordPart(t[i])) i++;
  return i;
}

// the end of the option of Gmsh starting with the category ending at j
// ("Mesh" of "Mesh.Algorithm", "View" of "View[0].Visible", "Geometry" of
// "Geometry.Color.Points"), or -1 if there is none
static int optionEnd(const std::string &t, const std::string &category, int j,
                     const language &l)
{
  auto it = l.options.find(category);
  if(it == l.options.end()) return -1;
  int n = (int)t.size();
  if(j < n && t[j] == '[') { // an index
    while(j < n && t[j] != ']' && t[j] != '\n') j++;
    j++;
  }
  if(j + 1 >= n || t[j] != '.' || !isWordStart(t[j + 1])) return -1;
  int k = wordEnd(t, j + 1);
  std::string name = t.substr(j + 1, k - j - 1);
  if(name == "Color" && k + 1 < n && t[k] == '.' && isWordStart(t[k + 1])) {
    int m = wordEnd(t, k + 1);
    name += "." + t.substr(k + 1, m - k - 1);
    k = m;
  }
  return it->second.count(name) ? k : -1;
}

std::string GetScriptStyles(const std::string &fileName, const std::string &t)
{
  int n = (int)t.size();
  std::string style(n, (char)StylePlain);
  const language *l = languageOf(fileName);
  if(!l) return style;
  auto fill = [&](int from, int to, char s) {
    for(int k = from; k < to; k++) style[k] = s;
  };
  int i = 0;
  while(i < n) {
    char c = t[i], next = (i + 1 < n) ? t[i + 1] : 0;
    int j = i + 1;
    if(c == '/' && next == '/') { // to the end of the line
      while(j < n && t[j] != '\n') j++;
      fill(i, j, StyleComment);
    }
    else if(c == '/' && next == '*') { // to the next */
      j = i + 2;
      while(j < n && !(t[j] == '*' && j + 1 < n && t[j + 1] == '/')) j++;
      j = std::min(n, j + 2);
      fill(i, j, StyleComment);
    }
    else if(c == '"') { // to the next " not escaped, on the line
      while(j < n && t[j] != '"' && t[j] != '\n') j += (t[j] == '\\') ? 2 : 1;
      j = std::min(n, j + 1);
      fill(i, j, StyleString);
    }
    else if(isdigit((unsigned char)c) ||
            (c == '.' && isdigit((unsigned char)next))) {
      while(j < n && (isalnum((unsigned char)t[j]) || t[j] == '.' ||
                      ((t[j] == '+' || t[j] == '-') &&
                       (t[j - 1] == 'e' || t[j - 1] == 'E'))))
        j++;
      fill(i, j, StyleNumber);
    }
    else if(c == '$' && isWordStart(next)) { // a current value of GetDP
      j = wordEnd(t, i + 1);
      if(l->words.count(t.substr(i + 1, j - i - 1))) fill(i, j, StyleWord);
    }
    else if(isWordStart(c)) {
      j = wordEnd(t, i);
      std::string word = t.substr(i, j - i);
      int k = optionEnd(t, word, j, *l);
      if(k > 0) {
        fill(i, k, StyleOption);
        j = k;
      }
      else if(l->words.count(word))
        fill(i, j, StyleWord);
    }
    i = j;
  }
  return style;
}
