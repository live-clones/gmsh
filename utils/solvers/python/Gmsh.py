#!/usr/bin/env python
"""Gmsh.py - Python module for interacting with the Gmsh pre/post processor.

Module functions:
    getopt() -- Parse command line options
    send() -- Send a string to the Gmsh socket if open

Included classes:
    Client -- A class for maintaining socket communication with Gmsh.
    Mesh -- A class for storing nodes and elements.

Typical use:
    import sys
    import Gmsh
    opt = Gmsh.getopt(sys.argv[1:])
    if opt.has_key('--socket'):
        c = Gmsh.Client(opt['--socket'])
    Gmsh.send('Testing testing', Gmsh.INFO)

Carl Osterwisch <osterwischc@asme.org>, January 2005
"""

import socket
import struct
import time
import os
import sys

START    = 1
STOP     = 2
INFO     = 10
WARNING  = 11
ERROR    = 12
PROGRESS = 13
VIEW     = 20
OPTION   = 100
OPTION_1 = OPTION + 0
OPTION_2 = OPTION + 1
OPTION_3 = OPTION + 2
OPTION_4 = OPTION + 3
OPTION_5 = OPTION + 4

# Module variable used to store the open communication socket with Gmsh
sock = None

def getopt(opts):
    """Parse the given list (usually sys.argv) into a dict. 

    This is a very crude function which scans for options of the form
    ['-option=value'] and returns a dict of the form {'-option':'value'}.
    """
    options = {}
    for o in opts:
        s = o.split('=', 1)
        if len(s) < 2:
            if s[0].startswith('-'):
                # Option with no value given.
                options[s[0].lower()] = None
            else:
                # Value with no option given.
                options[None] = s[0]
        else:
            # Assign the given value to the option.
            options[s[0].lower()] = s[1]
    return options

def send(message, type=INFO):
    """Send information to Gmsh using the open socket. 

    Keyword arguments:
    message -- the string message to send
    type -- the type of message being sent (default INFO)

    As of Gmsh version 1.56, type should be one of:
    START STOP INFO WARNING ERROR PROGRESS VIEW OPTION 
    OPTION_1 OPTION_2 OPTION_3 OPTION_4 OPTION_5 

    If no socket has been opened (using a Gmsh.Client instance) then print the
    string sys.stderr.
    """
    if sock:
        sock.sendall(struct.pack('II', type, len(message)))
        sock.sendall(message)
    elif type is not PROGRESS:
        print >>sys.stderr, message

class Client:
    """Initiate and maintain connection with Gmsh socket.
    
    Instance this class to open and initiate socket communication with Gmsh.
    Communication will be automatically and gracefully terminated when the
    instance is destroyed.  Only one instance should exist at a time.
    """

    def __init__(self, filename):
        """Open and initiate connection to Gmsh socket.
        
        Keyword arguments:
        filename -- the name of the Unix socket given by Gmsh
            
        Assigns the new socket to the module variable sock and sends the
        process id to Gmsh to initiate the communication.
        """
        self.initialized = 0
        global sock
        if not sock:
            sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
            time.sleep(0.1)
            sock.connect(filename)
            send(str(os.getpid()), START)
            self.initialized = 1
        else:
            send('Gmsh.sock already exists as'+sock.getsockname(), ERROR)

    def __del__(self):
        """Gracefully close communications upon destruction.
        
        Sends the STOP signal to Gmsh and closes the socket.
        """
        global sock
        if self.initialized:
            send('Done.', STOP)
            sock.close()
            sock = None

class Mesh:
    """This is a class for storing nodes and elements.

    Members:
    nodes -- A dict of the form { nodeID: [ xcoord, ycoord, zcoord] }
    elements -- A dict of the form { elemID: (type, [tags], [nodeIDs]) }

    Methods:
    read(file) -- Parse a Gmsh version 1.0 or 2.0 mesh file
    write(file) -- Output a Gmsh version 2.0 mesh file
    """

    def __init__(self):
        self.nodes = {}
        self.elements = {}

    def read(self, mshfile):
        """Read a Gmsh .msh file.
        
        Reads Gmsh format 1.0 and 2.0 mesh files, storing the nodes and
        elements in the appropriate dicts.
        """

        readmode = 0
        send('Reading %s'%mshfile.name)
        for line in mshfile:
            line = line.strip()
            if line.startswith('$'):
                if line == '$NOD' or line == '$Nodes':
                    readmode = 1
                elif line == '$ELM':
                    readmode = 2
                elif line == '$Elements':
                    readmode = 3
                else:
                    readmode = 0
            elif readmode:
                columns = line.split()
                if readmode == 1 and len(columns) == 4:
                    # Version 1.0 or 2.0 Nodes
                    try:
                        self.nodes[int(columns[0])] = map(float, columns[1:])
                    except ValueError:
                        send('Node format error: '+line, ERROR)
                        readmode = 0
                elif readmode > 1 and len(columns) > 5:
                    # Version 1.0 or 2.0 Elements 
                    try:
                        columns = map(int, columns)
                    except ValueError:
                        send('Element format error: '+line, ERROR)
                        readmode = 0
                    else:
                        (id, type) = columns[0:2]
                        if readmode == 2:
                            # Version 1.0 Elements
                            tags = columns[2:4]
                            nodes = columns[5:]
                        else:
                            # Version 2.0 Elements
                            ntags = columns[2]
                            tags = columns[3:3+ntags]
                            nodes = columns[3+ntags:]
                        self.elements[id] = (type, tags, nodes)
        send('  %d Nodes'%len(self.nodes))
        send('  %d Elements'%len(self.elements))

    def write(self, file):
        """Dump the mesh out to a Gmsh 2.0 msh file."""
        print >>file, '$MeshFormat\n2.0 0 8\n$EndMeshFormat'
        print >>file, '$Nodes\n%d'%len(self.nodes)
        for (id, coord) in self.nodes.items():
            print >>file, id, ' '.join(map(str, coord))
        print >>file, '$EndNodes'
        print >>file, '$Elements\n%d'%len(self.elements)
        for (id, elem) in self.elements.items():
            (type, tags, nodes) = elem
            print >>file, id, type, len(tags),
            print >>file, ' '.join(map(str, tags)),
            print >>file, ' '.join(map(str, nodes))
        print >>file, '$EndElements'

if __name__ == '__main__':
    print __doc__

