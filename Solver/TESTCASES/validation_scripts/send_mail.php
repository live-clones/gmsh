#!/usr/bin/php5
<?php
function concat($i,$j){
  return "$i\n$j";
}
exec("/usr/bin/php5 -q benchmarks.php https://subversion.mema.ucl.ac.be/~slimdata",$result);
$mail_content=array_reduce($result,"concat");
$emails="richard.comblen@uclouvain.be,olivier.lietaer@uclouvain.be,sylvain.bouillon@uclouvain.be,olivier.gourgue@uclouvain.be,sebastien.blaise@uclouvain.be,benjamin.debrye@uclouvain.be,tuomas.karna@uclouvain.be,jonathanlambrechts@gmail.com";
$headers  = 'MIME-Version: 1.0' . "\r\n";
$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
$headers .= 'From: slim validation manager <richard.comblen@uclouvain.be>' . "\r\n";
mail($emails,"[slim automatic validation]",$mail_content,$headers);
?>
