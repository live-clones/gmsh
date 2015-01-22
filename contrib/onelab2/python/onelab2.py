"""
OneLab - Copyright (C) 2011-2014 ULg-UCL

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished
to do so, provided that the above copyright notice(s) and this
permission notice appear in all copies of the Software and that
both the above copyright notice(s) and this permission notice
appear in supporting documentation.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
OF THIS SOFTWARE.

Please report all bugs and problems to the public mailing list
<gmsh@geuz.org>.
"""

import socket, struct, os, sys, subprocess
_VERSION = 2
_ONELAB_PARAMETER = {
  'number' : 0x06,
  'string' : 0x07}

def file_exist(filename):
  try:
    with open(filename) as f:
      return True
  except IOError:
    return False

def path(dirname, inp):
  # dirname is a directory, can be empty
  # inp is an optional file or subdirectory name
  # returns the path to 'inp' in the same directory as 'ref' 
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
    ('neverChanged', 'bool', 0), ('visible', 'bool', 1), ('readOnly', 'bool', 0), 
    ('attributes', ('dict', 'string', 'string'), {}),
    ('clients', ('dict', 'string', 'bool'), {})
  ]
  _members = {
    'string' : _membersbase + [
      ('value', 'string',''), ('kind', 'string', 'generic'), 
      ('choices', ('list', 'string'), [])
    ],
    'number' : _membersbase + [
      ('value', 'float',0),
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
      if t=='string' : l.append(v)
      elif t =='int': l.append(str(v))
      elif t=='float' : l.append('%.16g' % v)
      elif t[0]=='list' : 
        l.append(str(len(v)))
        for i in v : tocharitem(l, t[1], i)
      elif t[0]=='dict' :
        l.append(str(len(v)))
        for i, j in v.items() :
          tocharitem(l, t[1], i)
          tocharitem(l, t[2], j)
    msg = [_VERSION, self.type]
    for i in _parameter._members[self.type] :
      tocharitem(msg, i[1], getattr(self, i[0]))
    return '\0'.join(msg)

  def tobytes(self):
    def tobytesitem(t, v):
      val = None
      if t=='string':
        val = v+'\0'
      elif t=='bool':
        val = struct.pack('!B', v)
      elif t=='int':
        val = struct.pack('!i', v)
      elif t=='float':
        val = struct.pack('!d', v)
      elif t[0]=='list':
        val = struct.pack('!H', len(v))
        for i in v:
          val += tobytesitem(t[1], i)
      elif t[0]=='dict':
        val = struct.pack('!H', len(v))
        for i, j in v.items():
          val += tobytesitem(t[1], i)
          val += tobytesitem(t[2], j)
      return val
    msg = ''
    for i in _parameter._members[self.type]:
      msg += tobytesitem(i[1], getattr(self, i[0]))
    return struct.pack('!HH', _ONELAB_PARAMETER[self.type], len(msg)) + msg

  def frombytes(self, b):
    def frombytesitem(p_w, t):
      p = p_w[0]
      val = None
      if t=='string':
        val = p[:p.index('\0')]
        p_w[0] = p[p.index('\0')+1:]
      elif t=='bool':
        val = struct.unpack('!B', p[:1])[0]
        p_w[0] = p[1:]
      elif t=='int':
        val = struct.unpack('!i', p[:4])[0]
        p_w[0] = p[4:]
      elif t=='float':
        val = struct.unpack('!d', p[:8])[0]
        p_w[0] = p[8:]
      elif t[0]=='list':
        l = struct.unpack('!H', p[:2])[0]
        p_w[0] = p[2:]
        val = [frombytesitem(p_w, t[1]) for i in range(l)]
      elif t[0]=='dict':
        l = struct.unpack('!H', p[:2])[0]
        p_w[0] = p[2:]
        val = dict([(frombytesitem(p_w, t[1]), frombytesitem(p_w, t[2])) for i in range(l)])
      return val
    tmp = [b[4:]]
    for p in _parameter._members[self.type]:
      setattr(self, p[0], frombytesitem(tmp, p[1]))
    return self

  def fromchar(self, msg) :
    def fromcharitem(l, t) :
      if t=='string' : return l.pop()
      elif t =='int': return int(l.pop())
      elif t=='float' : return float(l.pop())
      elif t[0]=='list' : return [fromcharitem(l, t[1]) for i in range(int(l.pop()))]
      elif t[0]=='dict' : return dict([(fromcharitem(l, t[1]),fromcharitem(l, t[2])) for i in range(int(l.pop()))])
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
  _ONELAB_START   = 0x10
  _ONELAB_STOP    = 0x11
  _ONELAB_MESSAGE = 0x12
  _ONELAB_REQUEST = 0x13
  _ONELAB_RESPONSE= 0x14
  _ONELAB_UPDATE  = 0x15


  def _createSocket(self) :
    addr = self.addr
    if '/' in addr or '\\' in addr or ':' not in addr :
      self.socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
      self.socket.connect(addr)
    else :
      self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
      s = addr.split(':')
      self.socket.connect((s[0], int(s[1])))

  def _send(self, t, m=''):
    if not self.socket :
      return

    try:
      if self.socket.send(struct.pack('!BBH', _VERSION, t, len(m))+m) == 0 :
        RuntimeError('onelab socket closed')
    except socket.error:
      self.socket.close()
      self._createSocket()
      #self.socket.send(struct.pack('ii%is' %len(m), t, len(m), m))

  def _clearbuffer(self):
    self.socket.recv(1024)

  def _receive(self) :
    def buffered_receive(l) :
      msg = b''
      while len(msg) < l:
        chunk = self.socket.recv(l - len(msg))
        if not chunk :
          RuntimeError('onelab socket closed')
        msg += chunk
      return msg
    msg = buffered_receive(struct.calcsize('BBH'))
    v, t, l = struct.unpack('!BBH', msg)
    if v != _VERSION :
      RuntimeError('onelab version mismatch')
    msg = buffered_receive(l)
    if t == self._ONELAB_MESSAGE :
      print('onelab info : %s' % msg)
    return t, msg

  def _getParameter(self, param, warn_if_not_found=True) :
    def extract_attr(b):
      print(len(b))
      t, l = struct.unpack('!HH', b[:4])
      if l+4 > len(b):
        RuntimeError('onelab invalid parameter')
      return t ,b[4:]

    if not self.socket :
      return
    self._send(self._ONELAB_REQUEST, struct.pack('!HHB', 0x05, len(param.name)+1, _ONELAB_PARAMETER[param.type])+param.name)
    (t, msg) = self._receive()
    if t == self._ONELAB_RESPONSE :
      ptype, p = extract_attr(msg)
      if ptype == 0x06 or ptype == 0x05:
        print("recv")
        param.frombytes(msg)
      elif ptype == 0x0A and warn_if_not_found:
        print('Unknown parameter %s' %(param.name))

  def getString(self, name, warn_if_not_found=True):
    param = _parameter('string', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.value

  def getNumber(self, name, warn_if_not_found=True):
    param = _parameter('number', name=name)
    self._getParameter(param, warn_if_not_found)
    return param.value

  def setNumber(self, name, **param):
    if not self.socket :
      return
    p = _parameter('number', name=name)
    self._getParameter(p, False)
    p.modify(**param)
    self._send(self._ONELAB_UPDATE, p.tobytes())

  def _sendMessage(self, msg, lvl=5):
    if not self.socket :
      print (msg)
      return
    self._send(self._ONELAB_MESSAGE, struct.pack("!HHB", 0x0A, len(msg)+1, lvl)+msg)

  def sendInfo(self, msg) :
    self._sendMessage(msg+'\0')

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
        self._send(self._ONELAB_START, struct.pack('!HH', 0x04, len(self.name))+self.name)
        self._receive() # wait for the server to reply
        self._clearbuffer()
    self.action = "compute" # default (subclients have no client.Action defined)
    self.action = self.getString(self.name + '/Action', False)
    self.setNumber('IsPyMetamodel',value=1,visible=0)
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
      #TODO self.waitOnSubClients()
      self._send(self._ONELAB_STOP)
      self._receive()
      self.socket.close()
      self.socket = None
    
  def __del__(self):
    self.finalize()

# tool to extract the (i, j)th element in an array file
#from rlcompleter import readline
def extract(filename,i,j):
    input = open(filename,'r')
    all_lines = input.readlines()
    input.close()
    if i == -1:
        i = len(all_lines) # last line
    items = all_lines[i-1].split()
    return float(items[j-1])
