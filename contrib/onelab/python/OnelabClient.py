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
    ('readOnly', 'int', 0), ('attributes', ('dict', 'string', 'string'), {}),
    ('clients', ('list', 'string'), [])
  ]
  _members = {
    'string' : _membersbase + [
      ('value', 'string',''), ('kind', 'string', 'generic'), ('choices', ('list', 'string'), [])
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
    for i in _parameter._members[self.type] :
      if i[0] in param :
        setattr(self, i[0], param[i[0]]) #NB: no else statement => update


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
  _GMSH_PARAMETER_NOT_FOUND = 29
  _GMSH_PARAMETER_CLEAR = 31
  _GMSH_PARAMETER_UPDATE = 32

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

  def _declare_parameter(self, param) :
    if not self.socket :
      return
    self._send(self._GMSH_PARAMETER_QUERY, param.tochar())
    (t, msg) = self._receive() 
    if t == self._GMSH_PARAMETER :
      self._send(self._GMSH_PARAMETER_UPDATE, param.tochar()) #enrich a previous decl.
    elif t == self._GMSH_PARAMETER_NOT_FOUND :
      self._send(self._GMSH_PARAMETER, param.tochar()) #declaration
    #print param.tochar()
    
  def declareNumber(self, name, **param):
    if 'labels' in param :
      param["choices"] = param["labels"].keys()
    p = _parameter('number', name=name, **param)
    if 'value' not in param : #make the parameter readOnly
      p.readOnly = 1
      p.attributes={'Highlight':'Orchid'}
    self._declare_parameter(p)
    return p.value

  def declareString(self, name, **param):
    p = _parameter('string', name=name, **param)
    if 'value' not in param : #make the parameter readOnly
      p.readOnly = 1
      p.attributes={'Highlight':'Orchid'}
    self._declare_parameter(p)
    return p.value
  
  def setNumber(self, name, **param):
    if not self.socket :
      return
    p = _parameter('number', name=name)
    self._send(self._GMSH_PARAMETER_QUERY, p.tochar())
    (t, msg) = self._receive() 
    if t == self._GMSH_PARAMETER :
      p.fromchar(msg).modify(**param)
      self._send(self._GMSH_PARAMETER, p.tochar())
    elif t == self._GMSH_PARAMETER_NOT_FOUND :
      p.modify(**param)
      self._send(self._GMSH_PARAMETER, p.tochar())
    return p.value

  def setString(self, name, **param):
    if not self.socket :
      return
    p = _parameter('string', name=name)
    self._send(self._GMSH_PARAMETER_QUERY, p.tochar())
    (t, msg) = self._receive() 
    if t == self._GMSH_PARAMETER : #modify an existing parameter
      p.fromchar(msg).modify(**param)
      self._send(self._GMSH_PARAMETER, p.tochar())
    elif t == self._GMSH_PARAMETER_NOT_FOUND : #create a new parameter
      p.modify(**param)
      self._send(self._GMSH_PARAMETER, p.tochar())
    return p.value
  
  def _get_parameter(self, param, warn_if_not_found=True) :
    if not self.socket :
      return
    self._send(self._GMSH_PARAMETER_QUERY, param.tochar())
    (t, msg) = self._receive() 
    if t == self._GMSH_PARAMETER :
      param.fromchar(msg)
    elif t == self._GMSH_PARAMETER_NOT_FOUND and warn_if_not_found :
      print 'Unknown parameter %s' %(param.name)

  def getNumber(self, name, warn_if_not_found=True):
    param = _parameter('number', name=name)
    self._get_parameter(param, warn_if_not_found)
    return param.value

  def getString(self, name, warn_if_not_found=True):
    param = _parameter('string', name=name)
    self._get_parameter(param, warn_if_not_found)
    return param.value

  def geometry(self, filename) :
    if not self.socket or not filename :
      return
    #if self.action == 'compute' and self.getString('Gmsh/MergedGeo', False) == filename :
    if self.getString('Gmsh/MergedGeo', False) == filename :
      return
    else :
      self.setString('Gmsh/MergedGeo', value=filename)
    if filename[0] != '/' :
      filename = os.getcwd() + "/" + filename
    self._send(self._GMSH_MERGE_FILE, filename)

  def mesh(self, filename) :
    if not self.socket :
      return
    self._send(self._GMSH_PARSE_STRING, 'Mesh 3; Save "' + filename + '";')
    
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

  def run(self, name, command, arguments):
    if not self.socket :
      return
    if self.action == "check":
      msg = [name, command]
    else:
      msg = [name, command + ' ' + arguments]
    self._send(self._GMSH_CONNECT, '\0'.join(msg))
    self.NumSubClients +=1
    self._wait_on_subclients() # makes the subclient blocking

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
    self.setNumber('IsPyMetamodel',value=1,visible=0)
    if self.action == "initialize": exit(0)
  
  def __del__(self) :
    self._wait_on_subclients()
    #print "Calling destructor of %s with %d subclients" %(self.name, self.NumSubClients)
    if self.socket :
      self._send(self._GMSH_STOP, 'Goodbye!')
      self.socket.close()



      
