"""
ONELAB - Copyright (C) 2011-2022 Universite de Liege - Universite catholique
de Louvain

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
provided that the above copyright notice(s) and this permission notice appear in
all copies of the Software and that both the above copyright notice(s) and this
permission notice appear in supporting documentation.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT
SHALL THE COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY
CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

"""

#!/usr/bin/env python

import socket, struct, os, sys, subprocess, time
_VERSION = '1.3'

def path(dirname, inp):
  # dirname is a directory, can be empty
  # inp is an optional file or subdirectory name
  # returns the path to 'inp' in the same directory as 'ref'
  if dirname:
    dirname = os.path.dirname(dirname + os.sep)
  if not inp:
    return dirname
  if inp[0] == '/' or inp[0] == '\\' or (len(inp) > 2 and inp[1] == '\:'):
    return inp # do nothing, inp is an absolute path
  if inp[0] == '.' :
    inp = inp[2:] # cut off heading './' or '.\'
  if dirname:
    return dirname + os.sep + inp # append inp to the path of the reference file
  else:
    return inp

class _parameter() :
  _membersbase = [
    ('name', 'string'), ('label', 'string', ''), ('help', 'string', ''),
    ('changedValue', 'int', 31), ('visible', 'int', 1), ('readOnly', 'int', 0),
    ('attributes', ('dict', 'string', 'string'), {}),
    ('clients', ('dict', 'string', 'int'), {})
  ]
  _members = {
    'string' : _membersbase + [
      ('values', ('list', 'string'), ['']), ('kind', 'string', 'generic'),
      ('choices', ('list', 'string'), [])
    ],
    'number' : _membersbase + [
      ('values', ('list', 'float'), [0.]),
      ('min', 'float', -sys.float_info.max), ('max', 'float', sys.float_info.max),
      ('step', 'float', 0.), ('index', 'int', -1), ('choices', ('list', 'float'), []),
      ('labels', ('dict', 'float', 'string'), {})
    ]
  }

  def __init__(self, type, **values) :
    self.type = type
    for i in _parameter._members[self.type] :
      setattr(self, i[0], values[i[0]] if i[0] in values else i[2])

  def tochar(self) :
    def tocharitem(l, t, v) :
      if t == 'string' : l.append(v)
      elif t =='int': l.append(str(v))
      elif t == 'float' : l.append('%.16g' % v)
      elif t[0] == 'list' :
        l.append(str(len(v)))
        for i in v : tocharitem(l, t[1], i)
      elif t[0] == 'dict' :
        l.append(str(len(v)))
        for i, j in v.items() :
          tocharitem(l, t[1], i)
          tocharitem(l, t[2], j)
    msg = [_VERSION, self.type]
    for i in _parameter._members[self.type] :
      tocharitem(msg, i[1], getattr(self, i[0]))
    return '\0'.join(msg)

  def fromchar(self, msg) :
    def fromcharitem(l, t) :
      if t == 'string' : return l.pop()
      elif t =='int': return int(l.pop())
      elif t == 'float' : return float(l.pop())
      elif t[0] == 'list' : return [fromcharitem(l, t[1]) for i in range(int(l.pop()))]
      elif t[0] == 'dict' : return dict([(fromcharitem(l, t[1]),fromcharitem(l, t[2]))
                                       for i in range(int(l.pop()))])
    l = msg.split('\0')
    l.reverse()
    if l.pop() != _VERSION :
      print('onelab version mismatch')
    if l.pop() != self.type :
      print('onelab parameter type mismatch')
    for p in  _parameter._members[self.type]:
      setattr(self, p[0], fromcharitem(l, p[1]))
    return self

  def modify(self, **param) :
    ## updates the parameter with the content of param, attributes are merged
    for i in _parameter._members[self.type] :
      if i[0] in param :
        if i[0] == 'attributes' :
          self.attributes.update(param['attributes'])
        else :
          setattr(self, i[0], param[i[0]])


class client :
  _GMSH_START = 1
  _GMSH_STOP = 2
  _GMSH_INFO = 10
  _GMSH_WARNING = 11
  _GMSH_ERROR = 12
  _GMSH_PROGRESS = 13
  _GMSH_MERGE_FILE = 20
  _GMSH_PARSE_STRING = 21
  _GMSH_PARAMETER = 23
  _GMSH_PARAMETER_QUERY = 24
  _GMSH_PARAMETER_QUERY_ALL = 25
  _GMSH_PARAMETER_QUERY_END = 26
  _GMSH_CONNECT = 27
  _GMSH_OLPARSE = 28
  _GMSH_PARAMETER_NOT_FOUND = 29
  _GMSH_PARAMETER_CLEAR = 31
  _GMSH_PARAMETER_UPDATE = 32
  _GMSH_OPEN_PROJECT = 33
  _GMSH_CLIENT_CHANGED = 34

  def _createSocket(self) :
    addr = self.addr
    if '/' in addr or '\\' in addr or ':' not in addr :
      self.socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
      self.socket.connect(addr)
    else :
      self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
      s = addr.split(':')
      self.socket.connect((s[0], int(s[1])))

  def _receive(self) :
    def buffered_receive(l) :
      msg = b''
      while len(msg) < l:
        chunk = self.socket.recv(l - len(msg))
        if not chunk :
          RuntimeError('onelab socket closed')
        msg += chunk
      return msg
    msg = buffered_receive(struct.calcsize('ii'))
    t, l = struct.unpack('ii', msg)
    msg = buffered_receive(l).decode('utf-8')
    if t == self._GMSH_INFO :
      print('onelab info : %s' % msg)
    return t, msg

  def _send(self, t, msg) :
    if not self.socket :
      return
    m = msg.encode('utf-8')
    try:
      if self.socket.send(struct.pack('ii%is' %len(m), t, len(m), m)) == 0 :
        RuntimeError('onelab socket closed')
    except socket.error:
      self.socket.close()
      self._createSocket()
      self.socket.send(struct.pack('ii%is' %len(m), t, len(m), m))

  def _defineParameter(self, p) :
    if not self.socket :
      return p.values
    self._send(self._GMSH_PARAMETER_QUERY, p.tochar())
    (t, msg) = self._receive()
    if t == self._GMSH_PARAMETER :
      self._send(self._GMSH_PARAMETER_UPDATE, p.tochar())
      return p.fromchar(msg).values
    elif t == self._GMSH_PARAMETER_NOT_FOUND :
      self._send(self._GMSH_PARAMETER, p.tochar())
      return p.values

  def _getParameter(self, param, warn_if_not_found=True) :
    if not self.socket :
      return
    self._send(self._GMSH_PARAMETER_QUERY, param.tochar())
    (t, msg) = self._receive()
    if t == self._GMSH_PARAMETER :
      param.fromchar(msg)
    elif t == self._GMSH_PARAMETER_NOT_FOUND and warn_if_not_found :
      print ('Unknown parameter %s' %(param.name))

  def _getAllParameters(self, type, lst) :
    if not self.socket :
      return
    self._send(self._GMSH_PARAMETER_QUERY_ALL,
               _parameter(type, name='dummy').tochar())
    (t, msg) = self._receive()
    while t == self._GMSH_PARAMETER_QUERY_ALL:
      lst.append(_parameter(type, name='dummy').fromchar(msg))
      (t, msg) = self._receive()

  def defineNumber(self, name, **param):
    if 'value' in param :
      param["values"] = [param["value"]]
      del param["value"]
    if 'labels' in param :
      param["choices"] = param["labels"].keys()
    p = _parameter('number', name=name, **param)
    values = self._defineParameter(p)
    return values[0] if len(values) else 0

  def defineString(self, name, **param):
    if 'value' in param :
      param["values"] = [param["value"]]
      del param["value"]
    p = _parameter('string', name=name, **param)
    values = self._defineParameter(p)
    return values[0] if len(values) else ''

  def setNumber(self, name, **param):
    if not self.socket :
      return
    if 'value' in param :
      param["values"] = [param["value"]]
      del param["value"]
    p = _parameter('number', name=name)
    self._send(self._GMSH_PARAMETER_QUERY, p.tochar())
    (t, msg) = self._receive()
    if t == self._GMSH_PARAMETER :
      p.fromchar(msg).modify(**param)
    elif t == self._GMSH_PARAMETER_NOT_FOUND :
      p.modify(**param)
    self._send(self._GMSH_PARAMETER, p.tochar())

  def setString(self, name, **param):
    if not self.socket :
      return
    if 'value' in param :
      param["values"] = [param["value"]]
      del param["value"]
    p = _parameter('string', name=name)
    self._send(self._GMSH_PARAMETER_QUERY, p.tochar())
    (t, msg) = self._receive()
    if t == self._GMSH_PARAMETER : #modify an existing parameter
      p.fromchar(msg).modify(**param)
    elif t == self._GMSH_PARAMETER_NOT_FOUND : #create a new parameter
      p.modify(**param)
    self._send(self._GMSH_PARAMETER, p.tochar())

  def clear(self, name) :
    if not self.socket :
      return
    self._send(self._GMSH_PARAMETER_CLEAR, str(name))

  def _setNumberChoices(self, name, val):
    if not self.socket :
      return
    p = _parameter('number', name=name)
    self._send(self._GMSH_PARAMETER_QUERY, p.tochar())
    (t, msg) = self._receive()
    if t == self._GMSH_PARAMETER :
      if len(val) : # add new choices
        p.fromchar(msg).values = val
        p.choices.extend(val)
      else : # reset choices list
        p.fromchar(msg).choices = ()
    elif t == self._GMSH_PARAMETER_NOT_FOUND :
      print ('Unknown parameter %s' %(param.name))
    self._send(self._GMSH_PARAMETER, p.tochar())

  def resetNumberChoices(self, name):
    self._setNumberChoices(name,[])

  def addNumberChoice(self, name, value):
    self._setNumberChoices(name,[value])

  def getNumber(self, name, warn_if_not_found=True):
    param = _parameter('number', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.values[0] if len(param.values) else 0

  def getNumbers(self, name, warn_if_not_found=True):
    param = _parameter('number', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.values

  def getString(self, name, warn_if_not_found=True):
    param = _parameter('string', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.values[0] if len(param.values) else ''

  def getStrings(self, name, warn_if_not_found=True):
    param = _parameter('string', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.values

  def getAllParameters(self):
    lst = []
    self._getAllParameters('number', lst)
    self._getAllParameters('string', lst)
    dic = {}
    for p in lst:
      dic[p.name] = {a[0]: getattr(p, a[0])
                     for a in _parameter._members[p.type]}
    return dic

  def getNumberChoices(self, name, warn_if_not_found=True):
    param = _parameter('number', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.choices

  def getStringChoices(self, name, warn_if_not_found=True):
    param = _parameter('string', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.choices

  def getNumberRange(self, name, warn_if_not_found=True):
    param = _parameter('number', name=name)
    self._getParameter(param, warn_if_not_found)
    return [param.values[0] if len(param.values) else 0, param.min, param.max]

  def show(self, name) :
    if not self.socket or not name:
      return
    param = _parameter('number', name=name)
    self._send(self._GMSH_PARAMETER_QUERY, param.tochar())
    (t, msg) = self._receive()
    if t == self._GMSH_PARAMETER :
      print (msg.replace('\0','|'))
    elif t == self._GMSH_PARAMETER_NOT_FOUND :
      param = _parameter('string', name=name)
      self._send(self._GMSH_PARAMETER_QUERY, param.tochar())
      (t, msg) = self._receive()
      if t == self._GMSH_PARAMETER :
        print (msg.replace('\0','|'))
      elif t == self._GMSH_PARAMETER_NOT_FOUND :
        print('Unknown parameter %s' %(name))

  def sendCommand(self, command) :
    if not self.socket :
      return
    self._send(self._GMSH_PARSE_STRING, command)

  def mergeFile(self, filename) :
    if not self.socket or not filename :
      return
    self._send(self._GMSH_MERGE_FILE, filename)

  def openProject(self, filename) :
    if not self.socket or not filename :
      return
    self._send(self._GMSH_OPEN_PROJECT, filename)

  def sendInfo(self, msg) :
    if not self.socket :
      print (msg)
      return
    self._send(self._GMSH_INFO, str(msg))

  def sendWarning(self, msg) :
    if not self.socket :
      print (msg)
      return
    self._send(self._GMSH_WARNING, str(msg))

  def sendError(self, msg) :
    if not self.socket :
      print (msg)
      return
    self._send(self._GMSH_ERROR, str(msg))

  def preProcess(self, name, filename) :
    if not self.socket :
      return
    msg = [name, filename]
    self._send(self._GMSH_OLPARSE, '\0'.join(msg))
    (t, msg) = self._receive()
    if t == self._GMSH_OLPARSE :
      if msg == "true" :
          return True
    return False

  def isChanged(self, name) :
    if not self.socket :
      return
    msg = ["get", name]
    self._send(self._GMSH_CLIENT_CHANGED, '\0'.join(msg))
    (t, msg) = self._receive()
    if t == self._GMSH_CLIENT_CHANGED :
      if msg == "true" :
          return True
    return False

  def setChanged(self, name, changed) :
    if not self.socket :
      return
    msg = ["set", name, 'true' if changed else 'false']
    self._send(self._GMSH_CLIENT_CHANGED, '\0'.join(msg))

  def waitOnSubClients(self):
    if not self.socket :
      return
    while self._numSubClients > 0:
      (t, msg) = self._receive()
      if t == self._GMSH_STOP :
        self._numSubClients -= 1

  def runNonBlockingSubClient(self, name, command, arguments=''):
    if self.action == 'check':
      cmd = command
    else:
      cmd = command + ' ' + arguments
    if not self.socket :
      return os.system(cmd);
    msg = [name, cmd]
    self._send(self._GMSH_CONNECT, '\0'.join(msg))
    self._numSubClients +=1

  def runSubClient(self, name, command, arguments=''):
    self.runNonBlockingSubClient(name, command, arguments)
    self.waitOnSubClients() # makes the subclient blocking
    if self.action == 'compute':
      self.setChanged(name, False)

  def run(self, name, command, arguments=''):
    self.runSubClient(name, command, arguments)

  def __init__(self, ref=''):
    self.socket = None
    self.name = ""
    self.addr = ""
    self.wdir = os.path.dirname(ref)
    self._numSubClients = 0
    for i, v in enumerate(sys.argv) :
      if v == '-onelab':
        self.name = sys.argv[i + 1]
        self.addr = sys.argv[i + 2]
        self._createSocket()
        self._send(self._GMSH_START, str(os.getpid()))
    self.action = self.getString(self.name + '/Action', False)
    self.setNumber('IsPyMetamodel',values=[1],visible=0)
    self.loop = self.getNumber('0Metamodel/Loop', warn_if_not_found=False)
    self.batch = self.getNumber('0Metamodel/Batch', warn_if_not_found=False)
    self.sendInfo("Performing OneLab '" + self.action + "'")
    if self.action == "initialize":
      self.finalize()
      exit(0)

  def finalize(self):
    # code aster python interpreter does not call the destructor at exit, it is
    # necessary to call finalize() epxlicitely
    if self.socket :
      self.waitOnSubClients()
      self._send(self._GMSH_STOP, 'Goodbye!')
      self.socket.close()
      self.socket = None

  def __del__(self):
    self.finalize()

  def call(self, name, cmdline, remote='', rundir='', logfile='', poll=0):
    cwd = None
    if not remote :
      argv = cmdline.rsplit(' ')
      if rundir :
        cwd = rundir
    else :
      argv=['ssh', remote , "cd %s ; %s" %(rundir,cmdline) ]

    if poll and not logfile :
        logfile = os.devnull
    if logfile:
      call = subprocess.Popen(argv, bufsize=1, cwd=cwd,
                              stdout=open(logfile,"w"),
                              stderr=subprocess.STDOUT)
      while call.poll() == None :
        self.action = self.getString(self.name + '/Action', False)
        if self.action == 'stop':
          call.terminate()
          self._send(self._GMSH_WARNING, 'client killed')
          sys.exit(1)
        time.sleep(1) # check every second for the stop signal from Gmsh
    else:
      call = subprocess.Popen(argv, bufsize=1, cwd=cwd,
                              stdout=subprocess.PIPE,
                              stderr=subprocess.STDOUT)
      count = 0
      for line in iter(call.stdout.readline, b''):
        print(line.rstrip())
        count += 1
        if count == 50 : # check every 50 lines for the stop signal from Gmsh
          count = 0
          self.action = self.getString(self.name + '/Action', False)
          if self.action == 'stop':
            call.terminate()
            self._send(self._GMSH_WARNING, 'client killed')
            sys.exit(1)

    result = call.wait()
    if result == 0 :
      self._send(self._GMSH_INFO, 'done \"' + ' '.join(argv) + '\"')
      if self.action == 'compute':
        self.setChanged(name, False)
    else :
      self._send(self._GMSH_ERROR, 'error \"' + ' '.join(argv) + '\"')
      sys.exit(1)

  def copy(self, here, there):
    os.system('cp '+ here + ' ' + there)

  def upload(self, here, there, remote='') :
    if not here or not there :
      return
    if remote :
      argv=['rsync','-e','ssh','-auv', here, remote + ':' + there]
    else :
      argv=['cp','-f', here, there]

    call = subprocess.Popen(argv, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
    result = call.wait()
    if result == 0 :
      self._send(self._GMSH_INFO, 'upload: ' + ' '.join(argv))
    else :
      print(call.stderr.read())

  def download(self, there, here, remote='') :
    if not here or not there :
      return
    if remote :
      argv=['rsync','-e','ssh','-auv', remote + ':' + there, here]
    else :
      argv=['cp','-f', there, here]

    call = subprocess.Popen(argv, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
    result = call.wait()
    if result == 0 :
      self._send(self._GMSH_INFO, 'download: ' + ' '.join(argv))
    else :
      print(call.stderr.read())

  def getPath(self, inp='') :
    return path(self.wdir, inp)

  def fileExists(self, p) :
    return os.path.exists(p)

  def checkFile(self, p) :
    if not self.fileExists(p):
      self.sendError('path error: %s' %(p))
      exit(0)
    return True

  def checkPath(self, inp='') :
    p = path(self.wdir,inp)
    self.checkFile(p)
    return p

  def solutionFiles(self, client, list) :
    self.defineNumber('0Metamodel/9Use restored solution', values=[0], choices=[0,1])
    self.defineString('0Metamodel/9Tag', values=[''])
    if list :
      if self.getNumber('0Metamodel/9Use restored solution') :
        solFiles = self.getStringChoices('0Metamodel/9Solution files')
        for i in solFiles:
          self.checkFile(i)
      else :
        solFiles = list
        self.setString('0Metamodel/9Solution files', values=[solFiles[0]],
                       choices=solFiles, readOnly=1)
        for i in solFiles:
          if not self.fileExists(i) :
            self.setChanged(client, 'true')
    return solFiles

  def needsCompute(self, client) :
    # Avoid recomputation when a database with restored solutions has just been loaded
    # Otherwise, stop using restored solutions when the client elmer has changed
    if self.useRestoredSolution() == 2: # we have just loaded a database
      self.setRestoredSolution(1)
      self.setChanged(client, 'false') # do not compute
    else :
      if self.isChanged(client):
        self.setRestoredSolution(0)
        return True
    return False

  def willCompute(self, client) : # Inform user about the value of needsCompute
    if self.useRestoredSolution() == 2: # special value
      return False
    else :
      return True if self.isChanged(client) else False

  def useRestoredSolution(self) :
    return self.getNumber('0Metamodel/9Use restored solution')

  def setRestoredSolution(self, val) :
    self.setNumber('0Metamodel/9Use restored solution', values=[val])

  def outputFiles(self, list) :
    if list :
      self.setString('0Metamodel/9Output files', values=[list[0]],
                     choices=list, visible=1)

# tool to extract the (i, j)th element in an array file
# from rlcompleter import readline
def extract(filename,i,j):
    input = open(filename,'r')
    all_lines = input.readlines()
    input.close()
    if i == -1:
        i = len(all_lines) # last line
    items = all_lines[i-1].split()
    return float(items[j-1])
