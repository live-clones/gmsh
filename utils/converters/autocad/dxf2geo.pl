#!/usr/bin/perl
# dxf2geo.pl         SOURCE    LC    01/11/09
#
# [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
# CHAMPANEY Laurent  Universite de Versailles St Quentin le 24 / 10 / 01
#
# Transfert de geometrie DXF (AutoCAD) vers GEO (GMSH)
#
#  Usage :
#         dxf2geo.pl [-d densite] [-e epsilon] [-v] 
#                    [-D dimension] [-s GIBI;GMSH] essai
#  
#  lit essai.dxf et le converti en essai.geo   (-s GMSH)
#                                  essai.dgibi (-s GIBI)
#
#
# ======================================================================
#
# ======================================================================
# Analyse des arguments
# ======================================================================
use Getopt::Long;
@knownoptions = ("dimension|n=i",
                 "densite|d=f",
                 "epsilon|e=f",
                 "sortie|s=s",
                 "help|h",
                 "verbose|v");
GetOptions (@knownoptions) || exit ;
$dimen1 = 2;
if ($opt_dimension){$dimen1=$opt_dimension};
$densi1 = 1.;
if ($opt_densite){$densi1=$opt_densite};
$sortie = "GMSH";
if ($opt_sortie){$sortie=$opt_sortie};
$epsi1 = 1E-5;
if ($opt_epsilon){$epsi1=$opt_epsilon};
$verb1 = 0;
if ($opt_verbose){$verb1=1};
#
if ($opt_help){sortie_usage(); exit();};
#
if($#ARGV==-1) { sortie_usage(); exit();}
else {
        ($generic , $generic_ext) = ( $ARGV[0] =~ /([-_\/\w]*)\.?(\w*)/ ) ;
}
#
# ======================================================================
# Valeurs par defaut
# ======================================================================
$pi = atan2(1.,1.) * 4.;
# ======================================================================
# Fichiers
# ======================================================================
$dxf_file ="$generic.dxf";
if ($sortie eq "GIBI"){
	$sor_file = "$generic.dgibi";
}
else {
	$sor_file = "$generic.geo";
}
#
# ======================================================================
# En premier on mange le fichier dxf : les ENTITES seulement
# ======================================================================
open (INFIC, $dxf_file) || die "Le fichier $dxf_file n existe pas\n";
#$line = <INFIC>;
$nb1 = 0;
$flag1 = 0;
#
while ($line = <INFIC>)
{
	chomp($line);
#      Pour traiter les fichiers dos
        $line=~ s/\r//;
	if ($line eq 'ENTITIES') {$flag1 = 1};
	if ($line eq 'ENDSEC') {$flag1 = 0};
	if ($flag1 == 1)
	{
		$nb1 ++;
		$inlines[$nb1] = $line;
#		print "$inlines[$nb1]\n";
	}	
}
close (INFIC);
#
# ======================================================================
# On commence a lire
# ======================================================================
# Initialisations
$nb_POINT = 0;
$nb_LINE = 0;
$nb_ARC = 0;
$nb_CIRCLE = 0;
$nb_ELLI = 0;
$nb_LLINE = 0;
#
for ($iline = 1 ; $iline <= $nb1 ; $iline++) 
{
	$line = $inlines[$iline];
	if ($line eq 'LINE'){lit_LINE()}
	if ($line eq 'CIRCLE'){lit_CIRCLE()}
	if ($line eq 'ARC'){lit_ARC()}
	if ($line eq 'LWPOLYLINE'){lit_LWPOLYLINE()}
	if ($line eq 'ELLIPSE'){lit_ELLIPSE()}
}
#
# ======================================================================
# On ecrit le fichier 
# ======================================================================
open (OUFIC, ">$sor_file");
#
if ($sortie eq "GIBI"){
	sortie_gibi();
}
else {
	sortie_gmsh();
}
#
close OUFIC;
#
# ======================================================================
# On sort
# ======================================================================
print "\n";
print "Conversion $dxf_file vers $sor_file effectuee\n";
print "   (Densité $densi1 - Espilon pour les jonctions : $epsi1)\n";
print "\n";
exit;
#
#
# ===========================================================> End <===
#
# ======================================================================
# Subroutines
# ======================================================================
#
#
#
# ======================================================================
#  Avancee dans le fichier 
# ======================================================================
#
sub avance {
	while ($inlines[$iline] ne "@_") {$iline ++}
};
#
# ======================================================================
#  Controle du type de calque
# ======================================================================
#
sub controle_calque {
	avance("  8");
        $iline ++;
	$si_etoile = ($inlines[$iline] =~ /^\*/);
	return $si_etoile;
};
#
#
# ======================================================================
#  Lecture des entites LINE
# ======================================================================
#
sub lit_LINE {
#
#      Controle Calque
	if (controle_calque()) {return};
#
#      Premier point
	avance(" 10");
	$iline ++;
        my $x1 = $inlines[$iline];
	avance(" 20");
	$iline ++;
        my $y1 = $inlines[$iline];
	my $p1 = new_point($x1, $y1);
#      Deuxieme point
	avance(" 11");
	$iline ++;
        my $x2 = $inlines[$iline];
	avance(" 21");
	$iline ++;
        my $y2 = $inlines[$iline];
	my $p2 = new_point($x2, $y2);
#
	$nb_LINE++;
	$LINE[$nb_LINE][1] = $p1;
	$LINE[$nb_LINE][2] = $p2;
	if ($verb1){print "LINE  : Ligne $nb_LINE : $p1 $p2\n";}
#
	return;
};
#
#
# ======================================================================
#  Lecture des entites CIRCLE
# ======================================================================
#
sub lit_CIRCLE {
#
#      Controle Calque
	if (controle_calque()) {return};
#
#      Centre
        avance(" 10");
        $iline ++;
        my $x1 = $inlines[$iline];
        avance(" 20");
        $iline ++;
        my $y1 = $inlines[$iline];
        my $c0 = new_point($x1, $y1);
#      Rayon
        avance(" 40");
        $iline ++;
        my $r0 = $inlines[$iline];
#      Construction des points intermediaires
	$x2 = $x1 + $r0;
	$y2 = $y1 ;
        my $p1 = new_point($x2, $y2);
	$x2 = $x1 ;
	$y2 = $y1 + $r0;
        my $p2 = new_point($x2, $y2);
	$x2 = $x1 - $r0;
	$y2 = $y1 ;
        my $p3 = new_point($x2, $y2);
	$x2 = $x1 ;
	$y2 = $y1 - $r0;
        my $p4 = new_point($x2, $y2);
#
#      Construction des lignes
        $nb_CIRCLE++;
        $CIRCLE[$nb_CIRCLE][1] = $p1;
        $CIRCLE[$nb_CIRCLE][2] = $c0;
        $CIRCLE[$nb_CIRCLE][3] = $p2;
        if ($verb1){print "CIRCLE : Arc   $nb_CIRCLE : $p1 $c0 $p2\n";}
        $nb_CIRCLE++;
        $CIRCLE[$nb_CIRCLE][1] = $p2;
        $CIRCLE[$nb_CIRCLE][2] = $c0;
        $CIRCLE[$nb_CIRCLE][3] = $p3;
        if ($verb1){print "CIRCLE : Arc   $nb_CIRCLE : $p2 $c0 $p3\n";}
        $nb_CIRCLE++;
        $CIRCLE[$nb_CIRCLE][1] = $p3;
        $CIRCLE[$nb_CIRCLE][2] = $c0;
        $CIRCLE[$nb_CIRCLE][3] = $p4;
        if ($verb1){print "CIRCLE : Arc   $nb_CIRCLE : $p3 $c0 $p4\n";}
        $nb_CIRCLE++;
        $CIRCLE[$nb_CIRCLE][1] = $p4;
        $CIRCLE[$nb_CIRCLE][2] = $c0;
        $CIRCLE[$nb_CIRCLE][3] = $p1;
        if ($verb1){print "CIRCLE : Arc   $nb_CIRCLE : $p4 $c0 $p1\n";}
#      Le cercle complet
        $nb_LLINE++;
        $LLINE[$nb_LLINE][0] = 4;
        $LLINE[$nb_LLINE][1] = -1 * ($nb_CIRCLE - 3);
        $LLINE[$nb_LLINE][2] = -1 * ($nb_CIRCLE - 2);
        $LLINE[$nb_LLINE][3] = -1 * ($nb_CIRCLE - 1);
        $LLINE[$nb_LLINE][4] = -1 * ($nb_CIRCLE) ;
#
        return;
};
#
#
# ======================================================================
# lecture des entites ARC
# ======================================================================
#
sub lit_ARC {
#
#      Controle Calque
	if (controle_calque()) {return};
#
#      Centre
        avance(" 10");
        $iline ++;
        my $x1 = $inlines[$iline];
        avance(" 20");
        $iline ++;
        my $y1 = $inlines[$iline];
        my $c0 = new_point($x1, $y1);
#      Rayon
        avance(" 40");
        $iline ++;
        my $r0 = $inlines[$iline];
#      Angles initial et final
        avance(" 50");
        $iline ++;
        my $a1 = $inlines[$iline];
        avance(" 51");
        $iline ++;
        my $a2 = $inlines[$iline];
#      Construction du point initial
        $x2 = $x1 + ($r0 * cos($a1 / 180. * $pi));
        $y2 = $y1 + ($r0 * sin($a1 / 180. * $pi));
        my $p1 = new_point($x2, $y2);
	$a0 = ($a2 - $a1);
	if ($a0 < 0.) {$a0 = $a0 + 360.};
	if ($a0 >= 180.)
	{
#     		Construction du point intermediaire
		$a3 = ($a2 + $a1) / 2.;
		if (($a2 - $a1) < 0.) {$a3 =  $a3 + 180.};
        	$x2 = $x1 + ($r0 * cos($a3 / 180. * $pi));
        	$y2 = $y1 + ($r0 * sin($a3 / 180. * $pi));
        	my $p2 = new_point($x2, $y2);
#       	Construction du point final
        	$x3 = $x1 + ($r0 * cos($a2 / 180. * $pi));
        	$y3 = $y1 + ($r0 * sin($a2 / 180. * $pi));
        	my $p3 = new_point($x3, $y3);
#      		Construction des lignes
        	$nb_CIRCLE++;
        	$CIRCLE[$nb_CIRCLE][1] = $p1;
        	$CIRCLE[$nb_CIRCLE][2] = $c0;
        	$CIRCLE[$nb_CIRCLE][3] = $p2;
        	if ($verb1){print "ARC    : Arc    $nb_CIRCLE : $p1 $c0 $p2\n";}
#      		Construction des lignes
        	$nb_CIRCLE++;
        	$CIRCLE[$nb_CIRCLE][1] = $p2;
        	$CIRCLE[$nb_CIRCLE][2] = $c0;
        	$CIRCLE[$nb_CIRCLE][3] = $p3;
        	if ($verb1){print "ARC    : Arc    $nb_CIRCLE : $p2 $c0 $p3\n";}
#              Le cercle complet
                $nb_LLINE++;
		$LLINE[$nb_LLINE][0] = 2;
		$LLINE[$nb_LLINE][1] = -1*($nb_CIRCLE - 1);
		$LLINE[$nb_LLINE][2] = -1*($nb_CIRCLE) ;
	}
	else
	{
#       	Construction du point final
        	$x2 = $x1 + ($r0 * cos($a2 / 180. * $pi));
        	$y2 = $y1 + ($r0 * sin($a2 / 180. * $pi));
        	my $p2 = new_point($x2, $y2);
#      		Construction des lignes
        	$nb_CIRCLE++;
        	$CIRCLE[$nb_CIRCLE][1] = $p1;
        	$CIRCLE[$nb_CIRCLE][2] = $c0;
        	$CIRCLE[$nb_CIRCLE][3] = $p2;
        	if ($verb1){print "ARC    : Arc    $nb_CIRCLE : $p1 $c0 $p2\n";}
	}
#
        return;
};
#
#
# ======================================================================
#  Lecture des entites LWPOLYLINE
# ======================================================================
#
sub lit_LWPOLYLINE {
#
#      Controle Calque
	if (controle_calque()) {return};
#
#      nombre de segments
	avance(" 90");
	$iline ++;
        $nb_sommets = int($inlines[$iline]);
	avance(" 70");
	$iline ++;
        $poly_fermee = int($inlines[$iline]);
#        print "Polyline : $nb_sommets sommets : ferme : $poly_fermee \n";
        for (my $i = 1 ; $i <= $nb_sommets ; $i++) {
                avance(" 10");
	        $iline ++;
                $poly[$i][1] = $inlines[$iline];
                avance(" 20");
	        $iline ++;
                $poly[$i][2] = $inlines[$iline];
                if ($inlines[$iline + 1] eq " 42") {
                        avance(" 42");
	                $iline ++;
                        $poly[$i][3] = $inlines[$iline];
                }
                else {
                        $poly[$i][3] =  0;
                }
#                print "$poly[$i][1] $poly[$i][2] $poly[$i][3] \n";
        }
#      La multi-ligne pour la sortie GIBI
	$nb_LLINE++;
	my $nb_LLINE1 = 0;
#
#      Premier point
        $x1 = $poly[1][1];
        $y1 = $poly[1][2];
        $p1 = new_point($x1, $y1);
#
        for (my $i = 2 ; $i <= ($nb_sommets + $poly_fermee); $i++) {
#
#              Deuxieme point
                if ($i < ($nb_sommets + 1)) {
                        $x2 = $poly[$i][1];
                        $y2 = $poly[$i][2];
                        $p2 = new_point($x2, $y2);
                } 
                else {
                        $x2 = $poly[1][1];
                        $y2 = $poly[1][2];
                        $p2 = new_point($x2, $y2);
                }
#
                if ($poly[$i-1][3] == 0) {
                        $nb_LINE++;
                        $LINE[$nb_LINE][1] = $p1;
                        $LINE[$nb_LINE][2] = $p2;
                        if ($verb1){print "POLY  : Ligne $nb_LINE : $p1 $p2\n";}
			$nb_LLINE1 ++;
			$LLINE[$nb_LLINE][$nb_LLINE1] = $nb_LINE;
                }
                else {        
                # Rayon
                        my $L = sqrt((($x2 - $x1)*($x2 - $x1)) + (($y2 - $y1)*($y2 - $y1)));
                        my $a = $poly[$i-1][3] ; 
                        my $R = ($L/2.)*(1. + ($a*$a))/(2.*$a);
                        my $X = $R - ($a * $L / 2.);
                        if (abs($a) > 1.){$R = -1.*$R};
                        my $nx = ($x2 - $x1) / $L;
                        my $ny = ($y2 - $y1) / $L;
                        my $mx = -1.*$ny;
                        my $my = $nx;
                        my $x0 = $x1 + ($L/2.*$nx) + ($mx * $X);
                        my $y0 = $y1 + ($L/2.*$ny) + ($my * $X);
                        my $c0 = new_point($x0, $y0);
#       		Construction des lignes
                        if (abs($a) < 0.999) {
                                $nb_CIRCLE++;
                                $CIRCLE[$nb_CIRCLE][1] = $p1;
                                $CIRCLE[$nb_CIRCLE][2] = $c0;
                                $CIRCLE[$nb_CIRCLE][3] = $p2;
                                if ($verb1){print "POLY   : Arc    $nb_CIRCLE : $p1 $c0 $p2\n";}
				$nb_LLINE1 ++;
				$LLINE[$nb_LLINE][$nb_LLINE1] = -1*($nb_CIRCLE);
                        }
                        else {
                                my $x3 = $x1 + ($L/2.*$nx) - ($mx*$a*$L/2.);
                                my $y3 = $y1 + ($L/2.*$ny) - ($my*$a*$L/2.);
                                my $p3 = new_point($x3, $y3);
#
                                $nb_CIRCLE++;
                                $CIRCLE[$nb_CIRCLE][1] = $p1;
                                $CIRCLE[$nb_CIRCLE][2] = $c0;
                                $CIRCLE[$nb_CIRCLE][3] = $p3;
                                if ($verb1){print "POLY   : Arc    $nb_CIRCLE : $p1 $c0 $p3\n";}
				$nb_LLINE1 ++;
				$LLINE[$nb_LLINE][$nb_LLINE1] = -1*($nb_CIRCLE);
#
                                $nb_CIRCLE++;
                                $CIRCLE[$nb_CIRCLE][1] = $p3;
                                $CIRCLE[$nb_CIRCLE][2] = $c0;
                                $CIRCLE[$nb_CIRCLE][3] = $p2;
                                if ($verb1){print "POLY   : Arc    $nb_CIRCLE : $p3 $c0 $p2\n";}
				$nb_LLINE1 ++;
				$LLINE[$nb_LLINE][$nb_LLINE1] = -1*($nb_CIRCLE);
                        }

                }
#
                $x1 = $x2;
                $y1 = $y2;
                $p1 = $p2;
        }
#
	$LLINE[$nb_LLINE][0] = $nb_LLINE1;
#
	return;
};
#
#
# ======================================================================
#  Lecture des entites ELLIPSE
# ======================================================================
#
sub lit_ELLIPSE {
#
#      Controle Calque
	if (controle_calque()) {return};
#
#      Premier point
        avance(" 10");
        $iline ++;
        my $x1 = $inlines[$iline];
        avance(" 20");
        $iline ++;
        my $y1 = $inlines[$iline];
        my $p1 = new_point($x1, $y1);
#      Deuxieme point
        avance(" 11");
        $iline ++;
        my $x2 = $inlines[$iline];
	$x2 = $x1 + $x2;
        avance(" 21");
        $iline ++;
        my $y2 = $inlines[$iline];
	$y2 = $y1 + $y2;
        my $p2 = new_point($x2, $y2);
        avance(" 40");
        $iline ++;
        my $r0 = $inlines[$iline];
        avance(" 41");
        $iline ++;
        my $a1 = $inlines[$iline];
	$u1 = $a1 * 180. / $pi;
        avance(" 42");
        $iline ++;
        my $a2 = $inlines[$iline];
	$u2 = $a2 * 180. / $pi;
#
#       Construction du premier point
	$r1 = sqrt((($x2 - $x1) ** 2) + (($y2 - $y1) ** 2));
	$r2 = $r0 * $r1;
        $thet1 = atan2(($y2 - $y1),($x2 - $x1));
	$xp0 = ($r1 * cos ($a1));
	$yp0 = ($r2 * sin ($a1));
	$xp1 = $x1 + ( $xp0 * cos($thet1)) - ( $yp0 * sin($thet1));
	$yp1 = $y1 + ( $xp0 * sin($thet1)) + ( $yp0 * cos($thet1));
        $p3 = new_point($xp1, $yp1);
#
        $a0 = ($u2 - $u1);
        if ($a0 < 0.) {$a0 = $a0 + 360.};
        if ($a0 >= 120.)
        {
#               Construction du point intermediaire
                $a3 = ($u2 + $u1) / 2.;
                if (($u2 - $u1) < 0.) {$a3 =  $a3 + 180.};
	        $xp0 = ($r1 * cos ($a3 / 180 * $pi));
       		$yp0 = ($r2 * sin ($a3 / 180 * $pi));
       		$xp1 = $x1 + ( $xp0 * cos($thet1)) - ( $yp0 * sin($thet1));
       		$yp1 = $y1 + ( $xp0 * sin($thet1)) + ( $yp0 * cos($thet1));
                my $p4 = new_point($xp1, $yp1);
#               Construction du point final
		$xp0 = ($r1 * cos ($a2));
		$yp0 = ($r2 * sin ($a2));
		$xp1 = $x1 + ( $xp0 * cos($thet1)) - ( $yp0 * sin($thet1));
		$yp1 = $y1 + ( $xp0 * sin($thet1)) + ( $yp0 * cos($thet1));
                my $p5 = new_point($xp1, $yp1);
#               Construction des lignes
        	$nb_ELLI++;
		$ELLI[$nb_ELLI][1] = $p1;
		$ELLI[$nb_ELLI][2] = $p2;
		$ELLI[$nb_ELLI][3] = $r0;
		$ELLI[$nb_ELLI][4] = $u1;
		$ELLI[$nb_ELLI][5] = $a3;
		$ELLI[$nb_ELLI][6] = $p3;
		$ELLI[$nb_ELLI][7] = $p4;
		if ($verb1){print "ELLIPS: Ligne $nb_ELLI : $p1 $p2 $r0 $u1 $u2\n";}
#               Construction des lignes
        	$nb_ELLI++;
		$ELLI[$nb_ELLI][1] = $p1;
		$ELLI[$nb_ELLI][2] = $p2;
		$ELLI[$nb_ELLI][3] = $r0;
		$ELLI[$nb_ELLI][4] = $a3;
		$ELLI[$nb_ELLI][5] = $u2;
		$ELLI[$nb_ELLI][6] = $p4;
		$ELLI[$nb_ELLI][7] = $p5;
		if ($verb1){print "ELLIPS: Ligne $nb_ELLI : $p1 $p2 $r0 $u1 $u2\n";}
#              Le cercle complet
                $nb_LLINE++;
                $LLINE[$nb_LLINE][0] = 2;
                $LLINE[$nb_LLINE][1] = -1*($nb_ELLI - 1);
                $LLINE[$nb_LLINE][2] = -1*($nb_ELLI) ;
        }
        else
        {
#               Construction du point final
		$xp0 = ($r1 * cos ($a2));
		$yp0 = ($r2 * sin ($a2));
		$xp1 = $x1 + ( $xp0 * cos($thet1)) - ( $yp0 * sin($thet1));
		$yp1 = $y1 + ( $xp0 * sin($thet1)) + ( $yp0 * cos($thet1));
#                my $p4 = new_point($x3, $y3);
                my $p4 = new_point($xp1, $yp1);
#               Construction des lignes
        	$nb_ELLI++;
		$ELLI[$nb_ELLI][1] = $p1;
		$ELLI[$nb_ELLI][2] = $p2;
		$ELLI[$nb_ELLI][3] = $r0;
		$ELLI[$nb_ELLI][4] = $u1;
		$ELLI[$nb_ELLI][5] = $u2;
		$ELLI[$nb_ELLI][6] = $p3;
		$ELLI[$nb_ELLI][7] = $p4;
		if ($verb1){print "ELLIPS: Ligne $nb_ELLI : $p1 $p2 $r0 $u1 $u2\n";}
        }
#
        return;
};
#
# ======================================================================
#  CREATION d'un nouveau POINT
# ======================================================================
#
#
sub new_point {
	my($x0, $y0) = @_;
#	print "Test de point $x0 $y0\n";
	if ($nb_POINT != 0)
	{
		$i_POINT = 0;
		for (my $i = 1 ; $i <= $nb_POINT ; $i++)
		{
		        $dist = sqrt((($POINT[$i][1] - $x0) ** 2) +
			             (($POINT[$i][2] - $y0) ** 2));
#			printf ("%+22.14E\n",$dist);
#			if (($POINT[$i][1] == $x0) && ($POINT[$i][2] == $y0))
			if ($dist < $epsi1)
			{
				$i_POINT = $i;
			}
		}
		if ($i_POINT == 0)
		{
			cree_point($x0,$y0);
			$i_POINT = $nb_POINT;
		}	
	}
	else
	{
		cree_point($x0,$y0);
		$i_POINT = $nb_POINT;
	}
	return $i_POINT;
};		

sub cree_point {
	my($x0, $y0) = @_;
	$nb_POINT ++;
	$POINT[$nb_POINT][1] = $x0;
	$POINT[$nb_POINT][2] = $y0;
	if ($verb1){print "Nouveau POINT : $nb_POINT :  $x0 $y0\n";}
};
#
# ======================================================================
#  SORTIE vers GMSH
# ======================================================================
#
sub sortie_gmsh {
# La densite
	printf OUFIC "d1 = $densi1;\n";
# Les points
	for ($i = 1 ; $i <= $nb_POINT ; $i++) {
		printf OUFIC ("Point($i) = {%+22.14E, %+22.14E, 0., d1};\n", $POINT[$i][1], $POINT[$i][2]);
	}
# Les lignes
	for ($i = 1 ; $i <= $nb_LINE ; $i++) {
		printf OUFIC "Line ($i) = {$LINE[$i][1], $LINE[$i][2]};\n";
	}
# Les cercles
	for ($i = 1 ; $i <= $nb_CIRCLE ; $i++) {
		$j = $i + $nb_LINE;
		printf OUFIC "Circle($j) = {$CIRCLE[$i][1], $CIRCLE[$i][2], $CIRCLE[$i][3]};\n";
	}
# Les ellipses
	for ($i = 1 ; $i <= $nb_ELLI ; $i++) {
		$j = $i + $nb_LINE + $nb_CIRCLE;
		printf OUFIC "Ellipsis($j) = {$ELLI[$i][6], $ELLI[$i][1], $ELLI[$i][2], $ELLI[$i][7]};\n";
	}
#
};
#
# ======================================================================
#  SORTIE vers GIBIANE
# ======================================================================
#
sub sortie_gibi {
# si il y a des ellipses on place la routine GIBIANE de construction
	if ($nb_ELLI != 0) {ecrit_proc_ellipse()};
# Les options
	printf OUFIC "* Options generales\n";
	printf OUFIC "OPTI DIME $dimen1 ELEM TRI3;\n";
	printf OUFIC "DENS $densi1;\n";
# Les points
	printf OUFIC "* Les Points\n";
        for ($i = 1 ; $i <= $nb_POINT ; $i++) {
                if ($dimen1 == 2){
			printf OUFIC ("P$i = %13.5E %13.5E;\n", 
				$POINT[$i][1], $POINT[$i][2]);
		}
		else {
			printf OUFIC ("P$i = %13.5E %13.5E %13.5E;\n", 
				$POINT[$i][1], $POINT[$i][2], 0.);
		}
        }
# Les lignes
	printf OUFIC "* Les Lignes\n";

        for ($i = 1 ; $i <= $nb_LINE ; $i++) {
			printf OUFIC "L$i = DROI P$LINE[$i][1] P$LINE[$i][2];";
                if ($i == 1){ printf OUFIC "LT1 = L1;\n";}
                else { printf OUFIC "LT1 = LT1 ET L$i;\n";}
        }
# Les cercles
	printf OUFIC "* Les Arcs de Cercle\n";
        for ($i = 1 ; $i <= $nb_CIRCLE ; $i++) {
                $j = $i + $nb_LINE;
                printf OUFIC "L$j = CERC P$CIRCLE[$i][1] P$CIRCLE[$i][2] P$CIRCLE[$i][3];";
                if ($j == 1){ printf OUFIC "LT1 = L1;\n";}
                else { printf OUFIC "LT1 = LT1 ET L$j;\n";}
        }
# Les ellispes
	printf OUFIC "* Les Ellipses\n";
        for ($i = 1 ; $i <= $nb_ELLI ; $i++) {
                $j = $i + $nb_LINE + $nb_CIRCLE;
                printf OUFIC "L$j = ELLIPSE1 P$ELLI[$i][1] P$ELLI[$i][2]";
                printf OUFIC " P$ELLI[$i][6] P$ELLI[$i][7]\n";
                printf OUFIC " $ELLI[$i][3] $ELLI[$i][4] $ELLI[$i][5] ;\n";
                if ($j == 1){ printf OUFIC "LT1 = L1;\n";}
                else { printf OUFIC "LT1 = LT1 ET L$j;\n";}
        }
# Les multilignes 
	printf OUFIC "* Les Lignes complexes\n";
        for ($i = 1 ; $i <= $nb_LLINE ; $i++) {
		printf OUFIC "LL$i = ";
        	for ($j = 1 ; $j <= $LLINE[$i][0] ; $j++) {
			if ($LLINE[$i][$j] > 0){
				printf OUFIC "L$LLINE[$i][$j] ";
			}
			else {
				$k = $nb_LINE - $LLINE[$i][$j];
				printf OUFIC "L$k ";
			}
			if ($j == $LLINE[$i][0]) {printf OUFIC ";\n"}
			else {
				printf OUFIC "ET ";
				$l = $j - (6 * int($j / 6));
				if ($l == 0) {printf OUFIC "\n      "};	
			}
		}
	}
#
#
};
#
# ======================================================================
#  SORTIE vers GIBIANE : ecriture de la procedure de creation
#    des ellipses
# ======================================================================
#
sub ecrit_proc_ellipse{
printf OUFIC "debp ellipse1 c1*'POINT' c2*'POINT' ";
printf OUFIC "p1*'POINT' p2*'POINT'\n";
printf OUFIC "       a2*'FLOTTANT'  u1*'FLOTTANT' u2*'FLOTTANT';\n";
printf OUFIC "cx1 = coor 1 c1; cy1 = coor 2 c1;\n";
printf OUFIC "cx2 = coor 1 c2; cy2 = coor 2 c2;\n";
printf OUFIC "a1 = (((cx2 - cx1) ** 2) + ((cy2 - cy1) ** 2)) ** 0.5;\n";
printf OUFIC "b1 = a1 * a2;\n";
printf OUFIC "lo1 = (((a1 ** 2) + (b1 ** 2)) / 2.) ** 0.5;\n";
printf OUFIC "lo2 = lo1 * (u2 - u1) * PI / 180.;\n";
printf OUFIC "si (ega (vale dime) 2); n1 = ENTI (lo2 / (coor 3 c1));\n";
printf OUFIC "sinon; n1 = ENTI (lo2 / (coor 4 c1)); finsi;\n";
printf OUFIC "pr1 = prog u1 pas ((u2 - u1) / n1) u2;\n";
printf OUFIC "prx0 = prog (n1 + 1) * cx1;\n";
printf OUFIC "pry0 = prog (n1 + 1) * cy1;\n";
printf OUFIC "thet1 = ATG (cy2 - cy1) (cx2 - cx1);\n";
printf OUFIC "prx1 = (a1 * (cos pr1));\n";
printf OUFIC "pry1 = (b1 * (sin pr1));\n";
printf OUFIC "prx2 = prx0 + (prx1 * (cos thet1)) - (pry1 * (sin thet1));\n";
printf OUFIC "pry2 = pry0 + (prx1 * (sin thet1)) + (pry1 * (cos thet1));\n";
printf OUFIC "si (ega (vale dime) 2); l1 = quel seg2 prx2 pry2;\n";
printf OUFIC "sinon ; prz0 = prog (n1 + 1) * 0.;\n";
printf OUFIC "        l1 = quel seg2 prx2 pry2 prz0;finsi;\n";
printf OUFIC "elim (a1 / 1e3) l1 ((manu poi1 p1) et (manu poi1 p2));\n";
printf OUFIC "finp l1;\n";
};
#
# =======================================================================
#  Sortie par defaut apres erreur
# =======================================================================
#
sub sortie_usage {
        print "  \n";
        print "dxf2geo.pl : convertion DXF vers GEO (gmsh ou gibiane)\n";
        print "Laurent CHAMPANEY                     Novembre 2001\n";
        print "  \n";
        print "Usage :\n";
        print "         dxf2geo.pl [-d densite] [-e epsilon] [-v] \n";
        print "                    [-n dimension] [-s GIBI;GMSH] essai\n";
	print "Exemple :\n";
        print "  perl dxf2geo.pl -d 2. -e 1E-4 -v essai\n";
        print "  \n";
        print "  lit essai.dxf et le converti en essai.geo\n";
        print "    - en imposant une densite uniforme de 2  \n";
        print "    - en utilisant un epsilon de 1E-4 pour les jonctions\n";
        print "    - en visualisant des infos (-v)\n";
        print "  \n";
        print "  Elements géométriques supportés dans le fichier DXF : \n";
        print "   - Lignes     : LINE \n";
        print "   - Polylignes : LWPOLYLIGNE \n";
        print "   - Arcs       : ARC \n";
        print "   - Cercles    : CIRCLE \n";
        print "   - Ellipses   : ELLIPSE \n";
        print "  \n";
	return;
        };

