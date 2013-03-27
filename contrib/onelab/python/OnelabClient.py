import socket, struct, os, sys
_VERSION = '1.05'

def file_exist(filename):
  try:
    with open(filename) as f:
      return True
  except IOError:
    return False
    

class _parameter() :
  _membersbase = [
    ('name', 'string'), ('label', 'string', ''), ('help', 'string', ''),
    ('neverChanged', 'int', 0), ('changed', 'int', 1), ('visible', 'int', 1),
    ('read_only', 'int', 0), ('attributes', ('dict', 'string', 'string'), {}),
    ('clients', ('list', 'string'), [])
  ]
  _members = {
    'string' : _membersbase + [
      ('value', 'string'), ('kind', 'string', 'generic'), ('choices', ('list', 'string'), [])
    ],
    'number' : _membersbase + [
      ('value', 'float'),
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
    
class client :
  _GMSH_START = 1
  _GMSH_STOP = 2
  _GMSH_INFO = 10
  _GMSH_MERGE_FILE = 20
  _GMSH_PARSE_STRING = 21
  _GMSH_PARAMETER = 23
  _GMSH_PARAMETER_QUERY = 24
  _GMSH_CONNECT = 27
  _GMSH_OLPARSE = 28
  _GMSH_PARAM_NOT_FOUND = 29
  _GMSH_OPTION_1 = 100
  
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
    m = msg.encode('utf-8')
    try:
      if self.socket.send(struct.pack('ii%is' %len(m), t, len(m), m)) == 0 :
        RuntimeError('onelab socket closed')
    except socket.error:
      self.socket.close()
      self._createSocket()
      self.socket.send(struct.pack('ii%is' %len(m), t, len(m), m))

  def _define_parameter(self, param) :
    if not self.socket :
      return
    self._send(self._GMSH_PARAMETER_QUERY, param.tochar())
    (t, msg) = self._receive() 
    if t == self._GMSH_PARAMETER :
      param.fromchar(msg)
    elif t == self._GMSH_PARAM_NOT_FOUND :
      self._send(self._GMSH_PARAMETER, param.tochar())

  def setString(self, name, value, **param):
    param = _parameter('string', name=name, value=value, **param)
    self._define_parameter(param)
    return param.value

  def setNumber(self, name, value, **param):
    if "labels" in param :
      param["choices"] = param["labels"].keys()
    p = _parameter('number', name=name, value=value, **param)
    self._define_parameter(p)
    return p.value

  def _get_parameter(self, param, warn_if_not_found=True) :
    if not self.socket :
      return
    self._send(self._GMSH_PARAMETER_QUERY, param.tochar())
    (t, msg) = self._receive() 
    if t == self._GMSH_PARAMETER :
      param.fromchar(msg)
    elif t == self._GMSH_PARAM_NOT_FOUND and warn_if_not_found :
      print 'Unknown parameter %s' %(param.name)

  def getNumber(self, name, warn_if_not_found=True):
    param = _parameter('number', name=name, value=0)
    self._get_parameter(param, warn_if_not_found)
    return param.value

  def getString(self, name, warn_if_not_found=True):
    param = _parameter('string', name=name, value='void')
    self._get_parameter(param, warn_if_not_found)
    return param.value

  def showGeometry(self, filename) :
    if not self.socket or not filename :
      return
    if self.getString('Gmsh/MergedGeo', False) == filename :
      return
    else :
      self.setString('Gmsh/MergedGeo', filename)
    if filename[0] != '/' :
      filename = os.getcwd() + "/" + filename
    self._send(self._GMSH_MERGE_FILE, filename)
    
  def mergeFile(self, filename) :
    if not self.socket :
      return
    if filename and filename[0] != '/' :
      filename = os.getcwd() + "/" + filename;
    self._send(self._GMSH_PARSE_STRING, 'Merge "' + filename + '";')

  def preProcess(self, filename) :
    if not self.socket :
      return
    if filename and filename[0] != '/' :
      filename = os.getcwd() + "/" + filename;
    self._send(self._GMSH_OLPARSE, filename)

  def _createSocket(self) :
    addr = self.addr
    if '/' in addr or '\\' in addr or ':' not in addr :
      self.socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    else :
      self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.socket.connect(addr)
    #self.socket.setblocking(1)
    #self.socket.settimeout(5.0)

  def _wait_on_subclients(self):
    if not self.socket :
      return
    while self.NumSubClients > 0:
      (t, msg) = self._receive() 
      if t == self._GMSH_STOP :
        self.NumSubClients -= 1

  def run(self, name, command):
    msg = [name, command]
    if not self.socket :
      return
    self._send(self._GMSH_CONNECT, '\0'.join(msg))
    self.NumSubClients +=1
    self._wait_on_subclients()

  def __init__(self):
    self.socket = None
    self.name = ""
    self.addr = ""
    self.NumSubClients = 0
    for i, v in enumerate(sys.argv) :
      if v == '-onelab':
        self.name = sys.argv[i + 1]
        self.addr = sys.argv[i + 2]
        self._createSocket()
        self._send(self._GMSH_START, str(os.getpid()))
    self.action = self.getString('python/Action')
    if self.action == "initialize": exit(0)
  
  def __del__(self) :
    if self.socket :
      self._wait_on_subclients()
      self._send(self._GMSH_STOP, 'Goodbye!')
      self.socket.close()

## wait_on_clients
## a la fin de sub_client
## envoyer GMSH_STOP seulement si les sous-clients sont termines.
## et modif dans onelabGroup run pour interdire au main
## de fermer les sockets de clients non-termines.

      
