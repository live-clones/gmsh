#!/usr/bin/perl
#
# $Id: myperlsolver.pl,v 1.1 2005-01-13 20:36:54 geuzaine Exp $
#
# Copyright (c) 2002 Laurent CHAMPANEY <laurent.champaney@meca.uvsq.fr>. 
#
# This file contains a dummy perl client solver for Gmsh. It does not
# solve anything, but shows how to program your own perl solver 
# to interact with the Gmsh solver module.
#   
# To test this solver, copy the myperlsolver.opt file into your default
# Gmsh option file, or lauch Gmsh with the command:
#   
# gmsh -option myperlsolver.opt 
#
#
use Getopt::Long;
#
# Let's include the Gmsh client interface definitions. At the time of
# this writing, the client interface contains only three functions:
# GMSH_CLIENT::Connect, GMSH_CLIENT::SendString and
# GMSH_CLIENT::Disconnect. This example shows how to use these
# functions in order to program some simple interactions between a
# solver and Gmsh.
#
require 'GMSH_CLIENT.pm';
#
# 1. Loop through the command line arguments, remember the action
#    the solver has to perform and store the socket name, the
#    option name and the problem name. 
#
@knownoptions = ("options", 
		 "run=s",
		 "mesh=s",
		 "socket=s");
GetOptions(@knownoptions) || exit;
#
# 2. If the '-socket' option was not given, we cannot connect to Gmsh...
#
$socket_file = $opt_socket or die "No socket file";
#
$problem =  $ARGV[0];
#
# 3. Try to connect to the socket given by the '-socket' command
#    line option:
#
#   3.1. If the socket is down, issue an error...
#
GMSH_CLIENT::Connect(CLIENT, $socket_file);
#
#   3.2. ...otherwise, send the GMSH_CLIENT_START command (together
#        with the process ID of the solver), check if a problem name was
#        specified, and decide what to do
#
my $mysolver_pid = $$;
GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::START, "$mysolver_pid");
#
#     3.2.1. If options, the solver sends the valid options
#            (here for the first option):
#
if ($opt_options) {
	GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::OPTION_1, "VAL1");
	GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::OPTION_1, "VAL2");
	GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::OPTION_1, "VAL3");
};
#
#     3.2.2. If run, the solver runs the chosen option, updates the progress
#            message, issues some information data, produces a post-processing
#            map and asks Gmsh to merge it:
#
if ($opt_run) {
#
	if (!$problem) {
		GMSH_CLIENT::SendString(CLIENT,$GMSH_CLIENT::ERROR,"Missing File Name");
		GMSH_CLIENT::Disconnect(CLIENT);
		exit;
	};
	$mess = "Running $problem with option $opt_run"; 
	GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::INFO, $mess);
	for (my $i=0 ; $i < 10; $i++) {
	        my $j = 10 * $i;
		$mess = "$j% Complete";
		GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::PROGRESS, $mess);
		work();
	};
	$mess = "Done with $problem!"; 
	GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::INFO, $mess);
#
	open (POSFIC, ">mysolver.pos")
		or die "Unable to open output file";
	print POSFIC ("View \"$opt_run\"{\n");
	print POSFIC "ST(0,0,0,1,0,0,0,1,0){0,1,2};\n";
	print POSFIC "};\n";
	close POSFIC;
	GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::VIEW, "mysolver.pos");
};
#
#   3.3. We can now disconnect the solver from Gmsh:
#
GMSH_CLIENT::SendString(CLIENT, $GMSH_CLIENT::STOP, "Goodbye!");
GMSH_CLIENT::Disconnect(CLIENT);
#
# 4. That's it!
#
exit;

sub work {
	sleep 1;
};	
