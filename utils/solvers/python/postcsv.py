#!/usr/bin/env python
"""Convert csv finite element data into Gmsh pos format.

Usage:
    postcsv.py --mesh=gmshfile.msh --results=csvfile.csv [--average]

If --average is specified, the data for each node ID and each element ID is
averaged, otherwise repeated IDs are assumed to be new time steps.

csvfile.csv is in the following format:
    # comments start with #
    # time step 1 nodal scalar and vector data
    node, heading1, heading2
    1, 132.5, .0032 .0012 .0011
    2, 100.2, .0030 .0004 -.0120
    3,  98.3, .0021 .0032 .0002
    # time step 1 elemental scalar data
    element, heading3
    1, 32.63
    2, 30.34
    3, 21.32
    # time step 2 nodal scalar and vector data
    node, heading1, heading2
    1, 232.5, .0022 .0022 .0031
    2, 200.2, .0020 .0014 .0110
    3,  68.3, .0011 .0022 .0012

Carl Osterwisch <osterwischc@asme.org>, January 2005
"""

import Gmsh
import os, sys, re

class PostMesh(Gmsh.Mesh):
    """Store and convert FE results into Gmsh pos format.

    Extends the Gmsh.Mesh class by adding the following attributes:

    Members:
    dataTypes -- dict to convert data length into type (scalar, vector, ...)
    elemTypes -- dict to convert mesh element type into pos element type
    posTypes -- list in pos defined order of pos object types
    nodalData -- dict of nodal results
    elementData -- dict of element centroid results

    Methods:
    csvparse(csvfile): Read a comma-separated-value file of nodal results
    makeviews(file): Write all the data out to a Gmsh pos file
    saveview(posfile): Called by makeviews to output the data for one view
    """
    
    # dataTypes is used to translate the length of a vector into its
    # corresponding Gmsh type.
    dataTypes = {1:'S', 3:'V', 9:'T'}

    # elemTypes is used to convert from Gmsh mesh element type to Gmsh
    # post-processing object type.
    elemTypes = {1:'L', 2:'T', 3:'Q', 4:'S', 5:'H', 6:'I', 7:'Y'}

    # postTypes lists the valid Gmsh post-processing objects (dataType-elemType
    # combinations) in the order they are defined in the pos output file
    # format.
    postTypes = ['SP', 'VP', 'TP',
              'SL', 'VL', 'TL',
              'ST', 'VT', 'TT',
              'SQ', 'VQ', 'TQ',
              'SS', 'VS', 'TS',
              'SH', 'VH', 'TH',
              'SI', 'VI', 'TI',
              'SY', 'VY', 'TY',
              'T2', 'T2C', 'T3', 'T3C']

    def __init__(self):
        Gmsh.Mesh.__init__(self)

        self.nodalData = {}
        #{ viewName: { nodeID: [ [time1data], [time2data] ] } }

        self.elementData = {}
        #{ viewName: { elemID: [ [time1data], [time2data] ] } }

        # Delimiter between columns in the data file
        self.separator = '[,;]'

    def csvparse(self, csvfile):
        """Parse ascii file of results into elementData and nodeData.

        The file should be comma separated columns with matching column
        headings at the top.  The first column is assumed to be the node or
        element number.  Each unique heading will generate a new view within
        Gmsh.  Repeated headings will generate time steps for that view.
        """

        csv = re.compile('\s*' + self.separator + '\s*')
        elem = re.compile('el', re.I)
        datatype = self.nodalData

        Gmsh.send('Parsing results from %s'%csvfile.name)
        headings = []
        for line in csvfile:
            columns = csv.split(line.strip())
            if len(columns) > 1:
                # There are at least two columns.
                linedata = []
                try:
                    id = int(columns[0])
                    linedata = [map(float, column.split()) for column in columns[1:]]
                except ValueError:
                    # Assume this is a heading.
                    headings = columns
                    if elem.match(headings[0]):
                        datatype = self.elementData
                    else:
                        datatype = self.nodalData
                else:
                    for viewName, viewData in zip(headings[1:], linedata):
                        if not datatype.has_key(viewName):
                            datatype[viewName] = {}
                        if not datatype[viewName].has_key(id):
                            datatype[viewName][id] = [ viewData ]
                        else:
                            datatype[viewName][id].append(viewData)
        for (viewName, nodes) in self.nodalData.items():
            Gmsh.send('  %s %d Nodal Results'%(viewName, len(nodes)))
        for (viewName, elems) in self.elementData.items():
            Gmsh.send('  %s %d Elemental Results'%(viewName, len(elems)))

    def saveview(self, posfile, viewName=None, viewData=[]):
        """Store the given viewData to the posfile.

        If viewName is None it will output a header line to the file.
        """
        if not viewName:
            print >>posfile, '$PostFormat\n1.2 0 8\n$EndPostFormat'
        elif len(viewData):
            Gmsh.send('  View '+viewName)

            nts = len(viewData.values()[0][0][1][0])
            print >>posfile, '$View\n%s %d'%(viewName, nts)

            # Print section lengths.
            for type in self.postTypes:
                if viewData.has_key(type):
                    print >>posfile, len(viewData[type]),
                    Gmsh.send('    %s %d'%(type, len(viewData[type])))
                else:
                    print >>posfile, 0,

            # Print dummy time-step values.
            print >>posfile, '\n', ' '.join([str(i) for i in range(nts)])

            # Print data.
            for type in self.postTypes:
                if viewData.has_key(type):
                    for object in viewData[type]:
                        for x in range(3):
                            # Print the coordinates in the appropriate order.
                            print >>posfile, ' '.join([str(i[x]) for i in object[0]])
                        for timestep in range(nts):
                            for nodalResult in object[1]:
                                # Print the results.
                                try:
                                    print >>posfile, ' '.join([str(i) 
                                            for i in nodalResult[timestep]])
                                except IndexError:
                                    Gmsh.send('      Insufficient time steps for all locations.', 
                                            Gmsh.ERROR)
                                    Gmsh.send('      Consider using --average if this is one time step.', 
                                            Gmsh.ERROR)
            print >>posfile, '$EndView'

    def makeviews(self, file):
        """Generate post-processing views for the results.

        1. Loop through all defined elements and generate corresponding
        post-processor objects for elements with nodalData.

        2. Loop through all elementData and generate corresponding
        post-processor objects.
        """
        self.saveview(file) # This just prints the header information

        if len(self.nodalData):
            Gmsh.send('Saving nodal results to '+file.name)
            for viewName in self.nodalData.keys():
                viewData = {}
                for elem in self.elements.values():
                    # Iterate over all defined elements.
                    coord = []
                    result = []
                    for nid in elem[2]:
                        # Gather node coordinates and results for this element.
                        try:
                            coord.append(self.nodes[nid])
                        except KeyError:
                            Gmsh.send('  Mesh is missing node %d'%nid, 
                                    Gmsh.ERROR)
                        try:
                            result.append(self.nodalData[viewName][nid])
                        except KeyError:
                            pass
                    if len(result) == len(coord) and \
                            self.elemTypes.has_key(elem[0]):
                        # There was data available at every node for this
                        # element and this element has a corresponding
                        # post-processing object.
                        if self.dataTypes.has_key(len(result[0][0])):
                            postType = self.dataTypes[len(result[0][0])] + \
                                    self.elemTypes[elem[0]]
                            if not viewData.has_key(postType):
                                viewData[postType] = []
                            viewData[postType].append( (coord, result) )
                        else:
                            Gmsh.send("  No data type for "+repr(result[0]), 
                                    Gmsh.ERROR)
                self.saveview(file, viewName, viewData)

        if len(self.elementData):
            Gmsh.send('Saving elemental results to %s'%file.name)
            for (viewName, data) in self.elementData.items():
                viewData = {}
                for (eid, edata) in data.items():
                    try:
                        elem = self.elements[eid]
                    except KeyError:
                        Gmsh.send('  Mesh is missing element %d'%eid, 
                                Gmsh.ERROR)
                    else:
                        coord = []
                        for nid in elem[2]:
                            # Gather node coordinates and results for this
                            # element.
                            try:
                                coord.append(self.nodes[nid])
                            except KeyError:
                                Gmsh.send('  Mesh is missing node %d'%nid, 
                                        Gmsh.ERROR)
                        if len(elem[2]) == len(coord) and \
                                self.elemTypes.has_key(elem[0]):
                            # There was data available at every node for this
                            # element and this element has a corresponding
                            # post-processing object.
                            result = [edata]*len(coord)
                            if self.dataTypes.has_key(len(result[0][0])):
                                postType = (self.dataTypes[len(result[0][0])]
                                        + self.elemTypes[elem[0]])
                                if not viewData.has_key(postType):
                                    viewData[postType] = []
                                viewData[postType].append( (coord, result) )
                            else:
                                Gmsh.send("  No data type for "+repr(result[0]),
                                        Gmsh.ERROR)
                self.saveview(file, viewName, viewData)

###############################################################################
# Main program begins here
###############################################################################
cmdline = Gmsh.getopt(sys.argv[1:])
if cmdline.has_key('--socket'):
    connection = Gmsh.Client(cmdline['--socket'])

if cmdline.has_key('--help') or cmdline.has_key('-h'):
    print __doc__
elif cmdline.has_key('--options'):
    Gmsh.send('--noaverage', Gmsh.OPTION)
    Gmsh.send('--average', Gmsh.OPTION)
else:
    if not cmdline.has_key('--mesh'):
        Gmsh.send("No mesh specified.", Gmsh.ERROR)
        sys.exit(1)
    if not cmdline.has_key('--results'):
        Gmsh.send("No results specified.", Gmsh.ERROR)
        sys.exit(1)

    try:
        mshfile = open(cmdline['--mesh'])
        csvfile = open(cmdline['--results'])
    except:
        Gmsh.send(str(sys.exc_info()[1]), Gmsh.ERROR)
    else:
        pmesh = PostMesh()
        pmesh.read(mshfile)
        mshfile.close()
        pmesh.csvparse(csvfile)
        csvfile.close()
        if cmdline.has_key('--average'):
            Gmsh.send('Averaging data to one time step.')
            for result in [ pmesh.nodalData, pmesh.elementData ]:
                for view in result.keys():
                    for (id, data) in result[view].items():
                        nts = len(data)
                        averaged = []
                        for col in range(min(map(len, data))):
                            sum = 0.0
                            for d in data:
                                sum += d[col]
                            averaged.append(sum/nts)
                        result[view][id] = [averaged]
        try:
            posfile = open(os.path.splitext(csvfile.name)[0]+'.pos', 'w')
        except:
            Gmsh.send(str(sys.exc_info()[1]), Gmsh.ERROR)
        else:
            pmesh.makeviews(posfile)
            posfile.close()
            Gmsh.send(posfile.name, Gmsh.VIEW)
