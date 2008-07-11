# Copyright (c) 2002 Laurent CHAMPANEY <laurent.champaney@meca.uvsq.fr>. 
# All rights reserved.
# This program is free software; you can redistribute it and/or
# modify it under the same terms as Perl itself.

package GMSH_CLIENT;
use Socket;

$START        = 1;
$STOP         = 2;
$INFO         = 10;
$WARNING      = 11;
$ERROR        = 12;
$PROGRESS     = 13;
$VIEW         = 20; # deprecated: use MERGE_FILE instead
$MERGE_FILE   = 20;
$PARSE_STRING = 21;
$OPTION       = 100;
$OPTION_1     = ($OPTION+0);
$OPTION_2     = ($OPTION+1);
$OPTION_3     = ($OPTION+2);
$OPTION_4     = ($OPTION+3);
$OPTION_5     = ($OPTION+4);

sub SocketSendData (*$;$$) {
	my ($socket, $buffer, $bytes) = @_; 
	$lng = $bytes;
	$decalage = 0;
	while ($lng) {
		$ecrit = syswrite $socket, $buffer, $lng,  $decalage;
		$decalage += $ecrit;
		$lng -= $ecrit;
	}
	return;
};

sub SendString (*$;$$) {
	my ($socket, $type, $str) = @_;
	$type1 = pack("V", $type);
	my $len2 = length($type1);
	SocketSendData($socket, $type1, $len2);
	my $len = length($str);
	$len1 = pack("V", $len);
	$len2 = length($len1);
	SocketSendData($socket, $len1, $len2);
	SocketSendData($socket, $str, $len);
	return;
};

sub Disconnect (*) {
	$socket = @_;
	close $socket;
	return;
};

sub Connect (*$;$$) {
	my ($socket, $socket_file) = @_;
	socket($socket, AF_UNIX, SOCK_STREAM, 0)
		or die "Can't create socket : $!";
	connect($socket, sockaddr_un($socket_file))
    		or die "Can't connect to $socket_file: $!";
	return;
};

1;
