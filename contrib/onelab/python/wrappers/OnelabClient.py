import onelab
import sys

class client :

  def get_number(self, name, default, label = '', min = -sys.float_info.max, max = sys.float_info.max, step = 0, choices = [], labels = [], attributes = {}, help = "", visible = 1, read_only = 0) :
    if not self.client :
      return default
    n = onelab.number(name, default)
    n.setLabel(label)
    n.setVisible(visible)
    n.setReadOnly(read_only)
    n.setMin(min)
    n.setMax(max)
    n.setStep(step)
    n.setHelp(help)
    n.setChoices(choices)
    if labels :
      n.setChoices([k for k in labels.keys()])
      n.setChoiceLabels([v for v in labels.values()])
    for k,v in attributes.items() :
      n.setAttribute(k, v)
    r = onelab.OnelabNumberVector()
    self.client.get(r, n.getName())
    if r :
      return r[0].getValue()
    else :
      self.client.set(n)
      return default

  def get_string(self, name, default, choices = [], help ="", label = "", visible = 1, read_only = 0, kind = "generic", attributes = {}) :
    if not self.client :
      return default
    n = onelab.string(name, default)
    n.setChoices(choices)
    n.setReadOnly(read_only)
    n.setVisible(visible)
    n.setLabel(label)
    n.setHelp(help)
    n.setKind(kind)
    r = onelab.OnelabStringVector()
    for k,v in attributes.items() :
      n.setAttribute(k, v)
    self.client.get(r, n.getName())
    if r :
      return r[0].getValue()
    else :
      self.client.set(n)
      return default

  def __init__(self):
    self.client = None
    self.name = ""
    for i, v in enumerate(sys.argv) :
      if v == '-onelab':
        self.name = sys.argv[i + 1]
        self.client = onelab.remoteNetworkClient(self.name, sys.argv[i+2])
    self.action = self.get_string(self.name + '/Action', 'compute')
    if self.action == "initialize": exit(0)
